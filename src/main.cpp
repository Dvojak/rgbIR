#include <Arduino.h>
#include <IRremote.hpp>

// Definování pinů a konstant
#define IR_RECEIVE_PIN 12 // Pin pro přijímač IR signálu
#define ENTER 4127850240 // Kód klávesy ENTER z IR ovladače
#define RL 5 // Pin pro červenou LED
#define GL 6 // Pin pro zelenou LED
#define BL 9 // Pin pro modrou LED

// Pole kódů pro číslice 0-9 z IR ovladače
unsigned long codes[] = {
    3910598400, // 0
    4077715200, // 1
    3877175040, // 2
    2707357440, // 3
    4144561920, // 4
    3810328320, // 5
    2774204160, // 6
    3175284480, // 7
    2907897600, // 8
    3041591040, // 9
};

String stringNum = ""; // Proměnná pro ukládání přijímaného čísla jako řetězce
int barva = 0; // Proměnná pro ukládání aktuálně vybrané barvy (0 = červená, 1 = zelená, 2 = modrá)

// Vypočítání velikosti pole codes
int codesSize = sizeof(codes) / sizeof(codes[0]);

// Funkce pro převod kódu IR na odpovídající číslici
String receivedNum(unsigned long irData) {
    for (int i = 0; i < codesSize; i++) { 
        if (irData == codes[i]) {
            return String(i); // Pokud nalezeno, vrátí číslici jako řetězec
        }
    }
    return ""; // Pokud kód není nalezen, vrátí prázdný řetězec
}

void setup() {
    // Inicializace přijímače IR signálu
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
    Serial.begin(9600); // Inicializace sériové komunikace
    // Nastavení pinů LED jako výstupní
    pinMode(RL, OUTPUT);
    pinMode(GL, OUTPUT);
    pinMode(BL, OUTPUT);
}

void loop() {
    if (IrReceiver.decode()) { // Kontrola, zda byl přijat IR signál
        unsigned long irData = IrReceiver.decodedIRData.decodedRawData; // Načtení přijatého IR datového kódu
        if (irData > 0) {
            Serial.print(irData); // Vypsání přijatého kódu do sériového monitoru
            Serial.print(",");
            if (irData == ENTER) { // Kontrola, zda byl přijat kód ENTER
                int intNum = stringNum.toInt(); // Převod přijatého čísla na integer
                if (intNum >= 0 && intNum <= 255) { // Kontrola, zda je číslo v rozsahu 0-255
                    switch (barva) { // Nastavení hodnoty PWM pro odpovídající LED
                        case 0:
                            analogWrite(RL, intNum); // Červená LED
                            break;
                        case 1:
                            analogWrite(GL, intNum); // Zelená LED
                            break;
                        case 2:
                            analogWrite(BL, intNum); // Modrá LED
                            break;
                    }
                    Serial.print("Chosen value: ");
                    Serial.println(intNum); // Vypsání nastavené hodnoty
                    stringNum = ""; // Vymazání uloženého čísla
                } else {
                    Serial.println("Out of range"); // Vypsání chybové zprávy, pokud je číslo mimo rozsah
                    stringNum = ""; // Vymazání uloženého čísla
                }
            } else if (irData == 3125149440) { // Kontrola, zda byl přijat kód pro červenou LED
                barva = 0; // Nastavení červené LED
                Serial.println("Red LED");
            } else if (irData == 3108437760) { // Kontrola, zda byl přijat kód pro zelenou LED
                barva = 1; // Nastavení zelené LED
                Serial.println("Green LED");
            } else if (irData == 3091726080) { // Kontrola, zda byl přijat kód pro modrou LED
                barva = 2; // Nastavení modré LED
                Serial.println("Blue LED");
            } else { 
                stringNum += receivedNum(irData); // Přidání přijaté číslice k uloženému číslu
                Serial.println(stringNum); // Vypsání aktuálně uloženého čísla
            }
        }

        IrReceiver.resume(); // Připravení přijímače pro další příjem
    }
}

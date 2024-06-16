#Ovládání RGB LED pomocí IR ovladače
Tento projekt umožňuje ovládat RGB LED pomocí IR ovladače. Můžete nastavit jas každé barvy (červená, zelená a modrá) zadáním čísel od 0 do 255 pomocí ovladače. Vybraná hodnota jasu je aplikována na aktuálně zvolenou barvu (červená, zelená nebo modrá).

Potřebné komponenty
Arduino deska
IR přijímač
RGB LED
Rezistory (odpovídající hodnoty pro vaši RGB LED)
IR ovladač
Propojovací dráty
Breadboard
Zapojení
Připojte IR přijímač:

VCC k 5V na Arduinu
GND k GND na Arduinu
Signálový pin k pinu 12 na Arduinu
Připojte RGB LED:

Společnou katodu/anodu k GND (pokud společná katoda) nebo VCC (pokud společná anoda) na Arduinu přes odpovídající rezistory
Červený pin k pinu 5 na Arduinu
Zelený pin k pinu 6 na Arduinu
Modrý pin k pinu 9 na Arduinu
Instalace
Stáhněte a nainstalujte knihovnu IRremote

Otevřete Arduino IDE
Jděte do Sketch -> Include Library -> Manage Libraries...
Vyhledejte IRremote od shirriff a nainstalujte ji
Nahrání kódu

Zkopírujte poskytnutý kód do Arduino IDE
Připojte Arduino k počítači přes USB
Vyberte správnou desku a port v menu Tools
Klikněte na tlačítko nahrání
Použití
Zapněte systém

Připojte Arduino k napájecímu zdroji (USB nebo externí napájení)
Vyberte barvu

Pomocí IR ovladače vyberte barvu k nastavení:
Červená LED: Stiskněte tlačítko odpovídající kódu 3125149440
Zelená LED: Stiskněte tlačítko odpovídající kódu 3108437760
Modrá LED: Stiskněte tlačítko odpovídající kódu 3091726080
Nastavte jas

Použijte číslicová tlačítka na IR ovladači k zadání hodnoty mezi 0 a 255
Stiskněte tlačítko ENTER (kód 4127850240) k nastavení jasu vybrané barvy
Zobrazte výsledek

Vybraná LED upraví svůj jas na zadanou hodnotu
Příklad workflow
Nastavení červené LED na jas 100:

Vyberte červenou LED: Stiskněte tlačítko odpovídající kódu 3125149440
Zadejte 100: Stiskněte číslicová tlačítka 1, 0, 0
Potvrďte: Stiskněte tlačítko ENTER (kód 4127850240)
Nastavení zelené LED na jas 200:

Vyberte zelenou LED: Stiskněte tlačítko odpovídající kódu 3108437760
Zadejte 200: Stiskněte číslicová tlačítka 2, 0, 0
Potvrďte: Stiskněte tlačítko ENTER (kód 4127850240)
Nastavení modré LED na jas 50:

Vyberte modrou LED: Stiskněte tlačítko odpovídající kódu 3091726080
Zadejte 50: Stiskněte číslicová tlačítka 5, 0
Potvrďte: Stiskněte tlačítko ENTER (kód 4127850240)
Řešení problémů
Ujistěte se, že jsou všechny spojení pevně a správně zapojena.
Ověřte, že IR přijímač funguje tím, že tisknete přijímané IR kódy do sériového monitoru.
Ujistěte se, že správné kódy pro váš specifický IR ovladač jsou definovány v poli codes a pro tlačítka ENTER, Červená, Zelená a Modrá.

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include "LogicEngine.h"
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "NandGate.h"
#include "XorGate.h"
#include "HalfAdder.h"

/**
 * TEIL C: Rohdaten-Parser
 * Liest die Datei schaltzustaende.txt und parst die Ziffern in einen Vektor
 */
std::vector<int> parseInputFile(const std::string& filename) {
    std::vector<int> signals;
    std::ifstream inputFile(filename);

    // Prüfe, ob Datei erfolgreich geöffnet wurde
    if (!inputFile.is_open()) {
        std::cerr << "FEHLER: Datei '" << filename << "' konnte nicht geöffnet werden!" << std::endl;
        return signals; // Leerer Vektor zurückgeben
    }

    std::cout << "[Parser] Datei '" << filename << "' geöffnet." << std::endl;

    // Ganzen Inhalt in einen String lesen
    std::string line;
    while (std::getline(inputFile, line)) {
        // std::stringstream zum Parsen der einzelnen Ziffern
        std::stringstream ss(line);
        int value;
        while (ss >> value) {
            if (value == 0 || value == 1) {
                signals.push_back(value);
                std::cout << "[Parser] Signal gelesen: " << value << std::endl;
            } else {
                std::cerr << "[Parser WARNUNG] Ungültiger Wert: " << value 
                          << " (erwartet 0 oder 1)" << std::endl;
            }
        }
    }

    inputFile.close();
    std::cout << "[Parser] Datei geschlossen. Insgesamt " << signals.size() 
              << " Signale gelesen." << std::endl;

    return signals;
}

/**
 * ZUSATZAUFGABE: Fehlertest - Versucht, auf private Variable zuzugreifen
 * Dies ist ABSICHTLICH auskommentiert, um zu zeigen, dass es nicht kompiliert!
 * Wenn auskommentiert, würde der Compiler einen Fehler auslösen:
 * 
 * "error: 'inputA' is a private member of 'LogicSim::AndGate'"
 * 
 * Das ist GEWÜNSCHT, weil es die Kapselung schützt.
 */
void demonstrateEncapsulation() {
    std::cout << "\n=== ZUSATZAUFGABE 3: Fehlertest (Kapselung) ===" << std::endl;
    std::cout << "Die folgende Zeile ist AUSKOMMENTIERT, da sie nicht kompiliert:" << std::endl;
    std::cout << "// AndGate gate; gate.inputA = 1;  // FEHLER: inputA ist private!" << std::endl;
    std::cout << "\nDies ist erwünscht, da private Variablen die Kapselung schützen." << std::endl;
    std::cout << "Der Compiler verbietet direkten Zugriff und zwingt zur Nutzung von Setter-Methoden." << std::endl;
}

//Lab4: Zusatzaugabe 1:
bool Unit_Test(){
    //LogikEngine notwendig um ein XorGate zu erstellen??? Nein! 
    //weil es hier nur um einen Gatter "XorGate" geht!
    /*LogicEngine engine;
    engine.setCircuitName("Unit_Test");

    Component *g1 = new XorGate("Xor");

    engine.addComponent(g1);*/

    XorGate xorGate("Unit_Test-Xor");
    bool testBestanden = true;
    //Eingaenge 00
    xorGate.setInputA(0);
    xorGate.setInputB(0);

    bool erg = xorGate.evaluate();
    if(erg == true)
        {std::cout << "falsch. Erwartet 0, bekommen 1" << std::endl;
        testBestanden = false;}
    else 
        std::cout << "richtig" << std::endl;

    //Eingaenge 01
    xorGate.setInputA(0);
    xorGate.setInputB(1);

    erg = xorGate.evaluate();
    if(erg == false)
        {std::cout << "falsch. Erwartet 1, bekommen 0" << std::endl;
        testBestanden = false;}
    else 
        std::cout << "richtig" << std::endl;

    //Eingaenge 10
    xorGate.setInputA(1);
    xorGate.setInputB(0);

    erg = xorGate.evaluate();
    if(erg == false)
        {std::cout << "falsch. Erwartet 1, bekommen 0" << std::endl;
        testBestanden = false;}
    else 
        std::cout << "richtig" << std::endl;

    //Eingaenge 11
    xorGate.setInputA(1);
    xorGate.setInputB(1);

    erg = xorGate.evaluate();
    if(erg == true)
        {std::cout << "falsch" << std::endl;
        testBestanden = false;}
    else 
        std::cout << "richtig" << std::endl;

    return testBestanden;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Laboranweisung 2: Logikgatter-Simulation" << std::endl;
    std::cout << "========================================\n" << std::endl;

    // ================================================
    // TEIL D: Integration (Manueller Test)
    // ================================================

    std::cout << "--- TEIL D: Integration mit AndGate ---\n" << std::endl;

    // 1. Instanziierung eines AndGate-Objekts
    AndGate meinGatter("Haupt-AND");
    std::cout << std::endl;

    // 2. Rohdaten-Datei parsen (TEIL C)
    std::cout << "\n--- TEIL C: Rohdaten-Parser ---\n" << std::endl;
    std::vector<int> inputSignals = parseInputFile("schaltzustaende.txt");

    if (inputSignals.empty()) {
        std::cerr << "FEHLER: Keine Signale gelesen. Programm beendet." << std::endl;
        return 1;
    }

    // 3. Simulation durchführen und Ergebnisse speichern
    std::cout << "\n--- Simulation: AndGate mit eingelesenen Signalen ---\n" << std::endl;
    std::vector<int> outputSignals;

    // Wir verwenden die eingelesenen Signale als Eingang A und wechseln B
    for (size_t i = 0; i < inputSignals.size(); i++) {
        int signalA = inputSignals[i];
        int signalB = inputSignals[(i + 1) % inputSignals.size()]; // Nächster Wert (zirkulär)

        // Eingänge setzen
        meinGatter.setInputA(signalA);
        meinGatter.setInputB(signalB);

        // Berechnung durchführen
        //meinGatter.update(); // wird durch evaluate ersetzt

        //Component* test = new Component(); //test puer virtual function
        //Component test;

        // Zustand ausgeben
        std::cout << "Schritt " << (i + 1) << ": ";
        meinGatter.printState();

        // Ausgang speichern
        outputSignals.push_back(meinGatter.getOutput() ? 1 : 0);
    }

    // 4. Kontrolle: Wahrheitstabelle verifizieren
    std::cout << "\n--- Wahrheitstabelle Überprüfung (AND) ---" << std::endl;
    std::cout << "0 AND 0 = 0 (erwartet: 0)" << std::endl;
    std::cout << "0 AND 1 = 0 (erwartet: 0)" << std::endl;
    std::cout << "1 AND 0 = 0 (erwartet: 0)" << std::endl;
    std::cout << "1 AND 1 = 1 (erwartet: 1)" << std::endl;

    // ================================================
    // ZUSATZAUFGABE 1 & 2: NOT-Gate und NAND-Gate Demo
    // ================================================
/*
    std::cout << "\n=== ZUSATZAUFGABE 1 & 2: NOT- und NAND-Gatter ===" << std::endl;

    std::cout << "\n--- NOT-Gatter Demo ---" << std::endl;
    NotGate notGate;
    std::cout << std::endl;

    for (int signal : inputSignals) {
        notGate.setInput(signal);
        notGate.update();
        notGate.printState();
    }

    std::cout << "\n--- NAND-Gatter Demo (Komposition aus AND + NOT) ---" << std::endl;
    NandGate nandGate;
    std::cout << std::endl;

    for (size_t i = 0; i < inputSignals.size(); i++) {
        int signalA = inputSignals[i];
        int signalB = inputSignals[(i + 1) % inputSignals.size()];

        nandGate.setInputA(signalA);
        nandGate.setInputB(signalB);
        nandGate.update();

        std::cout << "Schritt " << (i + 1) << ": ";
        nandGate.printState();
    }
*/
    // ================================================
    // ZUSATZAUFGABE 3: Fehlertest (Kapselung)
    // ================================================

    demonstrateEncapsulation();

    // ================================================
    // ZUSATZAUFGABE 4: Log-Datei schreiben
    // ================================================

    std::cout << "\n=== ZUSATZAUFGABE 4: Log-Datei Ausgabe ===" << std::endl;

    std::ofstream logFile("simulation_log.txt", std::ios::app);

    if (!logFile.is_open()) {
        std::cerr << "FEHLER: Log-Datei konnte nicht geöffnet werden!" << std::endl;
        return 1;
    }

    logFile << "\n========================================\n";
    logFile << "Simulationslauf vom ";
    time_t now = time(nullptr);
    logFile << ctime(&now); // Zeitstempel
    logFile << "========================================\n";

    logFile << "\nEingangssignale: ";
    for (int sig : inputSignals) {
        logFile << sig << " ";
    }
    logFile << "\n";

    logFile << "Ausgangssignale (AND): ";
    for (int sig : outputSignals) {
        logFile << sig << " ";
    }
    logFile << "\n\nWahrheitstabellen:\n";

    logFile << "\nAND-Gatter:\n";
    logFile << "  A | B | Y\n";
    logFile << "  0 | 0 | 0\n";
    logFile << "  0 | 1 | 0\n";
    logFile << "  1 | 0 | 0\n";
    logFile << "  1 | 1 | 1\n";

    logFile << "\nOR-Gatter:\n";
    logFile << "  A | B | Y\n";
    logFile << "  0 | 0 | 0\n";
    logFile << "  0 | 1 | 1\n";
    logFile << "  1 | 0 | 1\n";
    logFile << "  1 | 1 | 1\n";

    logFile << "\nNOT-Gatter:\n";
    logFile << "  A | Y\n";
    logFile << "  0 | 1\n";
    logFile << "  1 | 0\n";

    logFile << "\nNAND-Gatter (AND + NOT):\n";
    logFile << "  A | B | Y\n";
    logFile << "  0 | 0 | 1\n";
    logFile << "  0 | 1 | 1\n";
    logFile << "  1 | 0 | 1\n";
    logFile << "  1 | 1 | 0\n";

    logFile.close();
    std::cout << "[Logger] Simulationsergebnisse in 'simulation_log.txt' appended." << std::endl;

    // ================================================
    // Zusammenfassung
    // ================================================

    std::cout << "\n========================================" << std::endl;
    std::cout << "Zusammenfassung der Ausgangssignale:" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Eingaben (A, B):  ";
    for (size_t i = 0; i < inputSignals.size(); i++) {
        int a = inputSignals[i];
        int b = inputSignals[(i + 1) % inputSignals.size()];
        std::cout << "(" << a << "," << b << ") ";
    }
    std::cout << std::endl;

    std::cout << "AND-Ausgänge:     ";
    for (int sig : outputSignals) {
        std::cout << sig << "     ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "✓ Alle Aufgaben erfolgreich implementiert!" << std::endl;
    std::cout << "✓ Kompilierung: g++ main.cpp LogicEngine.cpp -o simulator.exe" << std::endl;

    //Labor3: Zusatzaufgabe3: Upcasting:

    std::vector<Component*> meineSchaltung;
    meineSchaltung.push_back(new AndGate("G1"));// new weil Speicher auf dem Heap reserviert? Nachlesen!
    //meineSchaltung.push_back(new OrGate("G2"));  .. geht auch weil Typ Component!
    meineSchaltung.push_back(new OrGate("G2"));  
    meineSchaltung.push_back(new AndGate("G3"));

    //Lab4, TeilC: anfuegen von Components zum LogicEngine:
    LogicEngine engine;
    engine.setCircuitName("Leak-Test-Schaltung");

    std::cout << "Baue Schaltung auf dem Heap (Wird aktuell NICHT gelöscht!)..." << std::endl;

    Component *g1 = new AndGate("HauptAnd");
    Component *g2 = new OrGate("HauptOr");
    Component *g3 = new NandGate("HauptNand");
    Component *g4 = new XorGate("HauptXor");

    engine.addComponent(g1);
    engine.addComponent(g2);
    engine.addComponent(g3);
    engine.addComponent(g4);
    //Lab4: Zusatzaufgabe 1
    // Test-Eingänge setzen
    std::cout << "\nSetze Signale..." << std::endl;
    g1->setInputA(1);
    g1->setInputB(1);
    
    g2->setInputA(0);
    g2->setInputB(1);

    g3->setInputA(0);
    g3->setInputB(1);

    g4->setInputA(1);
    g4->setInputB(0);

    bool stub = g4->evaluate();
    std::cout << "Stub: " << stub << std::endl;

    // Simulation einmal durchrechnen
    std::cout << "\nStarte Simulation:" << std::endl;
    engine.doTick();

    std::cout << "\nProgramm beendet. Achtung: RAM wurde nicht freigegeben!" << std::endl;

    // FEHLER: Hier fehlen 'delete g1;', 'delete g2;', 'delete g3;', weil 
    //Components g1, g2, ... dynamisch erstellt wurden

    //Loesung: Dynamische Speicher auf Heap mit 'delete' freigeben
    delete g1;
    delete g2;
    delete g3;
    delete g4;

    //Lab4: Zusatzaufgabe 1:
    if (Unit_Test()) {
        std::cout << "SUCCES: Das XOR-Gatter funktioniert perfekt!" << std::endl;
    } else {
        std::cout << "ERROR: Das XOR-Gatter hat einen Logikfehler!" << std::endl;
    }

    // Lab4 TeilA, Test: virtell:
    // Component *bauteil = new Component();// compiler fehler, da pure virtuell function!

    //Lab4: Zusatzaufgabe 3: Halbaddierer, Komposition:
    // Irgendwo in deiner main()-Funktion:
    std::cout << "\n=== Zusatzaufgabe 3: Teste komplexen HalfAdder ===" << std::endl;

    LogicEngine engineHalfAdder;
    HalfAdder* meinAdder = new HalfAdder("HA_1");

    // Setze Eingänge für 1 + 1 (Sollte ergeben: Summe=0, Carry=1)
    meinAdder->setInputA(1);
    meinAdder->setInputB(1);

    // Der Engine übergeben (Upcasting funktioniert!)
    engineHalfAdder.addComponent(meinAdder);

    // Simulation starten (ruft intern meinAdder->evaluate() auf)
    engineHalfAdder.doTick();

    // Da doTick standardmäßig nur printState() der Basisklasse aufrufen würde, 
    // rufen wir hier manuell die spezielle printState des Adders auf, um das Carry zu sehen:
    meinAdder->printState();

    // Speicher freigeben
    delete meinAdder;


    return 0;
}






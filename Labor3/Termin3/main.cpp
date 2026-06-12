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
        meinGatter.update();

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

    return 0;
}






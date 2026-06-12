#include <iostream>
#include <vector>
#include "Component.h"
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "XorGate.h"
#include "NandGate.h"
#include "LogicEngine.h"

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Labor 5: Speichersicherheit & Refactoring" << std::endl;
    std::cout << "Ausgangslage: Rohe Pointer und Memory Leaks" << std::endl;
    std::cout << "========================================\n" << std::endl;

    LogicEngine engine;
    engine.setCircuitName("Leak-Test-Schaltung");

    std::cout << "Baue Schaltung auf dem Heap (Wird aktuell NICHT gelöscht!)...TESTAENDERUNG" << std::endl;

    // ---------------------------------------------------------
    // VERALTETER CODE: Nutzung von nacktem 'new'.
    // Dieser Code erzeugt absichtlich ein Memory Leak, da das 
    // zugehörige 'delete' nirgends aufgerufen wird!
    // ---------------------------------------------------------

    //new syntax weg, weil smart pointers benutzt!
    //auto: Datentyp automatisch eingefuegt. 
    //Hier: auto = std::unique_ptr<AndGate>

    auto g1 = std::make_unique<AndGate>("Haupt-AND");
    auto g2 = std::make_unique<OrGate>("Haupt-OR");
    auto g3 = std::make_unique<XorGate>("Test-XOR");

    // Test-Eingänge setzen
    std::cout << "\nSetze Signale..." << std::endl;
    g1->setInputA(1);
    g1->setInputB(1);
    
    g2->setInputA(0);
    g2->setInputB(1);
    
    g3->setInputA(1);
    g3->setInputB(0);

    //Eingaenge setzen, dann move. Denn sonst zeigen auf NullPointer,
    //und undefiniertes Verhalten!!
    
    // Gatter an die Engine übergeben (erwartet aktuell Component*)
    engine.addComponent(std::move(g1)); //Kopieren von ptr nicht moeglich weil smart, 
                                    //aber Besitzer verschieben!!
    engine.addComponent(std::move(g2));
    engine.addComponent(std::move(g3));

    // Simulation einmal durchrechnen
    std::cout << "\nStarte Simulation:" << std::endl;
    engine.doTick();

    std::cout << "\nProgramm beendet. Achtung: RAM wurde nicht freigegeben! TESTKONFLIKT" << std::endl;

    // FEHLER: Hier fehlen 'delete g1;', 'delete g2;', 'delete g3;'
    
    return 0;
}
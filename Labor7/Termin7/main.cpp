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
    // 1. Globaler Test-Status 
    bool testPassed = true; 
 
    std::cout << "--- STARTE AUTOMATISIERTE WAHRHEITSTABELLEN-TESTS ---" << std::endl; 
 
    //=====================================================
    //Tests if all logic gates are behaving as they should
    //=====================================================

    // 2. Beispiel-Testblock für ein AND-Gatter (Stellvertretend für alle Gatter) 
    { 
        // Instanziierung (Nutzen Sie Ihre Smart-Pointer-Architektur von letzter Woche!) 
        auto andGate = std::make_unique<AndGate>("Haupt-AND");  
         
        // Test-Matrix: InputA, InputB, Erwartetes Ergebnis 
        int testCases[4][3] = { 
            {0, 0, 0}, 
            {0, 1, 0}, 
            {1, 0, 0}, 
            {1, 1, 1} 
        }; 
 
        for (int i = 0; i < 4; ++i) { 
            andGate->setInputA(testCases[i][0]); 
            andGate->setInputB(testCases[i][1]); 
            andGate->evaluate(); 
             
            if (andGate->getOutput() != testCases[i][2]) { 
                std::cerr << "❌ TEST FAILED: AND bei Inputs A=" << testCases[i][0]  
                          << " B=" << testCases[i][1]  
                          << " -> Erhalten: " << andGate->getOutput()  
                          << " (Erwartet: " << testCases[i][2] << ")" << std::endl; 
                testPassed = false; 
            } 
        } 
    }
    
    //===============================================
    // [!] HIER WEITERE TESTBLÖCKE FÜR OR, NOT, XOR, NAND ERGÄNZEN (Insgesamt min. 18 Fälle) 
    //===============================================
        
    // Testblock für ein OR-Gatter 
    { 
        // Instanziierung (Nutzen Sie Ihre Smart-Pointer-Architektur von letzter Woche!) 
        auto orGate = std::make_unique<OrGate>("Haupt-OR");  
         
        // Test-Matrix: InputA, InputB, Erwartetes Ergebnis 
        int testCases[4][3] = { 
            {0, 0, 0}, 
            {0, 1, 1}, 
            {1, 0, 1}, 
            {1, 1, 1} 
        }; 
 
        for (int i = 0; i < 4; ++i) { 
            orGate->setInputA(testCases[i][0]); 
            orGate->setInputB(testCases[i][1]); 
            orGate->evaluate(); 
             
            if (orGate->getOutput() != testCases[i][2]) { 
                std::cerr << "❌ TEST FAILED: OR bei Inputs A=" << testCases[i][0]  
                          << " B=" << testCases[i][1]  
                          << " -> Erhalten: " << orGate->getOutput()  
                          << " (Erwartet: " << testCases[i][2] << ")" << std::endl; 
                testPassed = false; 
            } 
        } 
    } 

        // Testblock für ein XOR-Gatter 
    { 
        // Instanziierung (Nutzen Sie Ihre Smart-Pointer-Architektur von letzter Woche!) 
        auto xorGate = std::make_unique<XorGate>("Haupt-XOR");  
         
        // Test-Matrix: InputA, InputB, Erwartetes Ergebnis 
        int testCases[4][3] = { 
            {0, 0, 0}, 
            {0, 1, 1}, 
            {1, 0, 1}, 
            {1, 1, 0} 
        }; 
 
        for (int i = 0; i < 4; ++i) { 
            xorGate->setInputA(testCases[i][0]); 
            xorGate->setInputB(testCases[i][1]); 
            xorGate->evaluate(); 
             
            if (xorGate->getOutput() != testCases[i][2]) { 
                std::cerr << "❌ TEST FAILED: XOR bei Inputs A=" << testCases[i][0]  
                          << " B=" << testCases[i][1]  
                          << " -> Erhalten: " << xorGate->getOutput()  
                          << " (Erwartet: " << testCases[i][2] << ")" << std::endl; 
                testPassed = false; 
            } 
        } 
    } 

            // Testblock für ein NAND-Gatter 
    { 
        // Instanziierung (Nutzen Sie Ihre Smart-Pointer-Architektur von letzter Woche!) 
        auto nandGate = std::make_unique<NandGate>("Haupt-NAND");  
         
        // Test-Matrix: InputA, InputB, Erwartetes Ergebnis 
        int testCases[4][3] = { 
            {0, 0, 1}, 
            {0, 1, 1}, 
            {1, 0, 1}, 
            {1, 1, 0} 
        }; 
 
        for (int i = 0; i < 4; ++i) { 
            nandGate->setInputA(testCases[i][0]); 
            nandGate->setInputB(testCases[i][1]); 
            nandGate->evaluate(); 
             
            if (nandGate->getOutput() != testCases[i][2]) { 
                std::cerr << "❌ TEST FAILED: NAND bei Inputs A=" << testCases[i][0]  
                          << " B=" << testCases[i][1]  
                          << " -> Erhalten: " << nandGate->getOutput()  
                          << " (Erwartet: " << testCases[i][2] << ")" << std::endl; 
                testPassed = false; 
            } 
        } 
    } 

                // Testblock für ein NOT-Gatter 
    { 
        // Instanziierung (Nutzen Sie Ihre Smart-Pointer-Architektur von letzter Woche!) 
        auto notGate = std::make_unique<NotGate>("Haupt-NOT");  
         
        // Test-Matrix: InputA, InputB, Erwartetes Ergebnis 
        int testCases[2][2] = {  
            {0, 1}, // Wahrheitstabelle 
            {1, 0} 
        }; 
 
        for (int i = 0; i < 2; ++i) { 
            notGate->setInputA(testCases[i][0]); 
            //notGate->setInputB(testCases[i][1]); //gibt Fehler aus, da NOT nur 
                                        //einen InputA annimmt
            notGate->evaluate(); 
             
            if (notGate->getOutput() != testCases[i][1]) {  //'1' weil nur 2 Spalten, da wo output ist. Als andere Gatter
                std::cerr << "❌ TEST FAILED: NOT bei Inputs A=" << testCases[i][0]  
                          //<< " B=" << testCases[i][1]  
                          << " -> Erhalten: " << notGate->getOutput()  
                          << " (Erwartet: " << testCases[i][1] << ")" << std::endl; // '1',weil eine Spalte weniger als andere Gatter
                testPassed = false; 
            } 
        } 
    } 
 
    
 
    // 3. Finale Auswertung für die CI-Pipeline 
    if (!testPassed) { 
        std::cerr << "--- 🔴 PIPELINE-ABSTURZ: TESTS FEHLGESCHLAGEN ---" << std::endl; 
        return 1; // Signalisiert GitHub Actions: FEHLER! 
    } 
 
    std::cout << "--- 🟢 ALLER TESTS BESTANDEN (18/18) ---" << std::endl; 
    return 0; // Signalisiert GitHub Actions: ERFOLG! 
} 
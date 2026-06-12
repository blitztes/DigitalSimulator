#include "LogicEngine.h"
#include <iostream>
#include <vector>

// ============================================
// LogicEngine Implementation
// ============================================

LogicEngine::LogicEngine() {
    circuitName = "Unbenannt";
    tickCount = 0;
    currentOutput = 0;
}

void LogicEngine::setCircuitName(std::string name) {
    circuitName = name;
    std::cout << "[Engine] Schaltungsname gesetzt auf: " << circuitName << std::endl;
}

//VERALTET:void LogicEngine::addGate(std::string gateType) {
  //  std::cout << "[Engine] Bauteil hinzugefuegt: " << gateType << std::endl;
//}

/**
 * Fügt eine Komponente zur Schaltung hinzu
 * Dies ist der Schlüssel zu Polymorphismus:
 * Wir speichern einen Component*-Zeiger, wissen aber nicht, was dahinter steckt
 */
void LogicEngine::addComponent(Component* comp) {
    if (comp != nullptr) {
        circuit.push_back(comp);
        std::cout << "[LogicEngine] Komponente hinzugefügt. Gesamt: " << circuit.size() << std::endl;
    }
}

void LogicEngine::doTick() {
    /*tickCount++;
    if ((tickCount / 2) % 2 == 0) {
        currentOutput = 0;
    } else {
        currentOutput = 1;
    }*/
   for(Component* c : circuit){  //Lab4, TeilC. #include <vector>
       c->evaluate();
       //c->printState();
   }
}

int LogicEngine::getOutputState() const {
    return currentOutput;
}
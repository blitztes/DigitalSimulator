#include "LogicEngine.h"
#include <iostream>

LogicEngine::LogicEngine() {
    circuitName = "Unbenannt";
    tickCount = 0;
    currentOutput = 0;
}

void LogicEngine::setCircuitName(std::string name) {
    circuitName = name;
    std::cout << "[Engine] Schaltungsname gesetzt auf: " << circuitName << std::endl;
}

void LogicEngine::addGate(std::string gateType) {
    // In Labor 1 dient dies nur der Demonstration der Schnittstelle
    std::cout << "[Engine] Bauteil hinzugefuegt: " << gateType << std::endl;
}

void LogicEngine::doTick() {
    tickCount++;
    
    // Einfache Dummy-Logik: 
    // Das Signal wechselt alle 2 Taktzyklen (0, 0, 1, 1, 0, 0, ...)  falsch! (0,1,1,0,0,1,1...)
    if ((tickCount / 2) % 2 == 0) {
        currentOutput = 0;
    } else {
        currentOutput = 1;
    }
}

int LogicEngine::getOutputState() const {
    return currentOutput;
}
#include "LogicEngine.h"
#include <iostream>

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

void LogicEngine::addGate(std::string gateType) {
    std::cout << "[Engine] Bauteil hinzugefuegt: " << gateType << std::endl;
}

void LogicEngine::doTick() {
    tickCount++;
    if ((tickCount / 2) % 2 == 0) {
        currentOutput = 0;
    } else {
        currentOutput = 1;
    }
}

int LogicEngine::getOutputState() const {
    return currentOutput;
}
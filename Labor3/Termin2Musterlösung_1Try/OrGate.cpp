#include "OrGate.h"
#include <iostream>

OrGate::OrGate(std::string name) : Component(name) {
    std::cout << "[OrGate] Konstruktor: Initialisiert mit inputA=0, inputB=0" << std::endl;
}

void OrGate::update() {
    output = inA || inB;
}

void OrGate::printState() const {
    std::cout << "OrGate [A=" << (inA ? 1 : 0) 
              << ", B=" << (inB ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}

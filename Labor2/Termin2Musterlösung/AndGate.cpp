#include "AndGate.h"
#include <iostream>

AndGate::AndGate() : inputA(false), inputB(false), output(false) {
    std::cout << "[AndGate] Konstruktor: Initialisiert mit inputA=0, inputB=0" << std::endl;
}

void AndGate::setInputA(int val) {
    if (val == 0) {
        inputA = false;
    } else if (val == 1) {
        inputA = true;
    } else {
        std::cerr << "[AndGate FEHLER] Ungültiger Wert für inputA: " << val 
                  << " (erwartet 0 oder 1)" << std::endl;
    }
}

void AndGate::setInputB(int val) {
    if (val == 0) {
        inputB = false;
    } else if (val == 1) {
        inputB = true;
    } else {
        std::cerr << "[AndGate FEHLER] Ungültiger Wert für inputB: " << val 
                  << " (erwartet 0 oder 1)" << std::endl;
    }
}

void AndGate::update() {
    output = inputA && inputB;
}

bool AndGate::getOutput() const {
    return output;
}

void AndGate::printState() const {
    std::cout << "AndGate [A=" << (inputA ? 1 : 0) 
              << ", B=" << (inputB ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}

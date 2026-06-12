#include "OrGate.h"
#include <iostream>

OrGate::OrGate() : inputA(false), inputB(false), output(false) {
    std::cout << "[OrGate] Konstruktor: Initialisiert mit inputA=0, inputB=0" << std::endl;
}

void OrGate::setInputA(int val) {
    if (val == 0) {
        inputA = false;
    } else if (val == 1) {
        inputA = true;
    } else {
        std::cerr << "[OrGate FEHLER] Ungültiger Wert für inputA: " << val << std::endl;
    }
}

void OrGate::setInputB(int val) {
    if (val == 0) {
        inputB = false;
    } else if (val == 1) {
        inputB = true;
    } else {
        std::cerr << "[OrGate FEHLER] Ungültiger Wert für inputB: " << val << std::endl;
    }
}

void OrGate::update() {
    output = inputA || inputB;
}

bool OrGate::getOutput() const {
    return output;
}

void OrGate::printState() const {
    std::cout << "OrGate [A=" << (inputA ? 1 : 0) 
              << ", B=" << (inputB ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}

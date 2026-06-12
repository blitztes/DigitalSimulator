#include "NandGate.h"
#include <iostream>

NandGate::NandGate() {
    std::cout << "[NandGate] Konstruktor: Kombiniert AndGate + NotGate" << std::endl;
}

void NandGate::setInputA(int val) {
    andGate.setInputA(val);
}

void NandGate::setInputB(int val) {
    andGate.setInputB(val);
}

void NandGate::update() {
    andGate.update();
    notGate.setInput(andGate.getOutput() ? 1 : 0);
    notGate.update();
}

bool NandGate::getOutput() const {
    return notGate.getOutput();
}

void NandGate::printState() const {
    std::cout << "NandGate (AND + NOT)" << std::endl;
    andGate.printState();
    notGate.printState();
}

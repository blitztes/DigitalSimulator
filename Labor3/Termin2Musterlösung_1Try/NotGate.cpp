#include "NotGate.h"
#include <iostream>

NotGate::NotGate(std::string n) : input(false), output(true) {
    std::cout << "[NotGate] Konstruktor: Initialisiert mit input=0" << std::endl;
}

void NotGate::setInput(int val) {
    if (val == 0) {
        input = false;
    } else if (val == 1) {
        input = true;
    } else {
        std::cerr << "[NotGate FEHLER] Ungültiger Wert für input: " << val << std::endl;
    }
}

void NotGate::update() {
    output = !input;
}

bool NotGate::getOutput() const {
    return output;
}

void NotGate::printState() const {
    std::cout << "NotGate [Input=" << (input ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}






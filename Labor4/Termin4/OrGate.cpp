#include "OrGate.h"
#include <iostream>
#include <string>

//Kind
OrGate::OrGate(std::string n) : Component(n){
    std::cout << "[OrGate] Konstruktor: Name an Component Uebergeben" << std::endl;
}

bool OrGate::evaluate() {
    output = inA || inB;
    return output;
}

void OrGate::printState() const {
    std::cout << "OrGate [A=" << (inA ? 1 : 0) 
              << ", B=" << (inB ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}
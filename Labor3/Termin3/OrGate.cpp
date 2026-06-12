#include "OrGate.h"
#include <iostream>
#include <string>

//Kind
OrGate::OrGate(std::string n) : Component(n){
    std::cout << "[OrGate] Konstruktor: Name an Component Uebergeben" << std::endl;
}

void OrGate::update() {
    output = inA && inB;
}

void OrGate::printState() const {
    std::cout << "OrGate [A=" << (inA ? 1 : 0) 
              << ", B=" << (inB ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}
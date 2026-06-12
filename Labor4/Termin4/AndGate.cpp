#include "AndGate.h"
#include <iostream>
#include <string>

//Kind
AndGate::AndGate(std::string n) : Component(n){
    std::cout << "[AndGate] Konstruktor: Name an Component Uebergeben" << std::endl;
}

//void AndGate::update() {
  //  output = inA && inB;
//}

bool AndGate::evaluate(){
    output = inA && inB;
    return output;
}

void AndGate::printState() const {
    std::cout << "AndGate [A=" << (inA ? 1 : 0) 
              << ", B=" << (inB ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}

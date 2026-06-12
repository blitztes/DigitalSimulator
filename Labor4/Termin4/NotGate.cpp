#include "NotGate.h"
#include <iostream>
#include <string>

NotGate::NotGate(std::string n) : Component(n){
    std::cout << "[NotGate] Konstruktor: Initialisiert mit input=0" << std::endl;
}

void NotGate::setInputB(int val){ //Overriding, weil NotGate nur einen
                                  //einen Eingang hat!
    std::cerr << "Fehler: NotGate hat nur keinen Eingang B!" << std::endl;
}

void NotGate::update() {
    output = !inA;
}

void NotGate::printState() const {
    std::cout << "NotGate [Input=" << (inA ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}






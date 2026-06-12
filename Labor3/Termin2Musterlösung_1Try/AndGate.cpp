#include <iostream>
#include <string>
#include "AndGate.h"

//Konstruktor Implementierung: nimmt Name ein und leitet es 
//an Eltern klasse weiter
AndGate::AndGate(std::string name) : Component(name){
    std::cout << "[AndGate] Konstruktor: Initialisiert mit inputA=0, inputB=0" << std::endl;
}

//AND-Logik
void AndGate::update() {
    output = inA && inB;
}

//Hilfsfunktion zum Uebergeben des Outputs
void AndGate::printState() const {
    std::cout << "AndGate [A=" << (inA ? 1 : 0) 
              << ", B=" << (inB ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}

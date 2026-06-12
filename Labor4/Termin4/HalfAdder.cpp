#include "HalfAdder.h"
#include <iostream>

// Konstruktor initialisiert die internen Gatter mit passenden Namen
HalfAdder::HalfAdder(std::string n) 
    : Component(n), internalAnd(n + "_internalAND"), internalXor(n + "_internalXOR"), carry(false) {
    std::cout << "[HalfAdder] Komplexes Bauteil erstellt: " << name << std::endl;
}

bool HalfAdder::evaluate() {
    // 1. Eingänge an die internen Gatter weiterleiten
    internalAnd.setInputA(inA ? 1 : 0);
    internalAnd.setInputB(inB ? 1 : 0);
    
    internalXor.setInputA(inA ? 1 : 0);
    internalXor.setInputB(inB ? 1 : 0);

    // 2. Interne Gatter berechnen lassen
    carry = internalAnd.evaluate();   // AND liefert den Übertrag (Carry)
    output = internalXor.evaluate();  // XOR liefert die Summe (Output)

    return output; // Gibt die Summe zurück
}

bool HalfAdder::getCarry() const {
    return carry;
}

void HalfAdder::printState() const {
    std::cout << "HalfAdder [" << name << "] A=" << inA << ", B=" << inB 
              << " => Summe(Output)=" << output << ", Carry=" << carry << std::endl;
}
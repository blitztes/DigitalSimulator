#include "XnorGate.h"
#include <iostream>

/**
 * Konstruktor des XnorGate
 * Der Name wird an die Basisklasse Component weitergegeben
 */
XnorGate::XnorGate(std::string n) : Component(n) {
    std::cout << "[" << name << "] XNOR-Gatter aktiviert" << std::endl;
}

/**
 * Berechnet die XNOR-Logik:
 * output = NOT(XOR(inA, inB))
 *        = (inA && inB) || (!inA && !inB)
 *
 * Wahrheitstabelle:
 * A | B | XNOR
 * 0 | 0 | 1
 * 0 | 1 | 0
 * 1 | 0 | 0
 * 1 | 1 | 1
 */
bool XnorGate::evaluate() {
    output = (inA && inB) || (!inA && !inB);
    return output;
}

/**
 * Gibt den Zustand dieses XNOR-Gatters aus
 */
void XnorGate::printState() const {
    std::cout << "XnorGate [" << name << ": A=" << (inA ? 1 : 0)
              << ", B=" << (inB ? 1 : 0)
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}

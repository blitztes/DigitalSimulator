#include "XorGate.h"
#include <iostream>

/**
 * Konstruktor des XorGate
 * Der m_Name wird an die Basisklasse Gate weitergegeben
 */
XorGate::XorGate(std::string n) : Gate(n) {
    m_inputs.resize(2);  //Das XorGatter hat exact 2 EingangPins
    std::cout << "[" << m_name << "] XOR-Gatter aktiviert" << std::endl;
}

/**
 * Berechnet die XOR-Logik:
 * m_output = m_inA XOR m_inB = (m_inA && !m_inB) || (!m_inA && m_inB)
 * 
 * Bedeutung: Ausgabe ist 1, wenn die Eingänge unterschiedlich sind
 * A | B | XOR
 * ---------
 * 0 | 0 | 0
 * 0 | 1 | 1
 * 1 | 0 | 1
 * 1 | 1 | 0
 */
/*
bool XorGate::evaluate() {
    m_output = (m_inA && !m_inB) || (!m_inA && m_inB);
    return m_output;
}*/

//Zieht von vorherigen switch:lazy evaluate
bool XorGate::evaluate() { 
// Unverbundene Pins prüfen (früher "Floating Pin" genannt) 
    if (m_inputs[0] != nullptr && m_inputs[1] != nullptr) { 
        bool valA = m_inputs[0]->getOutput(); 
        bool valB = m_inputs[1]->getOutput(); 
        return m_output = valA != valB; 
    } else { 
        std::cerr << "FEHLER: AND-Gatter hat unverbundene Pins!" << std::endl; 
        return m_output = false; // Sicherer Fallback 
    } 
}

/**
 * Gibt den Zustand dieses XOR-Gatters aus
 */

/*
void XorGate::printState() const {
    std::cout << "XorGate [" << m_name << ": A=" << (m_inA ? 1 : 0) 
              << ", B=" << (m_inB ? 1 : 0) 
              << "] => m_Output=" << (m_output ? 1 : 0) << std::endl;
}*/

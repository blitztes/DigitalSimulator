#include "XnorGate.h"
#include <iostream>

/**
 * Konstruktor des XnorGate
 * Der m_name wird an die Basisklasse Gate weitergegeben
 */
XnorGate::XnorGate(std::string n) : Gate(n) {
    m_inputs.resize(2);  //Das XnorGatter hat exact 2 EingangPins
    std::cout << "[" << m_name << "] XNOR-Gatter aktiviert" << std::endl;
}

/**
 * Berechnet die XNOR-Logik:
 * m_output = NOT(XOR(m_inA, m_inB))
 *        = (m_inA && m_inB) || (!m_inA && !m_inB)
 *
 * Wahrheitstabelle:
 * A | B | XNOR
 * 0 | 0 | 1
 * 0 | 1 | 0
 * 1 | 0 | 0
 * 1 | 1 | 1
 */
/*
bool XnorGate::evaluate() {
    m_output = (m_inA && m_inB) || (!m_inA && !m_inB);
    return m_output;
}*/

//Zieht von vorherigen switch:lazy evaluate
bool XnorGate::evaluate() { 
// Unverbundene Pins prüfen (früher "Floating Pin" genannt) 
    if (m_inputs[0] != nullptr && m_inputs[1] != nullptr) { 
        bool valA = m_inputs[0]->getOutput(); 
        bool valB = m_inputs[1]->getOutput(); 
        return m_output = !(valA != valB); 
    } else { 
        std::cerr << "FEHLER: AND-Gatter hat unverbundene Pins!" << std::endl; 
        return m_output = false; // Sicherer Fallback 
    } 
}

/**
 * Gibt den Zustand dieses XNOR-Gatters aus
 */
/*
void XnorGate::printState() const {
    std::cout << "XnorGate [" << m_name << ": A=" << (m_inA ? 1 : 0)
              << ", B=" << (m_inB ? 1 : 0)
              << "] => m_Output=" << (m_output ? 1 : 0) << std::endl;
}*/

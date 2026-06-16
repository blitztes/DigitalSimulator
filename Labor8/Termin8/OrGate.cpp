#include "OrGate.h"
#include <iostream>

/**
 * Konstruktor des OrGate
 * Der m_name wird an die Basisklasse Gate weitergegeben
 */
OrGate::OrGate(std::string n) : Gate(n) {
    m_inputs.resize(2);  //Das OrGatter hat exact 2 EingangPins
    std::cout << "[" << m_name << "] OR-Gatter aktiviert" << std::endl;
}

/**
 * Berechnet die OR-Logik:
 * m_output = m_inA OR m_inB (mindestens einer muss true sein)
 * 
 * Die Methode speichert das Ergebnis und gibt es zurück.
 */
/*
 bool OrGate::evaluate() {
    m_output = m_inA || m_inB;
    return m_output;
}*/

//Zieht von vorherigen switch:lazy evaluate
bool OrGate::evaluate() { 
// Unverbundene Pins prüfen (früher "Floating Pin" genannt) 
    if (m_inputs[0] != nullptr && m_inputs[1] != nullptr) { 
        bool valA = m_inputs[0]->getOutput(); 
        bool valB = m_inputs[1]->getOutput(); 
        return m_output = valA || valB; 
    } else { 
        std::cerr << "FEHLER: AND-Gatter hat unverbundene Pins!" << std::endl; 
        return m_output = false; // Sicherer Fallback 
    } 
}

/**
 * Gibt den Zustand dieses OR-Gatters aus
 */

/* 
void OrGate::printState() const {
    std::cout << "OrGate [" << m_name << ": A=" << (m_inA ? 1 : 0) 
              << ", B=" << (m_inB ? 1 : 0) 
              << "] => m_output=" << (m_output ? 1 : 0) << std::endl;
}*/

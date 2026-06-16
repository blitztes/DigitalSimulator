#include "AndGate.h"
#include <iostream>

/**
 * Konstruktor des AndGate
 * Der m_Name wird an die Basisklasse Gate weitergegeben
 */
AndGate::AndGate(std::string n) : Gate(n) {
    m_inputs.resize(2);  //Das AndGatter hat exact 2 EingangPins
    std::cout << "[" << m_name << "] AND-Gatter aktiviert" << std::endl;
}

/**
 * Berechnet die AND-Logik:
 * m_output = m_inA AND m_inB (beide müssen true sein)
 * 
 * Die Methode speichert das Ergebnis und gibt es zurück.
 */

 //Zieht von vorherigen switch:lazy evaluate
bool AndGate::evaluate() { 
// Unverbundene Pins prüfen (früher "Floating Pin" genannt) 
    if (m_inputs[0] != nullptr && m_inputs[1] != nullptr) { 
        bool valA = m_inputs[0]->getOutput(); 
        bool valB = m_inputs[1]->getOutput(); 
        return m_output = valA && valB; 
    } else { 
        std::cerr << "FEHLER: AND-Gatter hat unverbundene Pins!" << std::endl; 
        return m_output = false; // Sicherer Fallback 
    } 
}

/**
 * Gibt den Zustand dieses AND-Gatters aus
 */

/*
void AndGate::printState() const {
    std::cout << "AndGate [" << m_name << ": A=" << (m_inA ? 1 : 0) 
              << ", B=" << (m_inB ? 1 : 0) 
              << "] => m_Output=" << (m_output ? 1 : 0) << std::endl;
}*/

#include "NandGate.h"
#include <iostream>

/**
 * Konstruktor des NandGate
 * Erstellt interne AndGate- und NotGate-Instanzen mit aussagekräftigen Namen
 * 
 * Wichtig: Wir rufen auch den Konstruktor der Basisklasse auf
 */
NandGate::NandGate(std::string n) 
    : Gate(n), andGate(n + "-AND"), notGate(n + "-NOT") {
    m_inputs.resize(2);  //Das NandGatter hat exact 2 EingangPins
    std::cout << "[" << m_name << "] NAND-Gatter aktiviert (Komposition: AND + NOT)" << std::endl;
}

/**
 * Setzt Eingang A - weitergeleitet an das interne AND-Gatter
 * Überschreibt die Methode der Basisklasse
 */
/*
void NandGate::setInputA(int val) {
    inA = (val != 0);  // Speichere auch im Basisklassen-Attribut
    andGate.setInputA(val);
}*/

/**
 * Setzt Eingang B - weitergeleitet an das interne AND-Gatter
 * Überschreibt die Methode der Basisklasse
 */
/*
void NandGate::setInputB(int val) {
    inB = (val != 0);  // Speichere auch im Basisklassen-Attribut
    andGate.setInputB(val);
}*/

/**
 * evaluate(): Der polymorphe Kern
 * 
 * Berechnet NAND = NOT(AND):
 * 1. AND-Gatter mit beiden Eingängen berechnen (evaluate)
 * 2. Ergebnis des AND an das NOT-Gatter weitergeben
 * 3. NOT-Gatter evaluieren
 */
/*
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
}*/

//Zieht von vorherigen switch:lazy evaluate
bool NandGate::evaluate() { 
// Unverbundene Pins prüfen (früher "Floating Pin" genannt) 
    if (m_inputs[0] != nullptr && m_inputs[1] != nullptr) { 
        bool valA = m_inputs[0]->getOutput(); 
        bool valB = m_inputs[1]->getOutput(); 
        return m_output = !(valA && valB); 
    } else { 
        std::cerr << "FEHLER: AND-Gatter hat unverbundene Pins!" << std::endl; 
        return m_output = false; // Sicherer Fallback 
    } 
}

/**
 * printState(): Gibt den kompletten Zustand des NAND-Gatters aus
 */
/* 
void NandGate::printState() const {
    std::cout << "NandGate [" << name << ": A=" << (inA ? 1 : 0) 
              << ", B=" << (inB ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}*/

#include "NotGate.h"
#include <iostream>

/**
 * Konstruktor des NotGate
 * Der m_name wird an die Basisklasse Gate weitergegeben
 */
NotGate::NotGate(std::string n) : Gate(n) {
    m_inputs.resize(1);  //Das NandGatter hat exact 1 EingangPin
    std::cout << "[" << m_name << "] NOT-Gatter aktiviert" << std::endl;
}

/**
 * Setzt Eingang B - aber NOT hat nur einen Eingang!
 * Diese Überschreibung (Override) gibt eine Warnung aus
 */


//void NotGate::setInputB(int /* val */) { //absichtlich kein parameter, damit wert emfangen wird, aber nicht in ein attribut geschrieben!
  //  std::cout << "[" << m_name << " WARNUNG] NOT-Gatter hat keinen Eingang B!" << std::endl;
   // std::cout << "           Nutzen Sie setInputA() für den einzigen Eingang." << std::endl;
//}


/**
 * Berechnet die NOT-Logik:
 * m_output = NOT m_inA
 * 
 * Die Methode speichert das Ergebnis und gibt es zurück.
 */
/*
bool NotGate::evaluate() {
    m_output = !m_inA;
    return m_output;
}*/

//Zieht von vorherigen switch:lazy evaluate
bool NotGate::evaluate() { 
// Unverbundene Pins prüfen (früher "Floating Pin" genannt) 
    if (m_inputs[0] != nullptr) { 
        bool valA = m_inputs[0]->getOutput(); 
        return m_output = !valA; 
    } else { 
        std::cerr << "FEHLER: AND-Gatter hat unverbundene Pins!" << std::endl; 
        return m_output = false; // Sicherer Fallback 
    } 
}

/**
 * Gibt den Zustand dieses NOT-Gatters aus
 */
/*
void NotGate::printState() const {
    std::cout << "NotGate [" << m_name << ": Input=" << (m_inA ? 1 : 0) 
              << "] => m_Output=" << (m_output ? 1 : 0) << std::endl;
}*/






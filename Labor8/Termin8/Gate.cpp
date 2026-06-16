#include "Gate.h"

/**
 * Konstruktor der Gate-Klasse
 * Initialisiert alle Attribute sicher
 */
Gate::Gate(std::string n) 
    : m_name(n), m_output(false) {
    std::cout << "[" << m_name << "] Komponente erstellt" << std::endl;
}

/**
 * Setter für Eingang A
 * Prüft, dass nur gültige Werte (0 oder 1) gesetzt werden
 */
/*
void Gate::setInputA(int val) {
    if (val == 0) {
        m_inA = false;
    } else if (val == 1) {
        m_inA = true;
    } else {
        std::cerr << "[" << m_name << " FEHLER] Ungültiger Wert für Eingang A: " << val 
                  << " (erwartet 0 oder 1)" << std::endl;
    }
}*/

/**
 * Setter für Eingang B
 * Prüft, dass nur gültige Werte (0 oder 1) gesetzt werden
 * Kann in abgeleiteten Klassen (z.B. NotGate) überschrieben werden
 */

/*
void Gate::setInputB(int val) {
    if (val == 0) {
        m_inB = false;
    } else if (val == 1) {
        m_inB = true;
    } else {
        std::cerr << "[" << m_name << " FEHLER] Ungültiger Wert für Eingang B: " << val 
                  << " (erwartet 0 oder 1)" << std::endl;
    }
}*/

void Gate::connectInput(int index, std::shared_ptr<Gate> source) { 
// Prüfen, ob der Pin physisch am Gatter existiert 
    if (index >= 0 && index < m_inputs.size()) { 
    m_inputs[index] = source; 
    } else { 
    std::cerr << "FEHLER: Pin " << index << " existiert nicht!" << 
    std::endl; 
    } 
} 

/**
 * Getter für den Ausgangswert
 */
bool Gate::getOutput() const {
    return m_output;
}

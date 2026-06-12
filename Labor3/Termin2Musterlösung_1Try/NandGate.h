#pragma once

#include "AndGate.h"
#include "NotGate.h"

/**
 * NAND-Gatter durch Komposition
 * Kombiniert ein AndGate mit einem NotGate
 */
class NandGate {
private:
    AndGate andGate;
    NotGate notGate;

public:
    // Konstruktor
    NandGate(std::string n);

    // Setter für Eingang A
    void setInputA(int val);

    // Setter für Eingang B
    void setInputB(int val);

    // Berechnet NAND = NOT(AND)
    void update();

    // Gibt das Ausgangssignal zurück
    bool getOutput() const;

    // Hilfsfunktion
    void printState() const;
};

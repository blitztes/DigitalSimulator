#pragma once

#include "Gate.h"

/**
 * XNOR-Gatter Klasse (erbt von Gate)
 * Ausgabe ist 1, wenn die Eingänge gleich sind
 *
 * Logik: XNOR(A, B) = NOT(XOR(A, B))
 *        = (A AND B) OR (NOT A AND NOT B)
 */
class XnorGate : public Gate {
public:
    /**
     * Konstruktor: Nimmt einen Namen entgegen
     * @param n Der Name dieses XNOR-Gatters
     */
    XnorGate(std::string n);

    /**
     * Berechnet die XNOR-Logik
     * @return true wenn die Eingänge gleich sind, sonst false
     */
    bool evaluate() override;

    /**
     * Gibt den aktuellen Zustand aus
     */
    //void printState() const override;
};

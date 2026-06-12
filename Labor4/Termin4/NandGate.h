#pragma once
#include "Component.h"
#include "AndGate.h"
#include "NotGate.h"

/**
 * NAND-Gatter durch Komposition
 * Kombiniert ein AndGate mit einem NotGate
 */

#pragma once
#include "Component.h"

class NandGate : public Component {
public:
    // Konstruktor reicht Namen an Component weiter
    NandGate(std::string n);

    // Überschreibt die reine virtuelle Methode aus Component
    bool evaluate() override;

    // Zustand auf der Konsole ausgeben
    void printState() const;
};
/*class NandGate { //VERALTET
private:
    AndGate andGate;
    NotGate notGate;

public:
    // Konstruktor
    NandGate();

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
};*/
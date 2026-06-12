#pragma once
#include "Component.h"
/**
 * AND-Gatter Klasse
 * Ausgabe ist 1, nur wenn beide Eingänge 1 sind
 */
class OrGate : public Component{

public:
    // Konstruktor: Nimmt Name an, und schickt sofort an Basis klasse 
    // in Initialisierungsliste. Andere Attribute auf false initialisiert
    OrGate(std::string n); 

    // Berechnet das Ausgangssignal basierend auf aktuellen Eingängen
    //void update();  //wird zu evaluate fuer pure virtual function. Gezwungene pruefung!

    bool evaluate() override;

    // Hilfsfunktion zur Ausgabe des Zustands
    void printState() const;
};
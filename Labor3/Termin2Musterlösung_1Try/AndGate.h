#pragma once

#include <string>
#include "Component.h"
/**
 * AND-Gatter Klasse
 * Ausgabe ist 1, nur wenn beide Eingänge 1 sind
 */
class AndGate : public Component{  //Kind: erbt von Klasse Component
//Attribute wie inA, out, sind in Component und werden geerbt!
public:
    // Konstruktor: AndGate braucht eigenen Konstruktor trotzdem! 
    // Nimmt Name ein und leitet es weiter an Konstruktor
    AndGate(std::string n);  //Nur Deklaration! Vererbung ist in .cpp
                             //wo auch Component steht!

    // Berechnet das Ausgangssignal basierend auf aktuellen Eingängen
    void update();

    // Hilfsfunktion zur Ausgabe des Zustands
    void printState() const;
};

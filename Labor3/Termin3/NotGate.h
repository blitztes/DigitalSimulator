#pragma once
#include "Component.h"
#include <string>

/**
 * NOT-Gatter Klasse
 * Ausgabe ist invertiert (NOT hat nur einen Eingang!)
 */
class NotGate : public Component{
public:
    // Konstruktor
    NotGate(std::string n);

    //Ueberschreiben von inB, da Not-Gate nur einen Eingang hat
    void setInputB(int val);

    // Berechnet das invertierte Ausgangssignal
    void update();

    // Hilfsfunktion
    void printState() const;
};

#pragma once
#include "Component.h"
/**
 * OR-Gatter Klasse
 * Ausgabe ist 1, wenn mindestens ein Eingang 1 ist
 */
class OrGate : public Component{ //Vererbung

public:
    // Konstruktor + Weiterleitung von name an Component:
    OrGate(std::string n);

    // Berechnet das Ausgangssignal
    void update();

    // Hilfsfunktion zur Ausgabe des Zustands
    void printState() const;
};

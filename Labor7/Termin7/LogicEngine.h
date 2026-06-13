#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Component.h"

/**
 * Die LogicEngine ist der Kern unseres Simulators.
 * Sie verwaltet eine Liste von Komponenten polymorphisch.
 * 
 * Das Schlüsselkonzept: Wir speichern Zeiger auf die Basisklasse Component,
 * aber die Engine "weiß" nicht, welcher konkrete Typ verborgen ist.
 * Durch polymorphe Aufrufe werden die richtigen Gatter-Logiken ausgeführt!
 */
class LogicEngine {
private:
    std::string circuitName;
    int tickCount;
    std::vector<std::unique_ptr<Component>> circuit;  // Polymorphe Liste von Komponenten
                            //Lab5: smart unique pointer auf type 'Component'
public:
    // Konstruktor: Initialisiert die Engine
    LogicEngine();

    // Destruktor: Räumt die Komponenten auf
    //Wegen unique_ptr ueberfluessig!
    //~LogicEngine();

    // Setzt den Namen der Schaltung
    void setCircuitName(std::string name);

    // Fügt eine Komponente polymorphisch zur Schaltung hinzu
    void addComponent(std::unique_ptr<Component> c); //Attribute: unique pointer auf Component

    // Berechnet einen Taktschritt: Evaluiert alle Komponenten
    void doTick();

    // Gibt die Anzahl der Komponenten zurück
    int getComponentCount() const;
};
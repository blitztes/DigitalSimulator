#pragma once
#include "Component.h"
#include <string>
#include <vector>

/**
 * Die LogicEngine ist der Kern unseres Simulators.
 * Sie verhält sich wie eine Blackbox: Wir nutzen die öffentlichen (public)
 * Methoden, um die Schaltung zu steuern, ohne wissen zu müssen,
 * wie die Signale intern berechnet werden.
 */
class LogicEngine {
private:
    std::string circuitName;
    int tickCount;
    int currentOutput;
    std::vector<Component*> circuit; //Lab4, TeilC

public:
    // Konstruktor: Initialisiert die Engine
    LogicEngine();

    // Setzt den Namen der Schaltung (Eigenschaft/Zustand)
    void setCircuitName(std::string name);

    // VERALTET:Fügt ein Gatter hinzu (hier noch vereinfacht als String-Übergabe)
    //void addGate(std::string gateType);

    /**
 * Fügt eine Komponente zur Schaltung hinzu
 * Dies ist der Schlüssel zu Polymorphismus:
 * Wir speichern einen Component*-Zeiger, wissen aber nicht, was dahinter steckt
 */
    // Fügt eine Komponente polymorphisch zur Schaltung hinzu
    void addComponent(Component *comp);

    // Berechnet einen einzelnen Taktschritt (Verhalten)
    void doTick();

    // Gibt den aktuellen Zustand des Ausgangs zurück (0 oder 1)
    int getOutputState() const;
};
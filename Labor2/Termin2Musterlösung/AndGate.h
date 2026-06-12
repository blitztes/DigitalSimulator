#pragma once

/**
 * AND-Gatter Klasse
 * Ausgabe ist 1, nur wenn beide Eingänge 1 sind
 */
class AndGate {
private:
    bool inputA;
    bool inputB;
    bool output;

public:
    // Konstruktor: Initialisiert beide Eingänge auf false (0)
    AndGate();

    // Setter für Eingang A (prüft auf gültige Werte 0 oder 1)
    void setInputA(int val);

    // Setter für Eingang B (prüft auf gültige Werte 0 oder 1)
    void setInputB(int val);

    // Berechnet das Ausgangssignal basierend auf aktuellen Eingängen
    void update();

    // Gibt das Ausgangssignal zurück
    bool getOutput() const;

    // Hilfsfunktion zur Ausgabe des Zustands
    void printState() const;
};

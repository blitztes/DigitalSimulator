#pragma once

/**
 * OR-Gatter Klasse
 * Ausgabe ist 1, wenn mindestens ein Eingang 1 ist
 */
class OrGate {
private:
    bool inputA;
    bool inputB;
    bool output;

public:
    // Konstruktor: Initialisiert beide Eingänge auf false (0)
    OrGate();

    // Setter für Eingang A
    void setInputA(int val);

    // Setter für Eingang B
    void setInputB(int val);

    // Berechnet das Ausgangssignal
    void update();

    // Gibt das Ausgangssignal zurück
    bool getOutput() const;

    // Hilfsfunktion zur Ausgabe des Zustands
    void printState() const;
};

#pragma once

/**
 * NOT-Gatter Klasse
 * Ausgabe ist invertiert (NOT hat nur einen Eingang!)
 */
class NotGate {
private:
    bool input;
    bool output;

public:
    // Konstruktor
    NotGate();

    // Setter für den einzigen Eingang
    void setInput(int val);

    // Berechnet das invertierte Ausgangssignal
    void update();

    // Gibt das Ausgangssignal zurück
    bool getOutput() const;

    // Hilfsfunktion
    void printState() const;
};

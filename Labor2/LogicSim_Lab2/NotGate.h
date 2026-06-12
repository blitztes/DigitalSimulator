#pragma once

class NotGate{
private:
    bool inputA;
    bool out;
public:
    NotGate() : inputA(0) {}; // Konstruktor mit Initialisierungsliste

    void setInputA(int val);    //defines inputA
    void update();              //OrGate-Logik
    bool getOutput() const;     //getter-Methode fuer Ergebnis
};
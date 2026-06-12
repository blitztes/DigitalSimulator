#pragma once

class OrGate{
private:
    bool inputA;
    bool inputB;
    bool out;
public:
    //Konstruktor:
    OrGate() : inputA(0), inputB(0) {}; //Initialisierungsliste

    void setInputA(int val);    //1. Input
    void setInputB(int val);    //2. Input
    void update();              //OrGate-Logik
    bool getOutput() const;     //Getter-Methode:Ausgabe
};
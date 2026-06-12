#pragma once
#include <iostream>
#include "Component.h"
#include "AndGate.h"
#include "XorGate.h"

class HalfAdder: public Component{
private:
    //Komposition: interne Bauteile als Objekte
    AndGate internalAnd;
    XorGate internalXor;

    //Zusaetzliche Ausgang, da Component nur einen Ausgang besitzt
    bool carry;

public:
    HalfAdder(std::string n); //warum string class nicht notwendig?

    bool evaluate() override; //Halbaddierer Logik

    bool getCarry() const; //Uebertrag-Zustand zurueckgeben

    void printState() const; //printState Methode duer zwei Ausgaenge
};
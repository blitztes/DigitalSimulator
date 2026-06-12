#pragma once
#include "AndGate.h"
#include "NotGate.h"
//Nand: besteht intern aus AND Gate, dann durch Not negiert

class NandGate{
private:
    bool inputA;
    bool inputB;
    bool out;

    //Musterloesung:
    
    AndGate andGate; // Eingaenge von AndGate.h
    NotGate notGate; // Eingang von NotGate.h
    

public:
    NandGate() : inputA(0) {};  //Konstruktor

    void setInputA(int val);  //defines 1. input
    void setInputB(int val);  //defines 2. input
    void update();            //Nand-logic    
    bool getOutput() const;   //outputs result

    // Hilfsfunktion zur Ausgabe 
    //void printState() const;
};
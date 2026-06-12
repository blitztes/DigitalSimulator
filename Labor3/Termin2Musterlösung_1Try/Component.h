#pragma once

#include <iostream>
#include <string>

class Component{
protected:
    std::string name;
    bool inA;
    bool inB;
    bool output;
public:

    Component(std::string n); // Konstruktor mit Name vom Gatter

    void setInputA(int val);  //Setter-Methode fuer InputA mit 1 bzw. 0 Pruefung
    void setInputB(int val);  //Setter-Methode InputB
    bool getOutput() const; //Getter-Methode output
};
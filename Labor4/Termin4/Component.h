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
    Component(std::string n);

    void setInputA(int val); //setter methode
    void setInputB(int val);

    //Polymorphie: Lab4 TeilA: pure virtuel function
    virtual bool evaluate() = 0;

    //Lab4, TeilA: virtuelle Destruktor
    virtual ~Component(){};

    bool getOutput() const; // getter methode
};
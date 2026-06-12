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
    bool getOutput() const;//getter methode
};
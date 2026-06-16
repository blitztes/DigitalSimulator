#pragma once
#include <iostream>
#include "Gate.h"

class Switch : public Gate {
public:

    //Konstruktor:
    Switch(std::string n);

    void setState(bool state);  //ist das der eingang???

    bool evaluate() override;

    //void printState() const override;
};
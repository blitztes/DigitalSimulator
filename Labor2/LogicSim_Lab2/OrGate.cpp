#include <iostream>
#include "OrGate.h"

void OrGate::setInputA(int val) //inputA
{
    if((val == 0) || (val == 1)){
        inputA = val;
    }
}

void OrGate::setInputB(int val) //inputB
{
    if((val == 0) || (val == 1)){
        inputB = val;
    }
}

void OrGate::update()  //OrGate-Logik
{
    out = inputA || inputB;
}

bool OrGate::getOutput() const{  //GetterMethode
    return out;
}

#include <iostream>
#include "NotGate.h"

//input A
void NotGate::setInputA(int val){
    if((val == 0) || (val == 1)){
        inputA = val;
    }
}

//Not-logik
void NotGate::update(){
    out = ~inputA;          //Negation der Eingang wegen NOT
}
//getter methode:
bool NotGate::getOutput() const{
    return out;
}
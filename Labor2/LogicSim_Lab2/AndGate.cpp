#include <iostream>
#include "AndGate.h"

//inputA
void AndGate::setInputA(int val){
    if((val == 0) || (val == 1)){
        inputA = val;
    }
}

//inputB
void AndGate::setInputB(int val){
    if((val == 0) || (val == 1)){
        inputB = val;
    }
}
//AND-logik
void AndGate::update(){
    out = inputA && inputB;
}
//getter methode:
bool AndGate::getOutput() const{
    return out;
}


    /*    void setInputA(int val){
            if((val == 0) || (val == 1)){
                inputA = val;
            }
        }
        void setInputB(int val){
            if((val == 0) || (val == 1)){
                inputA = val;
            }
        }
        void update(){
            out = inputA && inputB;
        }
        bool getOutput() const{
            return out;
    }*/
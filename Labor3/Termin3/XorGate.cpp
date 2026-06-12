#include <iostream>
#include "XorGate.h"
#include <string>

XorGate::XorGate(std::string n) : Component(n){ //Konstruktor: name annehmen und 
                                                //an Component weitergeben
}

void XorGate::update(){
    if(((inA == 1) && (inB == 0)) || ((inA == 0) && (inB == 1))){
        output = 1;
    }
    else{
        output = 0;
    }
}

void XorGate::printState() const{
    std::cout << "XorGate [A=" << (inA ? 1 : 0) 
              << ", B=" << (inB ? 1 : 0) 
              << "] => Output=" << (output ? 1 : 0) << std::endl;
}
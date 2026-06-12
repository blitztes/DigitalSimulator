#include <iostream>
#
#include "Component.h"

//Konstrukor mit Initialisierungsliste
Component::Component(std::string n) : name(n), inA(false), inB(false), output(false) {

};

void Component::setInputA(int val){
    if(val == 0){
        inA = false;
    }
    else if(val == 1){
        inA = true;
    }
    else{
        std::cerr << "Ungueltiger Wert fuer input: " << val << std::endl;    
    }
}

void Component::setInputB(int val){
    if(val == 0){
        inB = false;
    }
    else if(val == 1){
        inB = true;
    }
    else{
        std::cerr << "Ungueltiger Wert fuer input: " << val << std::endl;    
    }
}

bool Component::getOutput() const{
    return output;
}


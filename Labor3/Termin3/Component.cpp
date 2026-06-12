#include <iostream>
#include "Component.h"

//Eltern
Component::Component(std::string n) : name(n), inA(false), inB(false), output(false){

} 

//setter 1
void Component::setInputA(int val){
    if (val == 0) {
        inA = false;
    } else if (val == 1) {
        inA = true;
    } else {
        std::cerr << "[AndGate FEHLER] Ungültiger Wert für inputA: " << val 
                  << " (erwartet 0 oder 1)" << std::endl;
    }
}

//setter 2
void Component::setInputB(int val){
    if (val == 0) {
        inB = false;
    } else if (val == 1) {
        inB = true;
    } else {
        std::cerr << "[AndGate FEHLER] Ungültiger Wert für inputA: " << val 
                  << " (erwartet 0 oder 1)" << std::endl;
    }
}

//getter
bool Component::getOutput() const {
    return output;
}
#include "Switch.h"
#include <iostream>

//Konstruktor:
Switch::Switch(std::string n) : Gate(n){
    m_inputs.resize(0); //Switch hat keinen eingaengen
    std::cout << "[" << m_name << "] Switch" << std::endl;
}

void Switch::setState(bool state){
    m_output = state;
}


bool Switch::evaluate(){
    return m_output;
}

/*
void XnorGate::printState() const {
    std::cout << "XnorGate [" << m_name << ": A=" << (m_inA ? 1 : 0)
              << ", B=" << (m_inB ? 1 : 0)
              << "] => m_Output=" << (m_output ? 1 : 0) << std::endl;
}*/

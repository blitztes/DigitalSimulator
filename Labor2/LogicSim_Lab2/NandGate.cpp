#include <iostream>
#include "NandGate.h"  //drin sind AND und NOT included

//Konstruktor: kombiniert AND und NOT Gate

NandGate::NandGate(){
    std::cout << "Kombiniert AND und NOT Gate" << std::endl;
}


void NandGate::setInputA(int val){  //inputA

    /*if((val == 0) || (val == 1)){
        inputA = val;
    }
    else{ // Fehler
        std::cerr << "Ungueltiger Wert fuer Input: " << val << std::endl;
    }
    */

    //Musterloesung:
    andGate.setInputA(val);
}

void NandGate::setInputB(int val){  //inputB
    if((val == 0) || (val == 1)){
        inputB = val;
    }
    //Musterloesung:
    andGate.setInputB(val);
}

void NandGate::update(){
    //out = inputA && inputB;  //AndGate-Logik
    //out = ~out;  //Not-Gate-Logik
    
    //Musterloesung:
    andGate.update();
    notGate.setInputA(andGate.getOutput() ? 1 : 0);  //wenn And ausgang "1" dann 1 fuer 
                                                    // notgate bestaetigen und return und anders rum. 
                                                    // Das ist nicht als logik fuer notgate gedacht!
    notGate.update();
}

bool NandGate::getOutput() const{  //getter Methode fuer ergebnis
    return notGate.getOutput();
}


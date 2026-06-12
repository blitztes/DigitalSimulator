#pragma once

class AndGate
{
private:
    bool inputA;
    bool inputB;
    bool out;
public:
    AndGate(){  //Konstruktor fuer sichere Initialisierung der inputs
        inputA = false;
        inputB = false;
    }
    //AndGate() : inputA(), inputB(0){}; // Initialisierungsliste 
                                //noch effizienter als
                                //Zuweisung 

    void setInputA(int val);  //defines 1. input
    void setInputB(int val);  //defines 2. input
    void update();            //AND-logic    
    bool getOutput() const;   //outputs result

};


    // Implementierung:

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
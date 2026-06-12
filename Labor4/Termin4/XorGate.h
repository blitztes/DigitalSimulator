#include <iostream>
#include <string>
#include "Component.h"

#pragma once
#include "Component.h"

class XorGate : public Component {
public:
    XorGate(std::string n);

    bool evaluate() override;
    void printState() const;
};

/*
class XorGate : public Component{

public:
    XorGate(std::string n);  // Konstruktor, der Name des Gatters annimmt

    void update(); //XorGate Logik

    void printState() const;  //Hilfsfunktion zum Ausdrucken
};*/
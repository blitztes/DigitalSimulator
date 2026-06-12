// main.cpp  
// Bibliothek für Input/Output-Streams 
#include <iostream>  
#include "LogicEngine.h"
#include <vector>


void printHighCount(const std::vector<int>& logbuch){//vector als parameter um 1sen eines vectors aufzuzaehlen. 
                                                     //"&" referenz, damit wird vector nur 
                                                     //gelesen und keine kopie erstelllt (unnoetig)
                                                     //schneller
    int counter = 0;
    for(int signal : logbuch){
        if(signal == 1){
            counter++;
        }
    }
    std::cout << "Anzahl HIGH Signale: " << counter << std::endl;

}

int main() { 

    // 1. Objekt instanziieren (Die Blackbox wird im RAM erschaffen)
    LogicEngine meinSimulator;

    //Oeffentliche Funktionen des Objekts
    meinSimulator.setCircuitName("Testschaltung_1");
    meinSimulator.addGate("AND"); // fügt ein unsichtbares AND-Gatter hinzu

    std::vector<int> signal_log;  //speichert signalverlauf 1 oder 0 
                                  //nach jedem takt

    for (int zyklus = 0; zyklus < 10; zyklus++){
        meinSimulator.doTick(); // einen Taktschritt berechnen lassen

    //Aufgabe 
    //i) Objekt nach dem aktuellen Zustand fragen
    //ii) diesen Signal mit push_back in signal_log speichern

        signal_log.push_back(meinSimulator.getOutputState()); // nach aktuellen Zustand fragen
                                                // und in vector speichern
    }


    //Signale im vector mittels for-Schleife ausgeben
    for(int signal: signal_log){
        std::cout << signal << " ";
    }

    printHighCount(signal_log);

    // Wir melden dem Betriebssystem, dass alles fehlerfrei lief.
    return 0;
}
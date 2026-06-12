// main.cpp
// Bibliothek für Input/Output-Streams
#include <iostream>
#include "LogicEngine.h"
#include <vector>
#include <fstream> //bib zum Ablesen von und Schreiben in .txt Dateien. 
#include <sstream> //bib um parsing: info aus .txt zu lesen / aendern
#include "AndGate.h"



using namespace LogicSim;

void printHighCount(const std::vector<int> &logbuch)
{ // vector als parameter um 1sen eines vectors aufzuzaehlen.
  //"&" referenz, damit wird vector nur
  // gelesen und keine kopie erstelllt (unnoetig)
  // schneller
    int counter = 0;
    for (int signal : logbuch)
    {
        if (signal == 1)
        {
            counter++;
        }
    }
    std::cout << "Anzahl HIGH Signale: " << counter << std::endl;
}

int main()
{

    // 1. Objekt instanziieren (Die Blackbox wird im RAM erschaffen)
    LogicEngine meinSimulator;

    // Oeffentliche Funktionen des Objekts
    meinSimulator.setCircuitName("Testschaltung_1");
    meinSimulator.addGate("AND"); // fügt ein unsichtbares AND-Gatter hinzu

    std::vector<int> signal_log; // speichert signalverlauf 1 oder 0
                                 // nach jedem takt

    for (int zyklus = 0; zyklus < 10; zyklus++)
    {
        meinSimulator.doTick(); // einen Taktschritt berechnen lassen

        // Aufgabe
        // i) Objekt nach dem aktuellen Zustand fragen
        // ii) diesen Signal mit push_back in signal_log speichern

        signal_log.push_back(meinSimulator.getOutputState()); // nach aktuellen Zustand fragen
                                                              // und in vector speichern
    }

    // Signale im vector mittels for-Schleife ausgeben
    for (int signal : signal_log)
    {
        std::cout << signal << " ";
    }

    printHighCount(signal_log);

    //Datei schaltzustaende oeffnen und preufen:

    std::ifstream datei("schaltzustaende.txt"); //Objekt datei erstellt und     
                                                //Verbindung zu dieser .txt hergestellt

    if(!datei.is_open()){  //existiert die Datei jetzt?
        std::cout << "Textdatei nicht da!" << std::endl;  //Fehlerhinweis
    }

    //liest inhalt des Dateis und speichert es in Zeilen.
    //Danach werden die Zeilen genauer angeschaut und Ziffern 
    //davon in vector gespeichert. 
    //hier wird kein loop geben, weil contents nur aus ein paar ziffern besteht, 
    //also eine Zeile?? wie mehrere Zeilen aus .txt speichern??

    std::string zeile; // aus .txt file 1. zeile.

    while(std::getline(datei, zeile)){ //da nur ziffern benoetigt, ist hier nur die ziffern
        //hier nix??                   //wichtig. Also 'zeile' kann bis EOF gehen. 
                                       //Waere es woerter. dann schleife notwendig. Und
                                       //getline() faengt da, wo es letztes mal aufgehoert 
                                       //hat
    }

    std::vector<bool> ziffer;  //vector, wo Bit-folge gespeichert wird

    std::stringstream ss(zeile);
    int bit;  //ziffer was in abgelesen und in vector reingeschoben wird. 

    while(ss >> bit){
        ziffer.push_back(bit);
    }

    //Extra:
    //for (int i = 0; i <= ziffer.size(); i++) // wie war das intelligente for-loop in c++ fuer vectoren?
    //{
    //    std::cout << "Ausgabe: " + ziffer[i] << std::endl;
    //}

    //=================================================================
    //-------------Teil D: Integration---------------------------------
    //=================================================================

    //Teil D: 1
    AndGate gatter1;

    //Teil D: 2
    for(int i = 0; i < ziffer.size(); i++){  //ziffer vector durchlaufen
        gatter1.setInputA(ziffer[i]);
        gatter1.setInputB(ziffer[(i + 1)%ziffer.size()]);  //naechster wert zirkulaer

        std::cout << "InputA: " << ziffer[i];
        std::cout << "  InputB: " << ziffer[(i+1)%ziffer.size()] << std::endl;

        gatter1.update();

        bool output = 0;
        output = gatter1.getOutput();

        std::cout << "Ausgabe: " << output << std::endl;
    }

    //gatter1.inputA = 1;  // kein Zugriff auf private Variable der Klasse moeglich!

    //Zusatzaufgabe 4) Log-Datei
    //Ergebnisse mittels std::ofstream und std::ios::app in simulation_log.txt anhaengen!

    //Test ofstream:
    //std::ofstream testf("testofstream.txt");  //nur .txt datei erstellen.

    //std::ofstream testf("testofstream.txt", std::ios::app); // in schon existierende datei reinschreiben
    //testf << "test ofstream 3" << std::endl;  in testf Objekt reinschreiben

    //std::ofstream ausgabe("Gatter-Ausgabe.txt"); // .txt datei erstellen
    
    
    //std::ofstream ausgabe("AndGatter-Ausgabe.txt", std::ios::app); //.txt Datei erstellen, bennen, und Schreibmodus waehlen!!
    
    std::ofstream ausgabe("_log.txt", std::ios::app); //.txt Datei erstellen, bennen, und Schreibmodus waehlen!!
    if(ausgabe.is_open() != 1){
        std::cout << "Fehler: Datei koennte nicht geoffnet werden!" << std::endl;
    }

    for(int i = 0; i < ziffer.size(); i++){
        gatter1.setInputA(ziffer[i]);
        gatter1.setInputB(ziffer[(i + 1) % ziffer.size()]);

        //std::cout << "Input A: " << ziffer[i];
        //std::cout << "Input B: " << ziffer[(i + 1) % ziffer.size()];

        ausgabe << "Input A: " << ziffer[i];
        ausgabe << " Input B: " << ziffer[(i + 1) % ziffer.size()] << std::endl;

        gatter1.update();

        ausgabe << "Ausgabe: " << gatter1.getOutput() << std::endl;
    }


    // Wir melden dem Betriebssystem, dass alles fehlerfrei lief.
    return 0;
}
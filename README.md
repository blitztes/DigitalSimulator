# C++ Logik-Simulator 
Logik-Simulator, wo mittels verschiedene Klassen eine Schaltung gebaut werden kann und Ergebnisse ausgegeben. 

Die Klassen sind: 
->Component.cpp: damit wird ein Logik Gatter ausgewaehlt
->LogicEngine.cpp: baut die Schaltung aus verschiedenen Klassen auf
->AndGate.cpp, OrGate.cpp: verschiedene Gatter die die Logik umsetzen


 ## Feedback zum Text

Ja, der Inhalt ist grundsätzlich in Ordnung als kurzer Projektüberblick, aber ich würde ihn etwas klarer formulieren.

### Vorschlag
- „Logik-Simulator, in dem mit verschiedenen Klassen eine Schaltung gebaut und das Ergebnis ausgegeben wird.“
- Dann die Klassen als kurze Liste:
  - Component.cpp: Basisklasse für Logikgatter
  - LogicEngine.cpp: verwaltet die Schaltung und führt die Simulation aus
  - AndGate.cpp, OrGate.cpp: konkrete Gatterimplementierungen

### Tipp
Ein README.md sollte idealerweise auch kurz sagen:
- was das Programm macht,
- wie man es kompiliert / startet,
- welche Dateien wichtig sind.

So wirkt es professioneller und verständlicher.
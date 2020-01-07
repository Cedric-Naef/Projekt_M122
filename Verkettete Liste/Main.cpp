#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "Header.h"


typedef struct Auto {
  char Marke[40];
  int Jahrgang;
  double Preis;
  struct Auto* pNext;
  struct Auto* pPrev;
} struAuto;


int main() {


  return 0;
}

void random() {
  // Zufallszahlengenerator initialiseren
  // Damit bei jedem Programmstart andere Zahlen erzeugt werden, wird time() verwendet
  // time() Gibt die Zeit als Sekunden zurück, die seit Mitternacht, dem 1. Januar 1970 verstrichen sind 
  srand((unsigned)time(NULL));
  // 10 Zufallszahlen und Strings generieren, speichern und ausgeben
  int Zahl = 0;
  char Text[40];
  for (int iZahl = 0; iZahl < 10; iZahl++) {
    Zahl = rand() % 100;
    Text[0] = 'A' + rand() % 26;
    Text[1] = '\0';
    printf("%i: %i %s\n", iZahl + 1, Zahl, Text);
  }
  // Programmende
  printf("\n");
  system("pause");
}

void Liste() {

  int Anzahl = 10;
  struAuto *pStart = NULL;

  // Elemente erzeugen, mit Daten abfüllen   
  for (int i = 0; i < Anzahl; i++) {
    struAuto *pAuto = (struAuto*)malloc(sizeof(struAuto));
    pAuto->Jahrgang = Anzahl - i;
    pAuto->pNext = NULL;
    if (i != 0) pAuto->pNext = pStart;
    pStart = pAuto;
  }

  // Liste ausgeben   
  for (struAuto* pAto = pStart; pAto != NULL; pAto = pAto->pNext)
  {
    printf("Marke: %c\n Jahrgang: %i\n Preis: %d\n", pAto->Jahrgang);
  }

  // Auf Tastendruck warten
  system("Pause");


}

void ElementLöschen(/*Pointer auf Element, Pointer auf "Start"*/) {


  //return "Start"
}

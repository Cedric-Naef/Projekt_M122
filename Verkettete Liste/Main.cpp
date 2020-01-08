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

    int Anzahl;
    struAuto* pStart = NULL;

    int eingabe;


    //Das Menü wird eingeblendet
    printf("Was wollen Sie machen?\n"
        "1 -> Liste erstellen\n"
        "2 -> Liste loeschen\n"
        "3 -> Element loeschen\n"
        "4 -> Liste sortieren\n"
        "5 -> Liste ausgeben\n"
        "6 -> Programm beenden\n\n");

    scanf_s("%i", &eingabe);

    //Es wird der eingegebene Wert überprüft
    if (eingabe == 1)
    {
        //Liste erstellen
        
        //Anzahl der Elemente eingeben
        printf("Geben Sie die Anzahl der Elemente ein, die Sie wollen\n");
        scanf_s("%i", &Anzahl);
        struAuto* pStart = NULL;

        // Elemente erzeugen, mit Daten abfüllen   
        for (int i = 0; i < Anzahl; i++) {
            struAuto* pAuto = (struAuto*)malloc(sizeof(struAuto));
            pAuto->Jahrgang = Anzahl - i;
            pAuto->pNext = NULL;
            if (i != 0) pAuto->pNext = pStart;
            pStart = pAuto;
        }
    }
    else if (eingabe == 2)
    {
        printf("Liste wird geloescht!\n");
    }
    else if (eingabe == 3)
    {
        printf("Element wird geloescht!\n");
    }
    else if (eingabe == 4)
    {
        printf("Liste wird sortiert!\n");
    }
    else if (eingabe == 5)
    {
        // Liste ausgeben   
        for (struAuto* pAto = pStart; pAto != NULL; pAto = pAto->pNext)
        {
            printf("Marke: %c\n Jahrgang: %i\n Preis: %d\n", pAto->Jahrgang);
        }
    }
    else
    {
        //Programm beenden
        system("pause");
        return 0;
    }


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

//Löscht ein Element
void ElementLöschen(/*Pointer auf Element, Pointer auf "Start"*/) {


  //return "Start"
}

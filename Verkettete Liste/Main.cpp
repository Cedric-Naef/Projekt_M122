#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "Sort.h"
#include "Main.h"


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

    switch (eingabe)
    {
    case 1:
        printf("Liste wird geloescht!\n");
        break;

    case 2:
        printf("Element wird geloescht!\n");
        break;
    case 3:
        printf("Element geslöscht\n");
        break;
    case 4:
        printf("Liste wird sortiert!\n");
        break;
    case 5:
        for (struAuto* pAto = pStart; pAto != NULL; pAto = pAto->pNext)
        {
            printf("Marke: %c\n Jahrgang: %i\n Preis: %d\n", pAto->Jahrgang);
        }

    default:
        printf("Eingabe ungültig");
    }

    //Programm beenden
    system("pause");
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

//Löscht ein Element
void ElementLöschen(/*Pointer auf Element, Pointer auf "Start"*/) {


  //return "Start"
}
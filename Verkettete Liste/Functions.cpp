#include "stdio.h"
#include "stdlib.h"
#include "time.h"

//Own header files
#include "Main.h"
#include "Functions.h"
#include "StructAuto.h"



void bubblesort(int *array, int length)
{
  int i, j, tmp;

  for (i = 1; i < length; i++)
  {
    for (j = 0; j < length - i; j++)
    {
      if (array[j] > array[j + 1])
      {
        tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
    }
  }
}

struAuto* CreateList(int Anzahl)
{
    //Anzahl der Elemente eingeben
    printf("Geben Sie die Anzahl der Elemente ein, die Sie wollen\n");
    //scanf_s("%i", &Anzahl);
    struAuto* pStart = NULL;

    // Elemente erzeugen, mit Daten abfüllen   
    for (int i = 0; i < Anzahl; i++) {
        struAuto* pAuto = (struAuto*)malloc(sizeof(struAuto));
        pAuto->Jahrgang = Anzahl - i;
        pAuto->pNext = NULL;
        if (i != 0) pAuto->pNext = pStart;
        pStart = pAuto;
    }
    return pStart;
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

void PrintList(struAuto *pAuto)
{
    //for (struAuto* pAto = pStart; pAto != NULL; pAto = pAto->pNext)
    //{
    //    printf("Marke: %c\n Jahrgang: %i\n Preis: %d\n", pAto->Jahrgang);
    //}
}

//Löscht ein Element
void DeleteElement(/*Pointer auf Element, Pointer auf "Start"*/) {


    //return "Start"
}
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

//Own header files
#include "Main.h"
#include "Functions.h"
#include "StructAuto.h"



void Bubblesort(int *array, int length)
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
        pAuto->Preis = 10000;
        pAuto->pNext = NULL;
        if (i != 0) pAuto->pNext = pStart;
        pStart = pAuto;
    }
    return pStart;
}

void Randomize() {
    // Zufallszahlengenerator initialiseren
    // Damit bei jedem Programmstart andere Zahlen erzeugt werden, wird time() verwendet
    // time() Gibt die Zeit als Sekunden zurück, die seit Mitternacht, dem 1. Januar 1970 verstrichen sind 
    srand((unsigned)time(NULL));
 
    char marke[40];
    int jahrgang = 0;
    double preis = 0;
    
    for (int iZahl = 0; iZahl < 10; iZahl++) {
        marke[0] = 'A' + rand() % 26;
        marke[1] = '\0';
        jahrgang = rand() % 100;
        preis = rand() % 100;
        printf("%c, %i, %p\n", marke, jahrgang, preis);
        return (marke, jahrgang, preis);
    }
    // Programmende
    printf("\n");
    system("pause");
}

void PrintList(struAuto *pStart)
{
    for (struAuto* pAto = pStart; pAto != NULL; pAto = pAto->pNext)
    {
        printf("Marke: %s\n Jahrgang: %i\n Preis: %f\n", pAto->Marke, pAto->Jahrgang, pAto->Preis);
    }
}

//Löscht ein Element
void DeleteElement(Auto* pElement/*Pointer auf Element, Pointer auf "Start"*/) {


    //return "Start"
}

//Löscht die Liste
void DeleteList() 
{


    //free(list);
}
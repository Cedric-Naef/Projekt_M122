#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "Sort.h"
#include "Main.h"


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

void CreateList(int& Anzahl)
{
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
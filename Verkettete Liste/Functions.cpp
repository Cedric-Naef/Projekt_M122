#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

//Own header files
#include "Main.h"
#include "Functions.h"
#include "StructAuto.h"


void sortList(struAuto* pStart) {
    //struAuto* pAutoA = pListHead;
    //struAuto* pAutoB = pListHead->pNext;
    //int swaps = 1;
    //while(swaps){
    //    swaps = 0;
    //    pAutoA = pAutoB;
    //    pAutoB = pAutoB->pNext;
    //    while (pAutoA->pNext != pListHead) {
    //        // bedingung
    //        if (pAutoA->Jahrgang > pAutoB->Jahrgang) {
    //            printf("swap");
    //            if (pAutoA == pListHead) {
    //                pListHead = pAutoB;
    //            }
    //            SwapElement(pAutoA, pAutoB);
    //            swaps += 1;
    //        }
    //        pAutoA = pAutoB;
    //        pAutoB = pAutoB->pNext;
    //    }
    //}
    struAuto* help = NULL;
    struAuto* store = pStart;
    int swap_data;
    while (store->pNext != pStart && pStart != NULL) {
        help = store;
        while (help->pNext != pStart) {
            if (help->Jahrgang < help->pNext->Jahrgang) {
                SwapElement(help, store);
            }
            help = help->pNext;
        }
        store = store->pNext;
    }
}

void SwapElement(struAuto* pAutoA, struAuto* pAutoB)
{
    pAutoA = pAutoB;
    pAutoB = pAutoB->pNext;
    struAuto* pTemp = pAutoA->pPrev;
    pAutoA->pNext = pAutoB->pNext;
    pAutoA->pPrev = pAutoB;
    pAutoA->pNext->pPrev = pAutoA;

    pAutoB->pNext = pAutoA;
    pAutoB->pPrev = pTemp;
    pAutoB->pPrev->pNext = pAutoB;
}

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
    struAuto* pLast = NULL;
    struAuto* pHead = NULL;
    int Index = 0;
    // Elemente erzeugen, mit Daten abf�llen   
    for (int i = 0; i < Anzahl; i++) {
        struAuto* pAuto = (struAuto*)malloc(sizeof(struAuto));
        pAuto->Key = i;

        
        char Marke[40];
        Marke[0] = getRandUpperCaseChar();
        Marke[1] = '\0';
        strcpy_s(pAuto->Marke, Marke);
        pAuto->Jahrgang = 1900;
        pAuto->Preis = getRandomNumber();
        if (i != 0)
        {
            pLast = pHead->pPrev;

            pAuto->pNext = pHead;
            pAuto->pPrev = pLast;
            pHead->pPrev = pAuto;
            pLast->pNext = pAuto;
        }
        else {
            pHead = pAuto;
            pHead->pNext = pHead;
            pHead->pPrev = pHead;
        }
            
    }
    return pHead;
}

void Randomize() {
    // Zufallszahlengenerator initialiseren
    // Damit bei jedem Programmstart andere Zahlen erzeugt werden, wird time() verwendet
    // time() Gibt die Zeit als Sekunden zur�ck, die seit Mitternacht, dem 1. Januar 1970 verstrichen sind 
    srand((unsigned)time(NULL));
 
    char marke[40];
    int jahrgang = 0;
    double preis = 0;
    
    // 4 Zufallszahlen und Strings generieren
    for (int iZahl = 0; iZahl < 4; iZahl++) {
        marke[0] = 'A' + rand() % 26;
        marke[1] = '\0';
        jahrgang = rand() % 80 + 1940;
        preis = rand() % 900 + 1;
        //return (marke, jahrgang, preis);
    }
}

void DeleteElementsByProperty(struAuto *pListHead, int Property)
{
    struAuto* CurrentElement = pListHead;
    while( CurrentElement->pNext != pListHead && pListHead != NULL)
    {
        if (CurrentElement == pListHead)
        {

        }

        if (Property == CurrentElement->Jahrgang)
        {
            printf("The following elent in list is getting deleted: \n");
            PrintElement(CurrentElement);
            pListHead = CurrentElement->pNext;
            CurrentElement = DeleteElement(CurrentElement);   
        }
        else
        {
            CurrentElement = CurrentElement->pNext;
        }


    }

    /* struAuto* CurrentElement = pListHead;
    while (CurrentElement->pNext != pListHead)
    {
        CurrentElement = DeleteElement(CurrentElement);
    }
    free(CurrentElement);
    PrintElement(CurrentElement);*/
}

void PrintList(struAuto* pStart)
{
    struAuto* pAto = pStart;
    while (pAto->pNext != pStart)
    {
        PrintElement(pAto);
        pAto = pAto->pNext;
    }
    PrintElement(pAto);
}

struAuto* GetElement(struAuto* pListHead, int Index)
{
    int CurrentIndex = 0;
    struAuto* Rtrn = NULL;

    struAuto* pAto = pListHead;
    while (pAto->pNext != pListHead)
    {
        if (CurrentIndex == Index)
        {
            PrintElement(pAto);
            Rtrn = pAto;
        }
        pAto = pAto->pNext;
        CurrentIndex++;
    }
    return Rtrn;
    //PrintElement(CurrentElement);
}

void PrintElement(struAuto* pElement)
{
    printf("\nKey: %d\n Marke: %s\n Jahrgang: %i\n Preis: %f Tausend\n", pElement->Key, pElement->Marke, pElement->Jahrgang, pElement->Preis);
}

//L�scht ein Element
struAuto* DeleteElement(struAuto* pElement) {

    //Auto* tmp1 = pElement->pPrev->pNext;
    //Auto* tmp2 = pElement->pNext->pPrev;

    if (pElement->pNext == pElement) {
        free(pElement);
        return NULL;
    }
    pElement->pPrev->pNext = pElement->pNext;
    pElement->pNext->pPrev = pElement->pPrev;
    
    struAuto* tmp = pElement->pNext;
    free(pElement);
    return tmp;
}

//L�scht die Liste
void DeleteList(struAuto* pStart)
{
    struAuto* pAto = pStart;
    while (pAto->pNext != pStart && pStart !=NULL)
    {
        pAto = DeleteElement(pAto);
    }
    free(pAto);
}


char getRandUpperCaseChar() {
    /* Return a random of the 26 chars after the value of 65 in ASCII. */
    return (char)(rand() % 26 + 65);
}

char GetRandomString(int Length)
{
    //char [] =
    //char Random[Length];

    for (int i = 0; i < Length; i++)
    {

    }
    
    return ('a');
}



int getRandomNumber() {
    return rand() % 100;
}
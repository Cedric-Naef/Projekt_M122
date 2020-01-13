#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

//Own header files
#include "Main.h"
#include "Functions.h"
#include "StructAuto.h"


void SortListFoward(struAuto* pListHead) {
    if (pListHead != NULL)
    {
        struAuto* help = NULL;
        struAuto* store = pListHead;
        int swap_data;
        while (store->pNext != pListHead && pListHead != NULL) {
            help = store;
            while (help->pNext != pListHead) {
                if (help->Jahrgang < help->pNext->Jahrgang) {
                    SwapElement(help, store);
                }
                help = help->pNext;
            }
            store = store->pNext;
        }
    }
}

void SortListBackward(struAuto* pListHead) {
    if (pListHead != NULL)
    {
        struAuto* help = NULL;
        struAuto* store = pListHead;
        int swap_data;
        while (store->pNext != pListHead && pListHead != NULL) {
            help = store;
            while (help->pNext != pListHead) {
                if (help->Jahrgang > help->pNext->Jahrgang) {
                    SwapElement(help, store);
                }
                help = help->pNext;
            }
            store = store->pNext;
        }
    }
}

void SwapElement(struAuto* pElementA, struAuto* pElementB)
{
    if (pElementA != NULL && pElementB != NULL)
    {
        pElementA = pElementB;
        pElementB = pElementB->pNext;
        struAuto* pTemp = pElementA->pPrev;
        pElementA->pNext = pElementB->pNext;
        pElementA->pPrev = pElementB;
        pElementA->pNext->pPrev = pElementA;

        pElementB->pNext = pElementA;
        pElementB->pPrev = pTemp;
        pElementB->pPrev->pNext = pElementB;
    }
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
    if (Anzahl != NULL)
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


            pAuto->Marke[0] = getRandUpperCaseChar();
            pAuto->Marke[1] = '\0';
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

struAuto* DeleteElementsByProperty(struAuto *pListHead, int Property)
{
    if (pListHead != NULL && Property != NULL)
    {
        struAuto* Rtrn = NULL;
        struAuto* pCurrentElement = pListHead;
        while (pCurrentElement->pNext != pListHead)
        {


            if (Property == pCurrentElement->Jahrgang)
            {
                printf("The following elent in list is getting deleted: \n\n");
                PrintElement(pCurrentElement);
                if (pCurrentElement == pListHead)
                {
                    pListHead = pCurrentElement->pNext;
                }

                Rtrn = DeleteElement(pListHead, pCurrentElement);
            } else
            {
                pCurrentElement = pCurrentElement->pNext;
            }

            pCurrentElement = DeleteElement(pCurrentElement);

            if (pCurrentElement == NULL)
            {
                return NULL;
            }
        }

        return Rtrn;
    }

    /* struAuto* pCurrentElement = pListHead;
    while (pCurrentElement->pNext != pListHead)
    {
        pCurrentElement = DeleteElement(pCurrentElement);
    }
    free(pCurrentElement);
    PrintElement(pCurrentElement);*/

    //If all failes return NULL
    return NULL;
}

void PrintList(struAuto* pStart)
{
    if (pStart != NULL)
    {
        struAuto* pAto = pStart;

        //Checks if there are more then one elements then one
        while (pAto->pNext != pStart)
        {
            PrintElement(pAto);
            pAto = pAto->pNext;
        }

        //Print last element
        PrintElement(pAto);
    }
}

struAuto* GetElement(struAuto* pListHead, int Index)
{
    if (pListHead != NULL && Index != NULL)
    {
        int CurrentIndex = 0;

        struAuto* pCurrentElement = pListHead;
        while (pCurrentElement->pNext != pListHead)
        {
            if (CurrentIndex == Index)
            {
                PrintElement(pCurrentElement);
                return pCurrentElement;
            }
            pCurrentElement = pCurrentElement->pNext;
            CurrentIndex++;
        }

        if (pListHead == pCurrentElement && Index == 0)
        {
            //If only one element is in list return ListHead
            return pListHead;
        }
    }
    //PrintElement(pCurrentElement);

    //If all fails return null
    return NULL;
}

void PrintElement(struAuto* pElement)
{
    printf("\nKey: %d\n Marke: %s\n Jahrgang: %i\n Preis: %f Tausend\n", pElement->Key, pElement->Marke, pElement->Jahrgang, pElement->Preis);
}

//L�scht ein Element
struAuto* DeleteElement(struAuto* pElement) {

    //Auto* tmp1 = pElementToBeDeleted->pPrev->pNext;
    //Auto* tmp2 = pElementToBeDeleted->pNext->pPrev;

    if (pElement != NULL)
    {
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

}

struAuto* DeleteElement(struAuto* pListHead, struAuto* pElementToBeDeleted)
{
    if (pListHead !=  NULL && pElementToBeDeleted != NULL)
    {
        //Checks if list hast only one element
        if (pListHead->pNext == pListHead)
        {
            free(pListHead);

            //Return null if last element was deleted
            return NULL;
        }

        //If the ListHead is to be deleted set ListHead to the next Element in List
        if (pListHead == pElementToBeDeleted)
        {
            pListHead = pElementToBeDeleted->pNext;
        }

        //Relink previous and next element from the item is to be deleted
        pElementToBeDeleted->pPrev->pNext = pElementToBeDeleted->pNext;
        pElementToBeDeleted->pNext->pPrev = pElementToBeDeleted->pPrev;

        free(pElementToBeDeleted);
        return pListHead;
    }
}

//Deletes whole the list
void DeleteList(struAuto* pListHead)
{
    if (pListHead != NULL)
    {
        //Sets pCurrentElement to ListHead
        struAuto* pCurrentElement = pListHead;

        while (pCurrentElement->pNext != pListHead)
        {

            pCurrentElement = DeleteElement(pCurrentElement);

            if (pCurrentElement == NULL)
            {
                return;
            }
        }

        //Deletes last element in list
        free(pCurrentElement);
    }
}

void DeleteElementsByProperty2(struAuto* pListHead, int Property)
{
    if (pListHead != NULL)
    {
        //Sets pCurrentElement to ListHead
        struAuto* pCurrentElement = pListHead;

        while (pCurrentElement->pNext != pListHead)
        {
            if (pCurrentElement->Jahrgang == Property)
            {
                struAuto* pElementToBeDeleted = pCurrentElement;
                pCurrentElement = pCurrentElement->pNext;
                DeleteElement(pListHead, pElementToBeDeleted);
            } else
            {
                pCurrentElement = pCurrentElement->pNext;
            }

            if (pCurrentElement == NULL)
            {
                return;
            }
        }

        if (pCurrentElement->Jahrgang == Property)
        {
            free(pCurrentElement);
        }
    }
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
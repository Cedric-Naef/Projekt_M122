#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

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


//Die Liste wird erstellt
//Autor: Naef Cedric, Rey Colin
struAuto* CreateList(int Anzahl)
{
    //Anzahl der Elemente eingeben
    printf("Geben Sie die Anzahl der Elemente ein, die Sie wollen\n");
    //scanf_s("%i", &Anzahl);
    struAuto* pLast = NULL;
    struAuto* pHead = NULL;
    int Index = 0;
    // Elemente erzeugen, mit Daten abfuellen   
    for (int i = 0; i < Anzahl; i++) {
        struAuto* pAuto = (struAuto*)malloc(sizeof(struAuto));
        pAuto->Key = i;
        pAuto->Marke, getRandUpperCaseChar();
        pAuto->Jahrgang = getRandomDate();
        pAuto->Preis = getRandomNumber();
        if (i != 0)
        {
            pLast = pHead->pPrev;
            pAuto->pNext = pHead;
            pAuto->pPrev = pAuto;
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


//Die Liste wird ausgegeben
//Autor: Rey Colin
void PrintList(struAuto *pStart)
{
    struAuto* pAto = pStart;
    while( pAto->pNext != pStart)
    {
        PrintElement(pAto);
        pAto = pAto->pNext;
    }
    PrintElement(pAto);
}


//Ein Element wird gesucht
//Autor: Rey Colin
struAuto* GetElement(struAuto* pStart, int Index)
{
    int CurrentIndex = 0;
    struAuto* Rtrn = NULL;

    struAuto* pAto = pStart;
    while (pAto->pNext != pStart)
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
    //PrintElement(pAto);
}


//Das Element wird ausgegeben
//Autor: Rey Colin
void PrintElement(struAuto* pElement)
{
    printf("\nKey: %d    Marke: %s    Jahrgang: %i    Preis: %f Tausend\n", pElement->Key, pElement->Marke, pElement->Jahrgang, pElement->Preis);
}


//Loescht ein Element
//Autor: Rey Colin
struAuto* DeleteElement(struAuto* pElement) {

    //Auto* tmp1 = pElement->pPrev->pNext;
    //Auto* tmp2 = pElement->pNext->pPrev;

    pElement = pElement->pNext->pNext;
    pElement->pPrev->pNext = pElement->pNext;
    pElement->pNext->pPrev = pElement->pPrev;

    struAuto* tmp = pElement->pNext;
    free(pElement);
    return tmp;
}


//Loescht die Liste
//Autor: Rey Colin
void DeleteList(struAuto* pStart)
{
    struAuto* pAto = pStart;
    while (pAto->pNext != pStart)
    {
        pAto = DeleteElement(pAto);
    }
    free(pAto);
}


//Ein zufaelliger Buchstabe wird erstellt
//Autor: Rey Colin
char getRandUpperCaseChar() {
    //Return a random of the 26 chars after the value of 65 in ASCII.
    return (char)(rand() % 26 + 65);
}


//Ein zufaelliges Datum wird erstellt
//Autor: Rey Colin, Naef Cedric
int getRandomDate() {
    return rand() % 80 + 1940;
}


//Eine zufaellige Zahl wird erstellt
//Autor: Rey Colin, Naef Cedric
int getRandomNumber() {
    rand() % 900 + 1;
}


//Die Liste wird sortiert
//Autor: Naef Cedric
void Sort()
{
    int UserInput;
    int srt = 0;
    
    do {
        //Menü zur Auswahl der sortierung
        printf("Nach was wollen Sie Sortieren?\n"
            "Nach Marke aufwärts sortieren ----> 1\n"
            "Nach Marke abwärts sortieren -----> 2\n"
            "Nach Jahrgang aufwärts sortieren -> 3\n"
            "Nach Jahrgang abwärts sortieren --> 4\n"
            "Nach Preis aufwärts sortieren ----> 5\n"
            "Nach Preis abwärts sortieren -----> 6\n\n");
        scanf_s("%i", &UserInput);

        switch (UserInput)
        {
        case 1:
            
            printf("Die liste wurde der Marke nach aufwärts sortiert.\n");
            srt = 1;
            break;

        case 2:

            printf("Die liste wurde der Marke nach abwärts sortiert.\n");
            srt = 1;
            break;

        case 3:

            printf("Die liste wurde dem Jahrgang nach aufwärts sortiert.\n");
            srt = 1;
            break;

        case 4:

            printf("Die liste wurde dem Jahrgang nach abwärts sortiert.\n");
            srt = 1;
            break;

        case 5:

            printf("Die liste wurde dem Preis nach aufwärts sortiert.\n");
            srt = 1;
            break;

        case 6:

            printf("Die liste wurde dem Preis nach abwärts sortiert.\n");
            srt = 1;
            break;

        default:
            printf("Eingabe ungueltig\n\n");
            break;
        }
    } while (srt != 1);
}
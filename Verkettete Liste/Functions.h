#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

//Own header files
#include "Main.h"
#include "Functions.h"
#include "StructAuto.h"


void SortListFoward(struAuto* pHead);

void SortListBackward(struAuto* pListHead);

void SwapElement(struAuto* pAutoA, struAuto* pAutoB);

void Bubblesort(int *array, int length);

struAuto* CreateList(int Anzahl);

void Randomize();

struAuto* DeleteElementsByProperty(struAuto* pStart, int Property);

void DeleteElementsByProperty2(struAuto* pStart, int Property);

void PrintList(struAuto* pStart);

struAuto* GetElement(struAuto* pStart, int Index);

void PrintElement(struAuto* pElement);

struAuto* DeleteElement(struAuto* pElement);

struAuto* DeleteElement(struAuto* pListHead, struAuto* pElementToBeDeleted);

void DeleteList(struAuto* pStart);

char getRandUpperCaseChar();

int getRandomNumber();

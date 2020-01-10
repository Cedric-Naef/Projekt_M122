#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

//Own header files
#include "Main.h"
#include "Functions.h"
#include "StructAuto.h"


void Bubblesort(int *array, int length);

void BubblesortC(char* array, int length);

void BubblesortBack(int* array, int length);

void BubblesortBackC(char* array, int length);

struAuto* CreateList(int Anzahl);

void PrintList(struAuto* pStart);

struAuto* GetElement(struAuto* pStart, int Index);

void PrintElement(struAuto* pElement);

struAuto* DeleteElement(struAuto* pElement);

void DeleteList(struAuto* pStart);

char getRandUpperCaseChar();

int getRandomNumber();

int getRandomDate();

void Sort(struAuto* pStart);
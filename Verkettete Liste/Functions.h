#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

//Own header files
#include "Main.h"
#include "Functions.h"
#include "StructAuto.h"


void Bubblesort(int *array, int length);

struAuto* CreateList(int Anzahl);

void Randomize();

void PrintList(struAuto* pStart);

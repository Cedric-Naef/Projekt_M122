#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

//Own header files
#include "Main.h"
#include "Functions.h"
#include "StructAuto.h"

typedef struct Auto {
    int Key;
    char Marke[40];
    int Jahrgang;
    double Preis;
    struct Auto* pNext;
    struct Auto* pPrev;
} struAuto;

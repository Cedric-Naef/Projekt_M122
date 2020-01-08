typedef struct Auto {
    char Marke[40];
    int Jahrgang;
    double Preis;
    struct Auto* pNext;
    struct Auto* pPrev;
} struAuto;

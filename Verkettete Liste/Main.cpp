#include "stdio.h"
#include "stdlib.h"
#include "time.h"

//Own header files
#include "Main.h"
#include "Functions.h"
#include "StructAuto.h"


int main()
{
    struAuto* pStart = NULL;

    int UserInput;

    pStart = CreateList(10);
    PrintList(pStart);

    //Das Menü wird eingeblendet
    printf("Was wollen Sie machen?\n"
        "1 -> Liste erstellen\n"
        "2 -> Liste loeschen\n"
        "3 -> Element loeschen\n"
        "4 -> Liste sortieren\n"
        "5 -> Liste ausgeben\n"
        "6 -> Programm beenden\n\n");

    scanf_s("%i", &UserInput);

    switch (UserInput)
    {
        case 1:
            printf("Liste wird erstellt!\n");
            break;

        case 2:
            printf("Liste wird gelöscht!\n");
            break;

        case 3:
            printf("Element geslöscht\n");
            break;

        case 4:
            printf("Liste wird sortiert!\n");
            break;

        case 5:
            printf("Hier Ihre Liste\n");
            break;

        case 6:
            printf("Programm wird beendet\n");
            break;

        default:
            printf("Ungültige Eingabe");
            break;
    }

    Randomize();

    //Programm beenden
    system("pause");
    return 0;
}





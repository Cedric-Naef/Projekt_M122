#include "stdio.h"
#include "stdlib.h"
#include "time.h"

//Own header files
#include "Main.h"
#include "Functions.h"
#include "StructAuto.h"




int main() {

    int Anzahl;
    struAuto* pStart = NULL;

    int eingabe;


    //Das Menü wird eingeblendet
    printf("Was wollen Sie machen?\n"
        "1 -> Liste erstellen\n"
        "2 -> Liste loeschen\n"
        "3 -> Element loeschen\n"
        "4 -> Liste sortieren\n"
        "5 -> Liste ausgeben\n"
        "6 -> Programm beenden\n\n");

    scanf_s("%i", &eingabe);

    switch (eingabe)
    {
        case 1:
            printf("Liste wird geloescht!\n");
            break;

        case 2:
            printf("Element wird geloescht!\n");
            break;

        case 3:
            printf("Element geslöscht\n");
            break;

        case 4:
            printf("Liste wird sortiert!\n");
            break;

        case 5:
            printf("Hier Ihre Liste");
            break;

        case 6:
            printf("Programm wird beendet");
            break;

        default:
            printf("Eingabe ungültig");
    }

    //Programm beenden
    system("pause");
    return 0;
}





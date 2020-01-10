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

    int Exit = 0;

    struAuto* tmp2 = NULL;

    pStart = CreateList(10);
    //GetElement(pStart, 2);


    do {
        //Das Menue wird eingeblendet
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
                if (pStart == NULL)
                {
                    //Anzahl der Elemente eingeben
                    printf("Wie viele Datensaetze wollen Sie?\n");
                    scanf_s("%i", &UserInput);
                    pStart = CreateList(UserInput);
                    printf("Liste wird erstellt\n\n");
                }
                else
                    printf("Bitte loeschen Sie Ihre Liste erst!\n\n");

                break;

            case 2:
                printf("Liste wird geloescht!\n\n");
                DeleteList(pStart);
                pStart = NULL;
                break;

            case 3:
                printf("Element wird gesloescht\n\n");
                tmp2 = GetElement(pStart, 2);
                DeleteElement(pStart);
                break;

            case 4:
                printf("Liste wird sortiert!\n\n");
                Sort(pStart);
                break;

            case 5:
                printf("Hier Ihre Liste:\n");
                PrintList(pStart);
                break;

            case 6:
                printf("Programm wird beendet\n");
                Exit = 1;
                break;

            default:
                printf("Eingabe ungueltig\n\n");
                break;
        }
    } while (Exit != 1);


    //Programm beenden
    system("pause");
    return 0;
}





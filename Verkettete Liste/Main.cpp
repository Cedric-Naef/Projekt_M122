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




    do{
        //Das Men� wird eingeblendet
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
                    printf("Liste wird erstellt\n");
                    pStart = CreateList(10);
                }
                else
                    printf("Bitte loeschen Sie Ihre Liste erst!\n");

                break;

            case 2:
                printf("Liste wird geloescht!\n");
                DeleteList(pStart);
                pStart = NULL;
                break;

            case 3:
                printf("Element wird gesloescht\n");
                tmp2 = GetElement(pStart, 2);
                DeleteElement(pStart);
                break;

            case 4:
                printf("Liste wird sortiert!\n");
                break;

            case 5:
                printf("Hier Ihre Liste");
                PrintList(pStart);
                break;

            case 6:
                printf("Programm wird beendet");
                Exit = 1;
                break;

            default:
                printf("Eingabe ungueltig");
                break;
        }
    } while (Exit != 1);



    //Randomize();

    //Programm beenden
    system("pause");
    return 0;
}





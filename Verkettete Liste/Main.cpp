#include "stdio.h"
#include "stdlib.h"
#include "time.h"

//Own header files
#include "Main.h"
#include "Functions.h"
#include "StructAuto.h"


int main()
{
    struAuto* pListHead = NULL;

    int UserInput;

    int Exit = 0;

    struAuto* tmp2 = NULL;

    pListHead = CreateList(10);
    //GetElement(pListHead, 2);




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
                if (pListHead == NULL)
                {
                    printf("Liste wird erstellt\n");
                    pListHead = CreateList(10);
                }
                else
                    printf("Bitte loeschen Sie Ihre Liste erst!\n");

                break;

            case 2:
                printf("Element wird geloescht!\n");
                DeleteList(pListHead);
                pListHead = NULL;
                break;

            case 3:
                printf("Element gesloescht\n");
                tmp2 = GetElement(pListHead, 2);
                DeleteElement(tmp2);
                break;

            case 4:
                printf("Liste wird sortiert!\n");
                sortList(pListHead);
                break;

            case 5:
                printf("Hier Ihre Liste");
                PrintList(pListHead);
                break;

            case 6:
                printf("Programm wird beendet");
                Exit = 1;
                break;

            case 7:
                scanf_s("%i", &UserInput);
                DeleteElementsByProperty(pListHead, UserInput);
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





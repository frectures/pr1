#include <stdio.h>

char eingabe[20];
int laenge;
char aufdeckung[20];
int leben;

int strlen(char a[])
{
    int i = 0;
    while (a[i] != 0)
    {
        ++i;
    }
    return i;
}

void verdecke()
{
    int i;
    for (i = 0; i < laenge; ++i)
    {
        aufdeckung[i] = '_';
    }
    aufdeckung[i] = 0;
}

void schreibe_entzerrt()
{
    int i;
    for (i = 0; i < laenge; ++i)
    {
        printf("%c ", aufdeckung[i]);
    }
    printf("\n");
}

int bereits_aufgedeckt(char x)
{
    int i;
    for (i = 0; i < laenge; ++i)
    {
        if (aufdeckung[i] == x) return 1;
    }
    return 0;
}

void decke_auf(char x)
{
    int i;
    for (i = 0; i < laenge; ++i)
    {
        if (eingabe[i] == x)
        {
            aufdeckung[i] = x;
        }
    }
}

int gewonnen()
{
    int i;
    for (i = 0; i < laenge; ++i)
    {
        if (aufdeckung[i] == '_') return 0;
    }
    return 1;
}

int in_eingabe_drin(char x)
{
    int i;
    for (i = 0; i < laenge; ++i)
    {
        if (eingabe[i] == x) return 1;
    }
    return 0;
}

void hauptschleife()
{
    while (!gewonnen() && leben > 0)
    {    
        printf("Buchstabe: ");
        char x;
        scanf(" %c", &x);
        if (!in_eingabe_drin(x))
        {
            printf("Der Buchstabe %c kommt nicht vor.\n", x);
            --leben;
            printf("Du hast noch %d Leben uebrig.\n", leben);
        }
        else if (bereits_aufgedeckt(x))
        {
            printf("Du hast das %c doch schon geraten, Du Trottel!\n", x);
        }
        else
        {
            decke_auf(x);
            schreibe_entzerrt();
        }
    }
}

int main()
{
    printf("Herzlich willkommen zu Hangman!\n\n");
    printf("Wort: ");
    scanf("%19s", eingabe);
    laenge = strlen(eingabe);
    
    verdecke();
    schreibe_entzerrt();
    leben = 5;
    hauptschleife();
    
    return 0;
}

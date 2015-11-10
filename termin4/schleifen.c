// Diese Datei enthaelt halbwegs sinnvolle Schleifen-Beispiele.
// Wenn du dir zum Beispiel nicht mehr ganz sicher bist,
// wie die for-Schleife aufgebaut ist, schaue einfach hier nach :)

void schreibe_trennlinie()
{
    printf("----------------------------------------------------------------------\n");
}



// Beispiele fuer for-Schleifen

void schreibe_alle_ziffern()
{
    int i;
    for (i = 0; i < 10; ++i)
    {
        printf("%d ist eine Ziffer.\n", i);
    }
}

void schreibe_dreier_ziffern_rueckwaerts()
{
    int i;
    for (i = 9; i >= 0; i -= 3)
    {
        printf("%d ist durch 3 teilbar.\n", i);
    }
}

int summe_erster_zahlen_bis(int n)
{
    int summe = 0;
    int i;
    for (i = 1; i <= n; ++i)
    {
        summe += i;
    }
    return summe;
}

void for_beispiele()
{
    schreibe_alle_ziffern();
    schreibe_trennlinie();

    schreibe_dreier_ziffern_rueckwaerts();
    schreibe_trennlinie();

    printf("Gauss haette %d schlauer berechnet.\n", summe_erster_zahlen_bis(100));
}



// Beispiele fuer while-Schleifen

int langsamer_divisionsrest(int x, int teiler)
{
    while (x >= teiler)
    {
        x -= teiler;
    }
    return x;
}

int linke_dezimalziffer(int x)
{
    while (x >= 10)
    {
        x = x / 10;
    }
    return x;
}

void while_beispiele()
{
    int x = 123;
    int y = 10;
    int z = 4711;

    printf("%d mod %d = %d\n", x, y, langsamer_divisionsrest(x, y));
    schreibe_trennlinie();
    
    printf("Die %d beginnt mit der Ziffer %d.\n", z, linke_dezimalziffer(z));
    
}



// Beispiele fuer do-while-Schleifen

int ist_zweierpotenz(int x)
{
    return (x & (x - 1)) == 0;
}

int finde_naechste_zweierpotenz(int x)
{
    do 
    {
        ++x;
    } while (!ist_zweierpotenz(x));
    return x;
}

void frage_nach_der_antwort()
{
    int antwort;
    do
    {
        printf("Was ist die Antwort auf alle Fragen? ");
        scanf("%d", &antwort);
    } while (antwort != 2 * 3 * 7);
    printf("Korrekt!\n");
}

void do_while_beispiele()
{
    printf("%d ist die kleinste dreistellige Zweierpotenz.\n", finde_naechste_zweierpotenz(64));
    schreibe_trennlinie();

    frage_nach_der_antwort();
}



int main()
{
    for_beispiele();
    schreibe_trennlinie();
    
    while_beispiele();
    schreibe_trennlinie();

    do_while_beispiele();
    return 0;
}

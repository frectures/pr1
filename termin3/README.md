#### FAQ

##### Was passiert in skorbut, wenn man auf den START-Button drückt?

Das System sucht nach einer speziellen Funktion namens `main` und führt diese aus:

    int main()
    {
        printf("hello world!\n");
        return 0;
    }

##### Welchen Sinn hat das `\n` bei `printf`?

Damit generiert man einen Zeilenumbruch. Dieser kann überall innerhalb der Gänsefüßchen stehen, nicht nur am Ende:

    printf("one\ntwo\nthree\n\nI've come to collect the fee!\n");

##### Warum steht da `int` statt `void`, und was bedeutet `return 0;`?

Damit signalisiert die `main`-Funktion dem System, dass sie fehlerfrei durchgelaufen ist.
Im Rahmen von PR1 ist das aber nicht weiter relevant.
Wenn man versucht, einen anderen Typen als `int` zu verwenden oder das `return` vergisst,
gibt es entsprechende Warnungen oder Fehlermeldungen.

##### Wie schreibt man eine Funktion, die eine Ganzzahl entgegennimmt?

Dazu muss man in den runden Klammern hinter dem Funktionsnamen einen Parameter vom Typ `int` definieren:

                       // ----- Parameter von print_neighbours   
    void print_neighbours(int x)
    {       
        printf("%d liegt zwischen %d und %d\n", x, x-1, x+1);
    }       // -------------------------------  -  ---  --- Argumente an scanf

    int main()
    {
        print_neighbours(42);
        print_neighbours(97);
        print_neighbours( 0);
        return 0;     // -- Argument an print_neighbours
    }
    
Ein Parameter ist eine Art Platzhalter, der beim Aufruf der Funktion mit einem konkreten Wert befüllt wird.
Diesen konkreten Wert nennt man auch Argument.
In diesem Beispiel ist also `int x` der Parameter,
und `42` ist das entsprechende Argument beim ersten Aufruf der Funktion.

##### Welchen Sinn hat das `%d` bei `printf`?

Damit sagt man der Funktion `printf`, dass sie an der Stelle, wo das `%d` auftaucht,
eine ganze Zahl auf die Konsole schreiben soll, und zwar im Dezimalsystem.
Die entsprechende Zahl muss man als weiteres Argument übergeben.

Wie man beim Aufruf von `printf` sehr schön sieht, können Argumente nicht nur konstante Zahlen wie `42` sein,
sondern auch Variablen wie `x` oder Rechnungen wie `x-1` und `x+1`.

##### Kann man hinter das `%` auch etwas anderes schreiben als `d`?

Ja, für Kommazahlen (`float` oder `double`) gibt es zum Beispiel `%f`.

##### Was ist der Unterschied zwischen `float` und `double`?

`float` hat etwa 7 Stellen Genauigkeit und `double` etwa 16.
Dafür verbraucht `double` aber auch doppelt so viel Speicher wie `float`.
Im Rahmen von PR1 werden wir immer `double` verwenden, da es auf ein paar Bytes nicht ankommt :)

##### Wie liest man eine Ganzahl von der Konsole ein?

Dazu definiert man zunächst eine Variable, in welcher die Zahl später einmal landen soll:

    int a;

Dann sollte man einen sinnvollen Text auf die Konsole schreiben,
der dem Benutzer klar macht, dass er jetzt etwas eingeben soll,
aber rein technisch ist das natürlich nicht erforderlich:

    printf("Was ist ihre Lieblingszahl? ");

Und zuletzt ruft man die Funktion `scanf` auf:

    scanf("%d", &a);

##### Was bedeutet das `&` vor `a`?

Wenn das `&` dort nicht stehen würde, dann würden wir versuchen,
den aktuellen Wert von `a` an `scanf` zu übergeben,
aber in `a` steht ja noch gar kein sinnvoller Wert drin.
Stattdessen wollen wir `scanf` "die Variable an sich" übergeben,
damit `scanf` den eingelesenen Wert in der Variable `a` ablegen kann.
(Technisch wird die Speicheradresse der Variable `a` an `scanf` übergeben,
aber diesen Sachverhalt schauen wir uns erst in PR2 im Detail an.)

##### Wie liest man Kommazahlen von der Konsole ein?

Im Gegensatz zu `printf`, wo `%f` sowohl für `float` als auch für `double` steht,
unterscheidet `scanf` zwischen `float` (`%f`) und `double` (`%lf`).
Dafür gibt es technische Gründe, die aber im Rahmen von PR1 nicht relevant sind.

##### Wie schreibt man eine Funktion, die eine Ganzzahl liefert?

Genau so, wie `main` das auch macht, also mit `int` statt `void` und einem `return`:

    int average(int a, int b)
    {
        return (a + b) / 2;
    }

Im Gegensatz zu `void`-Funktionen sollte man `average` aber nicht "einfach so" aufrufen:

    average(10, 20);

Das System generiert eine entsprechende Warnung, weil es keinen Sinn macht,
den Durchschnitt von 10 und 20 zu berechnen und das Ergebnis (in diesem Fall 15) anschließend zu verwerfen.
Wir sollten irgendwas mit dem Ergebnis tun,
zum Beispiel in einer Variable speichern oder als Argument an eine Funktion übergeben,
ansonsten hätte der Computer den Durchschnitt ja ganz umsonst berechnet:

    int x = average(10, 20);

    printf("Die Antwort lautet %d\n", average(40, 44));

##### Wie prüft man, ob eine Variable einen bestimmten Wert hat?

    void pruefe_antwort(int x)
    {
        if (x == 42)
        {
            printf("Korrekt!\n");
        }
        else
        {
            printf("Daneben!\n");
        }
    }

##### Was ist der Unterschied zwischen `=` und `==`?

Diese beiden Operatoren werden so häufig von Anfängern verwechselt,
dass das System entsprechende Warnungen generiert.
`x == 42` prüft, ob in der Variable `x` die Zahl `42` gespeichert ist.
`x = 42` weist dagegen den Wert `42` an die Variable `x` zu,
d.h. `x` hat anschließend den Wert `42`, egal welcher Wert vorher in `x` gespeichert war.

##### Welche Vergleichsoperatoren gibt es sonst noch in C?

    a < b    kleiner
    a > b    größer
    a <= b   kleiner oder gleich
    a >= b   größer oder gleich
    a != b   ungleich

##### Wie kann man mehrere Bedingungen miteinander kombinieren?

Genau wie in Karel, mit `&&` (und) bzw. `||` (oder):

    if (0 <= x && x < 10)
    {
        printf("x besteht lediglich aus einer Ziffer!\n");
    }
    else
    {
        printf("x ist negativ und/oder besteht aus mehreren Ziffern!\n");
    }

    if (x == 2 || x == 3 || x == 5 || x == 7)
    {
        printf("x ist eine einstellige Primzahl!\n");
    }

#### Buchempfehlung

Nach intensiver Recherche scheint das für Anfänger am wenigsten schlecht geeignete Buch "Grundkurs C" von Jürgen Wolf zu sein. Folgende Kapitel empfehle ich für das Selbststudium zum Termin 3:

![](http://i.imgur.com/6AtJVE7.png)

![](http://i.imgur.com/XKV8Fuf.png)

![](http://i.imgur.com/1lzMbkO.png)

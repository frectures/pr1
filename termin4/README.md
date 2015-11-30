#### FAQ

##### Was bedeutet `#include <stdio.h>` und warum brauche ich das?

Mittels `#include` werden sog. Header-Dateien in die aktuelle `.c`-Datei eingebunden.
In der Header-Datei `stdio.h` werden Standard-Funktionen mitgeliefert,
die mit Ein- und Ausgabe zu tun haben, zum Beispiel `printf` und `scanf`.

So gut wie jedes C-Programm fängt mit `#include <stdio.h>` an,
weil das Programm ansonsten gar nicht mit dem Benutzer interagieren könnte.

(In skorbut sind Header-Dateien derzeit nicht realisiert, dort sind `printf` und `scanf` "magische" Funktionen.)

##### Welche anderen Standard-Header-Dateien gibt es sonst noch?

Im Rahmen von PR1 relevant:
```C
<math.h>
double sin(double x);
double cos(double x);
double tan(double x);
double sqrt(double x);
double floor(double x);
...

<stdio.h>
int printf(char format[], ...);
int scanf(char format[], ...);
int puts(char str[]);
int putchar(int character);
int getchar();
...

<stdlib.h>
void srand(unsigned seed);
int rand();
int abs(int x);
int system(char command[]);
void exit(int status);
...

<string.h>
unsigned strlen(char str[]);
void strcpy(char destination[], char source[]);
void strcat(char destination[], char source[]);
int strcmp(char str1[], char str2[]);
...

<time.h>
```
Im Rahmen von PR1 irrelevant:
```C
<assert.h>
<ctype.h>
<errno.h>
<float.h>
<limits.h>
<locale.h>
<setjmp.h>
<signal.h>
<stdarg.h>
<stddef.h>
```

##### Wie funktionieren `srand` und `rand`?

`srand` sollte einmalig zu Beginn des Programms aufgerufen werden und danach nie wieder.

Das Argument von `srand` legt fest, welche Zufallszahlen als nächstes von `rand` gezogen werden.
Wenn man `srand` mit einem festen Wert aufruft, zum Beispiel `srand(42)`,
dann wird bei jedem Programmstart dieselbe Zufallszahlen-Sequenz erzeugt.
(Wenn man `srand` gar nicht aufruft, dann ist das so, als hätte man `srand(0)` aufgerufen.)

Damit die Zufallszahlen bei jedem Programmstart anders sind, sollte man ein zeitabhängiges Argument an `srand` übergeben.
Dafür eignet sich z.B. die Standard-Funktion `time`, welche die Sekunden seit dem 1. Januar 1970 liefert.

Auf keinen Fall sollte man `srand` mehrfach aufrufen,
schon gar nicht innerhalb einer Schleife unmittelbar vor `rand`,
weil der Zufallszahlen-Generator ansonsten ständig zurückgesetzt werden würde,
d.h. `rand` würde immer (zumindest innerhalb einer Sekunde) denselben Wert liefern.

##### Wie sind `srand` und `rand` implementiert?

Mit einem linearen Kongruenzgenerator:
```C
unsigned random;

void srand(unsigned seed)
{
    random = seed;
}

int rand()
{
    random = random * 214013 + 2531011;   // Je nach Compiler andere Zahlen
    return (random << 1) >> 17;           // Zahl zwischen 0 und 32767
}
```
Die so generierten Pseudo-Zufallszahlen haben eine relativ schlechte Qualität
und sind für sicherheitskritische Anwendungen oder Physik-Simulationen völlig ungeeignet!

#### Buchempfehlung

Nach intensiver Recherche scheint das für Anfänger am wenigsten schlecht geeignete Buch "Grundkurs C" von Jürgen Wolf zu sein. Folgende Kapitel empfehle ich für das Selbststudium zum Termin 4:

![](http://i.imgur.com/Cag4XrN.png)

![](http://i.imgur.com/yhiCVrl.png)

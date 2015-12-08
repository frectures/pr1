#include <stdio.h>

char formel[100];
int index;

// Funktionsdeklarationen
int parseSum();
int parseProduct();
int parsePower();
int parseFactor();

// TODO
// 1 Mehrziffrige Zahlen
// 4 Potenzierung
// 1 Negative Zahlen

// Funktionsdefinitionen
int main()
{
    printf("Herzlich willkommen zum Rumrechnen!\n\n");
    while (1 <3)
    {
        printf("> ");
        scanf("%99s", formel);
        index = 0;
        int ergebnis = parseSum();
        if (formel[index] == 0)
        {
            printf("%d\n", ergebnis);
        }
        else
        {
            printf("expected operator but found %c\n", formel[index]);
        }
    }
    return 0;
}

int parseSum()
{
    int pro1 = parseProduct();
    while (formel[index] == '+' || formel[index] == '-')
    {
        char operator = formel[index];
        ++index;
        int pro2 = parseProduct();
        if (operator == '+')
        {
            pro1 = pro1 + pro2;
        }
        else
        {
            pro1 = pro1 - pro2;
        }
    }
    return pro1;
}

int parseProduct()
{
    int pow1 = parsePower();
    while (formel[index] == '*' || formel[index] == '/')
    {
        char operator = formel[index];
        ++index;
        int pow2 = parsePower();
        if (operator == '*')
        {
            pow1 = pow1 * pow2;
        }
        else
        {
            pow1 = pow1 / pow2;
        }
    }
    return pow1;
}

int power(int b, int e)
{
    int result = 1;
    int i;
    for (i = 0; i < e; ++i)
    {
        result = result * b;
    }
    return result;
}

int parsePower()
{
    int base = parseFactor();
    while (formel[index] == '^')
    {
        ++index;
        int exponent = parseFactor();
        base = power(base, exponent);
    }
    return base;
}

int parseFactor()
{
    if (formel[index] >= '0' && formel[index] <= '9')
    {
        return formel[index++] - '0';
    }
    else if (formel[index] == '(')
    {
        ++index; // eat (
        int temp = parseSum();
        if (formel[index] == ')')
        {
            ++index; // eat )
            return temp;
        }
        else
        {
            printf("expected ) but found %c\n", formel[index]);
        }
    }
    else
    {
        printf("expected digit but found %c\n", formel[index]);
    }
}

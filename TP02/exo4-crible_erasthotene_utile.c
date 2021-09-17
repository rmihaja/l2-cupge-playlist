#include <stdio.h>
#define TAILLE 100000

int crible(int *t)
{
    t[0] = 0;
    t[1] = 0;

    for (int i = 2; i < TAILLE; i++)
    {
        t[i] = 1;
    }

    for (int i = 0; i < TAILLE; i++)
    {
        if (t[i] == 1)
        {
            // i est un nombre premier
            t[i] = i;
            for (int j = 2; j * i < TAILLE; j++)
            {
                // nous avons les multiples de i : i * j
                t[i * j] = j;
            }
        }
    }
    return 0;
}

// void criblef(int crible, int entier)
// {
// }

int main()
{
    int t[TAILLE];
    if (crible(t) != 0)
        return 307;

    while (1) // ? il n'y a pas de wkeyword true en C
    {
        int entier;
        printf("Veuillez entrer un entier : ");
        scanf("%d", &entier);
        if (entier < 0)
            break;
        else if (entier >= TAILLE)
            continue;
        else
            printf("L'entier est-il premier ? %d\n", t[entier]);
    }

    return 0;
}
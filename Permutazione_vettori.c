#include <stdio.h>
#include <stdbool.h>
#define N 5

void ordinamento(int v[N])
{
    int app, z;

    for(z = 0; z < N; z++)
    {
        if(v[z+1] < v[z])
        {
            app = v[z+1];
            v[z+1] = v[z];
            v[z] = app;
        }

    }
}

void stampa(int vect[N])
{
    int i;

    printf ("\n\tInserire i %d valori delle celle del vettore ---> ", N);
    
    for(i = 0; i < N; i++)
    {
        scanf("%d", &vect[i]);
    }
}

bool check(int v1[N], int v2[N])
{
    int i;
    bool perm = true;

    for(i = 0;i < N; i++)
    {
        if(v2[i] != v1[i])
        {
            perm = false;
        }
    }

    return perm;
}

int main (void)
{
    int vect1[N], vect2[N], i;
    bool permutazione;

    stampa(vect1);
    stampa(vect2);

    ordinamento(vect1);
    ordinamento(vect2);

    permutazione = check(vect1, vect2);

    if(permutazione != false)
    {
        printf("Il secondo vettore è una permutazione del primo");
    }else
    {
        printf("Il secondo vettore è una permutazione del primo");
    }

    return 0;
}
#include <stdio.h>
#define N 4
//array dedicato al numero di frazioni di cui si vorrà fare la somma
#define M 1
//array dedicato alla cella in cui verrà riportata la somma (per evitare di richiamare o aggiungere inutili funzioni)
//NON MODIFICARE M!!!

typedef struct
{
    int numeratore[N];
    int denominatore[N];
    int mcm[M];
    int somma[M];
}frazione;

int ins(int k)
{
    int num, den;

    if(k == 0)
    {
        printf("\n\tInserire il numeratore della frazione --->  ");
        scanf("%d", &num);
        return num;
    }else
    {
        printf("\n\tInserire il denominatore della frazione --->  ");
        scanf("%d", &den);
        return den;
    }
}

int massimo(int den[N])
{
    int i, maxi;
    //variabile massimo per tenere traccia del massimo tra i diversi denominatori

    maxi = den[0];

    for(i = 1; i < N; i++)
    {
        if(den[i] > maxi)
        {
            maxi = den[i];
        }
    }
    return maxi;
}

void somma(int num[N], int den[N], int som[M], int mcm1[M], int max)
{
    int res, rest = 1, j, k, ntent;
    //ntent rappresenta il numero massimo a cui sarà uguale il divisore comune

    ntent = den[0];

    for(j = 1; j < N; j++)
    {
        ntent *= den[j];
    }

    for(j = 1; (j <= (ntent/max))&&(rest != 0);j++)  //ntent/max in modo che arrivo a un j massimo uguale al prodotto di tutti i 
    {                                               //denominatori eccetto per il loro massimo (dato che più avanti lo moltiplicherò comunque)
        rest = 0;
        for(k = 0; k < N; k++)
        {
            mcm1[0] = j*max;
            rest += ((j*max) % (den[k]));
        }
    }

    for(j = 0; j < N; j++)
    {
        res = mcm1[0]/den[j];
        som[0] += res*num[j];
    }

}

int minore(int som[M], int mcm1[M])
{
    int s, m;
    //s ed m sostituiscono som e mcm1 dato che andrei a modificarne il segno se agissi su di loro,
    // per conservarne il segno uso quindi due variabili appoggio

    if(som[0] < 0)
    {
        s = som[0]*(-1);
    }

    if(mcm1[0] < 0)
    {
        m = mcm1[0]*(-1);
    }

    if(s < m)
    {
        return som[0];
    }else 
    {
        return mcm1[0];
    }
}

void semplificazione(int som[M], int mcm1[M], int min)
{
    int j, rest1, rest2;

    for(j = 2 + (min/2); j >= 2; j--)
    {   
        rest1 = som[0] % j;
        rest2 = mcm1[0] % j;

        if((rest1 == 0)&&(rest2 == 0))
        {
            som[0] = som[0] / j;
            mcm1[0] = mcm1[0] / j;
        }
    }
}

char segno(int som[M], int mcm1[M])
{
    char s;
    //segno

    if((mcm1[0] < 0)&&(som[0] < 0))
    {
        mcm1[0] = mcm1[0] * (-1);
        som[0] = som[0] * (-1);
        s = '+';
    }else if((mcm1[0] > 0)&&(som[0] > 0))
    {
        s = '+';
    }else if((mcm1[0] < 0)&&(som[0] > 0))
    {
        mcm1[0] = mcm1[0] * (-1);
        s = '-';
    }else
    {
        som[0] = som[0] * (-1);
        s = '-';
    }
    return s;
}

int main (void)
{
    int i, minor, mass;
    //minor = minore, mass = massimo
    char segno1;
    frazione f;

    for(i = 0; i < N; i++)
    {
        f.numeratore[i] = ins(0);
        f.denominatore[i] = ins(1);
    }

    mass = massimo(f.denominatore);

    somma(f.numeratore, f.denominatore, f.somma, f.mcm, mass);

    minor = minore(f.somma, f.mcm);
    
    semplificazione(f.somma, f.mcm, minor);

    segno1 = segno(f.somma, f.mcm);

    if(f.mcm[0] != 1)
    {
        printf("\n\n\tLa somma delle frazioni è --> %c %d/%d ", segno1, f.somma[0], f.mcm[0]);
        printf("\n\n");
    }else
    {
        printf("\n\n\tLa somma delle frazioni è --> %c %d ", segno1, f.somma[0]);
        printf("\n\n");
    }

    return 0;
}

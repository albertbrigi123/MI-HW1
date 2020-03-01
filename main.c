#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//iranyok amerre a huszar lephet
int x[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int y[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

int counter;
void kiir(int**,int);
int biztonsagos(int, int, int**,int );
void megold();
void elso(int**,int);
void masodik(int**,int);
void harmadik(int**,int);
bool nyersBacktracking(int,int,int,int**,int);

int main()
{
    megold();
    return 0;
}

void kiir(int**a,int n)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            printf("%d " ,a[i][j]);
        }
    printf("\n");
    }
}

void megold()
{
    int n,opcio;
    printf("n = ");
    scanf("%i",&n);
    printf("Opciok:\n1 - nyers backtracking\n2 - backtracking + MVR + forward checking\n3 - backtracking + MVR + AC-3\nValasszon opciot: ");
    scanf("%i",&opcio);
    int **a;
    a=(int**)calloc(n,sizeof(int*));
    if(a==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    for(int i=0; i<n; ++i)
    {
        a[i]=(int*)calloc(n,sizeof(int));
        if(a[i]==NULL)
        {
            printf("Sikertelen dinamikus helyfoglalas");
        }
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            a[i][j]=-1;
        }
    }
    a[0][0]=0;
    switch(opcio)
    {
        case 1: elso(a,n);break;
        //case 2: masodik(a,n);break;
        //case 3: harmadik(a,n);break;
        default: printf("Helytelen opcio!");break;

    }

}


void elso(int**a,int n)
{
    printf("Nyers Backtrackging:\n");
    counter=0;
    if(nyersBacktracking(0,0,1,a,n)==false)
    {
        printf("Nincs megoldas");
    }
    else
    {
        kiir(a,n);
        printf("\nCounter: %i",counter);
    }
}

void masodik(int**a,int n)
{
    printf("Backtracking + MVR + forward checking");
    counter=0;
}

void harmadik(int**a,int n)
{
    printf("Backtracking + MVR + AC-3");
    counter=0;
}



bool nyersBacktracking(int i,int j,int k,int**a,int n)
{

    int kovX,kovY;
    //minden mezot bejart
    if(k==n*n)
    {
        return true;
    }
    for(int w=0; w<8; ++w)
    {
        kovX=i+x[w];
        kovY=j+y[w];
        //tud oda lepni(rajta van a sakktablan)
        if(biztonsagos(kovX,kovY,a,n))
        {
            a[kovX][kovY]=k;
            counter++;
            if(nyersBacktracking(kovX,kovY,k+1,a,n)==true)
                return true;
            else
                //ha nem vezet megoldashoz akkor visszalep
                a[kovX][kovY]=-1;
        }
    }
    return false;
}

/*void backtracking_forward_checking(int i,int j,int k,int**a,int n)
{

    int kovX,kovY;
    int
    //minden mezot bejart
    if(k==n*n)
    {
        return true;
    }
    for(int w=0; w<8; ++w)
    {
        kovX=i+x[w];
        kovY=j+y[w];
        //tud oda lepni(rajta van a sakktablan)
        if(biztonsagos(kovX,kovY,a,n))
        {
            a[kovX][kovY]=k;
            counter++;
            tomb=forward_checking(i,j,k,a,n);
            if(nyersBacktracking(kovX,kovY,k+1,a,n)==true)
                return true;
            else
                //ha nem vezet megoldashoz akkor visszalep
                a[kovX][kovY]=-1;
        }
    }
    return false;

}*/




int biztonsagos(int i, int j, int**a,int n)
{
    return ( i >= 0 && i < n && j >= 0 &&
             j < n && a[i][j] == -1);
}


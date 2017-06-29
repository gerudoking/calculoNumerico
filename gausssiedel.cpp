#include<stdio.h>
#include<math.h>
#define X 2   //Controla o tamanho da matriz
int main()
{
    float x[X][X+1],a[X], Be, maximo,t,s;
    int i,j,r,iteracoes;
    for(i=0;i<X;i++) a[i]=0;
    puts(" Digite os elementos da matriz na ordem que aparecem nas linhas (ex a1 b1 resultado1 a2 b2 resultado2\n");
    for(i=0;i<X;i++)
    {
    for(j=0;j<X+1;j++)
    {
    scanf("%f",&x[i][j]);
    }
    }
    printf(" Digite o erro maximoimo e o numero maximoimo de iteracoes permitidas com um espaco entre eles: ");
    scanf("%f%d",&Be,&iteracoes
);
    printf("Iteracao\tx[1]\tx[2]\n"); //Se a matriz aumentar adicionar tx[3], tx[4] e por ai vai
    for(r=1;r<=iteracoes
;r++)
    {
        maximo=0;
        for(i=0;i<X;i++)
        {
            s=0;
            for(j=0;j<X;j++)
            if(j!=i) s+=x[i][j]*a[j];
            t=(x[i][X]-s)/x[i][i];
            
            a[i]=t;
        }
        printf(" %5d\t",r);
        for(i=0;i<X;i++)
        printf(" %9.4f\t",a[i]);
        printf("\n");
        if(maximo<Be)
        {
            printf(" Converge em %3d iteracoes\n", r);
            for(i=0;i<X;i++)
            printf("a[%3d]=%7.4f\n", i+1,a[i]);
            return 0;
        }
 
        }
    }
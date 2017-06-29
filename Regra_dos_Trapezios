#include <stdio.h>
#include <math.h>
#define PI (3.141592653589793)

/* FUNCOES */
float RegraTrapezio(float pts, int opc){
     float total;
     /* FUNCAO 'a' */
     if (opc == 1){
         total = (pow(pts, 2) * log(pts));
     /* FUNCAO 'b' */
     } else if (opc ==2){
         total = (pow(pts, 2) * sin(pts));
     /* FUNCAO 'c' */
     } else {
        total = (pow(pts,3)) /  (sqrt(pow(pts,4) + 1));
     }
    return total;
}

int main(){

    float a,b,h,pts,total=0;
    int m,opc,i;

    /* SELECIONANDO A FUNCAO */
    do{
        printf("Escolha o nro que corresponda a letra da fcao desejada.:\n");
        printf("1. Letra a\n2. Letra b\n3. Letra c\n-> ");
        scanf("%d", &opc);
    }while(opc != 1 && opc != 2 && opc != 3 && opc!= 0);

    if(opc == 1){
        a = 1;
        b = 3;
        pts = a;
    } else if(opc == 2){
        a = 0;
        b = PI;
        pts = a;
    } else if(opc==3) {
        a = 2;
        b = 3;
        pts = a;
    }

    m=16;
    for(i=0; i<2; i++){
        h= (b-a)/m;

        total += RegraTrapezio(pts, opc);
        pts += h;
        while(pts < b){
            total += (RegraTrapezio(pts, opc))*2;
            pts += h;
        }

        RegraTrapezio(pts, opc);
        total += RegraTrapezio(pts, opc);
        printf("Aproximacao com m= %d %f\n", m, total*(h/2));
        m=32;
        pts=a;
        total=0;
    }


return 0;
}

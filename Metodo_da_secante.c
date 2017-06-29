#include <stdio.h>
#include <math.h>

double F(float x){
	return 1;// <-- digite a funcao aqui
}

double Secant_Method(double x0, x1){
	return x1 - (((x1 - x0)*F(x1))/(F(x1) - F(x0)))
}

int main(){
	int cont = 0;
	double intervalo1, intervalo2;
	double x0, x1, x2;
	printf("Digite o intervalo da funcao: ");
	scanf("%d %d", &intervalo1, &intervalo2);
	printf("Digite o valor de x1 e x2: ");
	scanf("%d %d", &x0, &x1);
	while(1){
		cont++;
		printf("Interacao %d\n\n", cont);
		x2 = Secant_Method(x0, x1);
		printf("x%d = %d\n\n", cont+1, x2);
		x0 = x1;
		x1 = x2;
		getchar();
		getchar();
	}
	return(0);
}

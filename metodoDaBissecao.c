/*
Implementado por Eduardo de Azevedo dos Santos

13/03/2017
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


float resultadoFuncao(float x){
	float resultado;

	resultado = sqrt(x);

	return resultado;
}

float metodoDaBissecao(/*char* funcao,*/ float a, float b, float tol, int nmax){
	int n = 0;
	float c;

	while(n <= nmax){
		c = (a + b)/2;

		if((resultadoFuncao(c) == 0) || ((b - a)/2 < tol)){
			printf("Sao necessarias %d iteracoes\n", n+1);
			return c;
		}

		n++;
		if(c*a > 0){
			printf("a = c, a era %f, agora eh %f\n", a, c);
			a = c;
		}
		else{
			printf("b = c, b era %f, agora eh %f\n", b, c);
			printf("%f\n", a);
			b = c;
		}
	}

	printf("%d\n", n);

	return -99;//Raiz não encontrada
}

int main(){
	float a, b, tol, resultado;
	int nmax;

	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &tol);
	scanf("%d", &nmax);

	resultado = metodoDaBissecao(a, b, tol, nmax);
	printf("\nc eh %f\n", resultado);

	return 0;
}
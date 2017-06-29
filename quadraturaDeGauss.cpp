#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

float resultadoDaFuncao(float x){
	float resultado;
	resultado = 1/(x + 3);//insira a função a ser processada nesta linha

	printf("%f\n", resultado);

	return resultado;
}

float quadraturaDeGauss(int n){
	const float X0N2 = -0.55735;
	const float X1N2 = 0.55735;
	const float A0N2 = 1;

	const float X0N3 = -0.7746;
	const float X1N3 = 0;
	const float X2N3 = 0.7746;
	const float A0N3 = 0.5556;
	const float A1N3 = 0.8889;

	float valor = 0;
	
	if(n == 2)
		valor += A0N2 * resultadoDaFuncao(X0N2) + A0N2 * resultadoDaFuncao(X1N2);
	else if(n == 3)
		valor += A0N3 * resultadoDaFuncao(X0N3) + A1N3 * resultadoDaFuncao(X1N3) + A0N3 * resultadoDaFuncao(X2N3);

	return valor;
}

int main(){
	int n;

	scanf("%d", &n);

	printf("\nO resultado da integracao numerica da funcao eh: %f\n", quadraturaDeGauss(n));

	return 0;
}
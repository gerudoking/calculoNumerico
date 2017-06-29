#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

float resultadoDaFuncao(float x){
	float resultado;
	resultado = exp(x) * cos(x);//insira a função a ser processada nesta linha

	printf("%f\n", resultado);

	return resultado;
}

float calculaH(float a, float b, int n){
	return (b - a)/n;
}

std::vector<float>* calculaX(float a, float b, int n){
	float parcela = 0;
	float resultado = 0;
	std::vector<float>* vetorDeX = new std::vector<float>;

	parcela = calculaH(a, b, n);

	for(int i = 0; i <= n; i++){
		printf("%f\n", resultado);
		vetorDeX->emplace_back(resultado);
		resultado += parcela;
	}

	return vetorDeX;
}

float umTercoDeSimpson(float a, float b, int n){
	float valor = 0;
	float altura = calculaH(a, b, n);
	std::vector<float>* vetorDeX = calculaX(a, b, n);
	float temporary;

	temporary = vetorDeX->at(0);
	valor += resultadoDaFuncao(temporary);

	for(int i = 1; i <= n/2 - 1; i++){
		temporary = vetorDeX->at(2*i);
		valor += 2 * resultadoDaFuncao(temporary);
	}

	for(int i = 1; i <= n/2; i++){
		temporary = vetorDeX->at(2*i - 1);
		valor += 4 * resultadoDaFuncao(temporary);
	}

	temporary = vetorDeX->at(n);
	valor += resultadoDaFuncao(temporary);

	valor = valor * altura/3;

	return valor;
}

int main(){
	float a, b;
	int n;

	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%d", &n);

	printf("\nO resultado da integracao numerica da funcao eh: %f\n", umTercoDeSimpson(a, b, n));

	return 0;
}
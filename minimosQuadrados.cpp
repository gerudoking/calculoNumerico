#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

pair<float, float>* minimosQuadrados(vector<float>* x, vector<float>* y, int n){
	float a0 = 0, a1 = 0;
	float xi = 0, xi2 = 0, yi = 0, xiyi = 0; 

	for(int i = 0; i < n; i++){
		xi2 += x->at(i) * x->at(i);
		yi += y->at(i);
		xiyi += x->at(i) * y->at(i);
		xi += x->at(i);
	}

	a0 = (xi2*yi - xiyi*xi)/(n*xi2 - xi*xi);

	a1 = (n*xiyi - xi*yi)/(n*xi2 - xi*xi);

	pair<float, float>* par = new pair<float, float>(a0, a1);

	return par;
}

int main(){
	pair<float, float>* par;
	vector<float> x, y;
	float temp1, temp2;
	int n;

	printf("Digite quantos sao os pares X Y:\n");
	scanf("%d", &n);

	printf("Digite o valor dos pares X Y:\n");
	for(int i = 0; i < n; i++){
		scanf("%f %f", &temp1, &temp2);
		x.emplace_back(temp1);
		y.emplace_back(temp2);
	}

	par = minimosQuadrados(&x, &y, n);

	printf("A funcao resultante do metodo eh: y = %f + %fx\n", par->first, par->second);

	delete par;
	return 0;
}
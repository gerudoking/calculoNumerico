#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

int main(){
	stringstream ss;
	int a=3/*mudar esse valor para a quantidade de pontos*/, i=0, j=0;
 	const int max=30;
 	float f[max][max];
	float p[max][max];

	for (i=0;i<(max-1);i++)
 		for (j=0; j<(max-1); j++)
 			p[i][j]= -999;
 	for (i=0;i<2;i++)
 		for (j=0; j<(max-1); j++)
 			f[i][j]= -999;

 	cout << "\nFazendo a leitura dos dados.";
 	cout << "\nInforme primeiro o valor para 'x' " << "e em seguida o correspondente em 'y'.\n";
 	int n = a;
 	for (i=0;i<n;i++)
 	{
 		cout<< "valor X["<<i<<"] = ";
 		scanf("%f", &f[0][i]);
 		cout<< "valor Y["<<i<<"] = ";
	 	scanf("%f", &f[1][i]);
 	}

 	for (i=0;i<n;i++)
 		p[i][0] = f[1][i];
 	int ordem=0, linha=a, aux=0;
 	for (ordem=1;ordem<a;ordem++)
 	{
 		linha--;
 		aux=ordem;
 		for (j=0;j<linha;j++)
 		{
			p[j][ordem]=(p[j+1][ordem-1]-p[j][ordem-1])/(f[0][aux]-f[0][j]);
 			aux++;
 		}
 	}

 	cout<<"\nTabela de diferencas divididas:";
 	for (j=0; j<5; j++)
 		for (i=0; i<8; i++)
 			if (p[i][j] != -999)
 				cout << "\nOrdem["<<j<<"] linha["<<i<<"] valor: " <<p[i][j];

 	/*cout<<"\n\nPolinomio de Newton:\n";
 	string s;
 	string str1 = " ", str2 = "";
 	for (ordem=0; ordem<a-1;ordem++)
 	{
 		str1="";
 		for (i=0; i<ordem+1;i++)
 		{
 			if (f[0][i]>=0){
 				ss << f[0][i];
	 			str1 = str1 + "(x - " + ss.str() + ")";
	 		}
 			else{
 				ss << f[0][i]*-1;
 				str1 = str1 + "(x+" + ss.str() + ")";
 			}
 		}
 		ss << p[0][ordem+1];
 		str2 = str2 + str1 + "("+ss.str() + ")";
 		if (ordem<a-2)
 		str2 = str2 + " + ";
 	}
 	ss << p[0][0];
 	s = ss.str() + " + " + str2;
 	cout<<"p(x) = " + s;*/
 	
 	return 0;   
}
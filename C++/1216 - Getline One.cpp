#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	int cont=0;
	double acumulador=0, entrada;
	char nome[500];
	
	cout << fixed;
	cout.precision(1);
	
	while(gets(nome)){
		
		scanf("%lf", &entrada);
		getchar();
		acumulador += entrada;
		cont++;
		
	}
	
	entrada = acumulador/cont;
	cout << entrada << endl;
	
	return 0;
}
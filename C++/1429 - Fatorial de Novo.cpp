#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

long long fatorial(long numero){
	
	long aux;
	aux = numero;
	
	while(numero > 1){
		
		aux = aux * (numero-1);
		numero--;
	}
	return aux;
}

int main(){
	
	string entrada;
	long long tam, result, fat, temp;
	
	while(cin >> entrada){
		
		if(entrada == "0"){
			break;
		}
		result = 0;
		tam = entrada.size();
		reverse(entrada.begin(), entrada.end());
		for(int i=tam;i>0;i--){
			fat = 1;				
			temp = entrada[i-1]-'0';
			result +=  temp * fatorial(i);									
		}
		cout << result << endl;
	}
	
	return 0;
}
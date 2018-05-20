#include <iostream>
#include <sstream>
using namespace std;



bool verificaNumIguais(string numero){
	//cout << numero << endl;
	//cout << numero.size() << endl;
	if(numero.size() == 1){
		//cout << "TAMANHO 1" << endl;
		return true;	
	} 
	
	if(numero.size() == 2 && numero[0] != numero[1]){
		//cout << "TAMANHO 2 DIFERENTES" << endl;
		return true;	
	}else{
		if(numero.size() == 2 && numero[0] == numero[1]){
		//	cout << "TAMANHO 2 IGUAIS" << endl;
			return false;		
		}
	} 
	
	if(numero.size() == 3){
		if(numero[0] == numero[1] || numero[0] == numero[2] || numero[1] == numero[2]){
		//	cout << "TAMANHO 3 IGUAIS" << endl;
			return false;
		}else{
		//	cout << "TAMANHO 3 DIFERENTES" << endl;
			return true;
		}
	}	
	
	if(numero.size()==4){
		
		if(numero[0] == numero[1] || numero[0] == numero[2] || numero[0] == numero[3] || numero[1] == numero[2] || numero[1] == numero[3] || numero[2] == numero[3]){
		//	cout << "TAMANHO 4 IGUAIS" << endl;
			return false;
		}else{
		//	cout << "TAMANHO 4 DIFERENTES" << endl;
			return true;
		}
		
	}
	
}


int main(){
	
	int a, b, cont;
	
	string temp;
	while(cin >> a >> b){
		cont=0;
		int temp1=a;
		
		for(int i=a;i<=b;i++){
			ostringstream convert;
			convert << i;
			temp = convert.str();
			if(verificaNumIguais(temp)) cont++;
												
		}
		
		cout << cont << endl;
		
	}
	
	return 0;
}
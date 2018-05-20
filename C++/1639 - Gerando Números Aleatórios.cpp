#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

int casasDecimais(int num){
	int qunt=1;
	
	while((num = num/10) > 0){
		qunt++;
	}
	
	return qunt;
	
}

int main(){
	
	vector<int> gerador;
	int entrada, cont,k;
	string temp, vals;
	bool teste;
	while(cin >> entrada){
		if(entrada == 0){
			break;
		}		
		cont=0;
		gerador.clear();
		teste = false;
		while(teste == false){
			
			for(k=0;k<gerador.size();k++){
				if(entrada == gerador[k]){
					cout << cont << endl;
					teste = true;
				}								
			}
			if(k == gerador.size()){
				gerador.push_back(entrada);
				cont++;
			}
			
			temp.clear();
			vals.clear();
			entrada *= entrada;
			
			if(casasDecimais(entrada) < 8){
				
				ostringstream convert;
				convert << entrada;
				temp = convert.str();
				for(int i=0;i<8-casasDecimais(entrada);i++){ //Adiciona os Zeros no inicio de uma string
					vals.push_back('0');
				}	
				for(int i=0;i<temp.size();i++){//adiciona o restando dos numeros na frente dos zeros anteriores
					vals.push_back(temp[i]);
				}
				temp.clear();
				
				for(int i=2;i<6;i++){//pega os numeros do meio
					temp.push_back(vals[i]);	
				}			
				
				entrada = atoi(temp.c_str());
							
			}else{
				
				ostringstream convert;
				convert << entrada;
				vals = convert.str();
				for(int i=2;i<6;i++){//pega os numeros do meio
					temp.push_back(vals[i]);	
				}	
				entrada = atoi(temp.c_str());	
			
			}
			
			
		}
	}
	
	return 0;
}
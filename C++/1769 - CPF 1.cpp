#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	char cpf[14];
	int quant, acumula=0, acumula2=0;
	int converte, aa = 10, bb = 0, divi1, divi2;

	
	while(cin >> cpf){
		
		for(int j=0;j<11;j++){
			
			if(cpf[j] != '.'){	
				converte = cpf[j] - '0';
				bb++;
			    acumula += converte * (bb);
			}	
		}
		
		for(int j=0;j<11;j++){
			
			if(cpf[j] != '.'){	
				converte = cpf[j] - '0';
				aa--;
				acumula2 += converte * (aa);
			}
		}
		
		divi1 = acumula%11;
		if(divi1 == 10){
			divi1 = 0;
		}
		
		divi2 = acumula2%11;
		if(divi2 == 10){
			divi2 = 0;
		}
		
		if((divi1 == (cpf[12] - '0')) && (divi2 == (cpf[13] - '0'))){
			cout << "CPF valido" << endl;
		}else{
			cout << "CPF invalido" << endl;
		}
		
		acumula = 0;
		acumula2 = 0;
		aa = 10;
		bb = 0;
		
	}
	
	return 0;
}
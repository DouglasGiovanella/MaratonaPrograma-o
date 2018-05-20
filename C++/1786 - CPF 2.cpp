#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	char cpf[9], cpfSaida[14];
	int quant, acumula=0, acumula2=0;
	int converte, aa = 10, bb = 0, divi1, divi2;
	
	
	while(cin >> cpf){
		
		for(int j=0;j<9;j++){
			
			converte = cpf[j] - '0';
			bb++;
			acumula += converte * (bb);
				
		}
		
		for(int j=0;j<9;j++){
			
			converte = cpf[j] - '0';
			aa--;
			acumula2 += converte * (aa);
			
		}
		
		divi1 = acumula%11;
		if(divi1 == 10){
			divi1 = 0;
		}
		
		divi2 = acumula2%11;
		if(divi2 == 10){
			divi2 = 0;
		}
		
		
		for(int i=0; i<14;i++){
			
			if(i == 3 || i == 6){
				cout << ".";			
			}
			if(i == 11){
				cout << "-";
			}
			
			if(i== 12){
				cout << divi1;
			}
			if(i== 13){
				cout << divi2;
			}
			if(i<9 && (i != 3 || i != 7 || i != 11 ||i != 12 || i != 13)){
				cout << cpf[i];	
			}
			
		}
		 
		cout << endl; 

		acumula = 0;
		acumula2 = 0;
		aa = 10;
		bb = 0;
		
	}
	
	return 0;
}
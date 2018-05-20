#include <iostream>
#include <cstdlib>
using namespace std;


int main(){
	
	int numpares, numfem, nummasc,cont=0;
	string linha, numbusca;
	
	
	while(cin >> numbusca){
		if(cont != 0){
			cout << endl;
		}
		
		getchar();
		getline(cin, linha);
		
		numpares=0;
		numfem=0;
		nummasc=0;
		
		for(int k=0;k<linha.size();k++){
			
			if(linha[k] ==  numbusca[0] && linha[k+1] == numbusca[1]){
				numpares++;
			}
			
			if((linha[k] ==  numbusca[0] && linha[k+1] == numbusca[1]) && linha[k+3] == 'M'){
				nummasc++;
			}
			if((linha[k] ==  numbusca[0] && linha[k+1] == numbusca[1]) && linha[k+3] == 'F'){
				numfem++;
			}
		}
	
		
		
		cout << "Caso " << cont+1 << ":" << endl;
		cout << "Pares Iguais: " << numpares << endl;
		cout << "F: " << numfem << endl;
		cout << "M: " << nummasc << endl;
		
		cont++;
		
	}
	
	
	return 0;
}
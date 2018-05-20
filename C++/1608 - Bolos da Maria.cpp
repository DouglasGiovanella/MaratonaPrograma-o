#include <iostream>
#include <vector>

using namespace std;

int quntMaxima(int a, int b){
	
	//b = Quantidade de dinheiro que possui
	//a = Maximo que pode ir
	int result=0, qunt=0;
	if(a > b){
		return 0;
	}else{
		while(1){
			if(result > b){
				qunt--;
				return qunt;
				break;
			}else{
				result += a;
				qunt++;	
			}
				
		}	
	}
	
		
}

int main(){
         
    int casos, dinheiro, numIng, quntBolo, temp, quntIng, indice, qunt, valbolo;
	vector<int> precos, valbolos;
	int maiorqunt;
	
	cin >> casos;
	
	for(int i=0;i<casos;i++){
		
		maiorqunt=0;
		cin >> dinheiro >> numIng >> quntBolo;
		precos.clear();
		valbolos.clear();
		for(int j=0;j<numIng;j++){
			cin >> temp;
			precos.push_back(temp);
		}
		
		
		
		for(int k=0;k<quntBolo;k++){
			cin >> quntIng;	
			valbolo=0;
		
			for(int j=0;j<quntIng;j++){	
				cin >> indice >> qunt;
				valbolo+= precos[indice]*qunt;
			}
			valbolos.push_back(valbolo);
		
		}
		
		for(int j=0;j<valbolos.size();j++){
		
			if( (quntMaxima(valbolos[j],dinheiro)) > maiorqunt){
				maiorqunt = quntMaxima(valbolos[j],dinheiro);
			}
			
		}
		
		cout << maiorqunt << endl;
	}   

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int casos, andares, pessoas, capacidade_elevador;
	int temp, consumo_energia;
	vector<int> andares_ir;
	
	cin >> casos;
	
	for(int i=0;i<casos;i++){
		
		cin >> andares >> capacidade_elevador >> pessoas;
		
		consumo_energia=0;
		andares_ir.clear();
		
		for(int j=0;j<pessoas;j++){
			cin >> temp;
			andares_ir.push_back(temp);
		}
		
		sort(andares_ir.begin(), andares_ir.end());
		reverse(andares_ir.begin(), andares_ir.end());
		
	
		if(pessoas <= capacidade_elevador){
			consumo_energia+=andares_ir[0]*2;
			//vai em uma viagem so, parando nos andares;				
		}else{
			//mais de uma viagem, tendo que voltar ao andar 0 para buscar o resto das pessoas;
			while(andares_ir.size()!=0){
				
				if(andares_ir.size() > capacidade_elevador){
					consumo_energia+=andares_ir[0]*2;	
					andares_ir.erase(andares_ir.begin(), andares_ir.begin()+capacidade_elevador);		
				}else{
					consumo_energia+=andares_ir[0]*2;
					andares_ir.clear();
				}

						
			}

		}
	
		cout << consumo_energia << endl;
		
	}
	
	
	return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	//comp = comprimento estacionamento
	int comp, eventos, placa, compcarro;
	int cont=0, posicao;
	int saldo=0;
	char tipo[1];
	vector<int> vetorPlaca, vetorComp, vetorPosicao;

	while(cin >> comp >> eventos){
		
		char comprEst[comp+1];
		
		for(int j=0;j<comp;j++){
			comprEst[j] = 'E';	
		}
		comprEst[comp] = '\0';
		
		for(int i=0;i<eventos; i++){
			scanf(" ");
			cin >> tipo[0] >> placa;
		
			
			if(tipo[0] == 'C'){
					
				cin >> compcarro;
				
				for(int j=0;j<comp;j++){
					if(comprEst[j] == 'E'){
						if(cont == 0){
							posicao=j;	
						}	
						cont++;	
						if(cont == compcarro){
							vetorPlaca.push_back(placa);
							vetorComp.push_back(compcarro);
							vetorPosicao.push_back(posicao);
							saldo += 10;
							for(int k=posicao;k<=(posicao+(cont-1));k++){
								comprEst[k] = 'X';
							}
					
							break;
						}	
					}else{
						cont =0;
					}	
				}
				
				
			}else{
				
				for(int t=0;t<vetorPlaca.size();t++){
					if(vetorPlaca[t] == placa){
						
						for(int h=vetorPosicao[t];h<=(vetorPosicao[t]+(vetorComp[t]-1));h++){
							comprEst[h] = 'E';
						}
				
						vetorPlaca[t]=0;
						vetorComp[t]=0;
						vetorPosicao[t]=0;
						
					}				
					
				}
				
			}
			cont = 0;
			compcarro =0;	
		}
		cout << saldo << endl;
		vetorPlaca.clear();
		vetorComp.clear();
		vetorPosicao.clear();
		saldo = 0;
	}
		
	
	return 0;
}
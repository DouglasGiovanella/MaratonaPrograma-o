#include <iostream>
#include <vector>

using namespace std;

int main(){
    int amostras, h, picos;
    vector <int> notas;

    while (cin >> amostras) {
        
        if(amostras == 0){
        	break;	
		} 

        notas.clear();
        for(int i=0;i<amostras;i++) {
            cin >> h;
            notas.push_back(h);
        }

        picos = 0;
        if(notas[amostras - 1] > notas[0] && notas[1] > notas[0]){
        	picos++;
		}else{
			if(notas[amostras - 1] < notas[0] && notas[1] < notas[0]){
				picos++;	
			}
		}
        if(notas[amostras-2] > notas[amostras-1] && notas[0]>notas[amostras-1]){
        	picos++;
		}else{
			if(notas[amostras-2] < notas[amostras-1] && notas[0] < notas[amostras-1]){
				picos++;	
			}
		}

        for(int i=1;i<amostras-1;i++){
            if(notas[i-1] > notas[i] && notas[i+1] > notas[i]){
            	picos++;
			}else{
				if(notas[i-1] < notas[i] && notas[i+1] < notas[i]){
					picos++;		
				}
                
			} 
        }    

        cout << picos << endl;
    }

    return 0;
}
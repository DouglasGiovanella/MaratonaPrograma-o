#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	
	int cartasAlice, cartasBeatriz, temp, trocasAlice=0, trocasBeatriz=0, i;
	vector<int> alice, beatriz;
    
    while(cin >> cartasAlice >> cartasBeatriz){    
		
		if(cartasAlice == 0 && cartasBeatriz == 0){
			break;
		}
		for(i=0;i<cartasAlice;i++){
			cin >> temp;
			alice.push_back(temp);
		}
		for(i=0;i<cartasBeatriz;i++){
			cin >> temp;
			beatriz.push_back(temp);
		}
		
		
		for(int j=0;j<cartasAlice;j++){
			if (j < cartasAlice-1 && alice[j] == alice[j+1]){
				continue;	
			}
			for(i=0;i<cartasBeatriz;i++){
				if(alice[j] == beatriz[i]){
					break;
				}else{
					if(alice[j] < beatriz[i]){
						trocasAlice++;
						break;
					}
				}
			}
			
			if(i == cartasBeatriz){
				trocasAlice++;	
			}
		}
		
		for(int j=0;j<cartasBeatriz;j++){
			if (j < cartasBeatriz-1 && beatriz[j] == beatriz[j+1]){
					continue;	
				}
			for(i=0;i<cartasAlice;i++){
				if(alice[i] == beatriz[j]){
					break;
				}else{
					if(alice[i] > beatriz[j]){
						trocasBeatriz++;
						break;
					}
				}
			}
			
			if(i == cartasAlice){
				trocasBeatriz++;	
			}
		}															
		
		if(trocasAlice < trocasBeatriz){
			cout << trocasAlice << endl;
		}else{
			cout << trocasBeatriz << endl;
		}
		trocasAlice=0;
		trocasBeatriz=0;
		alice.clear();
		beatriz.clear();
    }
    
	return 0;
}
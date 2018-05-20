#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	int teste[10000];
	int qunt, temp;
	
	cin >> qunt;
	
	for(int i=0;i<10000;i++){
		teste[i] = 0;		
	}
	
	for(int i=0;i<qunt;i++){
		cin >> temp;		
		teste[temp]++;			
	}
	
	for(int i=0;i<10000;i++){
		if(teste[i] != 0){
			cout << i << " aparece " << teste[i] << " vez(es)" << endl;
		}
	}
	
	return 0;
}
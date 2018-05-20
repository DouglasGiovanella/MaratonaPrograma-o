#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	int dias, custoPorDia, temp, maior;
	vector<int> custo;
	
	while(cin >> dias >> custoPorDia){
		
		for(int i=0;i<dias;i++){
			cin >> temp;
			custo.push_back(temp);
		}
		
		for(int i=0;i<custo.size();i++){
			
			if(i==0){
				custo[i] = custo[i]-custoPorDia;	
				if(custo[i] < 0){
					custo[i] =0;
				}
				maior = custo[i];
			}else{
				custo[i] = max(0, custo[i-1]-custoPorDia+custo[i]);
				if(custo[i] > maior){
					maior= custo[i];
				}
			}
			
		}
		cout << maior << endl;
		custo.clear();
		maior=0;
	}
	
	return 0;
}
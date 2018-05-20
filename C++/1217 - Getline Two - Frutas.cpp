#include <iostream>

using namespace std;


int main(){
	
	
	double casos, kg=1, totalkg=0;
	double valor, total=0;
	string frutas;
	
	cout << fixed;
	cout.precision(0);
	
	cin >> casos;
	
	for(int i=0;i<casos;i++){
		cin >> valor;
		total +=valor;
		getchar();
		getline(cin, frutas);
		kg=1;
		for(int k=0;k<frutas.size();k++){
			
			if(frutas[k] == ' '){
				kg++;
			}
			
		}
		totalkg +=kg;
		cout << "day " << i+1 << ": " << kg << " kg" << endl;
	}
	
	cout << fixed;
	cout.precision(2);
	
	cout << totalkg/casos << " kg by day" << endl;
	cout << "R$ " << total/casos << " by day" << endl;
	
	
	return 0;
}
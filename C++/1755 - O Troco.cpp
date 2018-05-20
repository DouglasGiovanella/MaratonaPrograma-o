#include <iostream>
#include <vector>
#include <algorithm>   
using namespace std;

double troco(double a, double b){
	double result=0;
	if(a > b){
		return 0;
	}
	while(1){
		if(result > b){
			result -=a;
			//cout << result << endl;
			//cout << b-result << endl;
			return b-result;
			break;
		}else{
			result += a;	
			//cout << "\t" << result << endl;
		}
			
	}
		
	
}


int main(){
	
	int casos, produtos;
	double dinheiro, temp, maior;
	vector<double> precos;
	
	cout << fixed;
	cout.precision(2);
	
	cin >> casos;
	
	for(int i=0;i<casos;i++){
		
		maior=0;
		precos.clear();
		
		cin >> dinheiro >> produtos;
		
		for(int k=0;k<produtos;k++){
			cin >> temp;
			precos.push_back(temp);
		}
		sort(precos.begin(),precos.end());
		
		for(int k=0;k<precos.size();k++){
			precos[k] = troco(precos[k], dinheiro);
		}
		
		for(int k=0;k<precos.size();k++){
			if(precos[k] > maior){
				maior = precos[k];
			}
		}
		
		cout << maior << endl;
	}
	
	
	
	return 0;
}
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
	
	int casos, alunos, soma, cont;
	double media;
	vector<int> notas;
	cin >> casos;
	int temp;
	for(int i=0;i<casos;i++){
		soma=0;
		cont=0;
		notas.clear();
		cin >> alunos;
		
		for(int j=0;j<alunos;j++){
			cin >> temp;
			notas.push_back(temp);		
			soma += temp;
		}
		
		media = soma/alunos;
		for(int j=0;j<notas.size();j++){
			if(notas[j] > media){
				cont++;
			}
		}
		
		cout << fixed;
		cout.precision(3);
		double a = cont*100.0/alunos;
		cout << a << "%" << endl;
		
	}
	
	return 0;
}
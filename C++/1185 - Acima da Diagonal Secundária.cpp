#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	
	cout << fixed;
	cout.precision(1);
	
	char op[1];
	double m[12][12], result=0,cont=0 ;
	int var = 10, j,i;
	
	cin >> op[0];
	
	for(i=0;i<12;i++){
		for(j=0;j<12;j++){
			cin >> m[i][j];
		}
	}
	for(i=0;i<11;i++){
		for(j=0;j<=var;j++){
			result += m[i][j];
			cont++;
		}
		var--;
	}
	
	if(op[0] == 'S'){
		cout << result << endl;
	}else{
		cout << result/cont << endl;
	}
	
	return 0;
}
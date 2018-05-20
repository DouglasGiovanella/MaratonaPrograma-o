#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
	
	int numHabi, temp;
	vector<int> negocio;
	long long int result, acumula;
	while(cin >> numHabi){
		if(numHabi == 0){
			break;
		}
		acumula =0;
		result =0;
		for(int i=0;i<numHabi;i++){
			cin >> temp;
			acumula +=temp;			
			result += llabs(acumula);
		}
		
		cout << result << endl;
	}
    
    return 0;
}
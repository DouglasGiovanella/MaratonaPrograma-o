#include <iostream>

using namespace std;

int main(){
	
	int jogadas, mary, john, temp;
	
	while(cin >> jogadas){
		
		if(jogadas == 0){
			break;
		}
		
		mary =0;
		john=0;
		
		for(int i=0;i<jogadas;i++){
			cin >> temp;
			if(temp == 0){
				mary++;
			}else{
				john++;
			}
		}
		
		cout << "Mary won " << mary << " times and John won " << john 
		<< " times" << endl;
		
	}

	
	return 0;
}
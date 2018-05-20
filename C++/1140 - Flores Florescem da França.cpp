#include <iostream>
#include <cctype>

using namespace std;

int main(){
	
	string entrada;
	char primeira, maisc, mins;
	bool vf;

	while(getline(cin, entrada)){
		if(entrada == "*"){
			break;
		}
		
		vf = true;
		maisc = toupper(entrada[0]);
		mins = tolower(entrada[0]);
		for(int i=0;i<entrada.size();i++){
			if(entrada[i] == ' '){
				if(entrada[i+1] != maisc && entrada[i+1] != mins){
					vf = false;
					break;
				}
			}
		}
		
		if(vf){
			cout << "Y" << endl;
		}else{
			cout << "N" << endl;
		}

		entrada.clear();
	}
	
	return 0;
}
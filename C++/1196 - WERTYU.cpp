#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	char teclado[] = {"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};
	string entrada, saida;

	while(getline(cin, entrada)){

		for(int i=0;i<entrada.size();i++){
			
			for(int j=0;j<47;j++){
				
				if(entrada[i] == teclado[j]){
					saida += teclado[j-1];
					break;
				}
				if(entrada[i] == ' '){
					saida += ' ';
					break;
				}
			}
		}		
		cout << saida << endl;
		saida.clear();
	}
	
	return 0;
}
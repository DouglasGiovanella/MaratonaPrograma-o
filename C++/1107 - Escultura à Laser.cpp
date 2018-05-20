#include <iostream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
  
  using namespace std;
  
int main(int argc, char *argv[]) {
	
 	int a, c, temp;
	int result, quantAnterior;
	
	while(cin>>a>>c){
		if (a==0 && c==0){
			break;
		}
		
		for(int i =0; i<c; i++){
			cin >> temp;
			if(i==0){
				result = a - temp;
			}else{
				if(temp < quantAnterior){
					result = (quantAnterior - temp) + result;			
				}
				
			}
			quantAnterior = temp;
		}
		
		cout << result << endl;
		
	}
	return 0;
}
#include <iostream>

using namespace std;

int main(){
	
	int h1, m1, h2, m2, result=0;
	
	while(cin >> h1 >> m1 >> h2 >> m2){
		if(h1==0 && m1==0 && h2==0 && m2==0){
			break;
		}
		int a=h1, b=m1;
		while(1){
			
			if(a==h2 && b == m2){
				break;
			}else{
				b++;
				result++;
				if(b == 60){
					b=0;
					if(a == 23){
						a=0;
					}else{
						a++;
					}
					
				}
			}
		}
		cout << result << endl;
		result=0;
	}

	return 0;
}
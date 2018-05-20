#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	
	int a,b,c,d;
	int menor=1000000001, result=0;
	cin >> a >> b >> c >> d;
	
	for(int i=1;i<=sqrt(c);i++){
		
		if(i%a==0 && i%b!=0 && c%i==0 && d%i!=0){
			if(i < menor) menor = i;
		}else{
			if((c/i)%a==0 && (c/i)%b!=0 && c%(c/i)==0 && d%(c/i)!=0){
				if((c/i) < menor) menor = c/i;
			}
		}
		
	}		
	
	if(menor == 1000000001){
		cout << "-1" << endl;
	}else{
		cout << menor << endl;
	}
	
	return 0;
}
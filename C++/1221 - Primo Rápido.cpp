#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(long long value){
    // NOTE: if the problem consider the number 1
    // as a prime number, then comment the line above
    if( value==1 ) return false;
    if( value<=3 ) return true;
    long long aux = sqrt(value);
    if((value%2 == 0) || (value%3 == 0)) return false;
    for(long long i=6; i<=aux; i+=6)
        if((value%(i-1)==0) || (value%(i+1)==0))
			return false;
    return true;
}

int main(){
	
	long long casos, num;
	
	cin >> casos;
		
	for(int i=0;i<casos;i++){
		cin >> num;
		if(isPrime(num)){
			cout << "Prime" << endl;
		}else{
			cout << "Not Prime" << endl;
			
		}
	}
		

	return 0;
}
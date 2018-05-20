#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	int angulo;
	
	while(cin >> angulo){
		
		if((angulo%6)==0){
			cout << "Y" << endl;
		}else{
			cout << "N" << endl;
		}
		
	}
	
	
	
		
	
	return 0;
}
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	
	double d, vf, vg;
	double temp;
	while(cin >> d >> vf >> vg){
		
		temp = sqrt(d*d + 144);
			
		if(temp/vg <= 12/vf){
			cout << "S" << endl;
		}else{
			cout<< "N" << endl;
		}
		
	}
	
	return 0;
}
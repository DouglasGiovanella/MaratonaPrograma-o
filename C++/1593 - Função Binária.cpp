#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef long long unsigned LLU;


class BigInteger{
	public:bool negative;
	public:vector<bool> digits;
	
	///////////////////////////////////////////////
	// Constructor using a string. The string passed
	// as parameter may have the signal '-'
	public:BigInteger( string number ){
		if( number[0]=='-' ){
			negative = true;	
			number.erase( number.begin() );
		}
		else negative = false;
		
		string old_number;
		for( ; ; ){
			if( number.size()==1 && number[0]<'2' ){
				digits.push_back( number[0] );
				break;
			}
			old_number.assign( number );
			number.clear();
			int aux = 0;
			bool first_digit = true;
			
			for(unsigned i=0; i<old_number.size(); i++){
				aux = aux*10 + old_number[i]-'0';
				if( first_digit && aux<2 ) continue;
				first_digit = false;
				number.push_back( (aux/2)+'0' );
				aux = aux % 2;
			}
			digits.push_back( aux==1 );
		}
	}
	
	///////////////////////////////////////////////
	public:void show(bool forceSignal=false){
		if( negative ) putchar('-');
		else if( forceSignal ) putchar('+');
		for(int i=digits.size()-1; i>=0; i--){
			putchar( digits[i]+'0' );
		}
		putchar('\n');
	}
	
	///////////////////////////////////////////////
	public:unsigned countOnes(){
		unsigned ones = 0;
		for(unsigned i=0; i<digits.size(); i++)
			if( digits[i] ) ones++;
		return ones;
	}
};


int main(int argc, char** argv) {
	
	int casos;
	cin >> casos;
	string entrada;
	for(int i=0;i<casos;i++){
		cin >> entrada;
		BigInteger a1(entrada);
		cout << a1.countOnes() << endl;
	}	
	
	return 0;
}
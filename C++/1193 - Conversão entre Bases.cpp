#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long unsigned LLU;
using namespace std;

class Number{
	unsigned base;
	bool negative;
	string number; //inverse representation
	
	public:Number(string n="0", unsigned b=2, bool s=false){
		reverse( n.begin(), n.end() );
		number = n;
		base = b;
		negative = s;
	}
	
	private:LLU char2Num(char c){
        if( c>='0' && c<='9') return c-'0';
        if( c>='A' && c<='Z') return c-'A'+10;
        if( c>='a' && c<='z') return c-'a'+10;
        return -1;
    }
    private:char num2Char(LLU n){
	    if( n<10 ) return n+'0';
	    return 'a'+n-10;
	}
	
	
	public:void transform( unsigned nbase ){
		LLU n = 0;
		if(base != 10)
			for(int i=0; i<number.size(); i++)
				n += char2Num(number[i]) * pow(base,i);
		else
			for(int i=number.size()-1; i>=0; i--)
				n = n*10 + char2Num(number[i]);
		
		number.clear();
		do {
			number.push_back( num2Char(n % nbase) );
			n /= nbase;
		} while(n>0);
		base = nbase;
	}
	
	public:string getNumber(bool forceSignal=false){
		string res;
		if( negative ) res.push_back('-');
		else if( forceSignal ) res.push_back('+');
		for(int i=number.size()-1; i>=0; i--)
			res.push_back(number[i]);
		return res;
	}
};

int main(){
	
	int casos;
	string num, tipo;
	
	cin >> casos;
	getchar();
	for(int i=0;i<casos;i++){
		cin >> num >> tipo;
		cout << "Case " << i+1 << ":" << endl;
		if(tipo == "bin"){
			
			Number a1(num, 2);
			a1.transform(10);
			cout << a1.getNumber() << " dec" << endl;
			a1.transform(16);
			cout << a1.getNumber() << " hex" << endl;
			
					
		}else{
			if(tipo == "dec"){
				
				Number a1(num, 10);	
				a1.transform(16);
				cout << a1.getNumber() << " hex" << endl;
				a1.transform(2);
				cout << a1.getNumber() << " bin" << endl;
					
			}else{
				
				Number a1(num, 16);	
				a1.transform(10);
				cout << a1.getNumber() << " dec" << endl;	
				a1.transform(2);
				cout << a1.getNumber() << " bin" << endl;

			}
		}
		
		cout << endl;
	}
	
	return 0;
}
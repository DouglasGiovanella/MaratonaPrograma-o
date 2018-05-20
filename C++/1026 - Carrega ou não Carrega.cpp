#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	
	unsigned int val1, val2, final;
    
    while(cin >> val1 >> val2){    
		final = val1^val2;
        cout << final << endl;
    }
    
	return 0;
}
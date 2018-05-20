#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
 	
 	string num1, num2;
 	int soma1 = 0, soma2 = 0;

 	while (cin >> num1 >> num2) {
 		if (num1[0] == '0' && num2[0] == '0') return 0;

 			for (int i = 0; i < num1.size(); ++i) {
 				soma1 += num1[i] - '0';
 			}

 			for (int i = 0; i < num2.size(); ++i) {
 				soma2 += num2[i] - '0';
 			}

 			if (soma1 >= 10) {
 				while (soma1 >= 10) {
 					soma1 = 0;

 					for (int i = 0; i < num1.size(); ++i) {
 						soma1 += num1[i] - '0';
 					}

 					ostringstream convert1;
 					convert1 << soma1;
 					num1 = convert1.str();
 				}
 			}

 			if (soma2 >= 10) {
 				while (soma2 >= 10) {
 					soma2 = 0;

 					for (int i = 0; i < num2.size(); ++i) {
 						soma2 += num2[i] - '0';
 					}

 					ostringstream convert2;
 					convert2 << soma2;
					num2 = convert2.str();
 				}
 			}
 		if (soma1 > soma2) cout << "1" << endl;
 		if (soma2 > soma1) cout << "2" << endl;
 		if (soma1 == soma2) cout << "0" << endl;

 		soma1 = 0;
 		soma2 = 0;
	}

 	return 0;
 }
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	int cases, peoples, jump, temp;

	cin >> cases;

	for (int i = 0; i<cases; i++) {

		cin >> peoples >> jump;
		temp = 0;
		for (int j = 2; j <= peoples; j++) {
			temp = (temp + jump) % j;
		}
		cout << "Case " << i + 1 << ": " << temp + 1 << endl;
	}
	return 0;
}
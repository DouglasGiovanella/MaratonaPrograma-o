#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<unsigned, unsigned> PUU;
typedef vector<PUU> VPUU;
typedef vector<unsigned> VU;
typedef vector<VU> VVU;
typedef unsigned long long ULL;

#include <limits>
unsigned INF_U = numeric_limits<unsigned>::max();
ULL INF_L = numeric_limits<ULL>::max();

unsigned solve(unsigned value, VU coins) {

	unsigned n = coins.size();
	unsigned pd[value + 1];
	pd[0] = 0;
	for (unsigned i = 1; i <= value; i++) {
		pd[i] = INF_U;
		for (unsigned j = 0; j < n; j++) {
			if (coins[j] <= i)
				pd[i] = min(pd[i], pd[i - coins[j]] + 1);
		}
	}
	return pd[value];
}

int main(int argc, char** argv) {

	int numInst, blockTypes, length;
	unsigned int temp;
	VU coins;

	cin >> numInst;

	for (int i = 0; i < numInst; i++) {
		cin >> blockTypes >> length;
		for (int i = 0; i < blockTypes; i++) {
			cin >> temp;
			coins.push_back(temp);
		}
		cout << solve(length, coins) << endl;
		coins.clear();
	}

	return 0;
}
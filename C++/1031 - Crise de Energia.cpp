#include <iostream>

using namespace std;

int main() {

	int regions, temp = 0, jumpCont;

	while (cin >> regions)
	{
		if (regions == 0)
			break;

		jumpCont = 1;

		while (1)
		{
			temp = 0;
			for (int j = 1; j < regions; j++)
			{
				temp = (temp + jumpCont) % j;
			}

			if (temp != 11)
			{
				jumpCont++;
			}
			else
			{
				break;
			}
		}

		cout << jumpCont << endl;
	}
	return 0;
}
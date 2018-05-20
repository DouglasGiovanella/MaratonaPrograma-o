#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

void inverte(char data[], int size)
{
	char temp;
	for (int i = 0; i < size / 2; i++)
	{
		temp = data[i];
		data[i] = data[size - i - 1];
		data[size - i - 1] = temp;
	}
}

int main() {

	int cases, i, j, size;
	char data[1001];

	scanf("%d", &cases);
	cin.getline(data, 0);

	for (i = 0; i < cases; i++)
	{
		cin.getline(data, 1001);

		for (j = 0; data[j] != '\0'; j++)
		{
			if (data[j] >= 65 && data[j] <= 90 || data[j] >= 97 && data[j] <= 122)
			{
				data[j] += 3;
			}
		}

		size = strlen(data);

		inverte(data, size);

		for (j = size / 2; data[j] != '\0'; j++)
		{
			data[j]--;
		}

		printf("%s\n", data);
	}
	return 0;
}


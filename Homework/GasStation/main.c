
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#include <stdio.h>
#include <time.h>
#define MAX_ARRAY 10001
int arr[2][MAX_ARRAY];
int main() {
	FILE* ptr = fopen("gasStation.txt", "r");
	if (ptr == NULL) {
		printf("File khong ton tai");
		return 0;
	}
	int buf;
	int testCases = 0, N = 0, line = -2, n = 0, testCase = 1;
	while (fscanf(ptr, "%d", &buf) == 1) {
		if (line == -2)testCases = buf;
		if (line == -1)N = buf;
		if (line >= 0)arr[line % 2][n] = buf;
		if (line % 2 == 1)n++;
		if (line == N * 2 - 1)
		{


			int ans = -1, remainGas = -1;
			for (int i = 0; i < N; i++)
			{
				if (arr[0][i] > arr[1][i]) {
					int currInx = i, gas = 0;
					for (int j = 0; j < N; j++)
					{

						if (gas + arr[0][currInx] < arr[1][currInx])break;
						else
						{
							gas += arr[0][currInx] - arr[1][currInx];
						}
						if (++currInx == N)currInx = 0;
					}
					if (currInx == i)
					{
						if (ans > i || ans == -1) { ans = i, remainGas = gas; }
						//printf("Xe co the di tu tram so %d va con lai %d xang\n", ans, remainGas);
						goto result;
					}
				}
			}
		result:

			
			if (ans != -1) {
				printf("\rTest case #%d: Xe co the di tu tram gan nhat %d va con lai %d xang", testCase, ans, remainGas);
			}
			else
			{
				printf("\rTest case #%d: Xe khong the di qua het tram xang!", testCase);
			}
			testCase++;
			int lastClock = clock();
			while (clock() < lastClock + CLOCKS_PER_SEC / 2);



















			line = -1;
			n = 0;
		}
		else {
			line++;

		}

	}
	return 0;
}
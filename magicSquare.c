#include <stdio.h>

#define SQR_SIZE 5
#define AUG_SQR_SIZE (SQR_SIZE + 4)

int main()
{
	int magicSqr[SQR_SIZE][SQR_SIZE] = {0};
	int augSqr[AUG_SQR_SIZE][AUG_SQR_SIZE] = {0};
	int currNum = 1;
	int iM, jM;

	for (int n = 0; n < SQR_SIZE; n++)
	{
		for (int i = 0; i < SQR_SIZE; i++)
		{
			augSqr[SQR_SIZE - 1 - i + n][i + n] = currNum;
			currNum++;
		}
	}

	for (int i = 0; i < AUG_SQR_SIZE; i++)
	{
		iM = i - 2;

		if (iM < 0) iM += SQR_SIZE;
		else if (iM >= SQR_SIZE) iM -= SQR_SIZE;

		for (int j = 0; j < AUG_SQR_SIZE; j++)
		{
			if (!augSqr[i][j]) continue;

			jM = j - 2;

			if (jM < 0) jM += SQR_SIZE;
			else if (jM >= SQR_SIZE) jM -= SQR_SIZE;

			magicSqr[iM][jM] = augSqr[i][j];
		}
	}

	for (int i = 0; i < SQR_SIZE; i++)
	{
		for (int j = 0; j < SQR_SIZE; j++)
		{
			printf("%d\t", magicSqr[i][j]);
		}
		puts("\n");
	}

	return 0;
}

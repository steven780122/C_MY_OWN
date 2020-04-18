// 4.23DecimalToBiOxHex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

#define INT_RANGE_MIN		1
#define INT_RANGE_MAX		256
#define BINARY_DIVISOR		2
#define OCTAL_DIVISOR		8
#define HEXADECIMAL_DIVISOR	16
#define MAX_BUFFER_SIZE		10
#define INPUT_BASE			10


int DecimalToBinary(int iDecimal, int *piBinary, int iDigitDivisor)
{
	int iQuotient = 0;
	unsigned int uiExeCount = 0;
	int aiBinary[MAX_BUFFER_SIZE] = {0};
	int iIndex = 0;

	if (!piBinary)
	{
		printf("Parameter piBinary error!\n");
		return EXIT_FAILURE;
	}	

	iQuotient = iDecimal;

	while (iQuotient != 0)
	{
		
		aiBinary[uiExeCount] = iQuotient % iDigitDivisor;
		iQuotient = iQuotient / iDigitDivisor;
		
		uiExeCount++;
	}
	
	for (iIndex = uiExeCount - 1; iIndex >= 0; iIndex--)
	{
		printf("%d", aiBinary[iIndex]);    //§ï¼g¤ÏÂà!
	}

	return EXIT_SUCCESS;
}

int main()
{
	
	int iRet = 0;
	int iBinaryResult = 0;
	unsigned int uiIndex = 0;

	printf("The following is the Binary, Octal and Hexadecimal number between %d ~ %d:\n", INT_RANGE_MIN, INT_RANGE_MAX);
	
	printf("Number\t\tBinary\t\tOctor\t\tHex\n");

	for (uiIndex = INT_RANGE_MIN; uiIndex <= INT_RANGE_MAX; uiIndex++)
	{
		printf("%d\t\t", uiIndex);


		iRet = DecimalToBinary(uiIndex, &iBinaryResult, BINARY_DIVISOR);
		if (iRet == EXIT_FAILURE)
		{
			printf("Decimal to Binary error!\n");
			return EXIT_FAILURE;
		}

		printf("\t\t");

		iRet = DecimalToBinary(uiIndex, &iBinaryResult, OCTAL_DIVISOR);
		if (iRet == EXIT_FAILURE)
		{
			printf("Decimal to Octor error!\n");
			return EXIT_FAILURE;
		}

		printf("\t\t");

		iRet = DecimalToBinary(uiIndex, &iBinaryResult, HEXADECIMAL_DIVISOR);
		if (iRet == EXIT_FAILURE)
		{
			printf("Decimal to Hex error!\n");
			return EXIT_FAILURE;
		}

		printf("\n");
	}

	system("pause");
	return EXIT_SUCCESS;

}

// 3_32BinaryToDecimal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_BINARY_NUM	10
#define BINARY_CARRY	2

int BinaryToDecimal(char szBinary[], int *piDecimalResult)
{
	//int iBinaryToDigit = 0;
	unsigned int uiBinaryLen = 0;
	unsigned int uiIndex = 0;
	int iDecimalResult = 0;

	if (!piDecimalResult)
	{
		printf("Error!\n");
		return EXIT_FAILURE;
	}
	
	uiBinaryLen = strlen(szBinary);
	
	for (uiIndex = 0; uiIndex < uiBinaryLen; uiIndex++)
	{
		iDecimalResult = iDecimalResult + (szBinary[uiIndex] - '0') * (int)pow(BINARY_CARRY, uiBinaryLen - uiIndex - 1);
	}

	*piDecimalResult = iDecimalResult;

	return EXIT_SUCCESS;
}

int main()
{
	char szBinary[MAX_BINARY_NUM + 1] = {0};
	unsigned int uiInputLen = 0;
	unsigned int uiIndex = 0;
	int iRet = 0;
	int iResult = 0;

	printf("Please enter the binary number to transfer into decimal number!\n (Input is at most %d digital numbers!)\n", MAX_BINARY_NUM);
	if (!fgets(szBinary, MAX_BINARY_NUM + 1, stdin))
	{
		printf("Fgets error!\n");
		system("pause");
		return EXIT_FAILURE;
	}

	uiInputLen = strlen(szBinary);

	if (szBinary[uiInputLen - 1] == '\n')
	{
		szBinary[uiInputLen - 1] = '\0';
	}

	uiInputLen = strlen(szBinary);
	
	for (uiIndex = 0; uiIndex < uiInputLen; uiIndex++)
	{
		if (!isdigit(szBinary[uiIndex]))
		{
			printf("There are error types in your input!\n");
			system("pause");
			return EXIT_FAILURE;
		}
	}

	for (uiIndex = 0; uiIndex < uiInputLen; uiIndex++)
	{
		char cTemp = szBinary[uiIndex];

		if (cTemp != '0' && cTemp != '1')
		{
			printf("You can only type 0 or 1.\n");
			system("pause");
			return EXIT_FAILURE;
		}		
	}

	iRet = BinaryToDecimal(szBinary, &iResult);
	if (iRet == EXIT_FAILURE)
	{
		printf("Error!\n");
		system("pause");
		return EXIT_FAILURE;
	}

	printf("The decimal after transfer is >> %d. \n", iResult);
	
	system("pause");
	return EXIT_SUCCESS;
}
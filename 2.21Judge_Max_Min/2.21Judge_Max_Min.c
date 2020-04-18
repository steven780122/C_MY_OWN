// 2.21Judge_Max_Min.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE	20
#define DIGIT_NUM		5
#define DIGIT_DELIM		" "

int JudgeMinMax(const int aiNumber[DIGIT_NUM], int *piMin, int *piMax)
{
	unsigned int uiIndex = 0;
	int iMin = 0;
	int iMax = 0;

	if (!piMax)
	{
		printf("Error!\n");
		return EXIT_FAILURE;
	}

	if (!piMax)
	{
		printf("Error!\n");
		return EXIT_FAILURE;
	}
	
	iMax = aiNumber[0];
	iMin = aiNumber[0];

	for (uiIndex = 0; uiIndex < DIGIT_NUM; uiIndex++)
	{
		if (iMin < aiNumber[uiIndex])
		{
			iMin = aiNumber[uiIndex];
		}

		if (iMax > aiNumber[uiIndex])
		{
			iMax = aiNumber[uiIndex];
		}
	}

	*piMax = iMax;
	*piMin = iMin;

	return EXIT_SUCCESS;
}

int main()
{
	char szDigitBuffer[MAX_BUFFER_SIZE + 1] = {0};
	int aiInteger[DIGIT_NUM] = {0};
	char *pszDigit = NULL;
	char *pszDigitStart = NULL;
	int iMaxResult = 0;
	int iMinResult = 0;
	unsigned int uiStrLen = 0;
	unsigned int uiNumLen = 0;
	unsigned int uiInputNum = 0;
	unsigned int uiIndex = 0;
	int iRet = 0;

	printf("Please input %d integers at most size %d\n", DIGIT_NUM, MAX_BUFFER_SIZE);
	if (!fgets(szDigitBuffer, MAX_BUFFER_SIZE + 1, stdin))
	{
		printf("Error!\n");
		return EXIT_FAILURE;
	}
	
	uiStrLen = strlen(szDigitBuffer);

	if (szDigitBuffer[uiStrLen - 1] == '\n')
	{
		szDigitBuffer[uiStrLen - 1] = '\0';
	}

	pszDigit = strtok(szDigitBuffer, DIGIT_DELIM);
	while (pszDigit != NULL)
	{
		pszDigitStart = pszDigit;
		uiInputNum++;

		uiNumLen = strlen(pszDigit);
		for (uiIndex = 0; uiIndex < uiNumLen; uiIndex++)
		{
			if (!isdigit(*pszDigit))
			{
				printf("There are wrong types input!\n");
				system("pause");
				return EXIT_FAILURE;
			}

			pszDigit++;
		}
		
		if (uiInputNum > DIGIT_NUM)
		{
			printf("Too many inputs!\n");
			break;
		}

		aiInteger[uiInputNum - 1] = atoi(pszDigitStart);		

		pszDigit = strtok(NULL, DIGIT_DELIM);
	}

	if (uiInputNum < DIGIT_NUM)
	{
		printf("Too few integers!\n");
		system("pause");
		return EXIT_FAILURE;
	}
	
	iRet = JudgeMinMax(aiInteger, &iMinResult, &iMaxResult);
	if (iRet == EXIT_FAILURE)
	{
		printf("Error!\n");
		system("pause");
		return EXIT_FAILURE;
	}
	
	printf("The min is %d\n", iMinResult);
	printf("The max is %d\n", iMaxResult);

	system("pause");
	return EXIT_SUCCESS;
}

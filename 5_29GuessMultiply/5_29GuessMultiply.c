// 5_29GuessMultiply.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

typedef int BOOL;

#define NUMBER_MIN	1
#define NUMBER_MAX	10
#define TRUE		1
#define FALSE		0

typedef enum E_Menu
{
	eGuessNew = 1,
	eLeave
} EMenu;

void ShowMenu()
{
	printf("(%d). Show two number between %d ~ %d and guess the multiply.\n", eGuessNew, NUMBER_MIN, NUMBER_MAX);
	printf("(%d). Leave!\n", eLeave);

	printf("Please show your option:\n");
}

int GenerateNumber(int *piNumber1, int *piNumber2)
{
	if (!piNumber1)
	{
		printf("Parameter piNumber1 error!\n");
		return EXIT_FAILURE;
	}

	if (!piNumber2)
	{
		printf("Parameter piNumber2 error!\n");
		return EXIT_FAILURE;
	}

	*piNumber1 = rand() % (NUMBER_MAX - NUMBER_MIN + 1) + NUMBER_MIN;
	*piNumber2 = rand() % (NUMBER_MAX - NUMBER_MIN + 1) + NUMBER_MIN;

	return EXIT_SUCCESS;
}

int CheckGuess(const int iProduct, const int iGuess, BOOL *pbResult)
{
	if (!pbResult)
	{
		printf("pbResult parameter error!\n");
		return EXIT_FAILURE;
	}

	if (iGuess > iProduct)
	{
		printf("Guess too HIGH!\n");
		return EXIT_SUCCESS;
	}

	if (iGuess < iProduct)
	{
		printf("Guess too LOW!\n");
		return EXIT_SUCCESS;
	}

	if (iGuess == iProduct)
	{
		printf("Guess Right!\n");
		*pbResult = TRUE;
		return EXIT_SUCCESS;
	}

	return EXIT_SUCCESS;
}

int main()
{
	BOOL bFlag = FALSE;
	int iNumber1 = 0;
	int iNumber2 = 0;

	srand((unsigned)time(NULL));

	
	while (bFlag == FALSE)
	{
		int iOption = 0;
		int iRet = 0; 
		int iGuess = 0;
		BOOL bGuessResult = FALSE;
		EMenu eOptrion = 0;

		ShowMenu();
		iRet = scanf("%d", &iOption);
		if (iRet == 0)
		{
			printf("Input error!\n");
			continue;
		}

		if (iOption < eGuessNew || iOption > eLeave)
		{
			printf("The input is out of range!\n");
			continue;
		}

		eOptrion = iOption;
		switch (eOptrion)
		{
		case eGuessNew:
			iRet = GenerateNumber(&iNumber1, &iNumber2);
			if (iRet == EXIT_FAILURE)
			{
				printf("Generate number error!\n");
				continue;
			}

			printf("How mush is %d times %d ?\n", iNumber1, iNumber2);

			while (bGuessResult == FALSE)
			{
				printf("Please Guess the product>>\n");
				iRet = scanf("%d", &iGuess);
				if (iRet == 0)
				{
					printf("Input error!");
					continue;
				}

				iRet = CheckGuess(iNumber1 * iNumber2, iGuess, &bGuessResult);
				if (iRet == EXIT_FAILURE)
				{
					printf("Check error!\n");
					continue;
				}
			}

			break;

		case eLeave:
			bFlag = TRUE;
			break;

		default:
			break;
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}
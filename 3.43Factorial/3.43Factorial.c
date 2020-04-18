// 3.43Factorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <math.h>

typedef int BOOL;

#define TRUE				1
#define FALSE				0
#define EXPONENTIAL_TIMES	10

typedef enum E_Menu
{
	eFactorial = 1,
	eExponential,
	eExponential_X,
	eLeave
} EMenu;

void ShowMenu()
{
	printf("(%d). Input a unsigned int to get the factorial.\n", eFactorial);
	printf("(%d). Display the value of exponential number.\n", eExponential);
	printf("(%d). Input the square to get the exponential value.\n", eExponential_X);
	printf("(%d). Leave!\n", eLeave);
}

int Factorial(const unsigned int uiInput, unsigned int *puiResult)
{
	unsigned int uiResult = 0;
	int iRet = 0;

	if (!puiResult)
	{
		printf("Parameter puiResult error!\n");
		return EXIT_FAILURE;
	}

	if (uiInput == 0)
	{
		uiResult = 1;		
	}
	else
	{
		iRet = Factorial(uiInput - 1, &uiResult);
		if (iRet == EXIT_FAILURE)
		{
			printf("Recursive error!\n");
			return EXIT_FAILURE;
		}

		uiResult = uiInput * uiResult;
	}

	*puiResult = uiResult;

	return EXIT_SUCCESS;
}

int ComputeExponential(const double dNumber, double *pdResult)				//loop times is fixed 
{
	unsigned int dResultFactorial = 0;
	double dResultExponential = 0;
	unsigned int uiIndex = 0;
	int iRet = 0;

	if (!pdResult)
	{
		printf("Parameter pdResult error!\n");
		return EXIT_FAILURE;
	}

	for (uiIndex = 0; uiIndex < EXPONENTIAL_TIMES; uiIndex++)
	{
		dResultFactorial = 0;
		iRet = Factorial(uiIndex, &dResultFactorial);
		if (iRet == EXIT_FAILURE)
		{
			printf("Error!\n");
			return EXIT_FAILURE;
		}

		dResultExponential = dResultExponential + pow(dNumber, uiIndex) / dResultFactorial;    
		
		printf("%lf\n", pow(dNumber, uiIndex));
		printf("%lf\n", dResultFactorial);


	}

	*pdResult = dResultExponential;

	return EXIT_SUCCESS;
}

int main()
{
	int iRet = 0;
	int iNumber = 0;
	unsigned int uiResult = 0;
	double dExponentialResult = 0.0;
	double dExponentialInput = 0.0;

	BOOL bLeave = FALSE;
	EMenu eOption = 0;
	
	ShowMenu();
	while (bLeave == FALSE)
	{
		printf("Please choose the option:\n");

		fflush(stdin);
		iRet = scanf("%d", &eOption);
		if (iRet == 0)
		{
			printf("Scanf error!\n");
			continue;
		}

		if (eOption < eFactorial || eOption > eLeave)
		{
			printf("The option is out of range!\n");
			continue;
		}

		switch (eOption)
		{
		case eFactorial:
			fflush(stdin);
			printf("Please enter a unsigned integer to compute the factorial value.\n");
			iRet = scanf("%d", &iNumber);
			if (iRet == 0)
			{
				printf("Scanf Error!\n");
				continue;
			}

			if (iNumber < 0)
			{
				printf("You must enter unsigned integer!\n");
				continue;
			}

			iRet = Factorial(iNumber, &uiResult);
			if (iRet == EXIT_FAILURE)
			{
				printf("Factorial function error!\n");
				continue;
			}

			printf("%d! == %d\n", iNumber, uiResult);

			break;

		case eExponential:
			iRet = ComputeExponential(1.0, &dExponentialResult);
			if (iRet == EXIT_FAILURE)
			{
				printf("Error!\n");
				continue;
			}

			printf("%f!!!", dExponentialResult);

			break;

		case eExponential_X:
			fflush(stdin);
			printf("Please enter a number to get the exponential number of it!\n");
			iRet = scanf("%lf", &dExponentialInput);	//小心這裡!!! scanf double時，資料型態要用%lf 否則會錯
			if (iRet == 0)
			{
				printf("Input error!\n");
				continue;
			}

			iRet = ComputeExponential(dExponentialInput, &dExponentialResult);
			if (iRet == EXIT_FAILURE)
			{
				printf("Error!\n");
				continue;
			}

			printf("The result is %f.\n", dExponentialResult);

			break;
			
		case eLeave:
			bLeave = TRUE;
			break;

		default:
			break;
		}
	}

	
	system("pause");
	return EXIT_SUCCESS;
}
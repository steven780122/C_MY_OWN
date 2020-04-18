// 2.26_SquareCube.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <math.h>

#define MIN_NUM			0
#define MAX_NUM			10
#define SQUARE_TIMES	2
#define CUBE_TIMES		3

int main()
{	
	unsigned int uiIndex = 0;

	printf("The following are the square and cube numbers between %d ~ %d:\n", MIN_NUM, MAX_NUM);

	for (uiIndex = 0; uiIndex <= MAX_NUM; uiIndex++)
	{
		printf("%d\t%d\t%d\n", uiIndex, uiIndex * uiIndex, uiIndex * uiIndex * uiIndex);
	}

	system("pause");
	return EXIT_SUCCESS;
}


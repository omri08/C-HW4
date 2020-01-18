#pragma once
#include "groups.h"

typedef struct
{
	unsigned int num : 2;
}Num;

char* createSequence(char* fileName);
Num* createSigns(char* seq1, char* seq2, int n, int* arrSize);
int getCount(Num* arr, int size);
int evaluateDifference(char* seq1, char* seq2, int n);
#define _CRT_SECURE_NO_WARNINGS
#define UNSIGNED_CHAR_SIZE 8
#include <stdio.h>
#include <string.h>
#include "Seq.h"

char* createSequence(char* fileName)
{
	FILE* f = fopen(fileName, "r");
	if (!f)
		return NULL;
	char* seq = (char*)malloc(sizeof(char) * 300);
	if (!seq)
	{
		fclose;
		return NULL;
	}
	if (fgets(seq, 300, f))
	{
		fclose(f);
		return seq;
	}
	else
	{
		fclose(f);
		return NULL;
	}
}

Num* createSigns(char* seq1, char* seq2, int n, int* arrSize)
{
	if (strlen(seq1) < strlen(seq2))
		return NULL;
	 *arrSize = strlen(seq2);
	Num* arr = (Num*)malloc(sizeof(Num) * *arrSize);
	if (!arr)
		return NULL;
	attribute* close = createAttribute(Close);
	if (!close)
	{
		free(arr);
		return NULL;
	}
	attribute* sim = createAttribute(Similar);
	if (!sim)
	{
		free(arr);
		free(sim);
		return NULL;
	}
	seq1 += n;
	for (int i = 0; i < *arrSize; i++)
	{
		
		arr[i].num  = CheckRelation(*seq1, *seq2, close, sim);
		seq1++;
		seq2++;

	}
	free(close);
	free(sim);
	return arr;

}

int getCount(Num* arr, int size)
{
	int numOfAs = 0;
	int numOfCol = 0;
	
	for (int i = 0; i < size; i++)
	{
			if (arr[i].num == COLON)
				numOfCol++;
			else if (arr[i].num == ASTERISK)
				numOfAs++;	
	}
	return numOfAs - numOfCol;
}

int  evaluateDifference(char* seq1, char* seq2, int n)
{
	int size;
	Num* arr = createSigns(seq1, seq2, n, &size);
	return getCount(arr, size);
}
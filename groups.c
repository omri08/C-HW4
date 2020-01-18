#pragma once
#include <stdlib.h>
#include <string.h>
#include "groups.h"

attribute* createAttribute(attributeType type)
{
	if (type == 0)
		return createClose();
	else
		return createSimilar();
}

attribute* createClose()
{
	attribute* at = (attribute*)malloc(sizeof(attribute));
	if (!at)
		return NULL;
	at->type = Close;
	at->numOfGroups = 9;
	at->sign = COLON;
	at->allGroups = (char**)malloc(sizeof(char*) * at->numOfGroups);
	if (!at->allGroups)
		return NULL;
	for (int i = 0; i < at->numOfGroups; i++)
		at->allGroups[i] = (char*)malloc(sizeof(char) * 5);

	at->allGroups[0] = "STA";
	at->allGroups[1] = "NEQK";
	at->allGroups[2] = "NDEQ";
	at->allGroups[3] = "NHQK";
	at->allGroups[4] = "QHRK";
	at->allGroups[5] = "MILV";
	at->allGroups[6] = "MILF";
	at->allGroups[7] = "HY";
	at->allGroups[8] = "FYW";

	return at;

}


attribute* createSimilar()
{
	attribute* at = (attribute*)malloc(sizeof(attribute));
	if (!at)
		return NULL;
	at->type = Similar;
	at->numOfGroups = 11;
	at->sign = DOT;
	at->allGroups = (char**)malloc(sizeof(char*) * at->numOfGroups);
	if (!at->allGroups)
		return NULL;
	for (int i = 0; i < at->numOfGroups; i++)
		at->allGroups[i] = (char*)malloc(sizeof(char) * 7);

	at->allGroups[0] = "CSA";
	at->allGroups[1] = "ATV";
	at->allGroups[2] = "SAG";
	at->allGroups[3] = "STNK";
	at->allGroups[4] = "STPA";
	at->allGroups[5] = "SGND";
	at->allGroups[6] = "SNDEQK";
	at->allGroups[7] = "NDEQHK";
	at->allGroups[8] = "NEQHRK";
	at->allGroups[9] = "FVLIM";
	at->allGroups[10] = "HFY";

	return at;
}


int CheckRelation(const char letter1, const char letter2, attribute* close, attribute* sim)
{
	if (letter1 == letter2)
		return ASTERISK;

	for (int i = 0; i < close->numOfGroups; i++)
	{
		if (strchr(close->allGroups[i], letter1) != NULL
			&& strchr(close->allGroups[i], letter2) != NULL)
		{
			return close->sign;
		}
			
	}

	for (int i = 0; i < sim->numOfGroups; i++)
	{
		if (strchr(sim->allGroups[i], letter1) != NULL
			&& strchr(sim->allGroups[i], letter2) != NULL)
		{
			return sim->sign;
		}
			
	}
	
	return SPACE;
}
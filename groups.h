#pragma once

#define SPACE 3
#define ASTERISK 2
#define DOT 1
#define COLON 0
typedef enum  { Close, Similar } attributeType;
typedef struct
{
	char** allGroups;
	int numOfGroups;
	int sign;
	attributeType type;

}attribute;



attribute* createAttribute(attributeType type);
attribute* createClose();
attribute* createSimilar();
int CheckRelation(const char letter1, const char letter2, attribute* close, attribute* sim);

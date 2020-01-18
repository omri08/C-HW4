#include "Seq.h"
int main()
{
	int s = sizeof(Num);
	char* seq1 = createSequence("Seq1.txt");
	char* seq2 = createSequence("Seq2.txt");
	int n = strlen(seq1) - strlen(seq2);
	int size;
	Num* arr = createSigns(seq1, seq2,n,&size);
	int t = getCount(arr, size);
}
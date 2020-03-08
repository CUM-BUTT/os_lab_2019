#include "swap.h"

void Swap(char *a, char *b)
{
	*a=*a^*b;
    *b=*a^*b;
    *a=*b^*a;
}

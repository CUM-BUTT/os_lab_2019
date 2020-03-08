#include "revert_string.h"

void RevertString(char *str)
{
char *buff=malloc(sizeof(char)*(strlen(str)+1));
int i=0;

strcpy(buff, str);
for(i=0;i<strlen(str);i++)
{
str[strlen(str)-1-i]=buff[i];
}
// *str=*buff;
// your code here
}
//./random.sh
//./average.sh $(cat numbers.txt)
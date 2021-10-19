// An example program to demonstrate working
// of enum in C
#include<stdio.h>

enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun};

int main()
{
	enum week day;
	day = Wed;
    int a = sizeof(day);
	printf("%d",a);
	return 0;
}
 
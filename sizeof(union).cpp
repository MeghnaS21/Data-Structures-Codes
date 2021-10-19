#include <stdio.h>

// Declaration of union is same as structures
union test {
	int x, y;
};

int main()
{
	// A union variable t
	union test t;
    int a=sizeof(t);

	printf("%d", a);
	return 0;
}

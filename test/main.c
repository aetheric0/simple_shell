#include "main.h"

int main(void)
{
	char arr[] = "The boy";

	arr[_strcspsn(arr, 'y')] = 'i';

	printf("%s", arr);

	return (0);
}

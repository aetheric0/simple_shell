#include "main.h"

int _strcspsn(char *source, char s)
{
        int i;

        for (i = 0; source[i] != s; i++)
		;

        return (i);
}

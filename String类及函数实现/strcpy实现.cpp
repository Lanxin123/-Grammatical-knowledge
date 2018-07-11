#include "stdafx.h"
#include <iostream>
#include <assert.h>

using namespace std;

char *strcpy(char *strDest, const char *strSrc)
{
	assert((strDest != NULL) && (strSrc != NULL));
	char *address = strDest;
	while (*strSrc != '\0')
		*strDest++ = *strSrc++;
	return address;
}
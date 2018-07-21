#include "stdafx.h"
#include <iostream>
#include <assert.h>

using namespace std;

char *strcpy(char *strDes, const char *string)
{
	if (string == NULL&&strDes == NULL)
		return NULL;
	char* address = strDes;
	while (*string != '\0')
		*(strDes++) = *(string++);
	*strDes = '\0';//一定注意最后结束时一定要加一个\0结尾；
	return address;//返回保存的strDes首地址;

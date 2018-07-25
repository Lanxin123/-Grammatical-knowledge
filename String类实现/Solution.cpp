#include "stdafx.h"
#include <utility>
#include <string.h>

#pragma once

#include <iostream>

class StringRealize
{
	friend std::ostream& operator<<(std::ostream& os, const StringRealize& str);//输出符重载
	friend std::ostream& operator>>(std::ostream& os, const StringRealize& str);//输入符重载

public:
	StringRealize(const char *str = NULL);//普通构造函数
	StringRealize(const StringRealize& str);//拷贝构造函数
	~StringRealize(void);//析构函数

	StringRealize& operator=(const StringRealize& str);//赋值运算符'='号重载
	StringRealize operator+(const StringRealize& str);//链接字符串‘+’号重载
	bool operator==(const StringRealize& str);//等号运算符‘==’号重载

	int getLength(void);//获取字符串的长度
private:
	char *m_data;//用于保存字符串
};

#include "StringRealize.h"

//普通构造函数
StringRealize::StringRealize(const char *str)
{
	if (str == NULL)
	{
		this->m_data = NULL;
	}
	else
	{
		this->m_data = new char[strlen(str) + 1];
		strcpy(this->m_data, str);
	}
}

//拷贝构造函数
StringRealize::StringRealize(const StringRealize& str)
{
	if (str.m_data == NULL)
	{
		this->m_data = NULL;
	}
	else
	{
		this->m_data = new char[strlen(str.m_data) + 1];
		strcpy(this->m_data, str.m_data);
	}
}

//析构函数
StringRealize::~StringRealize(void)
{
	if (this->m_data)
	{
		delete[] this->m_data;
		this->m_data = NULL;
	}
}

//赋值运算符'='号重载
StringRealize& StringRealize::operator=(const StringRealize& str)
{
	if (this != &str)
	{
		delete[] this->m_data;
		this->m_data = NULL;

		if (str.m_data == NULL)
		{
			this->m_data = NULL;
		}
		else
		{
			this->m_data = new char[strlen(str.m_data) + 1];
			strcpy(this->m_data, str.m_data);
		}
	}

	return *this;
}

//链接字符串‘+’号重载
StringRealize StringRealize::operator+(const StringRealize& str)
{
	StringRealize newString;
	if (str.m_data == NULL)
	{
		return *this;
	}
	else if (this->m_data == NULL)
	{
		newString = str;
	}
	else
	{
		newString.m_data = new char[strlen(str.m_data) + strlen(this->m_data) + 1];
		strcpy(newString.m_data, this->m_data);
		strcpy(newString.m_data, str.m_data);
	}

	return newString;
}

//等号运算符‘==’号重载
bool StringRealize::operator==(const StringRealize& str)
{
	if (strlen(this->m_data) != strlen(str.m_data))
	{
		return false;
	}
	else
	{
		return strcmp(this->m_data, str.m_data) ? false : true;
	}

}

//获取字符串的长度
int StringRealize::getLength()
{
	return strlen(this->m_data);
}

//输出符重载
std::ostream& operator<<(std::ostream& os, const StringRealize& str)
{
	os << str.m_data;
	return os;
}

//输入符重载
std::ostream& operator>>(std::ostream& os, const StringRealize& str)
{
	os >> str.m_data;
	return os;
}
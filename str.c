#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "str.h"

unsigned int my_strlen(const char* str)
{
	int length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}

	return length;
}


char* my_strcpy(char* dst_, const char* src_)
{
	if (!dst_ || !src_)
		return NULL;

	char* tmp = dst_;
	while (*src_)
	{
		*dst_ = *src_;
		dst_++;
		src_++;
	}
	*dst_ = '\0';

	return tmp;
}

char* my_strcat(char* dst_, const char* src_)
{
	if (!dst_ || !src_)
		return NULL;

	char* tmp = dst_;
	while (*dst_)
	{
		dst_++;
	}

	while (*src_)
	{
		*dst_ = *src_;
		dst_++;
		src_++;
	}
	*dst_ = '\0';

	return tmp;
}

int my_strcmp(const char* str1_, const char* str2_)
{
	unsigned int len1 = my_strlen(str1_);
	unsigned int len2 = my_strlen(str2_);

	if (len1 == len2)
	{
		return 0;
	}
	else
	{
		if (len1 > len2)
		{
			return 234;
		}
		else
		{
			return -234;
		}
	}
}


char* my_strstr(const char* str1_, const char* str2_)
{
	if (*str2_ == '\0')
	{
		return (char*)str1_;
	}

	while (*str1_) {
		const char* h = str1_;
		const char* n = str2_;

		while (*str1_ && *n && *str1_ == *n)
		{
			str1_++;
			n++;
		}

		if (*n == '\0') {
			return (char*)h;
		}

		str1_ = h + 1;
	}

	return NULL;
}



char* fgetline(FILE* stream) {
	char* line = NULL;
	size_t size = 0;
	size_t index = 0;
	int c;

	while ((c = fgetc(stream)) != EOF && c != '\n') {
		if (index == size) {
			size_t new_size = size == 0 ? 64 : size * 2;
			char* temp = realloc(line, new_size);
			if (temp == NULL) {
				free(line);
				return NULL;
			}
			line = temp;
			size = new_size;
		}

		line[index++] = (char)c;
	}

	char* temp = realloc(line, index + 1);
	if (temp == NULL) {
		free(line);
		return NULL;
	}
	line = temp;
	line[index] = '\0';

	return line;
}
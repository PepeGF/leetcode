// https://leetcode.com/problems/fizz-buzz/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>

/* 
static int	ft_num_len(int n);
static char	*ft_fill_str_positive(char *str, int n, int digits);

char	*ft_itoa(int n)
{
	int		digits;
	char	*str;

	digits = ft_num_len(n);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	str = ft_fill_str_positive(str, n, digits);
	return (str);
}

static char	*ft_fill_str_positive(char *str, int n, int digits)
{
	str[digits] = '\0';
	while (digits)
	{
		str[digits - 1] = n % 10 + '0';
		n /= 10;
		digits--;
	}
	return (str);
}

static int	ft_num_len(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	while (src[i] && i < (dstsize - 1) && dstsize != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	lens1;

	lens1 = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (lens1 + 1));
	if (ptr == NULL)
		return (0);
	ft_strlcpy(ptr, s1, lens1 + 1);
	return (ptr);
} */

char ** fizzBuzz(int n, int* returnSize)
{(void)returnSize;
	int i;
	char **string;

	i = 1;
	string = malloc(sizeof(char *) * n);
	// string = malloc(sizeof(char *) * (n + 1));
	// string[n] = NULL;
	while (i <= n)
	{
		if (i % 3 == 0 && i % 5 == 0)
			string[i - 1] = "FizzBuzz"; //faster with strdup but with more mem
		else if (i % 3 == 0)
			string[i - 1] = "Fizz"; //faster with strdup but with more mem
		else if (i % 5 == 0)
			string[i - 1] = "Buzz"; //faster with strdup but with more mem
		else
			string[i - 1] = ft_itoa(i);
		i++;
	}
	*returnSize = n;
	return (string);
}

int main (void)
{
	int n = 15;
	int m = 15;
	char **str = fizzBuzz(n, &m);

	(void)str;
 
	int i = 0;
	while (i < n)
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (0);
}
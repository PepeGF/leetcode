// https://leetcode.com/problems/fizz-buzz/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>


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


char ** fizzBuzz(int n, int* returnSize)
{(void)returnSize;
	int i;
	char **string;

	i = 1;
	string = malloc(sizeof(char *) * (n + 1));
	string[n] = NULL;
	while (i <= n)
	{
		if (i % 3 == 0 && i % 5 == 0)
			string[i] = "FizzBuzz";
		else if (i % 3 == 0)
			string[i] = "Fizz";
		else if (i % 5 == 0)
			string[i] = "Buzz";
		else
			string[i] = ft_itoa(i);
		
		printf("%s\n", string[i]);
		i++;
	}
	*returnSize = n + 1;
	return (string);
}

int main (void)
{
	int n = 15;
	int m = 15;
	char **str = fizzBuzz(n, &m);

	(void)str;
	return (0);
/* 
	int i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	} */
}
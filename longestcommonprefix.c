#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int matrix_len(char **strs)
{
	if (!strs)
		return 0;
	int i = 0;
	while (strs[i])
	{
		i++;
	}
	return i;
}

int str_len(char *str)
{
	int i;

	i = 0;
	if (!str)
		return i;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	get_shortest_index(char **strs)
{
	int min;
	int i;
	int len;
	int index_min;

	if (!strs)
		return 0;
	i = 0;
	min = str_len(strs[0]);
	index_min = 0;
	i++;
	while (strs[i])
	{
		len = str_len(strs[i]);
		if (len < min)
		{
			index_min = i;
			min = len;
		}
		i++;
	}
	return (index_min);
}

char * longestCommonPrefix(char ** strs, int strsSize)
{
	int index_shortest;
	int min_len;
	int i;
	char *aux = NULL;
	int j;
	// int k = 0;

	if (!strs)
		return NULL;
	index_shortest = get_shortest_index(strs);
	min_len = str_len(strs[index_shortest]);
	i = 0;
	while (strs[index_shortest][i])
	{
		j = 0;
		while (strs[j])
		{
			if (strs[j][i] != strs[index_shortest][i])
				break;
			j++;
		}
		if (j != strsSize)
			break;
		i++;
	}
	strlcpy(aux, strs[index_shortest], i);
	/* aux = malloc (i + 1);
		aux[i] = '\0';
	while (k < i)
	{
		aux[k] = strs[index_shortest][k];
		k++;
	} */
	return (aux);
}

int main()
{
	char *xxx;
	char *str[] = {"dog","racecar","car", NULL};
	xxx = longestCommonPrefix(str, matrix_len(str));
	printf("index shortest %d\n", get_shortest_index(str));
	printf("%s\n", xxx);
	return 0;
}
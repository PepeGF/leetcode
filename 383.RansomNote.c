// https://leetcode.com/problems/ransom-note/

/* 
 1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters
 */
#include <stdio.h>
#include <stdbool.h>

void	initused(int *array)
{
	int i;

	i = 0;
	while (i < 26)
	{
		array[i] = 0;
		i++;
	}
}

void readmagazine(char *magazine, int *avaliable)
{
	int i;

	i = 0;
	while (magazine[i])
	{
		avaliable[magazine[i] - 97]++;
		i++;
	}
}

void readransomnote(char *ransomNote, int *avaliable)
{
	int i;

	i = 0;
	while (ransomNote[i])
	{
		avaliable[ransomNote[i] - 97]--;
		i++;
	}
}

bool canConstruct(char * ransomNote, char * magazine)
{
	int avaliable[26];
	int i;

	initused(avaliable);
	readmagazine(magazine, avaliable);
	readransomnote(ransomNote, avaliable);
	i = 0;
	while (i < 26)
	{
		if (avaliable[i] < 0)
			return (false);
		i++;
	}
	return (true);
}

int main(void)
{
	char ransomNote[] = "abcdefghijklmnopqrtsuvwxyz";
	char magazine[] = "abcdefghijklmnopqrtzsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxyabcdefghijklmnopqrtsuvwxy";

 if (canConstruct(ransomNote, magazine) == true)
 	printf("TRUE\n");
else
	printf("FALSE\n");
/*	int	i;
	i = 97;
	while (i <= 122)
	{
		printf("'%c',", (char)i);
		i++;
	}
	printf("\n");
 */
	return (0);
}
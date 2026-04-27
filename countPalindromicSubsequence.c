#include <stdio.h>
#include <string.h>

void	intialize_tab(int *tab, int matrix[256][256])
{
	int	i;

	i = 0;
	while (i < 256)
	{
		tab[i] = -1;
		bzero(matrix[i++], 256 * sizeof(int));
	}
}
int	special(int start, int end, int *showed, char *s)
{
	int	i;
	int	re;

	i = start + 1;
	re = 0;
	while (i < end)
	{
		if (!showed[s[i]])
		{
			re++;
			showed[s[i]] = 1;
		}
		i++;
	}
	return (re);
}
int	countPalindromicSubsequence(char *s)
{
	int	first_seen[256];
	int	mid[256][256];
	int	i;
	int	re;

	i = 0;
	re = 0;
	intialize_tab(first_seen, mid);
	while (s[i])
	{
		if (first_seen[s[i]] == -1)
			first_seen[s[i]] = i;
		else
		{
			re += special(first_seen[s[i]], i, mid[s[i]], s);
		}
		i++;
	}
	return (re);
}
int	main(void)
{
	printf("case 1 : %d \n", countPalindromicSubsequence("abcdef"));
}

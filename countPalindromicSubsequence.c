#include <stdio.h>
#include <string.h>
<<<<<<< HEAD

=======
>>>>>>> dd8cd06534ea9976b29c42edaea227cc82b51a5a
void	intialize_tab(int *tab, int matrix[26][26])
{
	int	i;

	i = 0;
	while (i < 26)
	{
		tab[i] = -1;
		bzero(matrix[i++], 26 * sizeof(int));
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
<<<<<<< HEAD
		if (!showed[s[i] % 26])
		{
			re++;
			showed[s[i] % 26] = 1;
=======
		if (!showed[s[i]%26])
		{
			re++;
			showed[s[i]%26] = 1;
>>>>>>> dd8cd06534ea9976b29c42edaea227cc82b51a5a
		}
		i++;
	}
	return (re);
}
int	countPalindromicSubsequence(char *s)
{
	int	first_seen[26];
	int	mid[26][26];
	int	i;
	int	re;

	i = 0;
	re = 0;
	intialize_tab(first_seen, mid);
	while (s[i])
	{
		if (first_seen[s[i] % 26] == -1)
			first_seen[s[i] % 26] = i;
		else
		{
			re += special(first_seen[s[i] % 26], i, mid[s[i] % 26], s);
			if (first_seen[s[i] % 26] != i - 1 && (i < (strlen(s) - 1) && s[i+ 1] != s[i]))
				first_seen[s[i] % 26] = i;
		}
		i++;
	}
	return (re);
}
int	main(void)
{
	printf("case 1 : %d \n", countPalindromicSubsequence("xabdxx"));
}

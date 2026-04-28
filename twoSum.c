#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int			value;
	int			index;
	struct node	*next;
}				node;
int	hash(int n, int numsSize)
{
	if (++n < 0)
		n = -1 * n;
	return (n % numsSize);
}
node	*new_node(int value, int index)
{
	node	*new;

	new = malloc(sizeof(node));
	new->value = value;
	new->index = index;
	new->next = NULL;
	return (new);
}
void	insert(node **beg, node *new)
{
	node	*curent;

	if (!(*beg))
	{
		*beg = new;
		return ;
	}
	curent = *beg;
	while (curent->next)
		curent = curent->next;
	curent->next = new;
}
int	*make_table(int i, int j)
{
	int	*ret;

	ret = malloc(2 * sizeof(int));
	ret[0] = i;
	ret[1] = j;
	return (ret);
}
int	*twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	node	**tab;
	int		i;
	node	*new;
	int		index;

	tab = calloc(numsSize, sizeof(node));
	*returnSize = 2;
	i = 0;
	while (i < numsSize)
	{
		index = hash(nums[i], numsSize);
		new = new_node(nums[i], i);
		insert(&tab[index], new);
		i++;
	}
	i = 0;
	while (i < numsSize)
	{
		if (tab[hash(target - nums[i], numsSize)])
		{
			new = tab[hash(target - nums[i], numsSize)];
			while (new)
			{
				if (new->value + nums[i] == target &&new->index != i)
					return (make_table(i, new->index));
				new = new->next;
			}
		}
		i++;
	}
	return (NULL);
}

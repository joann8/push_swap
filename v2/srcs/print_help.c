#include "../sort.h"
#include <stdio.h>

void print_struct(int size, t_d *d)
{
	int j;

	j = 0;
	printf("___________________\n");
	while (j < size)
	{
		if (d->a[j].bol == 1 && d->b[j].bol == 1)
			printf("  |%d|   -   |%d|\n", d->a[j].nb, d->b[j].nb);
		else if (d->a[j].bol == 1)
			printf("  |%d|   -   |-|\n", d->a[j].nb);
		else if (d->b[j].bol == 1)
			printf("  |-|   -   |%d|\n", d->b[j].nb);
		else
			printf("  |-|   -   |-|\n");
		j++;
	}
	printf("\n\n");
}

int	print_list(t_list *l, int mod)
{
	t_list *tmp;
	int count;

	tmp = l;
	count = 0;
	while (tmp)
	{
		if (mod == 1 || mod == 2)
			printf("%s\n", tmp->content);
		count++;
		tmp = tmp->next;
	}
	if (mod == 1 || mod == 0)
		printf("total instructions = %d\n", count);
	return(count);
}
/*
void print_struct(int ac, t_s *a, t_s *b)
{
	int i;
	int j;

	printf("________________\n");
	printf("*** Stack A ****\n");
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (a[j].bol == 1)
			printf("   %d: nb = |%d| bol = %d\n", i, a[j].nb, a[j].bol);
		else
			printf("   %d: nb = |-| bol = %d\n", i, a[j].bol);
		i++;
		j++;
	}
	printf("\n*** Stack B ****\n");
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (b[j].bol == 1)
			printf("   %d: nb = |%d| bol = %d\n", i, b[j].nb, b[j].bol);
		else
			printf("   %d: nb = |-| bol = %d\n", i, b[j].bol);
		i++;
		j++;
	}
	printf("\n\n");
}*/

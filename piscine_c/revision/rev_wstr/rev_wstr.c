#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strwords(char *str)
{
	int		i;
	int		words;

	i = 0;
	words = 1;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			words++;
		i++;
	}
	return (words);
}

void	printer(char *str, int *mark, int n)
{
	int		i;

	i = 0;
	while (i != mark[n])
	{
		i++;
	}
	while (str[i] != ' ' && str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	if (n != 0)
		ft_putchar(' ');
	if (n > 0)
		printer(str, mark, n - 1);
}

void	ft_rev(char *str)
{
	int		i;
	int		n;
	int		*mark;

	i = 0;
	n = 0;
	mark = (int*)malloc(sizeof(int) * ft_strwords(str));
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || i == 0)
		{
			if (i == 0)
				mark[n] = i;
			else
				mark[n] = i + 1;
			n++;
		}
		i++;
	}
	printer(str, mark, n - 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_rev(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}

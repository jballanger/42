#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		separator(char str)
{
	if (str == ' ' || str == '\t')
		return (1);
	return (0);
}

int		ft_strwords(char *str)
{
	int		i;
	int		words;

	i = 0;
	words = 1;
	while (str[i] != '\0')
	{
		if (separator(str[i]) < 1)
		{
			while (separator(str[i]) < 1)
				i++;
			words++;
		}
		i++;
	}
}

int		ft_strlen(char *str, int i)
{

}

void	ft_rostring(char *str)
{
	int		i;
	int		n;
	char	*tab;

	i = 0;
	n = 0;
	tab = (char*)malloc(sizeof(char) * ft_strwords(str));
	while (str[i] != '\0')
	{
		if (separator(str[i] > 0 && str[i] != '\0'))
			i++;
		if (separator(str[i]) < 1 && str[i] != '\0')
		{
			tab[n] = (char*)malloc(sizeof(char) * ft_strlen(str, i));
			while (separator(str[i]) < 1 && str[i] != '\0')
			{
				tab[n] = ft_strcat(tab[n], str[i]);
				i++;
			}
			n++;
		}
	}
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_rostring(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}

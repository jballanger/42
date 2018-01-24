#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		nbr;

	i = 0;
	sign = 0;
	nbr = 0;
	while (str[i] < 33)
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += (str[i] - 48);
		i++;
	}
	if (sign == 1)
		nbr *= -1;
	return (nbr);
}

int		main(void)
{
	printf("atoi %d | ft_atoi %d\n", atoi(" aa 23 aa"), ft_atoi(" aa 23 aa"));
	printf("atoi %d | ft_atoi %d\n", atoi(" -158 -23"), ft_atoi(" -158 -23"));
	printf("atoi %d | ft_atoi %d\n", atoi("abc 22 abc"), ft_atoi("abc 22 abc"));
	printf("atoi %d | ft_atoi %d\n", atoi("   -22"), ft_atoi("   -22"));
	printf("atoi %d | ft_atoi %d\n", atoi("abc15"), ft_atoi("abc15"));
	printf("atoi %d | ft_atoi %d\n", atoi("-15 abc"), ft_atoi("-15 abc"));
	printf("atoi %d | ft_atoi %d\n", atoi("12211t11"), ft_atoi("12211t11"));
	printf("atoi %d | ft_atoi %d\n", atoi("-2147483648"), ft_atoi("-2147483648"));
	return (0);
}

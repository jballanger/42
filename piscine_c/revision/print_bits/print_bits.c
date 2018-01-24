#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		n;

	n = 128;
	while (n > 0)
	{
		if (n & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		n >>= 1;
	}
}

int		main(void)
{
	print_bits('r');
	return (0);	
}

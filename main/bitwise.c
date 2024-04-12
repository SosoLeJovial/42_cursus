#include <unistd.h>
#include <stdio.h>

// print_bits
void	binary_print(unsigned char octet)
{
	int		i;
	unsigned char bit;
	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
	write(1 ,"\n", 1);
}

unsigned char reverse_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int main(int ac, char **av)
{
	unsigned char octet;

	if (ac != 2)
		return (0);
	octet = av[1][0];
	binary_print(octet);
	binary_print(octet);
	return (0);
}


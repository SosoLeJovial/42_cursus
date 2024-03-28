#include <unistd.h>
#include <stdio.h>

// print_bits
void	binary_print(unsigned char octet)
{
	char	binary[9];
	int		i;

	i = 8;
	binary[8] = '\0';
	while (--i >= 0)
		binary[7 - i] = (octet & (1 << i)) ? '1' : '0';
	while (binary[++i])
		write(1, &binary[i], 1);
}

int main(void)
{
	unsigned char octet;

	octet = 5;
	binary_print(octet);
	return (0);
}


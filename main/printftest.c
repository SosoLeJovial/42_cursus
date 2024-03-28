// # include <stdlib.h>
# include <limits.h>

int	main(void)
{
	char character = 'A';
	char *string = "Test string";
	void *pointer = malloc(1); // Dynamically allocated to get a non-static address
	int integer = 42;
	int negative_integer = -42;
	unsigned int unsigned_integer = INT_MAX;
	unsigned int hex_number = 0x2a;

    // Test for %c
	printf("Real printf - char: '%c'\n", character);
	ft_printf("Your printf - char: '%c'\n", character);

    // Test for %s
	printf("Real printf - string: '%s'\n", string);
	ft_printf("Your printf - string: '%s'\n", string);

    // Test for %p
    printf("Real printf - pointer: '%p'\n", pointer);
    ft_printf("Your printf - pointer: '%p'\n", pointer);

    // Test for %d
    printf("Real printf - integer: '%d'\n", integer);
    ft_printf("Your printf - integer: '%d'\n", integer);

    // Test for negative %d
    printf("Real printf - negative integer: '%d'\n", negative_integer);
    ft_printf("Your printf - negative integer: '%d'\n", negative_integer);

    // Test for %i
    printf("Real printf - integer (%%i): '%i'\n", integer);
    ft_printf("Your printf - integer (%%i): '%i'\n", integer);

    // Test for %u
    printf("Real printf - unsigned integer: '%u'\n", unsigned_integer);
    ft_printf("Your printf - unsigned integer: '%u'\n", unsigned_integer);

    // Test for %x
    printf("Real printf - hexadecimal (lowercase): '%x'\n", hex_number);
    ft_printf("Your printf - hexadecimal (lowercase): '%x'\n", hex_number);

    // Test for %X
    printf("Real printf - hexadecimal (uppercase): '%X'\n", hex_number);
    ft_printf("Your printf - hexadecimal (uppercase): '%X'\n", hex_number);

    free(pointer); // Free the allocated memory
}

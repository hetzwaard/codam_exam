//#include <unistd.h>
//#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}


//int main (void)
//{
//	unsigned char ox = '2';
//	print_bits(ox);
//	return 0;
//}
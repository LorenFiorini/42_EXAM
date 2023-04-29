
unsigned char	swap_bits(unsigned char octet)
{
	unsigned char ans = 0;
	int i = 0;
	while (i < 4) {
		if (octet & (1 << i)) ans |= (1 << (4 + i));
		if (octet & (1 << (4 + i))) ans |= (1 << i);
		i++;
	}
	return ans;
}

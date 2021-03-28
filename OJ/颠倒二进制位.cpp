/*
颠倒给定的 32 位无符号整数的二进制位。
输入: 43261596 (00000010100101000001111010011100)
输出: 964176192 (00111001011110000010100101000000)
*/

uint32_t reverseBits(uint32_t n)
{

	uint32_t res = 0;

	// method 1
	// for (int i = 0; i < 32; ++i)
	// {
	//     res = (res << 1) | (n & 1);
	//     n >>= 1;
	// }

	// optimize method 1
	for (int i = 0; i < 32 && n > 0; ++i)
	{
		res |= (n & 1) << (31 - i);
		n >>= 1;
	}

	return res;
}

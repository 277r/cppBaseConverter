// file should've been called charHex, because it'll be bidirectional
#include <string>

char data16[] = "0123456789ABCDEF";
unsigned char getIndex16(int x)
{
	return data16[x];
}

std::string toHex(unsigned char input)
{
	// modulo by 16, rest is one of the bytes, remove the amount modulo'd
	std::string returndata;
	int a = input % 16;
	int b = (input -a ) / 16;
	//std::cout << a << '\n' << b << '\n';
	// a and b are characters from 0 - 15, turn into character with function or lookup array
	returndata += getIndex16(b);
	returndata += getIndex16(a);

	
	// ÿ
	return returndata;
}

int ints16[] = {0, 1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12, 13, 14,15};
int getInt16(char x)
{
	x -= '0';
	for (int i = 0; i < sizeof(ints16) / 4; i++)
	{
		if (x == ints16[i]){
			return ints16[i];
		}
	}
	return 255;
}

// the strings accepted are only 2 bytes, because there's only 2 bytes (in (one extended ASCII character or byte) saved as 2 bytes in hex)
char toChar(std::string input){
	int b = input[0];
	int a = input[1];
	b = getInt16(b);
	a = getInt16(a);
	return b * 16 + a;
}
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


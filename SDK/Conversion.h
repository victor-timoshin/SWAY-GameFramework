#ifndef CONVERSION_H
#define CONVERSION_H

inline std::string IntToStr(int value)
{
	char buffer[32] = {};
	sprintf_s(buffer, "%d", value);
	return buffer;
}

inline std::string UIntToStr(unsigned int value)
{
	char buffer[32] = {};
	sprintf_s(buffer, "%u", value);
	return buffer;
}

inline std::string ULongToStr(unsigned long value)
{
	char buffer[32] = {};
	sprintf_s(buffer, "%lu", value);
	return buffer;
}

#endif // CONVERSION_H
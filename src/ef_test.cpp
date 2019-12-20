#include <easyflash.h>
#include <variant.h>
#include <SPI.h>

void test(uint8_t a)
{
	Serial.print(a);
}

void test1(const char str[])
{
	Serial.print(str);
}

void test2(uint32_t a)
{
	Serial.print(a);
}

uint8_t transfer(uint8_t a)
{
	return SPI.transfer(a);
}
void spiBegin()
{
	return SPI.begin();
}
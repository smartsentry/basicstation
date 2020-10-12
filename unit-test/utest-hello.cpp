
#include <stdio.h>
#include <stdarg.h>
#include "CppUTest/TestHarness.h"

TEST_GROUP(HelloWorld)
{ 
	void setup()
	{

	}
	void teardown()
	{

	}
};

TEST(HelloWorld, PrintOk)
{
	static const char * str = "Hello World!";

    STRCMP_EQUAL( "Hello World!", str );
}
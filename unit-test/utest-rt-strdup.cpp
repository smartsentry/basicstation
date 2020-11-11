//
// Created by clock on 10/11/2020.
//

#include <stdio.h>
#include <stdarg.h>
#include "CppUTest/TestHarness.h"

extern "C"
{
#include "rt.h"
}

TEST_GROUP(Runntime_strdup)
{
    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(Runntime_strdup, dup)
{
    char * strdup = rt_strdup("Hello World!");

    STRCMP_EQUAL( "Hello World!", strdup );

    free(strdup);
}

TEST(Runntime_strdup, dupWithNULL)
{
    char * strdup = rt_strdup(NULL);

    POINTERS_EQUAL( NULL, strdup );

    free(strdup);
}

TEST(Runntime_strdup, dupWithQuote)
{
    char * strdup = rt_strdupq("Hello World!");

    STRCMP_EQUAL( "\"Hello World!\"", strdup );

    free(strdup);
}


//
// Created by clock on 11/11/2020.
//

#include <stdio.h>
#include <stdarg.h>
#include "CppUTest/TestHarness.h"

extern "C"
{
#include "rt.h"
}

TEST_GROUP(Runntime_lsb)
{
    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(Runntime_lsb, rlsbf2)
{
    const u1_t buf = 0x02;
    u2_t ret = rt_rlsbf2(&buf);

    // expected value is uncertain
    LONGS_EQUAL( 0x8802, ret );
}

TEST(Runntime_lsb, rt_rmsbf2)
{
    const u1_t buf = 0x01;
    u2_t ret = rt_rlsbf2(&buf);

    // expected value is uncertain
    LONGS_EQUAL( 0x8801, ret );
}

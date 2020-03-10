#include <test.h>
#include <CuTest.h>

void TestCuTestmeFunction(CuTest *tc)
{
	CuAssertTrue(tc, testme() == 42);
}

void TestCuSuccess(CuTest *tc)
{
	CuAssertTrue(tc, 2 == 2);
}



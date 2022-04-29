#include <ctest.h>
#include <geometrylib/geomfunc.h>

CTEST(arithmetic_suite, simple_sum)
{
    // Given
    float x = 1;
    float y = 2;
    int r = 3;

    // When

    // Then
    const int expected = 3;
    ASSERT_EQUAL(expected, result);
}
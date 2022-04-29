#include <geometrylib/geomfunc.h>
#include <ctest.h>

CTEST(ctest, ctest)
{
    char str[] = "closebracket)";
    int cbflagexpected = 12;
    int cbflag = isClsBracket(str, 0);
    ASSERT_EQUAL(cbflagexpected, cbflag);
}
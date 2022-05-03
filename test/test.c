#include <geometrylib/geomfunc.h>
#include <ctest.h>

CTEST(ctest, test_close_bracket)
{
    char str[] = "closebracket)";
    int cbflagexpected = 12;
    int cbflag = isClsBracket(str, 0);
    ASSERT_EQUAL(cbflagexpected, cbflag);
}

CTEST(ctest, test_open_bracket)
{
    char str[] = "open(bracket";
    int obflagexpected = 4;
    int obflag = isOpnBracket(str);
    ASSERT_EQUAL(obflagexpected, obflag);
}

CTEST(ctest, test_comma)
{
    char str[] = "isinmystrcomma()";
    int commaflag = isCorrectCntComma(str);
    int expectedcntcomma = 0;
    ASSERT_EQUAL(expectedcntcomma, commaflag);
}

CTEST(ctest, area_test)
{
    float expectedarea = 28.27;
    float areagetted = area(3);
    ASSERT_EQUAL(expectedarea, areagetted);
}

CTEST(ctest, perimeter_test)
{
    float expectedperimeter= 18.85;
    float perimetergetted = perimeter(3);
    ASSERT_EQUAL(expectedperimeter, perimetergetted);
}

CTEST(ctest, test_intersection)
{
    struct circle c1 , c2;
    c1.c1 = 1;
    c1.c2 = 1;
    c1.radius = 3;
    c2.c1 = 2;
    c2.c2 = 2;
    c2.radius = 2;
    int expectedintersection = 1;
    int gettedinstersection = isintersection(c1,c2);
    ASSERT_EQUAL(expectedintersection, gettedinstersection);
}

CTEST(ctest, test_tofloat)
{
    char* c = "0.123456";
    float cgetted = charToFloat(c);
    float cexpected = 0.123456;
    ASSERT_EQUAL(cexpected, cgetted);
}
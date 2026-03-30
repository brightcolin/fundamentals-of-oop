#include "CP_ComplexTest.h"

void CP_ComplexTest::testIncDec() {

    CP_Complex c, ret;

    printHeader("operator++ prefix   real+1, imag unchanged, return self");
    c = CP_Complex(3,4);  check("Case1 General   ++(3+4i)",   ++c, CP_Complex(4,4));
    c = CP_Complex(0,5);  check("Case2 Imaginary ++(0+5i)",   ++c, CP_Complex(1,5));
    c = CP_Complex(6,0);  check("Case3 Real      ++(6)",      ++c, CP_Complex(7,0));
    c = CP_Complex(0,0);  check("Case4 Zero      ++(0)",      ++c, CP_Complex(1,0));
    c = CP_Complex(-2,3); check("Case5 Negative  ++(-2+3i)",  ++c, CP_Complex(-1,3));

    printHeader("operator++ postfix  return old copy, then real+1");
    c = CP_Complex(3,4);  ret = c++;
    check("Case1 return val (3+4i)++",   ret, CP_Complex(3,4));
    check("Case1 self after",              c,   CP_Complex(4,4));
    c = CP_Complex(0,5);  ret = c++;
    check("Case2 return val (0+5i)++",   ret, CP_Complex(0,5));
    check("Case2 self after",              c,   CP_Complex(1,5));
    c = CP_Complex(6,0);  ret = c++;
    check("Case3 return val (6)++",      ret, CP_Complex(6,0));
    c = CP_Complex(0,0);  ret = c++;
    check("Case4 return val (0)++",      ret, CP_Complex(0,0));
    c = CP_Complex(-2,3); ret = c++;
    check("Case5 return val (-2+3i)++",  ret, CP_Complex(-2,3));
    check("Case5 self after",              c,   CP_Complex(-1,3));

    printHeader("operator-- prefix   real-1, imag unchanged, return self");
    c = CP_Complex(3,4);  check("Case1 General   --(3+4i)",   --c, CP_Complex(2,4));
    c = CP_Complex(0,5);  check("Case2 Imaginary --(0+5i)",   --c, CP_Complex(-1,5));
    c = CP_Complex(6,0);  check("Case3 Real      --(6)",      --c, CP_Complex(5,0));
    c = CP_Complex(0,0);  check("Case4 Zero      --(0)",      --c, CP_Complex(-1,0));
    c = CP_Complex(-2,3); check("Case5 Negative  --(-2+3i)",  --c, CP_Complex(-3,3));

    printHeader("operator-- postfix  return old copy, then real-1");
    c = CP_Complex(3,4);  ret = c--;
    check("Case1 return val (3+4i)--",   ret, CP_Complex(3,4));
    check("Case1 self after",              c,   CP_Complex(2,4));
    c = CP_Complex(0,5);  ret = c--;
    check("Case2 return val (0+5i)--",   ret, CP_Complex(0,5));
    check("Case2 self after",              c,   CP_Complex(-1,5));
    c = CP_Complex(6,0);  ret = c--;
    check("Case3 return val (6)--",      ret, CP_Complex(6,0));
    c = CP_Complex(0,0);  ret = c--;
    check("Case4 return val (0)--",      ret, CP_Complex(0,0));
    c = CP_Complex(-2,3); ret = c--;
    check("Case5 return val (-2+3i)--",  ret, CP_Complex(-2,3));
    check("Case5 self after",              c,   CP_Complex(-3,3));
 
    printHeader("operator==  /  operator!=");
    checkBool("Case1 equal     (3+4i)==(3+4i)",
              CP_Complex(3,4) == CP_Complex(3,4),  true);
    checkBool("Case1 not equal (3+4i)==(3+5i)",
              CP_Complex(3,4) == CP_Complex(3,5),  false);
    checkBool("Case2 imaginary (5i)==(5i)",
              CP_Complex(0,5) == CP_Complex(0,5),  true);
    checkBool("Case3 real      (6)==(6)",
              CP_Complex(6,0) == CP_Complex(6,0),  true);
    checkBool("Case4 zero      (0)==(0)",
              CP_Complex(0,0) == CP_Complex(0,0),  true);
    checkBool("Case5 negative  (-2+3i)==(-2+3i)",
              CP_Complex(-2,3) == CP_Complex(-2,3), true);
    checkBool("Case5 not equal (-2+3i)!=(-2+4i)",
              CP_Complex(-2,3) != CP_Complex(-2,4), true);
}

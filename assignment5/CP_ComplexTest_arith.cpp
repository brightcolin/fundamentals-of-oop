#include "CP_ComplexTest.h"

void CP_ComplexTest::testArith() {

    
    printHeader("operator+   (a+c) + (b+d)i");
    check("Case1 General   (3+4i) + (1+2i)",
          CP_Complex(3,4) + CP_Complex(1,2),   CP_Complex(4,6));
    check("Case2 Imaginary (5i)   + (-3i)",
          CP_Complex(0,5) + CP_Complex(0,-3),  CP_Complex(0,2));
    check("Case3 Real      (6)    + (2)",
          CP_Complex(6,0) + CP_Complex(2,0),   CP_Complex(8,0));
    check("Case4 Zero      (3+4i) + (0)",
          CP_Complex(3,4) + CP_Complex(0,0),   CP_Complex(3,4));
    check("Case5 Negative  (-2+3i)+ (-1-4i)",
          CP_Complex(-2,3)+ CP_Complex(-1,-4), CP_Complex(-3,-1));

    
    printHeader("operator-   (a-c) + (b-d)i");
    check("Case1 General   (3+4i) - (1+2i)",
          CP_Complex(3,4) - CP_Complex(1,2),   CP_Complex(2,2));
    check("Case2 Imaginary (5i)   - (-3i)",
          CP_Complex(0,5) - CP_Complex(0,-3),  CP_Complex(0,8));
    check("Case3 Real      (6)    - (2)",
          CP_Complex(6,0) - CP_Complex(2,0),   CP_Complex(4,0));
    check("Case4 Zero      (3+4i) - (0)",
          CP_Complex(3,4) - CP_Complex(0,0),   CP_Complex(3,4));
    check("Case5 Negative  (-2+3i)- (-1-4i)",
          CP_Complex(-2,3)- CP_Complex(-1,-4), CP_Complex(-1,7));

    printHeader("operator*   (ac-bd) + (ad+bc)i");
    check("Case1 General   (3+4i) * (1+2i)",
          CP_Complex(3,4) * CP_Complex(1,2),   CP_Complex(-5,10));
    check("Case2 Imaginary (5i)   * (-3i)",
          CP_Complex(0,5) * CP_Complex(0,-3),  CP_Complex(15,0));
    check("Case3 Real      (6)    * (2)",
          CP_Complex(6,0) * CP_Complex(2,0),   CP_Complex(12,0));
    check("Case4 Zero      (3+4i) * (0)",
          CP_Complex(3,4) * CP_Complex(0,0),   CP_Complex(0,0));
    check("Case5 Negative  (-2+3i)* (-1-4i)",
          CP_Complex(-2,3)* CP_Complex(-1,-4), CP_Complex(14,5));

    printHeader("operator/   [(ac+bd)+(bc-ad)i]/(c2+d2)  +  Case6: divisor=0");
    check("Case1 General   (3+4i) / (1+2i)",
          CP_Complex(3,4) / CP_Complex(1,2),    CP_Complex(2.2,-0.4));
    check("Case2 Imaginary (5i)   / (-3i)",
          CP_Complex(0,5) / CP_Complex(0,-3),   CP_Complex(-5.0/3, 0));
    check("Case3 Real      (6)    / (2)",
          CP_Complex(6,0) / CP_Complex(2,0),    CP_Complex(3,0));
    check("Case5 Negative  (-2+3i)/ (-1-4i)",
          CP_Complex(-2,3)/ CP_Complex(-1,-4),  CP_Complex(-10.0/17, -11.0/17));
    checkThrows("Case6 Zero div  (3+4i) / (0)",
          []{ CP_Complex(3,4) / CP_Complex(0,0); });
}
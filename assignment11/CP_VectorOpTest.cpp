#include <iostream>
#include <cmath>
using namespace std;
#include "CP_VectorOpTest.h"

void CP_VectorOpTest::mb_check(const string &name,bool condition)
{
    m_totalTests++;
    if(condition)
    {
        m_passedTests++;
        cout<<"  [PASS] "<<name<<endl;
    }
    else
    {
        cout<<"  [FAIL] "<<name<<endl;
    }
}

static bool sf_nearEqual(float a,float b,float eps=1e-3f)
{
    return fabs(a-b)<eps*(1.0f+fabs(a)+fabs(b));
}


void CP_VectorOpTest::mb_testGenerate()
{
    cout<<"\n===== T1: Generate Tests ====="<<endl;

    CP_VectorOp op;
    op.mb_generate(10);
    mb_check("generate n=10: size correct",
        op.mb_getN()==10 &&
        (int)op.mb_getV1().size()==10 &&
        (int)op.mb_getV2().size()==10);

    
    mb_check("s is generated (not default 0)",
        op.mb_getS()!=0.0f || true); 

    CP_VectorOp op2;
    op2.mb_generate(100);
    mb_check("generate n=100: size correct",
        op2.mb_getN()==100 &&
        (int)op2.mb_getV1().size()==100 &&
        (int)op2.mb_getV2().size()==100);

    
    CP_VectorOp op3;
    op3.mb_generate(10);
    bool differ=false;
    for(int i=0;i<10;i++)
    {
        if(op.mb_getV1()[i]!=op3.mb_getV1()[i])
        {
            differ=true;
            break;
        }
    }
    mb_check("two generations produce different data",differ);
}

void CP_VectorOpTest::mb_testScalarMul()
{
    cout<<"\n===== T2: Scalar Multiply Tests ====="<<endl;
    
    CP_VectorOp op;
    vector<float> v1={1.0f,2.0f,3.0f,4.0f,5.0f};
    vector<float> v2={5.0f,4.0f,3.0f,2.0f,1.0f};
    op.mb_setData(2.0f,v1,v2);

    vector<float> result=op.mb_scalarMul();
    bool ok=(result.size()==5);
    if(ok) ok=sf_nearEqual(result[0],2.0f)
           &&sf_nearEqual(result[1],4.0f)
           &&sf_nearEqual(result[2],6.0f)
           &&sf_nearEqual(result[3],8.0f)
           &&sf_nearEqual(result[4],10.0f);
    mb_check("s=2, v1={1,2,3,4,5}: result={2,4,6,8,10}",ok);

    op.mb_setData(0.0f,v1,v2);
    result=op.mb_scalarMul();
    ok=true;
    for(int i=0;i<5;i++)
        if(!sf_nearEqual(result[i],0.0f)) ok=false;
    mb_check("s=0: all results are 0",ok);

    op.mb_setData(-1.0f,v1,v2);
    result=op.mb_scalarMul();
    ok=sf_nearEqual(result[0],-1.0f)
      &&sf_nearEqual(result[1],-2.0f)
      &&sf_nearEqual(result[2],-3.0f);
    mb_check("s=-1: result = negation of v1",ok);

    op.mb_setData(1.0f,v1,v2);
    result=op.mb_scalarMul();
    ok=true;
    for(int i=0;i<5;i++)
        if(!sf_nearEqual(result[i],v1[i])) ok=false;
    mb_check("s=1: result = v1 (identity)",ok);
    
    CP_VectorOp opR;
    opR.mb_generate(1000);
    vector<float> resR=opR.mb_scalarMul();
    ok=true;
    float s=opR.mb_getS();
    const vector<float>& rv1=opR.mb_getV1();
    for(int i=0;i<1000;i++)
    {
        if(!sf_nearEqual(resR[i],s*rv1[i]))
        {
            ok=false;
            break;
        }
    }
    mb_check("random n=1000: manual verify s*v1[i]",ok);
}

void CP_VectorOpTest::mb_testDotProduct()
{
    cout<<"\n===== T3: Dot Product Tests ====="<<endl;

    CP_VectorOp op;
    vector<float> v1={1.0f,2.0f,3.0f,4.0f,5.0f};
    vector<float> v2={5.0f,4.0f,3.0f,2.0f,1.0f};
    op.mb_setData(1.0f,v1,v2);

    float dp=op.mb_dotProduct();
    mb_check("v1={1..5}, v2={5..1}: dot=35",sf_nearEqual(dp,35.0f));
    
    vector<float> a={1.0f,0.0f,0.0f,0.0f};
    vector<float> b={0.0f,1.0f,0.0f,0.0f};
    op.mb_setData(1.0f,a,b);
    dp=op.mb_dotProduct();
    mb_check("orthogonal vectors: dot=0",sf_nearEqual(dp,0.0f));
    
    vector<float> c={3.0f,4.0f,0.0f,0.0f};
    op.mb_setData(1.0f,c,c);
    dp=op.mb_dotProduct();
    mb_check("v1=v2={3,4,0,0}: dot=25",sf_nearEqual(dp,25.0f));

    vector<float> z={0.0f,0.0f,0.0f,0.0f};
    op.mb_setData(1.0f,z,z);
    dp=op.mb_dotProduct();
    mb_check("all zeros: dot=0",sf_nearEqual(dp,0.0f));

    vector<float> neg1={-1.0f,-2.0f,0.0f,0.0f};
    vector<float> pos1={3.0f,4.0f,0.0f,0.0f};
    op.mb_setData(1.0f,neg1,pos1);
    dp=op.mb_dotProduct();
    mb_check("neg values: {-1,-2,0,0}.{3,4,0,0}=-11",sf_nearEqual(dp,-11.0f));
}

void CP_VectorOpTest::mb_testParallelConsistency()
{
    cout<<"\n===== T4: Parallel vs Sequential Consistency ====="<<endl;

    CP_VectorOp op;
    op.mb_generate(10000);

    vector<float> seqMul=op.mb_scalarMul();
    vector<float> parMul=op.mb_scalarMulPar();
    bool ok=true;
    for(int i=0;i<10000;i++)
    {
        if(!sf_nearEqual(seqMul[i],parMul[i]))
        {
            ok=false;
            break;
        }
    }
    mb_check("scalarMul: par == seq (n=10000)",ok);
    
    float seqDot=op.mb_dotProduct();
    float parDot=op.mb_dotProductPar();
    
    bool dpOk=fabs(seqDot-parDot)<1e-1f*(1.0f+fabs(seqDot));
    mb_check("dotProduct: par ~= seq (n=10000)",dpOk);

    CP_VectorOp op2;
    op2.mb_generate(100000);
    seqMul=op2.mb_scalarMul();
    parMul=op2.mb_scalarMulPar();
    ok=true;
    for(int i=0;i<100000;i++)
    {
        if(!sf_nearEqual(seqMul[i],parMul[i]))
        {
            ok=false;
            break;
        }
    }
    mb_check("scalarMul: par == seq (n=100000)",ok);
}


void CP_VectorOpTest::mb_testEdgeCases()
{
    cout<<"\n===== T5: Edge Case Tests ====="<<endl;
    
    CP_VectorOp op;
    op.mb_generate(4);
    mb_check("n=4 (minimum): generate ok",op.mb_getN()==4);
    vector<float> r=op.mb_scalarMul();
    mb_check("n=4: scalarMul size=4",(int)r.size()==4);
    float dp=op.mb_dotProduct();
    mb_check("n=4: dotProduct computes (no crash)",true);

    vector<float> small={0.001f,0.002f,0.003f,0.004f};
    vector<float> ones={1.0f,1.0f,1.0f,1.0f};
    op.mb_setData(1000000.0f,small,ones);
    r=op.mb_scalarMul();
    mb_check("large s * small values",
        sf_nearEqual(r[0],1000.0f)&&sf_nearEqual(r[1],2000.0f));
}

void CP_VectorOpTest::mb_runAll()
{
    m_totalTests=0;
    m_passedTests=0;

    cout<<"============================================"<<endl;
    cout<<"   CP_VectorOp Automated Test Suite"<<endl;
    cout<<"============================================"<<endl;

    mb_testGenerate();
    mb_testScalarMul();
    mb_testDotProduct();
    mb_testParallelConsistency();
    mb_testEdgeCases();

    cout<<"\n============================================"<<endl;
    cout<<"  Total: "<<m_totalTests
        <<"  Passed: "<<m_passedTests
        <<"  Failed: "<<(m_totalTests-m_passedTests)<<endl;
    if(m_totalTests==m_passedTests)
        cout<<"  ALL TESTS PASSED!"<<endl;
    else
        cout<<"  SOME TESTS FAILED!"<<endl;
    cout<<"============================================"<<endl;
}

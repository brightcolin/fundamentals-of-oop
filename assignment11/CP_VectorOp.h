#ifndef CP_VECTOROP_H
#define CP_VECTOROP_H

#include <vector>
#include <string>
using namespace std;

class CP_VectorOp
{
private:
    int m_n;
    float m_s;
    vector<float> m_v1;
    vector<float> m_v2;

public:
    CP_VectorOp():m_n(0),m_s(0){}
    ~CP_VectorOp(){}

    void mb_generate(int n);
    vector<float> mb_scalarMul() const;
    vector<float> mb_scalarMulPar() const;

    float mb_dotProduct() const;
    float mb_dotProductPar() const;

    void mb_show() const;
    static void sb_showVector(const string &name,const vector<float> &v);

    int mb_getN() const { return m_n; }
    float mb_getS() const { return m_s; }
    const vector<float>& mb_getV1() const { return m_v1; }
    const vector<float>& mb_getV2() const { return m_v2; }

    void mb_setData(float s,const vector<float> &v1,const vector<float> &v2);
};

#endif

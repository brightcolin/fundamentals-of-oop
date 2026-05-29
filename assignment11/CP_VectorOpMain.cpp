#include <iostream>
using namespace std;
#include "CP_VectorOp.h"

int main(int argc,char *argv[])
{
    int n;
    cout<<"Enter n (integer > 3): ";
    cin>>n;
    if(n<=3)
    {
        cout<<"Error: n must be greater than 3."<<endl;
        system("pause");
        return 1;
    }

    CP_VectorOp op;
    op.mb_generate(n);
    op.mb_show();

    vector<float> sm=op.mb_scalarMul();
    cout<<"\ns * v1 (sequential):"<<endl;
    CP_VectorOp::sb_showVector("result",sm);

    float dp=op.mb_dotProduct();
    cout<<"\nv1 . v2 (sequential) = "<<dp<<endl;

    vector<float> smPar=op.mb_scalarMulPar();
    cout<<"\ns * v1 (parallel):"<<endl;
    CP_VectorOp::sb_showVector("result",smPar);

    float dpPar=op.mb_dotProductPar();
    cout<<"\nv1 . v2 (parallel) = "<<dpPar<<endl;

    system("pause");
    return 0;
}

#include <iostream>
#include <chrono>
#include <iomanip>
#include <algorithm>
using namespace std;
#include "CP_VectorOp.h"

static double sf_benchScalarMulSeq(CP_VectorOp &op,int repeat)
{
    auto start=chrono::high_resolution_clock::now();
    for(int r=0;r<repeat;r++)
    {
        vector<float> result=op.mb_scalarMul();
    }
    auto end=chrono::high_resolution_clock::now();
    return chrono::duration<double,milli>(end-start).count()/repeat;
}

static double sf_benchScalarMulPar(CP_VectorOp &op,int repeat)
{
    auto start=chrono::high_resolution_clock::now();
    for(int r=0;r<repeat;r++)
    {
        vector<float> result=op.mb_scalarMulPar();
    }
    auto end=chrono::high_resolution_clock::now();
    return chrono::duration<double,milli>(end-start).count()/repeat;
}

static double sf_benchDotSeq(CP_VectorOp &op,int repeat)
{
    auto start=chrono::high_resolution_clock::now();
    volatile float dummy;
    for(int r=0;r<repeat;r++)
    {
        dummy=op.mb_dotProduct();
    }
    auto end=chrono::high_resolution_clock::now();
    return chrono::duration<double,milli>(end-start).count()/repeat;
}

static double sf_benchDotPar(CP_VectorOp &op,int repeat)
{
    auto start=chrono::high_resolution_clock::now();
    volatile float dummy;
    for(int r=0;r<repeat;r++)
    {
        dummy=op.mb_dotProductPar();
    }
    auto end=chrono::high_resolution_clock::now();
    return chrono::duration<double,milli>(end-start).count()/repeat;
}


static void sf_drawBar(const string &label,double ms,double maxMs)
{
    int barLen=(int)(ms/maxMs*40);
    if(barLen<1) barLen=1;
    if(barLen>40) barLen=40;
    cout<<setw(14)<<label<<" |";
    for(int i=0;i<barLen;i++) cout<<"#";
    cout<<" "<<fixed<<setprecision(3)<<ms<<" ms"<<endl;
}

int main(int argc,char *argv[])
{
    cout<<"=============================================="<<endl;
    cout<<"  Parallel vs Sequential Performance Benchmark"<<endl;
    cout<<"=============================================="<<endl;

    
    int sizes[]={100,1000,5000,10000,50000,100000,500000,1000000,5000000,10000000};
    int numSizes=10;

    cout<<"\n"<<setw(12)<<"N"
        <<setw(14)<<"ScalMul_Seq"
        <<setw(14)<<"ScalMul_Par"
        <<setw(10)<<"Speedup"
        <<setw(14)<<"DotProd_Seq"
        <<setw(14)<<"DotProd_Par"
        <<setw(10)<<"Speedup"
        <<endl;
    cout<<string(88,'-')<<endl;

    int crossoverScalar=-1;
    int crossoverDot=-1;

    for(int i=0;i<numSizes;i++)
    {
        int n=sizes[i];
        CP_VectorOp op;
        op.mb_generate(n);

        int repeat=(n<10000)?100:(n<100000?20:(n<1000000?5:2));

        double seqScalar=sf_benchScalarMulSeq(op,repeat);
        double parScalar=sf_benchScalarMulPar(op,repeat);
        double seqDot=sf_benchDotSeq(op,repeat);
        double parDot=sf_benchDotPar(op,repeat);

        double speedupScalar=seqScalar/parScalar;
        double speedupDot=seqDot/parDot;

        cout<<setw(12)<<n
            <<setw(12)<<fixed<<setprecision(3)<<seqScalar<<" ms"
            <<setw(12)<<parScalar<<" ms"
            <<setw(9)<<setprecision(2)<<speedupScalar<<"x"
            <<setw(12)<<setprecision(3)<<seqDot<<" ms"
            <<setw(12)<<parDot<<" ms"
            <<setw(9)<<setprecision(2)<<speedupDot<<"x"
            <<endl;

        if(crossoverScalar<0&&speedupScalar>1.0) crossoverScalar=n;
        if(crossoverDot<0&&speedupDot>1.0) crossoverDot=n;
    }

    cout<<"\n=============================================="<<endl;

    {
        int n=sizes[numSizes-1];
        CP_VectorOp op;
        op.mb_generate(n);
        double seqS=sf_benchScalarMulSeq(op,2);
        double parS=sf_benchScalarMulPar(op,2);
        double seqD=sf_benchDotSeq(op,2);
        double parD=sf_benchDotPar(op,2);
        double maxVal=max(max(seqS,parS),max(seqD,parD));

        cout<<"\n  [N="<<n<<"] Scalar Multiply:"<<endl;
        sf_drawBar("Sequential",seqS,maxVal);
        sf_drawBar("Parallel",parS,maxVal);
        cout<<"\n  [N="<<n<<"] Dot Product:"<<endl;
        sf_drawBar("Sequential",seqD,maxVal);
        sf_drawBar("Parallel",parD,maxVal);
    }

    cout<<"\n=============================================="<<endl;
    cout<<"  Crossover Analysis:"<<endl;
    if(crossoverScalar>0)
        cout<<"  Scalar Multiply: parallel faster when n >= "<<crossoverScalar<<endl;
    else
        cout<<"  Scalar Multiply: parallel not faster in tested range"<<endl;
    if(crossoverDot>0)
        cout<<"  Dot Product:     parallel faster when n >= "<<crossoverDot<<endl;
    else
        cout<<"  Dot Product:     parallel not faster in tested range"<<endl;
    cout<<"=============================================="<<endl;

    system("pause");
    return 0;
}

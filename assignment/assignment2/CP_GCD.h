#ifndef GCD_H
#define GCD_H

class GCD {
public:
    GCD(long long a, long long b);

    long long result() const;
    long long geta()   const; 
    long long getb()   const; 

    void print() const;

private:
    long long a_;
    long long b_;
    long long result_;

    static long long compute(long long a, long long b);
};

#endif
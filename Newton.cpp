// Newton Raphson method for calculating square roots
#include "Float.hpp"
#include "math.h"
using namespace std;
Float *Float::newton_sqrt(Float &A, int p)
{
    //  int p;
    //  cout << "enter precision :";
    //  cin >> p;
    p++;
    Float *half;
    int aa = 1 << (A.num->base_exponent - 1);
    vector<int> a_ = {aa};
    half = new Float(a_, A.num->base_exponent, -1);
    Float *X1;
    Float *X0 = &(A);
    // Float *X0 = Float::Toom_multiply(A, *half);
    // int p_ = ceil(p * log(10) / log(A.num->base));
    // int a = ceil(log2(p)) + 1;
    // int limit = 4 * p_;
    vector<int> val = {1};
    Float *prec_num = new Float(val, A.num->base_exponent, -(p));
    for (; /*i <= a*/;)
    {
        X1 = X0;
        Float &b = *(Float::Division(A, *X0, p));
        Float &c = *X0 + (b);
        X0 = &((c) * *half);
        Float *diff = &(*X1 - *X0 - *prec_num);
        if (diff->num->sign != 0)
            break;
        // X0 = Float::Toom_multiply(c, *half);
    }
    X0->make_precise(p);
    return X0;
}
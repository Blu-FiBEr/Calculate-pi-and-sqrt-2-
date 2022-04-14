// Implementation of Toom3 algorithm for multiplication of large integers
#include "Integer.hpp"
using namespace std;
Integer *Integer::Toom_multiply(Integer &A, Integer &B)
{
    if (A.base_exponent != B.base_exponent)
        return NULL;

    int size_a = A.bits.size();
    int size_b = B.bits.size();
    if (max(size_a, size_b) < 5)
        return &(A * B);

    int k = size_b;
    if (size_a >= size_b)
    {
        B.Padding(size_a - size_b);
        k = size_a;
    }
    else
        A.Padding(size_b - size_a);

    if (k % 3 == 0)
        k /= 3;
    else
        k = k / 3 + 1;

    vector<int> a0(A.bits.begin(), A.bits.begin() + k);
    vector<int> a1(A.bits.begin() + k, A.bits.begin() + 2 * k);
    vector<int> a2(A.bits.begin() + 2 * k, A.bits.end());
    Integer A0(a0, A.base_exponent);
    Integer A1(a1, A.base_exponent);
    Integer A2(a2, A.base_exponent);

    vector<int> b0(B.bits.begin(), B.bits.begin() + k);
    vector<int> b1(B.bits.begin() + k, B.bits.begin() + 2 * k);
    vector<int> b2(B.bits.begin() + 2 * k, B.bits.end());
    Integer B0(b0, A.base_exponent);
    Integer B1(b1, A.base_exponent);
    Integer B2(b2, A.base_exponent);

    Integer *four, *two, *three;
    int marker = 0;
    if (A.base_exponent == 1)
    {
        vector<int> val1 = {0, 0, 1};
        four = new Integer(val1, 1);
        vector<int> val2 = {0, 1};
        two = new Integer(val2, 1);
        vector<int> val3 = {1, 1};
        three = new Integer(val3, 1);
        marker = 1;
    }
    else if (A.base_exponent == 2)
    {
        vector<int> val1 = {0, 1};
        four = new Integer(val1, 2);
        vector<int> val2 = {2};
        two = new Integer(val2, 2);
        vector<int> val3 = {3};
        three = new Integer(val3, 2);
    }
    else
    {
        vector<int> val1 = {4};
        four = new Integer(val1, A.base_exponent);
        vector<int> val2 = {2};
        two = new Integer(val2, A.base_exponent);
        vector<int> val3 = {3};
        three = new Integer(val3, A.base_exponent);
    }
    Integer p = A0 + A2;
    Integer P1 = p + A1;
    Integer Pn1 = p - A1;
    Integer X = Pn1 + A2;
    Integer *X_;
    if (X.base_exponent > 1)
        X_ = X.Special_shift(1);
    else
        X_ = &(X * *two);
    Integer Pn2 = *(X_)-A0;
    Integer q = B0 + B2;
    Integer Q1 = q + B1;
    Integer Qn1 = q - B1;
    Integer Y = (Qn1 + B2);
    Integer *Y_;
    if (Y.base_exponent > 1)
        Y_ = Y.Special_shift(1);
    else
        Y_ = &(Y * *two);
    Integer Qn2 = *(Y_)-B0;
    Integer *R0 = Integer::Toom_multiply(A0, B0);
    Integer *R1 = Integer::Toom_multiply(P1, Q1);
    Integer *Rn1 = Integer::Toom_multiply(Pn1, Qn1);
    Integer *Rn2 = Integer::Toom_multiply(Pn2, Qn2);
    Integer *Ri = Integer::Toom_multiply(A2, B2);

    // Matrice part after division

    Integer *r0 = R0;

    Integer *r4 = Ri;

    Integer &t1 = *Rn2 - *R1;
    Integer *r3;
    if (marker == 1)
        r3 = (get<0>(Integer::Div_mod(t1, *three, Only_Quotient)));
    else if (marker == 0)
        r3 = (get<0>(t1.Single_div(*three)));

    r3->sign = t1.sign;

    Integer &t2 = *R1 - *Rn1;
    Integer *r1;
    if (marker == 1)
        r1 = (get<0>(Integer::Div_mod(t2, *two, Only_Quotient)));
    else if (marker == 0)
    {

        // r1 = (get<0>(t2.Single_div(*two)));
        r1 = t2.Special_shift(-1);
    }
    r1->sign = t2.sign;

    Integer *r2 = &(*Rn1 - *R0);
    Integer t3 = *r2 - *r3;
    Integer *t4;
    if (marker == 1)
    {
        t4 = (get<0>(Integer::Div_mod(t3, *two, Only_Quotient)));
    }
    else if (marker == 0)
    {
        // t4 = (get<0>(t3.Single_div(*two)));

        t4 = t3.Special_shift(-1);
    }
    t4->sign = t3.sign;
    Integer &t6 = *Ri * *two;

    Integer *r3_ = &(*t4 + t6);

    Integer *r2_ = &(*r2 + *r1 - *r4);

    Integer *r1_ = &(*r1 - *r3_);

    // r0 + r1 << m+k + r2 << 2(m+k) + r3 << 3(m + k) + r4 << 4(m+k)
    *r1_ << (k);
    *r2_ << (2 * k);
    *r3_ << (3 * k);
    *r4 << (4 * k);

    Integer *ans = &(*r0 + *r1_ + *r2_ + *r3_ + *r4);
    if (!(A.sign && B.sign) && (A.sign || B.sign))
        ans->sign = 1;
    ans->Clean();
    delete four;
    delete two;
    delete three;
    delete r1;
    delete r1_;
    delete r2;
    delete r2_;
    delete r3;
    delete r3_;
    delete R0;
    delete R1;
    delete Rn1;
    delete Rn2;
    delete Ri;
    return (ans);
}
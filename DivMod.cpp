// Algorithm to find quotient and remainder when an integer is divided by another integer.
#include "Integer.hpp"
using namespace std;
tuple<Integer *, Integer *> Integer::Div_mod(Integer &A, Integer &B, int lambda)
{
    if (A.base_exponent != B.base_exponent)
    {
        tuple<Integer *, Integer *> nulltple(NULL, NULL);
        return nulltple;
    }

    Integer *c = new Integer(A);
    Integer &C = *c;
    Integer D(B);
    C.sign = 0;
    D.sign = 0;
    C.Clean();
    D.Clean();
    int size_c = C.bits.size();
    int size_d = D.bits.size();

    Integer *Q = new Integer(A.base_exponent);
    Integer *R = new Integer(A.base_exponent);

    if (size_c < size_d)
    {
        Q->bits.push_back(0);
        tuple<Integer *, Integer *> ans(Q, c);
        delete R;
        return ans;
    }

    // remove trailing zeroes if only quotient is needed
    if (lambda == Only_Quotient)
    {
        while (C.bits[0] == 0 && D.bits[0] == 0)
        {
            C << -1;
            D << -1;
            size_c--;
            size_d--;
        }
    }
    int m = 0;
    int num = D.base >> 1;
    int tempo = D.bits.back();

    while (tempo < num)
    {
        tempo = tempo << 1;
        m++;
    }

    D.Special_shift(m);
    C.Special_shift(m);

    size_c = C.bits.size();
    size_d = D.bits.size();
    vector<int> r;
    vector<int> q(size_c - size_d + 1);
    r = C.bits;
    r.push_back(0);

    int carry = 0, tmp = 0;

    for (int i = size_c - size_d; i >= 0; i--)
    {

        q[i] = (int)(((r[i + size_d] << C.base_exponent) + r[i + size_d - 1]) / D.bits[size_d - 1]);

        if (q[i] >= A.base)
            q[i] = A.base - 1;

        carry = 0;
        for (int j = 0; j < size_d; j++)
        {
            tmp = r[i + j] - q[i] * D.bits[j] + carry;
            r[i + j] = tmp & (A.base - 1);
            carry = tmp >> A.base_exponent;
        }
        r[i + size_d] += carry;
        while (r[i + size_d] < 0)
        {
            carry = 0;
            for (int j = 0; j < size_d; j++)
            {
                tmp = r[i + j] + D.bits[j] + carry;

                if (tmp >= A.base)
                {
                    carry = 1;
                    r[i + j] = tmp & (A.base - 1);
                }
                else
                {
                    carry = 0;
                    r[i + j] = tmp;
                }
            }
            r[i + size_d] += carry;
            q[i] -= 1;
        }
    }
    if (lambda == Only_Quotient)
    {
        Q->bits = move(q);
        tuple<Integer *, Integer *> ans(Q, NULL);
        delete R;
        return ans;
    }
    r.erase(r.begin() + size_d, r.end());
    R->bits = move(r);
    R->Special_shift(-m);
    Q->bits = move(q);
    Q->Clean();
    R->Clean();
    tuple<Integer *, Integer *> ans(Q, R);
    return ans;
}
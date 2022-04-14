// Simple addition algorithm for integers
#include "Integer.hpp"
using namespace std;
Integer *Integer::Add(Integer &A, Integer &B)
{
    if (A.base_exponent != B.base_exponent)
        return NULL;

    if (A.sign == 1 && B.sign == 0)
    {
        Integer C(A);
        C.sign = 0;
        return &(B - C);
    }

    else if (A.sign == 0 && B.sign == 1)
    {
        Integer C(B);
        C.sign = 0;
        return &(A - C);
    }

    int size_a = A.bits.size();
    int size_b = B.bits.size();
    int l, k;
    Integer *c, *d;
    if (size_a >= size_b)
    {
        l = size_b;
        k = size_a;
        c = &B;
        d = &A;
    }
    else
    {
        l = size_a;
        k = size_b;
        c = &A;
        d = &B;
    }
    Integer &C = *c;
    Integer &D = *d;
    int tmp = 0, carry = 0;
    Integer *ans = new Integer(D.base_exponent);
    for (int i = 0; i < l; i++)
    {
        tmp = D.bits[i] + C.bits[i] + carry;
        if (tmp >= D.base)
        {
            carry = 1;
            ans->bits.push_back(tmp & (D.base - 1));
        }
        else
        {
            carry = 0;
            ans->bits.push_back(tmp);
        }
    }

    tmp = 0;
    for (int i = l; i < k; i++)
    {
        tmp = D.bits[i] + carry;
        if (tmp >= D.base)
        {
            carry = 1;
            ans->bits.push_back(tmp & (D.base - 1));
        }
        else
        {
            carry = 0;
            ans->bits.push_back(tmp);
        }
    }
    if (carry == 1)
    {
        ans->bits.push_back(carry);
    }
    ans->Clean();
    if (A.sign == 1 && B.sign == 1)
        ans->sign = 1;
    return ans;
}
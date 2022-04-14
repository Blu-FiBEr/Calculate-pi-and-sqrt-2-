// Basic subtraction algorithm for integers
#include "Integer.hpp"
using namespace std;
Integer *Integer::Abs_difference(Integer &A, Integer &B)
{
    if (A.base_exponent != B.base_exponent)
        return NULL;

    if (A.sign == 0 && B.sign == 1)
    {
        Integer C(B);
        C.sign = 0;
        return &(A + C);
    }
    else if (A.sign == 1 && B.sign == 0)
    {
        Integer C(A);
        C.sign = 0;
        Integer *Ans = &(B + C);
        Ans->sign = 1;
        return (Ans);
    }
    int size_a = A.bits.size();
    int size_b = B.bits.size();
    int l, k, x = -1;
    Integer *c, *d;
    if (size_a >= size_b)
    {
        l = size_b;
        k = size_a;
        c = &B;
        d = &A;
        x = 1;
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
        tmp = A.bits[i] - B.bits[i] + carry;
        if (tmp < 0)
        {
            carry = -1;
            ans->bits.push_back(D.base + tmp);
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

        tmp = x * D.bits[i] + carry;
        if (tmp < 0)
        {
            carry = -1;
            ans->bits.push_back(D.base + tmp);
        }
        else
        {
            carry = 0;
            ans->bits.push_back(tmp);
        }
    }
    if (carry == -1)
    {
        vector<int> temp(k + 1, 0);
        temp[k] = 1;
        Integer *pseudo_ans = ans;
        ans = &((Integer(temp, A.base_exponent)) - *ans);
        ans->sign = 1;
        delete pseudo_ans;
    }
    ans->Clean();
    if (A.sign == 1 && B.sign == 1)
        ans->sign = 1 - ans->sign;
    return ans;
}
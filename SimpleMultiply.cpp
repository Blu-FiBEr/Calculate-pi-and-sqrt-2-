// Basic multiplication algorithm for integers
#include "Integer.hpp"
using namespace std;
Integer *Integer::Simple_multiply(Integer &A, Integer &B)
{
    if (A.base_exponent != B.base_exponent)
        return NULL;

    int size_a = A.bits.size();
    int size_b = B.bits.size();
    vector<int> temp(size_a + size_b, 0);

    Integer *ans = new Integer(temp, A.base_exponent);
    int carry = 0, tmp = 0;

    for (int i = 0; i < size_a; i++)
    {
        carry = 0;
        for (int j = 0; j < size_b; j++)
        {
            tmp = A.bits[i] * B.bits[j] + carry + ans->bits[i + j];
            carry = tmp >> A.base_exponent;
            ans->bits[i + j] = tmp & (A.base - 1);
        }
        ans->bits[i + size_b] = carry;
    }
    ans->Clean();
    if (!(A.sign && B.sign) && (A.sign || B.sign))
        ans->sign = 1;
    return ans;
}
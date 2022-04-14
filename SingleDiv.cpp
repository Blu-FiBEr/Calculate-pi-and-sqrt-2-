// Division by a single digit divisor
#include "Integer.hpp"
using namespace std;
tuple<Integer *, int> Integer::Single_div(Integer &B)
{
    if (this->base_exponent != B.base_exponent)
    {
        tuple<Integer *, int> nulltple(NULL, INT_MAX);
        return nulltple;
    }
    if (B.bits.size() != 1)
    {
        tuple<Integer *, int> nulltple(NULL, INT_MAX);
        return nulltple;
    }
    Integer C(*this);
    Integer D(B);
    C.sign = 0;
    D.sign = 0;
    C.Clean();
    int size_c = C.bits.size();
    Integer *Q = new Integer(this->base_exponent);
    vector<int> q(size_c);
    int carry = 0, tmp = 0;
    for (int i = this->bits.size() - 1; i >= 0; i--)
    {
        tmp = carry * this->base + this->bits[i];
        q[i] = tmp / D.bits[0];
        carry = tmp - q[i] * D.bits[0];
    }
    Q->bits = move(q);
    tuple<Integer *, int> ans(Q, carry);
    return ans;
}
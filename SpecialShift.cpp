// Algorithm to make division and multiplication by powers of 2(less than base) efficient
#include "Integer.hpp"
using namespace std;
Integer *Integer::Special_shift(int m)
{
    if (m == 0)
        return this;
    if (abs(m) >= this->base_exponent)
        return NULL;

    if (m > 0)
    {
        this->bits.push_back(0);
        for (int i = this->bits.size() - 2; i >= 0; i--)
        {
            this->bits[i] <<= m;
            this->bits[i + 1] += this->bits[i] >> this->base_exponent;
            this->bits[i] = this->bits[i] & (this->base - 1);
        }
        this->Clean();
    }

    else if (m < 0)
    {
        m = -m;
        int M = 1 << m;
        int carry = 0;
        for (int i = this->bits.size() - 1; i >= 0; i--)
        {
            this->bits[i] += (carry << this->base_exponent);
            carry = this->bits[i] & (M - 1);
            this->bits[i] = this->bits[i] >> (m);
        }
        this->Clean();
    }
    return this;
}
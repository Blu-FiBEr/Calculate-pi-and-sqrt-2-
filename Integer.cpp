// Implementation of methods for integer class
#include "Integer.hpp"
using namespace std;
Integer::Integer(int base_exponent)
{
    this->base_exponent = base_exponent;
    this->base = 1 << base_exponent;
    this->bits = vector<int>(0);
}

Integer::Integer(vector<int> &bits, int base_exponent)
{
    this->base_exponent = base_exponent;
    this->bits = bits;
    this->base = 1 << base_exponent;
}

Integer::Integer(const Integer &dummy)
{
    this->bits = dummy.bits;
    this->sign = dummy.sign;
    this->base = dummy.base;
    this->base_exponent = dummy.base_exponent;
}

void Integer::Clean()
{
    for (;;)
    {
        if (this->bits.back() == 0 && this->bits.size() != 1)
        {
            this->bits.erase(this->bits.end() - 1);
        }
        else
            break;
    }
}

void Integer::Shift(int m)
{
    if (m > 0)
        this->bits.insert(this->bits.begin(), m, 0);
    else if (m < 0)
    {
        m = -m;
        this->bits.erase(this->bits.begin(), this->bits.begin() + m);
    }
    return;
}

void Integer::Padding(int n)
{
    for (int i = 0; i < n; i++)
        this->bits.push_back(0);
    return;
}

Integer &Integer::operator+(Integer &B)
{
    return *(Integer::Add(*this, B));
}

Integer &Integer::operator-(Integer &B)
{
    return *(Integer::Abs_difference(*this, B));
}

Integer &Integer::operator*(Integer &B)
{
    return *(Integer::Simple_multiply(*this, B));
}
void Integer::operator<<(int m)
{
    this->Shift(m);
}
// Separate the integer and fractional part of a float
#include "Float.hpp"
using namespace std;
tuple<Integer *, Float *> Float::sep_float()
{
    this->Integer_convert();
    Integer *A1;
    Float *A2;
    if (this->order <= 0)
    {
        vector<int> a1(this->num->bits.begin() + -(this->order), this->num->bits.end());
        if (a1.size() == 0)
            a1.push_back(0);
        vector<int> a2(this->num->bits.begin(), this->num->bits.begin() + -(this->order));
        A1 = new Integer(a1, this->num->base_exponent);
        A2 = new Float(a2, this->num->base_exponent, this->order);
    }
    return make_tuple(A1, A2);
}
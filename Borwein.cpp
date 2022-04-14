// Borwein's algo for calculating pi
#include "Float.hpp"
using namespace std;
Float *Borwein_pi(int p, int base_exponent, int marker)
{
    int prec = ceil(p * log(10) / log(1 << base_exponent));
    float multiplier;
    // int precision = ceil(1.5 * prec); // 3 for 13, 2 for 8, 1 for 2
    int precision = prec + 8;
    Integer *two;
    if (base_exponent == 1)
    {
        vector<int> val = {0, 1};
        two = new Integer(val, 1);
    }
    else
    {
        vector<int> val = {2};
        two = new Integer(val, base_exponent);
    }
    vector<int> val = {1};
    Float *One = new Float(val, base_exponent);
    Float *Two = new Float(*two, 0);
    Float *a = Float::newton_sqrt(*Two, precision);
    vector<int> dummy = {0};
    Float *b = new Float(dummy, base_exponent);
    Float *P = &(*Two + *a);
    Float *P2;

    Float *Half;
    int aa = 1 << (base_exponent - 1);
    vector<int> a_ = {aa};
    Half = new Float(a_, base_exponent, -1);
    Float *prec_num = new Float(val, base_exponent, -prec - 1);
    for (; /*i <= ceil(log(prec)) + 2*/;)
    {
        // cout << "::" << i << endl;
        P2 = P;
        Float *temp1 = &(*a + *One);
        Float *temp2 = Float::newton_sqrt(*a, precision);
        Float *temp6 = &(*a + *b);
        Float *temp3 = Float::Division(*temp1, *temp2, precision);
        a = &(*Half * *temp3);
        a->make_precise(precision);

        Float *temp4 = &(*b + *One);
        Float *temp5;
        if (marker == 0)
            temp5 = &(*temp4 * *temp2);
        else if (marker == 1)
            temp5 = Float::Toom_multiply(*temp4, *temp2);
        temp5->make_precise(precision);
        temp6->make_precise(precision);

        b = Float::Division(*temp5, *temp6, precision);

        Float *temp7 = &(*a + *One);
        Float *temp8;
        if (marker == 0)
            temp8 = &(*temp7 * *P * *b);
        else if (marker == 1)
        {
            Float *transfer = Float::Toom_multiply(*temp7, *P);
            temp8 = Float::Toom_multiply(*transfer, *b);
        }
        temp8->make_precise(precision);
        Float *temp9 = &(*b + *One);
        P = Float::Division(*temp8, *temp9, precision);
        Float *diff = &(*P2 - *P - *prec_num);
        // cout << diff->num->sign << endl;
        if (diff->num->sign != 0)
            break;
    }
    P->Base_convert(p);
    return P;
}
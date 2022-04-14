// Convert from base 2^m to base 10 and later verify the result with million digits
#include "Float.hpp"
#include <fstream>
using namespace std;
void Float::Base_convert(int precision)
{
    Float *A = this;
    Integer *B;
    if (A->num->base_exponent == 1)
    {
        vector<int> b = {0, 1, 0, 1};
        B = new Integer(b, A->num->base_exponent);
    }
    else if (A->num->base_exponent == 2)
    {
        vector<int> b = {2, 2};
        B = new Integer(b, A->num->base_exponent);
    }
    else if (A->num->base_exponent == 3)
    {
        vector<int> b = {2, 1};
        B = new Integer(b, A->num->base_exponent);
    }
    else
    {
        vector<int> b = {10};
        B = new Integer(b, A->num->base_exponent);
    }

    Float *B_ = new Float(*B);

    // separate
    A->Integer_convert();
    Integer *A1;
    Float *A2;

    tuple<Integer *, Float *> n = A->sep_float();

    A1 = get<0>(n);
    A2 = get<1>(n);
    vector<int> dec;
    // for integer part
    for (;;)
    {
        tuple<Integer *, Integer *> an = Integer::Div_mod(*A1, *B);
        Integer *R = get<1>(an);
        A1 = get<0>(an);
        int sum = 0;
        for (int i = 0; i < R->bits.size(); i++)
        {
            sum += R->bits[i] * pow(R->base, i);
        }
        dec.push_back(sum);
        if (A1->bits.size() == 1 && A1->bits[0] == 0)
            break;
    }
    for (int i = dec.size() - 1; i >= 0; i--)
    {
        cout << dec[i];
    }

    cout << ".";

    // for fractional part
    vector<int> dec2;
    Integer *dummy2;
    Float *dummy;
    int sum = 0;
    tuple<Integer *, Float *> an;
    int size = A2->num->bits.size();

    for (int i = 0; !(A2->num->bits.size() == 1 && A2->num->bits[0] == 0) && A2->num->bits.size() != 0; i++)
    {
        dummy = &(*A2 * *B_);
        // cout << "%%%";
        // for (int i = dummy->num->bits.size() - 1; i >= 0; i--)
        // {
        //     cout << dummy->num->bits[i];
        // }
        // cout << " '" << dummy->order << "' ";
        // cout << endl;
        an = dummy->sep_float();
        dummy2 = get<0>(an);
        // cout << "&&&";
        // for (int i = dummy2->bits.size() - 1; i >= 0; i--)
        // {
        //     cout << dummy2->bits[i];
        // }
        // cout << endl;
        A2 = get<1>(an);
        A2->Adjust_increase();
        sum = 0;
        for (int i = 0; i < dummy2->bits.size(); i++)
        {
            sum += dummy2->bits[i] * pow(dummy2->base, i);
        }
        dec2.insert(dec2.begin(), sum);
        // cout << dec2.front() << endl;
    }

    int diff = dec2.size() - precision;
    if (diff > 0)
    {
        dec2.erase(dec2.begin(), dec2.begin() + diff);
    }
    for (int i = dec2.size() - 1; i >= 0; i--)
    {
        cout << dec2[i];
    }
    cout << endl;
    //------------------------------------------------------------------------------------------------
    ifstream in("onemillion.txt");
    char c;
    int status = 0;
    if (in.is_open())
    {
        for (int i = dec2.size() - 1; i >= 0 && in.good(); i--)
        {
            in.get(c);

            if (c - '0' != dec2[i])
            {
                status = 1;
            }
        }
        cout << endl;
        if (status == 0 && dec2.size() == precision && dec.size() == 1 && dec[0] == 3)
            cout << "This value is correct." << endl;
        else
            cout << "This value is incorrect." << endl;
    }
    in.close();

    //---------------------------------------------------------------------------------------------------------
}
// IMT2020101 Keshav Goyal
#include "Float.hpp"
#include <chrono>
#include <stdlib.h>
#include <time.h>
using namespace std;
using namespace std::chrono;
int main()
{
    // Test Passed for Addition, Subtraction, Simple_Multiplication
    /*vector<int> a{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<int> b{1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    vector<int> c{1};
    Integer A(a, 1);
    Integer B(b, 1);
    Integer C(c, 1);
    Integer E = A + B;
    for (int i = E.bits.size() - 1; i >= 0; i--)
    {
        cout << E.bits[i];
    }*/
    // vector<int> n = {3, 6, 2, 5, 6, 2, 3, 4, 1, 6, 3, 4, 2, 5, 6, 1, 2, 3};
    // vector<int> d = {6, 4, 3, 1, 7, 4, 1, 5, 3, 7, 1, 5, 4, 7, 2, 6, 2, 3, 5, 4, 3, 5, 6, 2, 4, 6, 3, 7, 1, 6};
    //  vector<int> n_(500000);
    //  vector<int> d_(500000);
    //  int base = 1 << 8;
    //  int mod = base - 1;

    // for (int i = 0; i < n_.size(); i++)
    // {
    //     n_[i] = rand() & mod;
    // }

    // cout << "done" << endl;
    // for (int i = 0; i < d_.size(); i++)
    // {
    //     d_[i] = rand() & mod;
    // }

    // cout << "done" << endl;
    // Integer N(n, 3);
    // Integer D(d, 3);
    // // tuple<Integer *, Integer *> ans = Integer::Div_mod(N, D);

    // // for (int i = get<0>(ans)->bits.size() - 1; i >= 0; i--)
    // // {
    // //     cout << get<0>(ans)->bits[i] << " ";
    // // }
    // auto start = high_resolution_clock::now();
    // Integer *F = Integer::Toom_multiply(N, D);
    // auto end = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(end - start);
    // for (int i = F->bits.size() - 1; i >= 0; i--)
    // {
    //     cout << F->bits[i];
    // }
    // cout << endl
    //      << duration.count() << endl;

    // vector<int> a{1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1};
    // vector<int> b{0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};

    /*vector<int> a = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1};
    vector<int> b = {0, 1};
    Float A(a, 1, -21);
    Float B(b, 1);
    Float *E = Float::Division(B, A);
    for (int i = E->num->bits.size() - 1; i >= 0; i--)
    {
        cout << E->num->bits[i];
    }
    cout << endl;
    cout << E->order << endl;*/

    // vector<int> val = {2};
    // Integer *two = new Integer(val, 8);

    // Float *Two = new Float(*two);
    // auto start = high_resolution_clock::now();
    // int p;
    // cin >> p;
    // int precision = ceil(p * log(10) / log(1 << 8));
    // Float *ans = Float::newton_sqrt(*Two, precision);
    // auto end = high_resolution_clock::now();
    // // print ans
    // auto duration = duration_cast<microseconds>(end - start);
    // cout << endl
    //      << duration.count() << endl;

    /*vector<int> a = {7, 7, 7, 7, 3, 7, 4};
    vector<int> b = {0, 1, 0, 1};
    // Float *A = new Float(a, 3, -1);
    Float *A = ans;
    Integer *B = new Integer(b, 1);
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

    for (int i = 0; i <= 2 * size && !(A2->num->bits.size() == 1 && A2->num->bits[0] == 0) && A2->num->bits.size() != 0; i++)
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
    for (int i = dec2.size() - 1; i >= 0; i--)
    {
        cout << dec2[i];
    }*/

    //-----------------------------------------------------------------------------------------------------------------------
    int query;
    cout << "If you want to get π, Enter 1. Else, if you want sqrt(2), Enter 2:-   ";
    cin >> query;
    if (query == 1)
    {
        int precision;
        int base;
        cout << endl;
        cout << "Enter Precision(number of digits in π or pi after the decimal point):-   ";
        cin >> precision;
        cout << endl;
        cout << "Enter 'm', where base used for calculation is 2^m (0 < m < 16):-   ";
        cin >> base;
        cout << endl;
        if (base > 15 || base < 1)
        {
            cout << "Invalid Base" << endl;
            cout << endl
                 << "Enter 'm', where base used for calculation is 2^m (0 < m < 16):-   ";
            cin >> base;
            cout << endl;
        }
        cout << "If you want to use Toom3 for multiplication, Enter 1. If not, Enter 0:-   ";
        int marker;
        cin >> marker;
        cout << endl;
        cout << "The value of π(pi) for given precision is:- " << endl;
        auto start = high_resolution_clock::now();
        Borwein_pi(precision, base, marker);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << endl
             << "Time taken for the whole process:- "
             << duration.count() / 1000000.0 << " s" << endl;
    }
    else
    {
        int precision;
        int base;
        cout << endl;
        cout << "Enter Precision(number of digits in sqrt(2) after the decimal point):-   ";
        cin >> precision;
        cout << endl;
        cout << "Enter 'm', where base used for calculation is 2^m (0 < m < 16):-   ";
        cin >> base;
        cout << endl;
        if (base > 15 || base < 1)
        {
            cout << "Invalid Base" << endl;
            cout << endl
                 << "Enter 'm', where base used for calculation is 2^m (0 < m < 16):-   ";
            cin >> base;
            cout << endl;
        }
        cout << "The value of sqrt(2) for given precision is:- " << endl;
        auto start = high_resolution_clock::now();
        Float *two;
        if (base == 1)
        {
            vector<int> val = {0, 1};
            two = new Float(val, 1);
        }
        else
        {
            vector<int> val = {2};
            two = new Float(val, base);
        }
        int prec = ceil(precision * log(10) / log(1 << base)) + 8;
        Float *ans = Float::newton_sqrt(*two, prec);
        ans->Base_convert_sqrt(precision);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << endl
             << "Time taken for the whole process:- "
             << duration.count() / 1000000.0 << " s" << endl;
    }
    //-------------------------------------------------------------------------------------------------------------------------------
    /*int query;
    cin >> query;
    if (query == 1)
    {
        int precision;
        int base;
        cin >> precision;
        cin >> base;
        Borwein_pi(precision, base, 0);
    }
    else
    {
        int precision;
        int base;

        cin >> precision;
        cin >> base;
        Float *two;
        if (base == 1)
        {
            vector<int> val = {0, 1};
            two = new Float(val, 1);
        }
        else
        {
            vector<int> val = {2};
            two = new Float(val, base);
        }
        int prec = ceil(precision * log(10) / log(1 << base)) + 8;
        Float *ans = Float::newton_sqrt(*two, prec);
        ans->Base_convert_sqrt(precision);
    }*/
    return 0;
}
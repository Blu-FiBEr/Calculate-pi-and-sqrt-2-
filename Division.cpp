// Algorithm that divides two integers and returns a rational number
#include "Integer.hpp"
#include "Float.hpp"
using namespace std;
Float *Integer::Divide(Integer &A, Integer &B, int limit)
{
    if (A.base_exponent != B.base_exponent)
    {
        return NULL;
    }

    Integer C(A);
    Integer D(B);
    C.sign = 0;
    D.sign = 0;
    C.Clean();
    D.Clean();
    Integer *Q = new Integer(A.base_exponent);
    Integer *R = new Integer(A.base_exponent);

    int m = 0;
    int numb = D.base >> 1;
    int tempo = D.bits.back();
    while (tempo < numb)
    {
        tempo = tempo << 1;
        m++;
    }
    D.Special_shift(m);
    C.Special_shift(m);

    tuple<Integer *, Integer *> ans = Div_mod_special(C, D);
    Q = get<0>(ans);
    R = get<1>(ans);
    int order = 0;
    Integer *Q_;
    for (int i = 0; R->bits.size() != 1 || R->bits.front() != 0; i++)
    {

        R->Shift(1);

        if (i > limit)
        {
            // cout << "invalid" << endl;
            break;
        }

        ans = Div_mod_special(*R, D);

        R = get<1>(ans);
        Q_ = get<0>(ans);
        order -= Q_->bits.size();
        vector<int> q;
        q.resize(Q->bits.size() + Q_->bits.size());
        move(Q_->bits.begin(), Q_->bits.end(), q.begin());
        move(Q->bits.begin(), Q->bits.end(), q.begin() + Q_->bits.size());
        Q->bits = move(q);
    }
    if (!(A.sign && B.sign) && (A.sign || B.sign))
        Q->sign = 1;
    Float *ANS = new Float(*Q, order);
    ANS->Clean();
    return ANS;
}
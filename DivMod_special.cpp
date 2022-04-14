// Special Dquotient and remainder algorithm to make complete division of integers efficient
#include "Float.hpp"
using namespace std;
tuple<Integer *, Integer *> Div_mod_special(Integer &A, Integer &B)
{
    Integer &C = A;
    Integer &D = B;
    int size_c = C.bits.size();
    int size_d = D.bits.size();
    Integer *Q = new Integer(A.base_exponent);
    Integer *R = new Integer(A.base_exponent);
    if (size_c < size_d)
    {
        Q->bits.push_back(0);
        tuple<Integer *, Integer *> ans(Q, &C);
        delete R;
        return ans;
    }
    vector<int> r;
    vector<int> q(size_c - size_d + 1, 0);
    r = C.bits;
    r.push_back(0);

    int carry = 0, tmp = 0;

    for (int i = size_c - size_d; i >= 0; i--)
    {

        q[i] = (int)(((r[i + size_d] << C.base_exponent) + r[i + size_d - 1]) / D.bits[size_d - 1]);

        if (q[i] >= A.base)
            q[i] = A.base - 1;

        carry = 0;
        for (int j = 0; j < size_d; j++)
        {
            tmp = r[i + j] - q[i] * D.bits[j] + carry;
            r[i + j] = tmp & (A.base - 1);
            carry = tmp >> A.base_exponent;
        }
        r[i + size_d] += carry;
        while (r[i + size_d] < 0)
        {
            carry = 0;
            for (int j = 0; j < size_d; j++)
            {
                tmp = r[i + j] + D.bits[j] + carry;

                if (tmp >= A.base)
                {
                    carry = 1;
                    r[i + j] = tmp & (A.base - 1);
                }
                else
                {
                    carry = 0;
                    r[i + j] = tmp;
                }
            }
            r[i + size_d] += carry;
            q[i] -= 1;
        }
    }
    r.erase(r.begin() + size_d, r.end());
    R->bits = move(r);
    Q->bits = move(q);
    Q->Clean();
    R->Clean();
    tuple<Integer *, Integer *> ans(Q, R);
    return ans;
}
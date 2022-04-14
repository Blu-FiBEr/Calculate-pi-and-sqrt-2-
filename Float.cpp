// Implementing methods for Float class
#include "Float.hpp"
using namespace std;
Float::Float(int base_exponent, int order)
{
    this->order = order;
    this->num = new Integer(base_exponent);
    while (-(this->order) >= this->num->bits.size() && this->order <= 0)
        this->num->bits.push_back(0);
}
Float::Float(Integer &A, int order)
{
    this->num = &A;
    this->order = order;
    while (-(this->order) >= this->num->bits.size() && this->order <= 0)
        this->num->bits.push_back(0);
}

Float::Float(vector<int> &bits, int base_exponent, int order)
{
    this->order = order;
    this->num = new Integer(bits, base_exponent);
    while (-(this->order) >= this->num->bits.size() && this->order <= 0)
        this->num->bits.push_back(0);
}

Float::Float(const Float &dummy)
{
    this->order = dummy.order;
    this->num = new Integer(*dummy.num);
    while (-(this->order) >= this->num->bits.size() && this->order <= 0)
        this->num->bits.push_back(0);
}

void Float::Clean()
{
    this->num->Clean();
    while (-(this->order) >= this->num->bits.size() && this->order <= 0)
        this->num->bits.push_back(0);
}

void Float::Shift(int m)
{
    if (m == 0)
        return;
    if (m > 0)
        this->num->Shift(m);
    else
    {
        m = (-m);
        this->order -= m;
    }
    while (-(this->order) >= this->num->bits.size() && this->order <= 0)
        this->num->bits.push_back(0);
}
void Float::Adjust(int m)
{
    if (m == 0)
        return;
    if (m < 0)
    {
        m = (-m);
        this->order -= m;
        this->Shift(m);
    }
    while (-(this->order) >= this->num->bits.size() && this->order <= 0)
        this->num->bits.push_back(0);
    return;
}
void Float::Integer_convert()
{
    if (this->order > 0)
    {
        this->Shift(order);
    }
    while (-(this->order) >= this->num->bits.size() && this->order <= 0)
        this->num->bits.push_back(0);
}

void Float::Adjust_increase()
{
    for (; this->num->bits.size() >= 1;)
    {
        if (this->num->bits.front() == 0)
        {
            this->num->bits.erase(this->num->bits.begin());
            this->order++;
        }
        else
            break;
    }
    while (-(this->order) >= this->num->bits.size() && this->order <= 0)
        this->num->bits.push_back(0);
    return;
}

Float *Float::Add(Float &A, Float &B)
{
    A.Adjust_increase();
    B.Adjust_increase();
    (A.order < B.order) ? B.Adjust(A.order - B.order) : A.Adjust(B.order - A.order);
    Float *ans = new Float(A.num->base_exponent, A.order);
    Integer &ans_num = *(A.num) + *(B.num);
    ans->num = &ans_num;
    while (-(ans->order) >= ans->num->bits.size() && ans->order <= 0)
        ans->num->bits.push_back(0);
    return ans;
}

Float &Float::operator+(Float &B)
{
    return *(Float::Add(*this, B));
}

Float *Float::Abs_difference(Float &A, Float &B)
{
    A.Adjust_increase();
    B.Adjust_increase();
    (A.order < B.order) ? B.Adjust(A.order - B.order) : A.Adjust(B.order - A.order);
    Float *ans = new Float(A.num->base_exponent, A.order);
    Integer &ans_num = *(A.num) - *(B.num);
    ans->num = &ans_num;
    while (-(ans->order) >= ans->num->bits.size() && ans->order <= 0)
        ans->num->bits.push_back(0);
    return ans;
}

Float &Float::operator-(Float &B)
{
    return *(Float::Abs_difference(*this, B));
}

Float *Float::Simple_multiply(Float &A, Float &B)
{
    A.Adjust_increase();
    B.Adjust_increase();
    Float *ans = new Float(A.num->base_exponent);
    Integer &ans_num = *(A.num) * *(B.num);
    ans->num = &ans_num;
    ans->order = A.order + B.order;
    ans->Adjust_increase();
    while (-(ans->order) >= ans->num->bits.size() && ans->order <= 0)
        ans->num->bits.push_back(0);
    return ans;
}

Float &Float::operator*(Float &B)
{
    return *(Float::Simple_multiply(*this, B));
}

Float *Float::Toom_multiply(Float &A, Float &B)
{
    A.Adjust_increase();
    B.Adjust_increase();
    Integer *ans = Integer::Toom_multiply(*(A.num), *(B.num));

    Float *Ans = new Float(*ans, A.order + B.order);
    Ans->Adjust_increase();
    while (-(Ans->order) >= Ans->num->bits.size() && Ans->order <= 0)
        Ans->num->bits.push_back(0);
    return Ans;
}

Float *Float::Division(Float &A, Float &B, int limit)
{
    while (A.num->bits.size() < B.num->bits.size())
    {
        A.num->bits.insert(A.num->bits.begin(), 0);
        A.order--;
    }
    Float *ans = Integer::Divide(*(A.num), *(B.num), limit);
    int new_order = ans->order + A.order - B.order;
    Float *Ans = new Float(*(ans->num), new_order);
    while (-(Ans->order) >= Ans->num->bits.size() && Ans->order <= 0)
        Ans->num->bits.push_back(0);
    return Ans;
}

Float &Float::operator/(Float &B)
{
    return *(Float::Division(*this, B));
}
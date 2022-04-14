// Representing any rational number(upto a finite precision) in base 2^m
#pragma once
#include <math.h>
#include "Integer.hpp"
std::tuple<Integer *, Integer *> Div_mod_special(Integer &A, Integer &B);
class Float
{
public:
    Integer *num;
    int order; // predominantly negative
    Float(std::vector<int> &bits, int base_exponent, int order = 0);
    Float(int base_exponent, int order = 0);
    Float(Integer &A, int order = 0);
    Float(const Float &dummy);
    void Integer_convert();
    void Clean();
    void Shift(int m);
    void Adjust(int m);
    void Adjust_increase();
    void Base_convert(int precision);
    void Base_convert_sqrt(int precision);
    void make_precise(int precision);
    std::tuple<Integer *, Float *> sep_float();
    Float *Special_shift(int m);
    static Float *Add(Float &A, Float &B);
    Float &operator+(Float &B);
    static Float *Abs_difference(Float &A, Float &B);
    Float &operator-(Float &B);
    static Float *Simple_multiply(Float &A, Float &B);
    Float &operator*(Float &B);
    static Float *Toom_multiply(Float &A, Float &B);
    static Float *Division(Float &A, Float &B, int limit = 1000);
    Float &operator/(Float &B);
    static Float *newton_sqrt(Float &A, int p);
};
Float *Borwein_pi(int p, int base_exponent, int marker);
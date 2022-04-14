// Representing any integer in base 2^m
#pragma once

#include <iostream>
#include <vector>
#include <tuple>
#define Only_Quotient 0
#define Both 1
typedef class Float Float;
class Integer
{
public:
    std::vector<int> bits;
    int base_exponent;
    int base;
    int sign = 0; // 0 means positive, 1 means negative

    Integer(std::vector<int> &bits, int base_exponent);
    Integer(int base_exponent);
    Integer(const Integer &dummy);
    void Clean();
    void Padding(int n);
    void Shift(int m);
    void operator<<(int m);
    Integer *Special_shift(int m);
    static Integer *Add(Integer &A, Integer &B);
    Integer &operator+(Integer &B);
    static Integer *Abs_difference(Integer &A, Integer &B);
    Integer &operator-(Integer &B);
    static Integer *Simple_multiply(Integer &A, Integer &B);
    Integer &operator*(Integer &B);
    static Integer *Toom_multiply(Integer &A, Integer &B);
    static std::tuple<Integer *, Integer *> Div_mod(Integer &A, Integer &B, int lambda = 1);
    std::tuple<Integer &> operator/(Integer &B);
    std::tuple<Integer *, int> Single_div(Integer &B);
    static Float *Divide(Integer &A, Integer &B, int limit = 1000);
};
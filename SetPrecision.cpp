// Adjusts the precision and order of a float
#include "Float.hpp"
using namespace std;
void Float::make_precise(int precision)
{
    int diff = this->num->bits.size() - precision;
    if (diff > 0)
    {
        this->num->bits.erase(this->num->bits.begin(), this->num->bits.begin() + diff);
        this->order += diff;
    }
}
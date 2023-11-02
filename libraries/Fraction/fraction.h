#pragma once
//
//    FILE: fraction.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.16
// PURPOSE: Arduino library to implement a Fraction data type
//     URL: https://github.com/RobTillaart/Fraction


#include "Arduino.h"

#define FRACTION_LIB_VERSION            (F("0.1.16"))


class Fraction: public Printable
{
public:
    explicit Fraction(double);
    explicit Fraction(float);
    Fraction(int32_t, int32_t);

    //  CONSTRUCTORS
    explicit Fraction(int32_t p)   : n(p), d(1) {}
    explicit Fraction(int16_t p)   : n(p), d(1) {}
    explicit Fraction(int8_t p)    : n(p), d(1) {}
    explicit Fraction(uint32_t p)  : n(p), d(1) {}
    explicit Fraction(uint16_t p)  : n(p), d(1) {}
    explicit Fraction(uint8_t p)   : n(p), d(1) {}
    Fraction(const Fraction &f) : n(f.n), d(f.d) {}

    size_t printTo(Print& p) const;

    //  EQUALITIES
    bool operator == (const Fraction&);
    //  bool operator == (const float&);
    bool operator != (const Fraction&);
    bool operator >  (const Fraction&);
    bool operator >= (const Fraction&);
    bool operator <  (const Fraction&);
    bool operator <= (const Fraction&);

    //  NEGATE
    Fraction operator - ();

    //  BASIC MATH
    Fraction operator + (const Fraction&);
    Fraction operator - (const Fraction&);
    Fraction operator * (const Fraction&);
    Fraction operator / (const Fraction&);

    Fraction& operator += (const Fraction&);
    Fraction& operator -= (const Fraction&);
    Fraction& operator *= (const Fraction&);
    Fraction& operator /= (const Fraction&);

    //  CONVERSION
    double  toDouble();
    float   toFloat();
    bool    isProper();     //  abs(f) < 1
    float   toAngle();

    int32_t  nominator();
    int32_t  denominator();

    //  MISCELLANEOUS (static)
    static Fraction mediant(const Fraction&, const Fraction&);
    static Fraction middle(const Fraction&, const Fraction&);

    //  approximate a fraction with defined denominator
    static Fraction setDenominator(const Fraction&, uint16_t);


protected:
    void    split(float);
    void    simplify();
    void    fractionize(float);
    int32_t gcd(int32_t, int32_t);

    int32_t n;
    int32_t d;
};


//  -- END OF FILE --

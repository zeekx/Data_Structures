//
//  Complex.hpp
//  Complex
//
//  Created by Milo on 2019/5/14.
//  Copyright © 2019 Musca. All rights reserved.
//

#ifndef Complex_hpp
#define Complex_hpp

#include <ostream>

class Complex {
private: int re;
private: int im;
    
    
public:
    Complex(double r = 0, double i = 0): re(r), im(i) {}
    
    //    Complex() :re(0), im(0) {}
    friend Complex operator+(const Complex& x, const Complex& y);
    friend Complex operator+(const Complex& r);
    friend Complex operator-(const Complex& r);
    Complex& operator += (const Complex&);
    bool operator == (const Complex&);
    
    
    
    
    double real() const {
        return re;
    }
    void real(double);
    
    double imag() const {
        return im;
    }
    
    double image() const {
        return im;
    }
    
    // Do assignment plus
    friend Complex& __doapl(Complex*, const Complex&);

    friend bool __doEqual(const Complex& l, const Complex& r);
    
};
inline
std::ostream& operator << (std::ostream & os, const Complex& c) {
    return os << '(' << c.real() << ',' << c.image() << ')';
}

inline void Complex::real(double re) {
    this->re = re;
}


inline double image(const Complex& r) {
    return r.image();
}

inline double real(const Complex& r) {
    return r.real();
}

inline Complex operator+(const Complex& x, const Complex& y) {
    return Complex(real(x) + real(y),
                   image(x) + image(y));
}

inline bool Complex::operator==(const Complex& r) {
    return __doEqual(*this, r);
}

inline Complex& Complex::operator+=(const Complex & r) {
    return __doapl(this, r);
}

inline
Complex operator+(Complex& r) {
    return r;
}

inline
Complex operator-(const Complex& r) {
    return Complex(-real(r), -image(r));
}

inline Complex& __doapl(Complex* ths, const Complex& r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline bool __doEqual(const Complex& l, const Complex& r) {
    return l.re == r.re && l.im == r.im;
}

#endif /* Complex_hpp */

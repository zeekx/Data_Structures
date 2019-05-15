//
//  Complex.hpp
//  Complex
//
//  Created by Milo on 2019/5/14.
//  Copyright © 2019 Musca. All rights reserved.
//

#ifndef Complex_hpp
#define Complex_hpp

class Complex {
private: int re;
private: int im;
    
    
public:
    Complex(double r = 0, double i = 0): re(r), im(i) {}
    
    //    Complex() :re(0), im(0) {}
    
    Complex& operator += (const Complex&);
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
};

//std::ostream & operator << (std::ostream & os, const Complex& c) {
//    return os << '(' << c.real() << ',' << c.image() << ')';
//}

inline void Complex::real(double re) {
    this->re = re;
}

inline Complex& __doapl(Complex* ths, const Complex& r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline Complex& Complex::operator+=(const Complex & r) {
    return __doapl(this, r);
}
#endif /* Complex_hpp */

#pragma once
#include <cmath>
#include<iostream>

template<typename T> requires std::floating_point<T> 
class complex
{
    T p_reale, p_im; // parte reale e parte immaginaria //
    
public:
    /* Default constructor */
    complex()
        : p_reale(0), p_im(0)
    {}
	
    /* User-defined constructor */
    explicit complex(T n)
        : p_reale(n), p_im(0)
    {
        std::cout << "converting constructor called" << ", è un numero reale" << std::endl;
    }
	
    /* User-defined constructor. Takes two parameters, real part and
     * imaginary part. */
    complex(T r, T i)
        : p_reale(r), p_im(i)
    {}
    
    /* Return the real part */
    T reale(void) const {
        return p_reale;
    }
    
    /* Return the imaginary part */
    T immag(void) const {
        return p_im;
    }
	
    /* Define the += operator between complex numbers. When you do   c1 += c2   this function gets called. */
    complex& operator+=(const complex& other) {
        T a = p_reale;
        T b = p_im;
        T c = other.p_reale;
        T d = other.p_im;
        p_reale = a + c;
        p_im = b + d;
        return *this;
	}
	
	/* Define operator+ in terms of operator +=. */
	complex operator+(const complex& other) const {
        complex ret = *this;
        ret += other;
        return ret;
    }

    /* Define the += operator between a complex on the left and a real number on the right. 
	* When you do   c1 += r   this function gets called. */
     complex& operator+=(const T& other) {
        p_reale += other;
		p_im += 0.0;
        return *this;
	}
	
	/* Define operator+ in terms of operator +=. */
	complex operator+(const T& other) const {
        complex ret = *this;
        ret += other;
        return ret;
    }
    
    /* This is the UNARY minus. It computes the opposite: c2 = -c1. */
    complex operator-() const {
        return complex(-p_reale,-p_im);
    }
    
	/* Define the -= operator between complex numbers. When you do   c1 -= c2   this function gets called. */
    complex& operator-=(const complex& other) {
        T a = p_reale;
        T b = p_im;
        T c = -other.p_reale;
        T d = -other.p_im;
        p_reale = a + c;
        p_im = b + d;
        return *this;
	}
	
	/* Define operator- in terms of operator -=. */
	complex operator-(const complex& other) const {
        complex ret = *this;
        ret -= other;
        return ret;
    }
	
	/* Define the -= operator between a complex on the left and a real number on the right. 
	* When you do   c1 -= r   this function gets called. */
     complex& operator-=(const T& other) {
        p_reale -= other;
		p_im -= 0.0;
        return *this;
	}
	
	/* Define operator- in terms of operator -=. */
	complex operator-(const T& other) const {
        complex ret = *this;
        ret -= other;
        return ret;
    }
	
	/* Define the *= operator between complex numbers. When you do   c1 *= c2   this function gets called. */
    complex& operator*=(const complex& other) {
        T a = p_reale;
        T b = p_im;
        T c = other.p_reale;
        T d = other.p_im;
        p_reale = a*c - b*d;
        p_im = a*d + b*c;
        return *this;
	}
	
	/* Define operator* in terms of operator *=. */
	complex operator*(const complex& other) const {
        complex ret = *this;
        ret *= other;
        return ret;
    }
    
	/* Define the *= operator between a complex on the left and a real number on the right. 
	* When you do   c1 *= r   this function gets called. */
     complex& operator*=(const T& other) {
        p_reale *= other;
		p_im *= other;
        return *this;
	}
	
	/* Define operator* in terms of operator *=. */
	complex operator*(const T& other) const {
        complex ret = *this;
        ret *= other;
        return ret;
    }
};

/* This operator is defined outside the complex class and is needed
 * to compute the sum of a T on the left and a complex<T> on the
 * right. */
template<typename T>
complex<T>
operator+(const T& i, const complex<T>& r)
{
    return r + i;
}

/* This operator is needed to compute the subtraction of a T 
* on the left and a complex<T> on the right. */
template<typename T>
complex<T>
operator-(const T& i, const complex<T>& r)
{
    return - r + i;
}

/* This operator is needed to compute the multiplication of a T 
* on the left and a complex<T> on the right. */
template<typename T>
complex<T>
operator*(const T& i, const complex<T>& r)
{
    return r * i;
}

/* Function computing the absolute value of a complex. */
template<typename T>
T
abs(const complex<T>& r) {
	T p1 = pow(r.reale(),2.0);
	T p2 = pow(r.immag(),2.0);
    T z = sqrt(p1+p2);
    return z;
}

/* Function computing the complex conjugate of a complex number */
template<typename T>
complex<T> coniug(const complex<T>& r) {
    return complex<T>(r.reale(), -r.immag());
}

/* Overload of <<, to make the complex numbers printable. */
template<typename T>
std::ostream&
operator<<(std::ostream& os, const complex<T>& r) {
	if (r.immag() < 0.0) {
		os << r.reale() << r.immag() << "i";
		return os;
	}
	os << r.reale() << "+" << r.immag() << "i";
	return os;
} 
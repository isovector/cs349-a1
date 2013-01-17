// This class is taken from http://willperone.net/Code/vector2.php
// it seemed silly to implement my own vector library

#ifndef VECTOR_MATH_H
#define VECTOR_MATH_H

#include <math.h> 

template <typename T>
struct vector2 {
	T x, y;
	
	//! trivial ctor
	vector2<T>() {}

	//! setting ctor
	vector2<T>(const T x0, const T y0): x(x0), y(y0) {}

	//! array indexing
	T &operator [](unsigned int i) 
	{   return *(&x+i);   }

	//! array indexing
	const T &operator [](unsigned int i) const 
	{	return *(&x+i);   }  

	//! function call operator
	void operator ()(const T x0, const T y0) 
	{	x= x0; y= y0;	}

	//! test for equality
	bool operator==(const vector2<T> &v)
	{	return (x==v.x && y==v.y);	}

	//! test for inequality
	bool operator!=(const vector2<T> &v)
	{	return (x!=v.x || y!=v.y);	}
	
	//! set to value
	const vector2<T> &operator =(const vector2<T> &v)
	{	
		x= v.x; y= v.y;			
		return *this;
	}
	
	//! negation
	const vector2<T> operator -(void) const
	{	return vector2<T>(-x, -y);	}

	//! addition
	const vector2<T> operator +(const vector2<T> &v) const
	{	return vector2<T>(x+v.x, y+v.y);	}
	
	//! subtraction
	const vector2<T> operator -(const vector2<T> &v) const
	{   return vector2<T>(x-v.x, y-v.y);	}
		
	//! uniform scaling
	const vector2<T> operator *(const T num) const
	{
		vector2<T> temp(*this);			
		return temp*=num;
	}

	//! uniform scaling
	const vector2<T> operator /(const T num) const
	{
		vector2<T> temp(*this);			
		return temp/=num;
	}		

	//! addition
	const vector2<T> &operator +=(const vector2<T> &v)
	{
		x+=v.x;	y+=v.y;						
		return *this;
	}

	//! subtraction
	const vector2<T> &operator -=(const vector2<T> &v) 
	{ 
		x-=v.x;	y-=v.y;						
		return *this;	
	}

	//! uniform scaling
	const vector2<T> &operator *=(const T num)
	{
		x*=num;	y*=num;										
		return *this;
	}
	
	//! uniform scaling
	const vector2<T> &operator /=(const T num)
	{
		x/=num;	y/=num;										
		return *this;
	}

	//! dot product
	T operator *(const vector2<T> &v) const
	{	return x*v.x + y*v.y;	}	
};




template <typename T>
struct rectangle {
    vector2<T> position;
    vector2<T> size;
    
    rectangle<T>() {}
	rectangle<T>(const T &x0, const T &y0, const T &w, const T &h) :
        position(x0, y0), size(w, h) { }
    rectangle<T>(const vector2<T> &pos, const vector2<T> &siz) :
        position(pos), size(siz) { }
        
    T left() const { return position.x; }
    T right() const { return position.x + size.x; }
    T top() const { return position.y; }
    T bottom() const { return position.y + size.y; }
        
    bool intersects(const rectangle<T> &r2) const {
        return !(r2.left() > right() || 
                 r2.right() < left() || 
                 r2.top() > bottom() ||
                 r2.bottom() < top());
    }
    
    rectangle<T> intersection(const rectangle<T> &r2) const {
        T left = max(left(), r2.left());
        T right = min(right(), r2.right());
        T top = max(top(), r2.top());
        T bottom = min(bottom(), r2.bottom());
        
        return rectangle<T>(left, top, right - left, bottom - top);
    }
};

typedef vector2<float> vec2;
typedef rectangle<float> rect2;

#define UNPACK(vec) (vec).x, (vec).y
#define UNPACKI(vec) static_cast<int>((vec).x), static_cast<int>((vec).y)

#endif

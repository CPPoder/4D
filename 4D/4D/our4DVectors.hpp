#ifndef OUR4DVECTORS_HPP
#define OUR4DVECTORS_HPP

#include <iostream>


namespace fd
{
	////////////////////////
	//Class Template Vector4
	template <typename T> class Vector4
	{
	public:
		/////////////////
		//Membervariables

		T x1;
		T x2;
		T x3;
		T x4;

		//////////////
		//Constructors

		//Default constructor
		Vector4()
			: x1(0), x2(0), x3(0), x4(0)
		{
		}

		//Componentwise constructor
		Vector4(T _x1, T _x2, T _x3, T _x4)
			: x1(_x1), x2(_x2), x3(_x3), x4(_x4)
		{
		}

		//Copy constructor
		template <typename S> explicit Vector4(Vector4<S> const & _vector)
			: x1(_vector.x1), x2(_vector.x2), x2(_vector.x2), x2(_vector.x2)
		{
		}


		//Output on Terminal
		void outputOnTerminal(std::string _separator = "\t", std::string _outputDescription = "") const
		{
			std::cout << _outputDescription << x1 << _separator << x2 << _separator << x3 << _separator << x4 << std::endl;
		}

	};

////////////////////
//Function templates : Standard calculus

//Additive inverse
template <typename T> Vector4<T> operator- (Vector4<T> const & _vec)
{
	return Vector4<T>(-_vec.x1, -_vec.x2, -_vec.x3, -_vec.x4);
}

//Addition
template <typename T> Vector4<T> operator+ (Vector4<T> const & _vec1, Vector4<T> const & _vec2)
{
	return Vector4<T>(_vec1.x1 + _vec2.x1, _vec1.x2 + _vec2.x2, _vec1.x3 + _vec2.x3, _vec1.x4 + _vec2.x4);
}

//Subtraction
template <typename T> Vector4<T> operator- (Vector4<T> const & _vec1, Vector4<T> const & _vec2)
{
	return Vector4<T>(_vec1.x1 - _vec2.x1, _vec1.x2 - _vec2.x2, _vec1.x3 - _vec2.x3, _vec1.x4 - _vec2.x4);
}

//S-Multiplication
template <typename T> Vector4<T> operator* (T _scalar, Vector4<T> const & _vector)
{
	return Vector4<T>(_scalar * _vector.x1, _scalar * _vector.x2, _scalar * _vector.x3, _scalar * _vector.x4);
}
//S-Multiplication
template <typename T> Vector4<T> operator* (Vector4<T> const & _vector, T _scalar)
{
	return Vector4<T>(_scalar * _vector.x1, _scalar * _vector.x2, _scalar * _vector.x3, _scalar * _vector.x4);
}

//Division
template <typename T> Vector4<T> operator/ (Vector4<T> const & _vector, T _scalar)
{
	return Vector4<T>(_vector.x1 / _scalar, _vector.x2 / _scalar, _vector.x3 / _scalar, _vector.x4 / _scalar);
}

//Strange Division
template <typename T> Vector4<T> operator/ (T _scalar, Vector4<T> & _vector)
{
	return Vector4<T>(_scalar / _vector.x1, _scalar / _vector.x2, _scalar / _vector.x3, _scalar / _vector.x4);
}

//Inner product
template <typename T> Vector4<T> operator* (Vector4<T> const & _vec1, Vector4<T> const & _vec2)
{
	return (_vec1.x1 * _vec2.x1 + _vec1.x2 * _vec2.x2 + _vec1.x3 * _vec2.x3 + _vec1.x4 * _vec2.x4);
}


//////////////////////////////////////////
//Function templates : Combined operations

//Assign after addition
template <typename T> Vector4<T>& operator+= (Vector4<T> & _vec1, Vector4<T> const & _vec2)
{
	return _vec1 = (_vec1 + _vec2);
}

//Assign after subtraction
template <typename T> Vector4<T>& operator-= (Vector4<T> & _vec1, Vector4<T> const & _vec2)
{
	return _vec1 = (_vec1 - _vec2);
}

//Assign after multiplication
template <typename T> Vector4<T>& operator*= (Vector4<T> & _vec1, T _scalar)
{
	return _vec1 = (_vec1 * _scalar);
}

//Assign after division
template <typename T> Vector4<T>& operator/= (Vector4<T> & _vec1, T _scalar)
{
	return _vec1 = (_vec1 / _scalar);
}


//////////////////////////////////////////
//Function templates : Comparing operators

//Check for equality
template <typename T> bool operator== (Vector4<T> const & _vec1, Vector4<T> const & _vec2)
{
	return ((_vec1.x1 == _vec2.x1) && (_vec1.x2 == _vec2.x2) && (_vec1.x3 == _vec2.x3) && (_vec1.x4 == _vec2.x4));
}

//Check for inequality
template <typename T> bool operator!= (Vector4<T> const & _vec1, Vector4<T> const & _vec2)
{
	return ((_vec1.x1 != _vec2.x1) || (_vec1.x2 != _vec2.x2) || (_vec1.x3 != _vec2.x3) || (_vec1.x4 != _vec2.x4));
}

//Check for greater or equal
template <typename T> bool operator>= (Vector4<T> const & _vec1, Vector4<T> const & _vec2)
{
	return ((_vec1.x1 >= _vec2.x1) && (_vec1.x2 >= _vec2.x2) && (_vec1.x3 >= _vec2.x3) && (_vec1.x4 >= _vec2.x4));
}

//Check for smaller or equal
template <typename T> bool operator<= (Vector4<T> const & _vec1, Vector4<T> const & _vec2)
{
	return ((_vec1.x1 <= _vec2.x1) && (_vec1.x2 <= _vec2.x2) && (_vec1.x3 <= _vec2.x3) && (_vec1.x4 <= _vec2.x4));
}

//Check for greater
template <typename T> bool operator> (Vector4<T> const & _vec1, Vector4<T> const & _vec2)
{
	return ((_vec1.x1 > _vec2.x1) && (_vec1.x2 > _vec2.x2) && (_vec1.x3 > _vec2.x3) && (_vec1.x4 > _vec2.x4));
}

//Check for smaller
template <typename T> bool operator< (Vector4<T> const & _vec1, Vector4<T> const & _vec2)
{
	return ((_vec1.x1 < _vec2.x1) && (_vec1.x2 < _vec2.x2) && (_vec1.x3 < _vec2.x3) && (_vec1.x4 < _vec2.x4));
}



//////////////////
//Define Typenames

typedef Vector4<unsigned int> Vector4u;
typedef Vector4<int> Vector4i;
typedef Vector4<float> Vector4f;




} //Namespace 4D


#endif
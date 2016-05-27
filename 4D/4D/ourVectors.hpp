#ifndef OURVECTORS_HPP
#define OURVECTORS_HPP

#include <iostream>
#include <vector>
#include <stdexcept>


namespace fd
{
	////////////////////////
	//Class Template Vector4
	template <typename T, unsigned int dimension> class Vector
	{
	private:
		/////////////////
		//Membervariables

		std::vector<T> vector;

	public:
		//////////////
		//Constructors

		//Default constructor
		Vector()
		{
			for (unsigned int pos = 0; pos < dimension; pos++)
			{
				vector.push_back(T(0));
			}
		}

		//Constructor from std::vector (Throws an exception std::length_error for unvalid vectorSizes)
		explicit Vector(std::vector<T> const & vectorOfCorrectSize)
			: vector(vectorOfCorrectSize)
		{
			if (vectorOfCorrectSize.size() != dimension)
			{
				throw std::length_error("Constructor Vector<T>::Vector(std::vector<T> const &) was called with a vector of the wrong length!");
			}
		}

		//Copy constructor
		template <typename S> explicit Vector(Vector<S, dimension> const & vectorInput)
			: Vector()
		{
			for (unsigned int pos = 0; pos < dimension; pos++)
			{
				vector.at(pos) = vectorInput.getValueAt(pos);
			}
		}


		////////////////////////
		//Public Memberfunctions

		//Getter
		T getValueAt(unsigned int position) const
		{
			return vector.at(position);
		}

		//Provides access to the vector
		T& at(unsigned int position)
		{
			return vector.at(position);
		}

		//Output on Terminal
		void outputOnTerminal(std::string separator = "\t", std::string outputDescription = "") const
		{
			std::cout << outputDescription;
			for (unsigned int pos = 0; pos < (dimension - 1); pos++)
			{
				std::cout << vector.at(pos) << separator;
			}
			std::cout << vector.at(dimension - 1) << std::endl;
		}

	};


////////////////////
//Function templates : Standard calculus

//Additive inverse
template <typename T, unsigned int dim> Vector<T, dim> operator- (Vector<T, dim> const & vec)
{
	Vector<T, dim> result;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result.at(pos) = -vec.getValueAt(pos);
	}
	return result;
}

//Addition
template <typename T, unsigned int dim> Vector<T, dim> operator+ (Vector<T, dim> const & vec1, Vector<T, dim> const & vec2)
{
	Vector<T, dim> result;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result.at(pos) = vec1.getValueAt(pos) + vec2.getValueAt(pos);
	}
	return result;
}

//Subtraction
template <typename T, unsigned int dim> Vector<T, dim> operator- (Vector<T, dim> const & vec1, Vector<T, dim> const & vec2)
{
	Vector<T, dim> result;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result.at(pos) = vec1.getValueAt(pos) - vec2.getValueAt(pos);
	}
	return result;
}

//S-Multiplication
template <typename T, unsigned int dim> Vector<T, dim> operator* (T scalar, Vector<T, dim> const & vec)
{
	Vector<T, dim> result;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result.at(pos) = scalar * vec.getValueAt(pos);
	}
	return result;
}

//S-Multiplication
template <typename T, unsigned int dim> Vector<T, dim> operator* (Vector<T, dim> const & vec, T scalar)
{
	Vector<T, dim> result;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result.at(pos) = scalar * vec.getValueAt(pos);
	}
	return result;
}

//Division
template <typename T, unsigned int dim> Vector<T, dim> operator/ (Vector<T, dim> const & vec, T scalar)
{
	Vector<T, dim> result;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result.at(pos) = vec.getValueAt(pos) / scalar;
	}
	return result;
}

//Strange Division
template <typename T, unsigned int dim> Vector<T, dim> operator/ (T scalar, Vector<T, dim> & vec)
{
	Vector<T, dim> result;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result.at(pos) = scalar / vec.getValueAt(pos);
	}
	return result;
}

//Inner product
template <typename T, unsigned int dim> T operator* (Vector<T, dim> const & vec1, Vector<T, dim> const & vec2)
{
	T result = T(0);
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result = result + (vec1.getValueAt(pos) * vec2.getValueAt(pos));
	}
	return result;
}


//////////////////////////////////////////
//Function templates : Combined operations

//Assign after addition
template <typename T, unsigned int dim> Vector<T, dim>& operator+= (Vector<T, dim> & vec1, Vector<T, dim> const & vec2)
{
	return vec1 = (vec1 + vec2);
}

//Assign after subtraction
template <typename T, unsigned int dim> Vector<T, dim>& operator-= (Vector<T, dim> & vec1, Vector<T, dim> const & vec2)
{
	return vec1 = (vec1 - vec2);
}

//Assign after multiplication
template <typename T, unsigned int dim> Vector<T, dim>& operator*= (Vector<T, dim> & vec1, T scalar)
{
	return vec1 = (vec1 * scalar);
}

//Assign after division
template <typename T, unsigned int dim> Vector<T, dim>& operator/= (Vector<T, dim> & vec1, T scalar)
{
	return vec1 = (vec1 / scalar);
}


//////////////////////////////////////////
//Function templates : Comparing operators

//Check for equality
template <typename T, unsigned int dim> bool operator== (Vector<T, dim> const & vec1, Vector<T, dim> const & vec2)
{
	bool result = true;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result = result && (vec1.getValueAt(pos) == vec2.getValueAt(pos));
		if (!result)
		{
			break;
		}
	}
	return result;
}

//Check for inequality
template <typename T, unsigned int dim> bool operator!= (Vector<T, dim> const & vec1, Vector<T, dim> const & vec2)
{
	bool result = true;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result = result && (vec1.getValueAt(pos) == vec2.getValueAt(pos));
		if (!result)
		{
			break;
		}
	}
	return (!result);
}

//Check for greater or equal
template <typename T, unsigned int dim> bool operator>= (Vector<T, dim> const & vec1, Vector<T, dim> const & vec2)
{
	bool result = true;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result = result && (vec1.getValueAt(pos) >= vec2.getValueAt(pos));
		if (!result)
		{
			break;
		}
	}
	return (result);
}

//Check for smaller or equal
template <typename T, unsigned int dim> bool operator<= (Vector<T, dim> const & vec1, Vector<T, dim> const & vec2)
{
	bool result = true;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result = result && (vec1.getValueAt(pos) <= vec2.getValueAt(pos));
		if (!result)
		{
			break;
		}
	}
	return (result);
}

//Check for greater
template <typename T, unsigned int dim> bool operator> (Vector<T, dim> const & vec1, Vector<T, dim> const & vec2)
{
	bool result = true;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result = result && (vec1.getValueAt(pos) > vec2.getValueAt(pos));
		if (!result)
		{
			break;
		}
	}
	return (result);
}

//Check for smaller
template <typename T, unsigned int dim> bool operator< (Vector<T, dim> const & vec1, Vector<T, dim> const & vec2)
{
	bool result = true;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result = result && (vec1.getValueAt(pos) < vec2.getValueAt(pos));
		if (!result)
		{
			break;
		}
	}
	return (result);
}


//////////////////
//Define Typenames

typedef Vector<unsigned int, 2> Vector2u;
typedef Vector<int, 2> Vector2i;
typedef Vector<float, 2> Vector2f;

typedef Vector<unsigned int, 3> Vector3u;
typedef Vector<int, 3> Vector3i;
typedef Vector<float, 3> Vector3f;

typedef Vector<unsigned int, 4> Vector4u;
typedef Vector<int, 4> Vector4i;
typedef Vector<float, 4> Vector4f;



} //Namespace 4D


#endif
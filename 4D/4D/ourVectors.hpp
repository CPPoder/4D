#ifndef OURVECTORS_HPP
#define OURVECTORS_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>

#include "SFML\Graphics.hpp"


namespace fd
{
	///////////////////////
	//Class Template Vector
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

		//Constructor from scalar
		explicit Vector(T scalar)
			: Vector()
		{
			for (unsigned int pos = 0; pos < dimension; pos++)
			{
				vector.at(pos) = scalar;
			}
		}

		//Constructor from initiallizer list (Throws an exception std::length_error for unvalid initializer_list sizes)
		explicit Vector(std::initializer_list<T> const & initList)
			: vector(initList)
		{
			if (initList.size() != dimension)
			{
				throw std::length_error("Constructor Vector::Vector(std::initializer_list<T> const &) was called with an initializer_list of the wrong length!");
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


////////////////////////////////////////
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

//Addition of scalar and vector (componentwise)
template <typename T, unsigned int dim> Vector<T, dim> operator+ (Vector<T, dim> const & vec, T scalar)
{
	Vector<T, dim> result;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result.at(pos) = scalar + vec.getValueAt(pos);
	}
	return result;
}
template <typename T, unsigned int dim> Vector<T, dim> operator+ (T scalar, Vector<T, dim> const & vec)
{
	Vector<T, dim> result;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result.at(pos) = scalar + vec.getValueAt(pos);
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

//Subtraction between scalar and vector (componentwise)
template <typename T, unsigned int dim> Vector<T, dim> operator- (Vector<T, dim> const & vec, T scalar)
{
	Vector<T, dim> result;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result.at(pos) = vec.getValueAt(pos) - scalar;
	}
	return result;
}
template <typename T, unsigned int dim> Vector<T, dim> operator- (T scalar, Vector<T, dim> const & vec)
{
	Vector<T, dim> result;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result.at(pos) = scalar - vec.getValueAt(pos);
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
template <typename T, unsigned int dim> Vector<T, dim> operator/ (T scalar, Vector<T, dim> const & vec)
{
	Vector<T, dim> result;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result.at(pos) = scalar / vec.getValueAt(pos);
	}
	return result;
}

//Componentwise Division
template <typename T, unsigned int dim> Vector<T, dim> operator/ (Vector<T, dim> const & vec1, Vector<T, dim> const & vec2)
{
	Vector<T, dim> result;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result.at(pos) = vec1.getValueAt(pos) / vec2.getValueAt(pos);
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

//Componentwise Multiplication
template <typename T, unsigned int dim> Vector<T, dim> componentwiseMultiplication(Vector<T, dim> const & vec1, Vector<T, dim> const & vec2)
{
	Vector<T, dim> result;
	for (unsigned int pos = 0; pos < dim; pos++)
	{
		result.at(pos) = vec1.getValueAt(pos) * vec2.getValueAt(pos);
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


//////////////////////////////////////////
//Function templates : Mathematical functions

//Cross product
template<typename T> Vector<T, 3> crossProduct(Vector<T, 3> const & vec1, Vector<T, 3> const & vec2)
{
	Vector<T, 3> result;
	result.at(0) = (vec1.getValueAt(1) * vec2.getValueAt(2) - vec1.getValueAt(2) * vec2.getValueAt(1));
	result.at(1) = (vec1.getValueAt(2) * vec2.getValueAt(0) - vec1.getValueAt(0) * vec2.getValueAt(2));
	result.at(2) = (vec1.getValueAt(0) * vec2.getValueAt(1) - vec1.getValueAt(1) * vec2.getValueAt(0));
	return result;
}


////////////////////////////////////////
//Function templates : Helpful functions

//Output on terminal
template <typename T, unsigned int dim> void outputOnTerminal(Vector<T, dim> const & vec, std::string separator = "\t", std::string outputDescription = "")
{
	std::cout << outputDescription;
	for (unsigned int pos = 0; pos < (dim - 1); pos++)
	{
		std::cout << vec.getValueAt(pos) << separator;
	}
	std::cout << vec.getValueAt(dim - 1) << std::endl;
}


////////////////////////////////////////////////////////////////////////
//Function templates : Bijective Homos between sf::Vector and fd::Vector

//Canonical maps from sf::Vector to fd::Vector
template <typename T> fd::Vector<T, 2> createFdFromSfVector(sf::Vector2<T> const & sfVector)
{
	fd::Vector<T, 2> result;
	result.at(0) = sfVector.x;
	result.at(1) = sfVector.y;
	return result;
}
template <typename T> fd::Vector<T, 3> createFdFromSfVector(sf::Vector3<T> const & sfVector)
{
	fd::Vector<T, 3> result;
	result.at(0) = sfVector.x;
	result.at(1) = sfVector.y;
	result.at(2) = sfVector.z;
	return result;
}

//Canonical maps from fd::Vector to sf::Vector
template <typename T> sf::Vector2<T> createSfFromFdVector(fd::Vector<T, 2> const & fdVector)
{
	return sf::Vector2<T>(fdVector.getValueAt(0), fdVector.getValueAt(1));
}
template <typename T> sf::Vector3<T> createSfFromFdVector(fd::Vector<T, 3> const & fdVector)
{
	return sf::Vector3<T>(fdVector.getValueAt(0), fdVector.getValueAt(1), fdVector.getValueAt(2));
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
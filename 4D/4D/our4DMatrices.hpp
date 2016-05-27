#ifndef OUR4DMATRICES_HPP
#define OUR4DMATRICES_HPP

#include "SFML\Graphics.hpp"

#include <iostream>
#include <vector>

#include "ourVectors.hpp"

namespace fd
{
	////////////////////////
	//Class Template Vector4
	template <typename T> class Matrix4
	{
	private:
		/////////////////
		//Membervariables

		std::vector<std::vector<T>> matrix;



	public:
		//////////////
		//Constructors

		//Default constructor
		Matrix4()
		{
			std::vector<T> column({ T(0), T(0), T(0), T(0) });
			matrix = std::vector<std::vector<T>>({ column, column, column, column });
		}

		//Componentwise constructor
		Matrix4(Vector4<T> _vec1, Vector4<T> _vec2, Vector4<T> _vec3, Vector4<T> _vec4, bool asColumnVectors)
			: Matrix4()
		{
			if (asColumnVectors)
			{

			}
			else
			{
				
			}
		}

		//Copy constructor
		/*template <typename S> explicit Vector4(Vector4<S> const & _vector)
			: x1(_vector.x1), x2(_vector.x2), x2(_vector.x2), x2(_vector.x2)
		{
		}*/


		//Access to matrix
		T& at(sf::Vector2u pos)
		{
			return matrix.at(pos.x).at(pos.y);
		}
		T& at(unsigned int row, unsigned int column)
		{
			return matrix.at(row).at(column);
		}


		//Output on terminal
		void outputOnTerminal(std::string separator = "", std::string description = "") const
		{
			if (description != "")
			{
				std::cout << description << std::endl;
			}
			for (unsigned int row = 0; row < 4; row++)
			{
				for (unsigned int column = 0; column < 4; column++)
				{
					std::cout << matrix.at(row).at(column) << separator;
				}
				std::cout << std::endl;
			}
		}



	};





//////////////////
//Define Typenames


typedef Matrix4<unsigned int> Matrix4u;
typedef Matrix4<int> Matrix4i;
typedef Matrix4<float> Matrix4f;




} //Namespace 4D


#endif
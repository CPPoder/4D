#ifndef OURMATRICES_HPP
#define OURMATRICES_HPP

#include "SFML\Graphics.hpp"

#include <iostream>
#include <vector>
#include <initializer_list>

#include "myUsefulMath.hpp"

#include "ourVectors.hpp"

namespace fd
{
	////////////////////////
	//Class Template Matrix
	template <typename T, unsigned int m, unsigned int n> class Matrix
	{
	private:
		/////////////////
		//Membervariables

		std::vector<std::vector<T>> matrix;



	public:
		//////////////
		//Constructors

		//Default constructor
		Matrix()
		{
			std::vector<T> rowVector;
			for (unsigned int pos = 0; pos < n; pos++)
			{
				rowVector.push_back(T(0));
			}
			for (unsigned int pos = 0; pos < m; pos++)
			{
				matrix.push_back(rowVector);
			}
		}

		//Constructor from scalar
		explicit Matrix(T scalar)
		{
			std::vector<T> rowVector;
			for (unsigned int pos = 0; pos < n; pos++)
			{
				rowVector.push_back(scalar);
			}
			for (unsigned int pos = 0; pos < m; pos++)
			{
				matrix.push_back(rowVector);
			}
		}

		//Constructor from initiallizer list (Throws an exception std::length_error for invalid initializer_list sizes)
		explicit Matrix(std::initializer_list<std::initializer_list<T>> const & initList)
			: Matrix()
		{
			std::vector<std::initializer_list<T>> initVector(initList);
			//Check for correct size
			bool rowLengthValid = true;
			for (unsigned int pos = 0; pos < m; pos++)
			{
				rowLengthValid = rowLengthValid && (initVector.at(pos).size() == n);
			}
			if (!(rowLengthValid && initVector.size() == m))
			{
				throw std::length_error("Constructor Matrix::Matrix(std::initializer_list<std::initializer_list<T>> const &) was called with an initializer_list of the wrong size!");
			}
			//Initialize
			for (unsigned int pos = 0; pos < m; pos++)
			{
				matrix.at(pos) = initVector.at(pos);
			}
		}

		//Copy constructor
		template <typename S> explicit Matrix(Matrix<S, m, n> const & matrixInput)
			: Matrix()
		{
			for (unsigned int i = 0; i < m; i++)
			{
				for (unsigned int j = 0; j < n; j++)
				{
					matrix.at(i).at(j) = matrixInput.getValueAt(i, j);
				}
			}
		}


		////////////////////////
		//Public Memberfunctions

		//Access to matrix
		T& at(sf::Vector2u pos)
		{
			return matrix.at(pos.x).at(pos.y);
		}
		T& at(fd::Vector2u pos)
		{
			return matrix.at(pos.at(0)).at(pos.at(1));
		}
		T& at(unsigned int row, unsigned int column)
		{
			return matrix.at(row).at(column);
		}

		//Getter
		T getValueAt(sf::Vector2u pos) const
		{
			return matrix.at(pos.x).at(pos.y);
		}
		T getValueAt(fd::Vector2u pos) const
		{
			return matrix.at(pos.at(0)).at(pos.at(1));
		}
		T getValueAt(unsigned int row, unsigned int column) const
		{
			return matrix.at(row).at(column);
		}

		//Get size
		Vector2u getSize() const
		{
			Vector2u out;
			out.at(0) = m;
			out.at(1) = n;
			return out;
		}

		//Get column (Throws an exception for invalid column numbers)
		Vector<T, m> getColumn(unsigned int column) const
		{
			if (column >= n)
			{
				throw "Matrix::getColumn(unsigned int) : Column number is incompatible with matrix size!";
			}
			Vector<T, m> result;
			for (unsigned int i = 0; i < m; i++)
			{
				result.at(i) = getValueAt(i, column);
			}
			return result;
		}

		//Get row (Throws an exception for invalid row numbers)
		Vector<T, n> getRow(unsigned int row) const
		{
			if (row >= m)
			{
				throw "Matrix::getRow(unsigned int) : Row number is incompatible with matrix size!";
			}
			Vector<T, n> result;
			for (unsigned int j = 0; j < n; j++)
			{
				result.at(j) = getValueAt(row, j);
			}
			return result;
		}

		//Get a submatrix with origin and size (Throws an exception for invalid origins and sizes)
		template <unsigned int rowNumber, unsigned int colNumber> Matrix<T, rowNumber, colNumber> getSubMatrix(unsigned int originRow, unsigned int originCol) const
		{
			if (((originRow + rowNumber) > m) || ((originCol + colNumber) > n))
			{
				throw "Matrix::getSubMatrix(unsigned int, unsigned int, unsigned int, unsigned int) : Sub matrix is incompatible with matrix size!";
			}
			Matrix<T, rowNumber, colNumber> result;
			for (unsigned int i = 0; i < rowNumber; i++)
			{
				for (unsigned int j = 0; j < colNumber; j++)
				{
					result.at(i, j) = getValueAt(originRow + i, originCol + j);
				}
			}
			return result;
		}

		//Get the transposed matrix without changing this
		Matrix<T, n, m> getTransposed() const
		{
			Matrix<T, n, m> transposed;
			for (unsigned int i = 0; i < n; i++)
			{
				for (unsigned int j = 0; j < m; j++)
				{
					transposed.at(i, j) = getValueAt(j, i);
				}
			}
			return transposed;
		}

		//Calculates the trace of this
		T trace() const
		{
			T trace = 0;
			for (unsigned int i = 0; i < myMath::min(m, n); i++)
			{
				trace = trace + getValueAt(i, i);
			}
			return trace;
		}

		//Output on terminal
		void outputOnTerminal(std::string separator = "", std::string description = "") const
		{
			if (description != "")
			{
				std::cout << description << std::endl;
			}
			for (unsigned int i = 0; i < m; i++)
			{
				for (unsigned int j = 0; j < n; j++)
				{
					std::cout << matrix.at(i).at(j) << separator;
				}
				std::cout << std::endl;
			}
		}

	};


	////////////////////////////////////////
	//Function templates : Standard calculus

	//Additive Inverse
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n> operator- (Matrix<T, m, n> const & mat)
	{
		Matrix<T, m, n> result;
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				result.at(i, j) = -mat.getValueAt(i, j);
			}
		}
		return result;
	}

	//Addition of matrices (Componentwise)
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n> operator+ (Matrix<T, m, n> const & mat1, Matrix<T, m, n> const & mat2)
	{
		Matrix<T, m, n> result;
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				result.at(i, j) = mat1.getValueAt(i, j) + mat2.getValueAt(i, j);
			}
		}
		return result;
	}

	//Subtraction of matrices (Componentwise)
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n> operator- (Matrix<T, m, n> const & mat1, Matrix<T, m, n> const & mat2)
	{
		Matrix<T, m, n> result;
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				result.at(i, j) = mat1.getValueAt(i, j) - mat2.getValueAt(i, j);
			}
		}
		return result;
	}

	//Addition of matrix and scalar (Componentwise)
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n> operator+ (Matrix<T, m, n> const & mat, T scalar)
	{
		Matrix<T, m, n> result;
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				result.at(i, j) = mat.getValueAt(i, j) + scalar;
			}
		}
		return result;
	}
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n> operator+ (T scalar, Matrix<T, m, n> const & mat)
	{
		Matrix<T, m, n> result;
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				result.at(i, j) = scalar + mat.getValueAt(i, j);
			}
		}
		return result;
	}

	//Subtraction of matrix and scalar (Componentwise)
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n> operator- (Matrix<T, m, n> const & mat, T scalar)
	{
		Matrix<T, m, n> result;
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				result.at(i, j) = mat.getValueAt(i, j) - scalar;
			}
		}
		return result;
	}
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n> operator- (T scalar, Matrix<T, m, n> const & mat)
	{
		Matrix<T, m, n> result;
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				result.at(i, j) = scalar - mat.getValueAt(i, j);
			}
		}
		return result;
	}

	//S-Multiplication (Componentwise)
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n> operator* (T scalar, Matrix<T, m, n> const & mat)
	{
		Matrix<T, m, n> result;
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				result.at(i, j) = scalar * mat.getValueAt(i, j);
			}
		}
		return result;
	}
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n> operator* (Matrix<T, m, n> const & mat, T scalar)
	{
		Matrix<T, m, n> result;
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				result.at(i, j) = mat.getValueAt(i, j) * scalar;
			}
		}
		return result;
	}

	//Division of Matrices (Componentwise)
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n> operator/ (Matrix<T, m, n> const & mat1, Matrix<T, m, n> const & mat2)
	{
		Matrix<T, m, n> result;
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				result.at(i, j) = mat1.getValueAt(i, j) / mat2.getValueAt(i, j);
			}
		}
		return result;
	}

	//Division with scalar (Componentwise)
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n> operator/ (Matrix<T, m, n> const & mat, T scalar)
	{
		Matrix<T, m, n> result;
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				result.at(i, j) = mat.getValueAt(i, j) / scalar;
			}
		}
		return result;
	}

	//Strange Division
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n> operator/ (T scalar, Matrix<T, m, n> const & mat)
	{
		Matrix<T, m, n> result;
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				result.at(i, j) = scalar / mat.getValueAt(i, j);
			}
		}
		return result;
	}

	//Matrixmultiplication
	template <typename T, unsigned int m, unsigned int t, unsigned int n> Matrix<T, m, n> operator* (Matrix<T, m, t> const & mat1, Matrix<T, t, n> const & mat2)
	{
		Matrix<T, m, n> result;
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				T entry(0);
				for (unsigned int k = 0; k < t; k++)
				{
					entry = entry + (mat1.getValueAt(i, k) * mat2.getValueAt(k, j));
				}
				result.at(i, j) = entry;
			}
		}
		return result;
	}


	//////////////////////////////////////////
	//Function templates : Combined operations

	//Assign after addition
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n>& operator+= (Matrix<T, m, n> & mat1, Matrix<T, m, n> const & mat2)
	{
		return mat1 = (mat1 + mat2);
	}

	//Assign after subtraction
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n>& operator-= (Matrix<T, m, n> & mat1, Matrix<T, m, n> const & mat2)
	{
		return mat1 = (mat1 - mat2);
	}

	//Assign after multiplication
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n>& operator*= (Matrix<T, m, n> & mat1, T scalar)
	{
		return mat1 = (mat1 * scalar);
	}

	//Assign after division
	template <typename T, unsigned int m, unsigned int n> Matrix<T, m, n>& operator/= (Matrix<T, m, n> & mat1, T scalar)
	{
		return mat1 = (mat1 / scalar);
	}


	//////////////////////////////////////////
	//Function templates : Comparing operators

	//Check for equality
	template <typename T, unsigned int m, unsigned int n> bool operator== (Matrix<T, m, n> const & mat1, Matrix<T, m, n> const & mat2)
	{
		bool result = true;
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				result = result && (mat1.getValueAt(i, j) == mat2.getValueAt(i, j));
				if (!result)
				{
					break;
				}
			}
			if (!result)
			{
				break;
			}
		}
		return result;
	}

	//Check for inequality
	template <typename T, unsigned int m, unsigned int n> bool operator!= (Matrix<T, m, n> const & mat1, Matrix<T, m, n> const & mat2)
	{
		bool result = true;
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				result = result && (mat1.getValueAt(i, j) == mat2.getValueAt(i, j));
				if (!result)
				{
					break;
				}
			}
			if (!result)
			{
				break;
			}
		}
		return (!result);
	}


	/////////////////////////////////////
	//Matrix and Vector mixing operations

	//Matrix times Vector
	template <typename T, unsigned int m, unsigned int n> Vector<T, m> operator* (Matrix<T, m, n> const & mat, Vector<T, n> const & vec)
	{
		Vector<T, m> result;
		for (unsigned int i = 0; i < m; i++)
		{
			T entry(0);
			for (unsigned int j = 0; j < n; j++)
			{
				entry = entry + (mat.getValueAt(i, j) * vec.getValueAt(j));
			}
			result.at(i) = entry;
		}
		return result;
	}


	//////////////////////////////////////////
	//Function templates : Helpful functions

	//Output on terminal
	template <typename T, unsigned int m, unsigned int n> void outputOnTerminal(Matrix<T, m, n> const & mat, std::string separator = "\t", std::string description = "")
	{
		if (description != "")
		{
			std::cout << description << std::endl;
		}
		for (unsigned int i = 0; i < m; i++)
		{
			for (unsigned int j = 0; j < n; j++)
			{
				std::cout << mat.getValueAt(i, j) << separator;
			}
			std::cout << std::endl;
		}
	}


//////////////////
//Define Typenames

typedef Matrix<unsigned int, 1, 1> Matrix11u;
typedef Matrix<unsigned int, 1, 2> Matrix12u;
typedef Matrix<unsigned int, 1, 3> Matrix13u;
typedef Matrix<unsigned int, 1, 4> Matrix14u;
typedef Matrix<unsigned int, 2, 1> Matrix21u;
typedef Matrix<unsigned int, 2, 2> Matrix22u;
typedef Matrix<unsigned int, 2, 3> Matrix23u;
typedef Matrix<unsigned int, 2, 4> Matrix24u;
typedef Matrix<unsigned int, 3, 1> Matrix31u;
typedef Matrix<unsigned int, 3, 2> Matrix32u;
typedef Matrix<unsigned int, 3, 3> Matrix33u;
typedef Matrix<unsigned int, 3, 4> Matrix34u;
typedef Matrix<unsigned int, 4, 1> Matrix41u;
typedef Matrix<unsigned int, 4, 2> Matrix42u;
typedef Matrix<unsigned int, 4, 3> Matrix43u;
typedef Matrix<unsigned int, 4, 4> Matrix44u;

typedef Matrix<int, 1, 1> Matrix11i;
typedef Matrix<int, 1, 2> Matrix12i;
typedef Matrix<int, 1, 3> Matrix13i;
typedef Matrix<int, 1, 4> Matrix14i;
typedef Matrix<int, 2, 1> Matrix21i;
typedef Matrix<int, 2, 2> Matrix22i;
typedef Matrix<int, 2, 3> Matrix23i;
typedef Matrix<int, 2, 4> Matrix24i;
typedef Matrix<int, 3, 1> Matrix31i;
typedef Matrix<int, 3, 2> Matrix32i;
typedef Matrix<int, 3, 3> Matrix33i;
typedef Matrix<int, 3, 4> Matrix34i;
typedef Matrix<int, 4, 1> Matrix41i;
typedef Matrix<int, 4, 2> Matrix42i;
typedef Matrix<int, 4, 3> Matrix43i;
typedef Matrix<int, 4, 4> Matrix44i;

typedef Matrix<float, 1, 1> Matrix11f;
typedef Matrix<float, 1, 2> Matrix12f;
typedef Matrix<float, 1, 3> Matrix13f;
typedef Matrix<float, 1, 4> Matrix14f;
typedef Matrix<float, 2, 1> Matrix21f;
typedef Matrix<float, 2, 2> Matrix22f;
typedef Matrix<float, 2, 3> Matrix23f;
typedef Matrix<float, 2, 4> Matrix24f;
typedef Matrix<float, 3, 1> Matrix31f;
typedef Matrix<float, 3, 2> Matrix32f;
typedef Matrix<float, 3, 3> Matrix33f;
typedef Matrix<float, 3, 4> Matrix34f;
typedef Matrix<float, 4, 1> Matrix41f;
typedef Matrix<float, 4, 2> Matrix42f;
typedef Matrix<float, 4, 3> Matrix43f;
typedef Matrix<float, 4, 4> Matrix44f;



} //Namespace 4D


#endif



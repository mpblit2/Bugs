#pragma once
#include "Vector2.h"

/*TODO:
	Matxik to zbi�r 2 wektor�w,
	Vector2 rows_[2];
	+ zrobi� prze�adowanie operatora [],
	- prze�adowa� operatory jak dla klasy Vector2
	- Nie ma d�ugo�ci tylko b�dzie "wyznacznik macierzy"
	- Mno�enie: 
		- 2 macierzy,
		- macierz razy wektor,
		- wektor razy macierz,
		- macie� razy skalar (obustronne)
	- dodawanie,
	- odejmowanie.
*/

namespace Bugs
{
	class Matrix2
	{
	public:
		Matrix2(Vector2 vector_1 = Vector2(), Vector2 vector_2 = Vector2() ) : rows_{vector_1, vector_2}
		{
		}

		~Matrix2()
		{
		}

		const Vector2& operator[](std::size_t item) const
		{
			if(item > 1)
				throw std::overflow_error("Out of range.");
			
			return rows_[item];
		}

		Matrix2& operator+=(const Matrix2& matrix)
		{
			this->rows_[0] += matrix[0];
			this->rows_[1] += matrix[1];

			return *this;
		}

	private:
		Vector2 rows_[2];
	};

	inline Matrix2 operator+(const Matrix2& left, const Matrix2& right)
	{
		Matrix2 result(left);
		return result += right;
	}
}
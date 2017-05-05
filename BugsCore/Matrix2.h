#pragma once
#include "Vector2.h"

/*TODO:
	Matrix to zbiór 2 wektorów,
	Vector2 rows_[2];
	+ zrobiæ prze³adowanie operatora [],
	- prze³adowaæ operatory jak dla klasy Vector2
	+ Nie ma d³ugoœci tylko bêdzie "wyznacznik macierzy"
	- Mno¿enie: 
		- 2 macierzy,
		- macierz razy wektor,
		- wektor razy macierz,
		- macie¿ razy skalar (obustronne)
	+ dodawanie,
	+ odejmowanie.
	+ równy,
	+ nierówny,
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

		bool operator==(const Matrix2& matrix) const
		{
			return this->rows_[0] == matrix[0] && this->rows_[1] == matrix[1];
		}

		bool operator!=(const Matrix2& matrix) const
		{
			return !(*this == matrix);
		}

		Vector2& operator[](std::size_t item)
		{
			//Assert is used because of efficiency reasons. It gives no runtime overhead.
			assert(item < 2);
			return rows_[item];
		}

		const Vector2& operator[](std::size_t item) const
		{
			//Assert is used because of efficiency reasons. It gives no runtime overhead.
			assert(item < 2);
			return rows_[item];
		}

		Matrix2& operator+=(const Matrix2& matrix)
		{
			this->rows_[0] += matrix[0];
			this->rows_[1] += matrix[1];

			return *this;
		}

		Matrix2& operator-=(const Matrix2& matrix)
		{
			this->rows_[0] -= matrix[0];
			this->rows_[1] -= matrix[1];

			return *this;
		}

		Matrix2 operator*(const Matrix2& matrix) const
		{
			float a00 = rows_[0][0] * matrix[0][0] + rows_[0][1] * matrix[1][0];
			float a01 = rows_[0][0] * matrix[0][1] + rows_[0][1] * matrix[1][1];
			float a10 = rows_[1][0] * matrix[0][0] + rows_[1][1] * matrix[1][0];
			float a11 = rows_[1][1] * matrix[0][1] + rows_[1][1] * matrix[1][1];

			return Matrix2(Vector2(a00, a01), Vector2(a10, a11));
		}

		//Determinant of the matrix
		float Det() const
		{
			return rows_[0][0] * rows_[1][1] - rows_[1][0] * rows_[0][1];
		}

	private:
		Vector2 rows_[2];
	};

	inline Matrix2 operator+(const Matrix2& left, const Matrix2& right)
	{
		Matrix2 result(left);
		return result += right;
	}

	inline Matrix2 operator-(const Matrix2& left, const Matrix2& right)
	{
		Matrix2 result(left);
		return result -= right;
	}
}
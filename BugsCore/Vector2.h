#pragma once
/*Stworzyæ operatory:
+ dodawanie,
+ odejmowanie,
+ mno¿enie przez sta³¹, 
+ dzielenie przez sta³¹,
+ pobieranie d³ugoœci wektora,
*/

namespace Bugs
{
	class Vector2
	{
	public:
		Vector2(float x = 0.0f, float y = 0.0f)
			: x_(x), y_(y)
		{
		}
		
		~Vector2()
		{
		}

		float GetX() const
		{
			return x_;
		}

		float& GetX()
		{
			return x_;
		}

		float GetY() const
		{
			return y_;
		}

		float& GetY()
		{
			return y_;
		}

		void SetX(float value)
		{
			x_ = value;
		}

		void SetY(float value)
		{
			y_ = value;
		}

		Vector2(const Vector2&) = default;

		Vector2& operator=(const Vector2&) = default;

		bool operator==(const Vector2& vector) const
		{
			return x_ == vector.x_ && y_ == vector.y_;
		}

		bool operator!=(const Vector2& vector) const
		{
			return !(this->operator==(vector));
		}

		//Tu zmieniamy stan obiektu wiêc metoda nie mo¿e byæ 'const'
		Vector2& operator+=(const Vector2& vector)
		{
			this->x_ += vector.x_;
			this->y_ += vector.y_;

			//Tu zwracamy '*this' poniewa¿ wartoœæ zwracana jest referencj¹.
			return *this;
		}

		Vector2& operator-=(const Vector2& vector)
		{
			this->x_ -= vector.x_;
			this->y_ -= vector.y_;

			return *this;
		}

		Vector2& operator*=(const float scalar)
		{
			this->x_ *= scalar;
			this->y_ *= scalar;

			return *this;
		}

		Vector2& operator/=(const float scalar)
		{
			if (scalar == 0)
				throw std::overflow_error("Divide by zero exception");
			return *this *= 1 / scalar;
		}

		//Metoda obliczaj¹ca iloczyn skalarny wektorów (je¿eli wynik jest równy 0, wówczas wektory s¹ prostopad³e)
		float Dot(const Vector2& vector) const
		{
			return this->x_ * vector.x_ + this->y_ * vector.y_;
		}

		//Metoda obliczaj¹ca iloczyn wektorowy wektorów (je¿eli wynik jest równy 0, wówczas wektory s¹ równoleg³e)
		float Cross(const Vector2& vector) const
		{
			return this->x_ * vector.y_ - this->y_ * vector.x_;
		}

		float GetLenght() const
		{
			return sqrt((this->x_ * this->x_) + (this->y_ * this->y_));
		}

	private:
		float x_;
		float y_;
	};

	//Umieszczamy tê metodê poza klas¹ poniewa¿ nie ma potrzeby do odwo³ywania siê do prywatnych zmiennych klasy Vector2
	//oraz operator + mo¿e byæ wyra¿ony przez operator +=, który znajduje siê wewn¹trz klasy.
	//'inline' jest tutaj potrzebny ¿eby operator nie by³ wkompilowany w ka¿dy plik, który za³acza ten plik nag³ówkowy.
	inline Vector2 operator+(const Vector2& left, const Vector2& right)
	{
		//U¿ywamy konstruktora kopiuj¹cego poniewa¿ nie mo¿my modyfikowaæ argumentów wejœciowych.
		Vector2 result(left);
		return result += right;
	}

	inline Vector2 operator-(const Vector2& left, const Vector2& right)
	{
		Vector2 result(left);
		return result -= right;
	}

	inline Vector2 operator*(const Vector2& left, const float right)
	{
		Vector2 result(left);
		return result *= right;
	}

	inline Vector2 operator*(const float left, const Vector2& right)
	{
		Vector2 result(right);
		return result *= left;
	}

	inline Vector2 operator/(const Vector2& left, const float right)
	{
		Vector2 result(left);
		return result /= right;
	}
}
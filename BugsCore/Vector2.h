#pragma once
/*Stworzy� operatory:
+ dodawanie,
+ odejmowanie,
+ mno�enie przez sta��, 
+ dzielenie przez sta��,
+ pobieranie d�ugo�ci wektora,
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

		//Tu zmieniamy stan obiektu wi�c metoda nie mo�e by� 'const'
		Vector2& operator+=(const Vector2& vector)
		{
			this->x_ += vector.x_;
			this->y_ += vector.y_;

			//Tu zwracamy '*this' poniewa� warto�� zwracana jest referencj�.
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

		//Metoda obliczaj�ca iloczyn skalarny wektor�w (je�eli wynik jest r�wny 0, w�wczas wektory s� prostopad�e)
		float Dot(const Vector2& vector) const
		{
			return this->x_ * vector.x_ + this->y_ * vector.y_;
		}

		//Metoda obliczaj�ca iloczyn wektorowy wektor�w (je�eli wynik jest r�wny 0, w�wczas wektory s� r�wnoleg�e)
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

	//Umieszczamy t� metod� poza klas� poniewa� nie ma potrzeby do odwo�ywania si� do prywatnych zmiennych klasy Vector2
	//oraz operator + mo�e by� wyra�ony przez operator +=, kt�ry znajduje si� wewn�trz klasy.
	//'inline' jest tutaj potrzebny �eby operator nie by� wkompilowany w ka�dy plik, kt�ry za�acza ten plik nag��wkowy.
	inline Vector2 operator+(const Vector2& left, const Vector2& right)
	{
		//U�ywamy konstruktora kopiuj�cego poniewa� nie mo�my modyfikowa� argument�w wej�ciowych.
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
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

		float GetY() const
		{
			return y_;
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

		Vector2 operator+(const Vector2& vector) const
		{
			return Vector2(x_ + vector.GetX(), y_ + vector.GetY());
		}

		Vector2 operator-(const Vector2& vector) const
		{
			return Vector2(x_ - vector.GetX(), y_ - vector.GetY());
		}

		Vector2 operator*(const float scalar) const
		{
			return Vector2(x_ * scalar, y_ * scalar);
		}

		Vector2 operator/(const float scalar) const
		{
			if (scalar == 0)
				throw std::overflow_error("Divide by zero exception");
			return Vector2(x_ / scalar, y_ / scalar);
		}

		float GetLenght() const
		{
			return sqrt((x_ * x_) + (y_ * y_));
		}

	private:
		float x_;
		float y_;
	};
}
#include "gtest/gtest.h"
#include "../BugsCore/Vector2.h"

using namespace Bugs;

TEST(Vector2Tests, defaultConstructorTest)
{
	Vector2 vector = Vector2();
	
	EXPECT_FLOAT_EQ(vector.GetX(), 0.0f);
	EXPECT_FLOAT_EQ(vector.GetY(), 0.0f);
}

TEST(Vector2Tests, constructorWithParamitersTest)
{
	Vector2 vector(1, 2);

	EXPECT_FLOAT_EQ(vector.GetX(), 1.0f);
	EXPECT_FLOAT_EQ(vector.GetY(), 2.0f);
}

TEST(Vector2Tests, addOperatorTest)
{
	Vector2 vector_1(1, 1);
	Vector2 vector_2(2, 2);

	Vector2 vector_3 = vector_1 + vector_2;

	EXPECT_FLOAT_EQ(vector_3.GetX(), 3.0f);
	EXPECT_FLOAT_EQ(vector_3.GetY(), 3.0f);
}

TEST(Vector2Tests, subtractionOperatorTest)
{
	Vector2 vector_1(1, 1);
	Vector2 vector_2(2, 2);

	Vector2 vector_3 = vector_1 - vector_2;

	EXPECT_FLOAT_EQ(vector_3.GetX(), -1.0f);
	EXPECT_FLOAT_EQ(vector_3.GetY(), -1.0f);
}

TEST(Vector2Tests, multiplicationOperatorTest)
{
	Vector2 vector_1(2, 1);
	float scalar = 2;

	Vector2 vector_2 = vector_1 * scalar;

	EXPECT_FLOAT_EQ(vector_2.GetX(), 4.0f);
	EXPECT_FLOAT_EQ(vector_2.GetY(), 2.0f);
}

TEST(Vector2Tests, divisionOperatorTest)
{
	Vector2 vector_1(2, 6);
	float scalar = 2;

	Vector2 vector_2 = vector_1 / scalar;

	EXPECT_FLOAT_EQ(vector_2.GetX(), 1.0f);
	EXPECT_FLOAT_EQ(vector_2.GetY(), 3.0f);
}

TEST(Vector2Tests, divideByZeroTest)
{
	Vector2 vector_1(2, 6);
	float scalar = 0;

	EXPECT_THROW(vector_1 / scalar, std::overflow_error);
}

TEST(Vector2Tests, getVectorLenghtTest)
{
	Vector2 vector(4, 3);

	EXPECT_FLOAT_EQ(vector.GetLenght(), 5);
}
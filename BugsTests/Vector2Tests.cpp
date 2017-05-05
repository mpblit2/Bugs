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

TEST(Vector2Tests, rightMultiplicationByScalarOperatorTest)
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

TEST(Vector2Tests, addEqualOperatorTest)
{
	Vector2 vector_1(2, 1);
	Vector2 vector_2(2, 2);

	vector_1 += vector_2;

	EXPECT_FLOAT_EQ(vector_1.GetX(), 4.0f);
	EXPECT_FLOAT_EQ(vector_1.GetY(), 3.0f);
}

TEST(Vector2Tests, subtractionEqualOperatorTest)
{
	Vector2 vector_1(2, 1);
	Vector2 vector_2(2, 2);

	vector_1 -= vector_2;

	EXPECT_FLOAT_EQ(vector_1.GetX(), 0.0f);
	EXPECT_FLOAT_EQ(vector_1.GetY(), -1.0f);
}

TEST(Vector2Tests, doubleEqualOperatorTest)
{
	Vector2 vector_1(2, 2);
	Vector2 vector_2(2, 2);

	vector_1 == vector_2;

	EXPECT_EQ(vector_1, vector_2);
}

TEST(Vector2Tests, notEqualOperatorTest)
{
	Vector2 vector_1(2, 1);
	Vector2 vector_2(2, 2);

	EXPECT_NE(vector_1, vector_2);
}

TEST(Vector2Tests, multiplicationEqualOperatorTest)
{
	Vector2 vector_1(2, 2);
	float scalar = 2;

	vector_1 *= scalar;

	EXPECT_FLOAT_EQ(vector_1.GetX(), 4.0f);
	EXPECT_FLOAT_EQ(vector_1.GetY(), 4.0f);
}

TEST(Vector2Tests, leftMultiplicationByScalarOperatorTest)
{
	Vector2 vector_1(2, 1);
	float scalar = 2;

	Vector2 vector_2 = scalar * vector_1;

	EXPECT_FLOAT_EQ(vector_2.GetX(), 4.0f);
	EXPECT_FLOAT_EQ(vector_2.GetY(), 2.0f);
}

TEST(Vector2Tests, divisionEqualOperatorTest)
{
	Vector2 vector_1(2, 1);
	float scalar = 2;

	vector_1 /= scalar;

	EXPECT_FLOAT_EQ(vector_1.GetX(), 1.0f);
	EXPECT_FLOAT_EQ(vector_1.GetY(), 0.5f);
}

TEST(Vector2Tests, dotMethodTest)
{
	Vector2 vector_1(0, 2);
	Vector2 vector_2(2, 0);

	EXPECT_FLOAT_EQ(vector_1.Dot(vector_2), 0.0f);
}

TEST(Vector2Tests, crossMethodTest)
{
	Vector2 vector_1(1, 2);
	Vector2 vector_2(2, 4);

	EXPECT_FLOAT_EQ(vector_1.Cross(vector_2), 0.0f);
}

TEST(Vector2Tests, atOperatorTest)
{
	Vector2 vector(1, 2);

	EXPECT_FLOAT_EQ(vector[0], 1.0f);
	EXPECT_FLOAT_EQ(vector[1], 2.0f);
}
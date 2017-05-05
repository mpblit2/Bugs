#include "gtest/gtest.h"
#include "../BugsCore/Matrix2.h"

using namespace Bugs;

TEST(Matrix2Tests, defaultConstructorTest)
{
	Matrix2 matrix = Matrix2();

	EXPECT_EQ(matrix[0], Vector2(0, 0));
	EXPECT_EQ(matrix[1], Vector2(0, 0));
}

TEST(Matrix2Tests, constructorWithParametersTest)
{
	Matrix2 matrix = Matrix2(Vector2(1, 2), Vector2(3, 4));
	
	EXPECT_EQ(matrix[0], Vector2(1, 2));
	EXPECT_EQ(matrix[1], Vector2(3, 4));
}

TEST(Matrix2Tests, addEqualOperatorTest)
{
	Matrix2 matrix(Vector2(1, 2), Vector2(3, 4));
	Matrix2 matrix_2(Vector2(1, 2), Vector2(3, 4));

	matrix += matrix_2;

	EXPECT_EQ(matrix[0], Vector2(2, 4));
	EXPECT_EQ(matrix[1], Vector2(6, 8));
}

TEST(Matrix2Tests, addOperatorTest)
{
	Matrix2 matrix_2(Vector2(1, 2), Vector2(3, 4));
	Matrix2 matrix_3(Vector2(1, 2), Vector2(3, 4));

	Matrix2 matrix = matrix_2 + matrix_3;

	EXPECT_EQ(matrix[0], Vector2(2, 4));
	EXPECT_EQ(matrix[1], Vector2(6, 8));
}

TEST(Matrix2Tests, subtractionEqualOperatorTest)
{
	Matrix2 matrix(Vector2(1, 2), Vector2(3, 4));
	Matrix2 matrix_2(Vector2(1, 2), Vector2(3, 4));

	matrix -= matrix_2;

	EXPECT_EQ(matrix[0], Vector2(0, 0));
	EXPECT_EQ(matrix[1], Vector2(0, 0));
}

TEST(Matrix2Tests, subtractionOperatorTest)
{
	Matrix2 matrix_2(Vector2(1, 2), Vector2(3, 4));
	Matrix2 matrix_3(Vector2(1, 2), Vector2(3, 4));

	Matrix2 matrix = matrix_2 - matrix_3;

	EXPECT_EQ(matrix[0], Vector2(0, 0));
	EXPECT_EQ(matrix[1], Vector2(0, 0));
}

TEST(Matrix2Tests, doubleEqualOperatorTest)
{
	Matrix2 matrix(Vector2(1, 2), Vector2(3, 4));
	Matrix2 matrix_2(Vector2(1, 2), Vector2(3, 4));

	EXPECT_EQ(matrix, matrix_2);
}

TEST(Matrix2Tests, notEqualOperatorTest)
{
	Matrix2 matrix(Vector2(1, 2), Vector2(3, 4));
	Matrix2 matrix_2(Vector2(4, 3), Vector2(2, 1));

	EXPECT_NE(matrix, matrix_2);
}

TEST(Matrix2Tests, atOperatorTest)
{
	Matrix2 matrix(Vector2(1, 2), Vector2(3, 4));

	EXPECT_FLOAT_EQ(matrix[0][0], 1.0f);
	EXPECT_FLOAT_EQ(matrix[0][1], 2.0f);
	EXPECT_FLOAT_EQ(matrix[1][0], 3.0f);
	EXPECT_FLOAT_EQ(matrix[1][1], 4.0f);
}

TEST(Matrix2Tests, changingValuesWithAtOperator)
{
	Matrix2 matrix(Vector2(0, 0), Vector2(0, 0));
	matrix[0][0] = 1.0f;
	matrix[0][1] = 2.0f;
	matrix[1][0] = 3.0f;
	matrix[1][1] = 4.0f;

	EXPECT_FLOAT_EQ(matrix[0][0], 1.0f);
	EXPECT_FLOAT_EQ(matrix[0][1], 2.0f);
	EXPECT_FLOAT_EQ(matrix[1][0], 3.0f);
	EXPECT_FLOAT_EQ(matrix[1][1], 4.0f);
}
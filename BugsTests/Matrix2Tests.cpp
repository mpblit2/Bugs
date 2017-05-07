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

TEST(Matrix2Tests, multiplicationOperatorTest)
{
	Matrix2 matrix_1(Vector2(1, 2), Vector2(3, 4));
	Matrix2 matrix_2(Vector2(4, 3), Vector2(2, 1));
	
	Matrix2 matrix = matrix_1 * matrix_2;

	EXPECT_FLOAT_EQ(matrix[0][0], 8.0f);
	EXPECT_FLOAT_EQ(matrix[0][1], 5.0f);
	EXPECT_FLOAT_EQ(matrix[1][0], 20.0f);
	EXPECT_FLOAT_EQ(matrix[1][1], 16.0f);
}

TEST(Matrix2Tests, detMethodTest)
{
	Matrix2 matrix(Vector2(1, 2), Vector2(3, 4));

	EXPECT_FLOAT_EQ(matrix.Det(), -2);
}

TEST(Matrix2Tests, multiplicationEqualOperatorTest)
{
	Matrix2 matrix(Vector2(1, 2), Vector2(3, 4));

	matrix *= 2;

	EXPECT_FLOAT_EQ(matrix[0][0], 2.0f);
	EXPECT_FLOAT_EQ(matrix[0][1], 4.0f);
	EXPECT_FLOAT_EQ(matrix[1][0], 6.0f);
	EXPECT_FLOAT_EQ(matrix[1][1], 8.0F);
}

TEST(Matrix2Tests, multiplicationByScalarTest)
{
	Matrix2 matrix_1(Vector2(1, 2), Vector2(3, 4));

	Matrix2 matrix = matrix_1 * 2;

	EXPECT_FLOAT_EQ(matrix[0][0], 2.0f);
	EXPECT_FLOAT_EQ(matrix[0][1], 4.0f);
	EXPECT_FLOAT_EQ(matrix[1][0], 6.0f);
	EXPECT_FLOAT_EQ(matrix[1][1], 8.0F);
}

TEST(Matrix2Tests, leftMultiplicationByScalarOperatorTest)
{
	Matrix2 matrix_1(Vector2(1, 2), Vector2(3, 4));

	Matrix2 matrix = 2 * matrix_1;

	EXPECT_FLOAT_EQ(matrix[0][0], 2.0f);
	EXPECT_FLOAT_EQ(matrix[0][1], 4.0f);
	EXPECT_FLOAT_EQ(matrix[1][0], 6.0f);
	EXPECT_FLOAT_EQ(matrix[1][1], 8.0F);
}

TEST(Matrix2Tests, rightMultiplicationByVectorTest)
{
	Matrix2 matrix(Vector2(1, 2), Vector2(3, 4));
	Vector2 vector(1, 2);

	Vector2  result = matrix * vector;

	EXPECT_FLOAT_EQ(result[0], 5.0f);
	EXPECT_FLOAT_EQ(result[1], 11.0f);
}

TEST(Matrix2Tests, leftMultiplicationByVectorTest)
{
	Matrix2 matrix(Vector2(1, 2), Vector2(3, 4));
	Vector2 vector(1, 2);

	Vector2  result = vector * matrix;

	EXPECT_FLOAT_EQ(result[0], 7.0f);
	EXPECT_FLOAT_EQ(result[1], 10.0f);
}
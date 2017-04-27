#include "gtest/gtest.h"
#include "../BugsCore/Application.h"

using namespace Bugs;

TEST(ApplicationTests, getTrueTest)
{
	Application app;
	auto result = app.getTrue();
	
	EXPECT_TRUE(result);
}
#include <gtest/gtest.h>

class ExampleTest: public ::testing::Test {
	public:
	
	virtual void SetUp(){}

	virtual void TearDown(){}
};

TEST_F(ExampleTest, TestOnePlusOne){
	EXPECT_DOUBLE_EQ(1.0+1.0, 2.0);
}


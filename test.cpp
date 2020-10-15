#include "c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld){
	char* test_val[3];
	test_val[0] = "./c-echo";
	test_val[1] = "hello";
	test_val[2] = "world";
	EXPECT_EQ("hello world", echo(3, test_val));
}

TEST(EchoTest, EmptyString){
	char* test_val[1];
	test_val[0] = "./c-echo";
	EXPECT_EQ("", echo(1, test_val));
}


TEST(EchoTest, LongString){
    char* test_val[2];
    test_val[0] = "./c-echo";
	test_val[1] = "abcdefghijklmopqrstuvwxysabcdefghijklmopqrstuvwxys";
    EXPECT_EQ("abcdefghijklmopqrstuvwxysabcdefghijklmopqrstuvwxys", echo(2, test_val));
}

TEST(EchoTest, VariousChars){
    char* test_val[2];
    test_val[0] = "./c-echo";
    test_val[1] = "s,74+8hj/ w.x*s";
    EXPECT_EQ("s,74+8hj/ w.x*s", echo(2, test_val));
}

TEST(EchoTest, MultipleString){
    char* test_val[10];
    test_val[0] = "./c-echo";
    test_val[1] = "'It";
	test_val[2] = "was";
    test_val[3] = "a";
    test_val[4] = "dark";
    test_val[5] = "and";
    test_val[6] = "stormy";
    test_val[7] = "night.'";
    test_val[8] = "How";
    test_val[9] = "boring.";
    EXPECT_EQ("'It was a dark and stormy night.' How boring.", echo(10, test_val));
}


int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>
#include "../word_counter.h"

class Count_test : public ::testing::Test
{
protected:
    void SetUp() override
    {

        str = new std::istringstream("aaa\n");

        counter = new WordCounter(*str);

    }
    void TearDown() override
    {
        delete counter;
        delete str;
    }
    WordCounter *counter;
    std::istringstream* str ;

};

TEST_F(Count_test,ALLCount){
    //arrange
    WordCounter::Data value;
    value.lines = 1;
    value.words = 1;
    value.chars = 4;
    //act

    //assert

   ASSERT_EQ(counter->AllCount(),value);

}


TEST_F(Count_test, LinesCount){
    //arrange
const int value = 1;

    //act
    //assert

    ASSERT_EQ(counter->LineCount(),value);

}

TEST_F(Count_test, WordCount){
    //arrange
   const int value = 1;
    //act
    //assert

    ASSERT_EQ(counter->LineCount(),value);

}


TEST_F(Count_test, CharsCount){
    //arrange
   const int value = 4;
    //act
    //assert

    ASSERT_EQ(counter->CharsCount(),value);

}

int main(int argc, char* *argv)
{

    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

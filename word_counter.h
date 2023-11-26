#pragma once

#include <iostream>
#include <tuple>


class WordCounter {
private:
    std::istream& in_;
    using WCount  = std::size_t;
    using LCount  = std::size_t;
    using CCount  = std::size_t;
public:
    struct Data{
        std::size_t lines{0};
        std::size_t words{0};
        std::size_t chars{0};
    };

    WordCounter(std::istream& in);

    Data AllCount ();
    LCount LineCount();
    WCount WordCount();
    CCount CharsCount();
};


bool operator==(const WordCounter::Data& lhs, const WordCounter::Data& rhs);

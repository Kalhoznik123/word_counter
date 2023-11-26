#include "word_counter.h"


WordCounter::Data WordCounter::AllCount(){

    std::size_t lines{0};
    std::size_t words{0};
    std::size_t chars{0};

    char prev_char = ' ';

    char ch  = in_.get();

    while(!in_.eof()) {


        if(ch == '\n'){
            ++lines;
        }

        if(std::isalnum(prev_char)&&(ch == '\n' || ch == ' '))
            ++words;

        ++chars;
        prev_char = ch;
        ch  = in_.get();
    }

    if(std::isalnum(prev_char))
        ++words;

    return {lines,words,chars};
}

WordCounter::WordCounter(std::istream &in):in_(in) {}

WordCounter::CCount WordCounter::CharsCount(){
    const auto data = AllCount();
    return data.chars;
}

WordCounter::WCount WordCounter::WordCount(){
    const auto data = AllCount();
    return data.words;
}

WordCounter::LCount WordCounter::LineCount(){
    const auto data = AllCount();
    return data.lines;
}

bool operator==(const WordCounter::Data &lhs, const WordCounter::Data &rhs){
    return std::tie(lhs.lines,lhs.words,lhs.chars) == std::tie(rhs.lines,rhs.words,rhs.chars);
}

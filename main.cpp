#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iterator>
#include <cctype>

class WordCounter
{
private:
    std::istream& in_;


public:
    struct Data{
        std::size_t chars{0};
        std::size_t words{0};
        std::size_t lines{0};
    };

    WordCounter(std::istream& in):in_(in) {}

    Data count (){

        std::size_t chars{0};
        std::size_t words{0};
        std::size_t lines{0};

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

        return {chars,words,lines};

    }

};



int main()
{
    std::istringstream str("aa aa\na a\n");

    WordCounter wc(str);

    auto data = wc.count();

    std::cout << data.lines <<' '<< data.words <<' '<< data.chars << '\n';

    return 0;
}

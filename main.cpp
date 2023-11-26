#include <iostream>
#include <sstream>
#include <cctype>
//#include <boost/program_options.hpp>
#include "word_counter.h"



///todo

/// прикрутить выбор ключей
/// добаить проверку на наличие пакета programm option



int main()
{

    std::istringstream str("aaa\n");

    WordCounter wc(str);

    auto data = wc.AllCount();

    std::cout << data.lines <<' '<< data.words <<' '<< data.chars << '\n';

    return 0;
}

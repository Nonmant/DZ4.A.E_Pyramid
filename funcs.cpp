//https://contest.yandex.ru/contest/27665/problems/E/

#include "funcs.h"
#include <bits/stdc++.h>

void parseFile(std::istream & input, std::ostream & output){

    std::map<unsigned int, unsigned int> blocks;
    int n;
    input >> n;
    unsigned int width, height;
    for(int i = 0; i < n; ++i){
        input >> width >> height;
        blocks[width] = std::max(blocks[width], height);
    }
    unsigned int sum = std::accumulate(std::begin(blocks), std::end(blocks), 0,
                                       [](const std::size_t previous, const auto & p)
                                       { return previous + p.second; });
    output << sum;
}

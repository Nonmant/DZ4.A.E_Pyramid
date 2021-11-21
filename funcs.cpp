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
    unsigned long long sum = 0;
    for(auto & block: blocks){
        sum += block.second;
    }
    output << sum;
}

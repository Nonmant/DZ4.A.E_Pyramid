#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
                "3\n"
                "3 1\n"
                "2 2\n"
                "3 3"
            ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();

    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    REQUIRE(buffer.str() ==
            "5"
    );
}

TEST_CASE("one block", ""){
    std::stringstream input(
            "5\n"
            "4 1\n"
            "4 2\n"
            "4 3\n"
            "4 5\n"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
    "5"
    );
}

TEST_CASE("longer test", ""){
    std::stringstream input(
            "5\n"
            "4 1\n"
            "3 1\n"
            "2 1\n"
            "1 1\n"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
    "4"
    );
}

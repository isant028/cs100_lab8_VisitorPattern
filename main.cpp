#ifndef MAIN_CPP
#define MAIN_CPP
#include "gtest/gtest.h"

#include "add_tests.hpp"
int main(int argc, char**argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

#endif
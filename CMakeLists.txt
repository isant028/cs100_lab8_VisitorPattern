CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    main.cpp
    binary_iterator.cpp
    CountVisitor.cpp
    preorder_iterator.cpp

)

ADD_EXECUTABLE(labtest
    labMain.cpp
    binary_iterator.cpp
    CountVisitor.cpp
    preorder_iterator.cpp

)


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
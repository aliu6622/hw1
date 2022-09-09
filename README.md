Angela Liu
aliu6622@usc.edu

Header files for part 1:
1) split.cpp
#include "split.h"
#include <iostream>
using namespace std;
2) split.h
#ifndef SPLIT_H
#define SPLIT_H
3) split_test.cpp
#include "split.h"
#include <iostream>
using namespace std;

Passes valgrind test: valgrind --tool=memcheck --leak-check=yes ./split
Compliation command: g++ -g -Wall -std=c++11 -c split.cpp

g++ -g -Wall -std=c++11 split_test.cpp split.cpp -o split

Header files for part 2:
1) ulliststr.cpp
#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
2) ulliststr.h
#ifndef ULLISTSTR_H
#define ULLISTSTR_H
#include <string>
3) ulliststr_test.cpp
#include <iostream>
#include "ulliststr.h"
#include "ulliststr.cpp"
using namespace std;

Passes valgrind test: valgrind --tool=memcheck --leak-check=yes ./ulliststr_test
Compliation command: g++ -g -Wall ulliststr.cpp ulliststr_test.cpp -o ulliststr_test
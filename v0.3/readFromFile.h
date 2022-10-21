#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include "duomenys.h"
#include "countWordsInString.h"
#include "printStudent.h"
#include "count_median.h"

using std::vector;
using std::ifstream;
using std::string;
using std::ws;
using std::cout;
using std::endl;

    void readFromFile(std::vector<duomenys>& Eil, int* pazymiu_sk);

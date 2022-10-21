#include "countWordsInString.h"

#include "duomenys.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include "countWordsInString.h"

int countWordsInString(string const& str)
{
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}

#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED
#include "library.h"

struct info {
    std::string Vardas, Pavarde;
    std::vector<int> paz = { 0 };
    int egzas;
    float GP = 0;
};
float count_median(vector<int> pazymiai);
void print_student(vector<info> Eil, int pazymiu_sk) ;
unsigned int countWordsInString(string const& str);
void read_from_file(vector<info>& Eil, int* pazymiu_sk);

#endif // STRUKTURA_H_INCLUDED


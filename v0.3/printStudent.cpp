#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include "printStudent.h"
#include "count_median.h"

void print_student(vector<duomenys> Eil, int pazymiu_sk) //atspausdina rezultatus
{
    ofstream output;
    output.open("rezultatai.txt");
    output << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < Eil.size(); i++)
    {
        output << setw(20) << left << Eil[i].Vardas
            << setw(20) << left << Eil[i].Pavarde
            << setw(18) << left << Eil[i].GP
            << count_median(Eil[i].paz) << endl;
    }
    output << "\n\n";
}

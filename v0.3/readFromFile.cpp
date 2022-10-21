
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <iterator>
#include "readFromFile.h"
#include "countWordsInString.h"



void readFromFile(vector<duomenys>& Eil, int* pazymiu_sk)
{
    int student_counter = 0;
    int temp;
    ifstream fileRead;
    string buff;
    try {
        fileRead.open("studentai100000.txt.txt");

        if (!fileRead.is_open())
            throw 0;

            getline(fileRead >> ws, buff);
            *pazymiu_sk = countWordsInString(buff) - 3;
            while (true)
            {

                Eil.resize(Eil.size() + 1);
                fileRead >> Eil.at(student_counter).Vardas;
                if (fileRead.eof()) { Eil.pop_back(); break; }
                fileRead >> Eil.at(student_counter).Pavarde;
                for (int i = 0; i < *pazymiu_sk; i++)
                {
                fileRead >> temp;
                Eil.at(student_counter).paz.push_back(temp);
                }
                fileRead >> Eil.at(student_counter).egz;

                //std::cout << Eil.at(student_counter).Vard;
                Eil.at(student_counter).GP = Eil.at(student_counter).GP / *pazymiu_sk;
                Eil.at(student_counter).GP = Eil.at(student_counter).GP * 0.4 + 0.6 * Eil.at(student_counter).egz;
                student_counter++;
            }

    }
    catch (int e)
    {
        cout << "Neteisingai ivestas failo pavadinimas " << e << endl;

    }
}



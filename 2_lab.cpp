#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>

struct info {
    std::string Vardas, Pavarde;
    std::vector<int> paz = { 0 };
    int egzas;
    float GP = 0;
};

//si funkcija skaiciuoja mediana
float count_median(std::vector<int> pazymiai) 
{
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        if (pazymiai[i] != 0)
        {
            counter++;
        }
        if (pazymiai[i] == -1)
        {
            pazymiai[i] = 0;
            counter--;
            break;
        }
    }
    if (counter % 2 == 0)
    {
        return float(((pazymiai[counter / 2 - 1]) + (pazymiai[(counter / 2)])) / 2.0);
    }
    else
    {
        return float(pazymiai[(counter / 2)]);
    }
}
//sis voidas spausdina rezultatus
void print_student(std::vector<info> Eil, int pazymiu_sk) 
{
    std::ofstream output;
    output.open("rezultatai.txt");
    output << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavarde"
        << std::setw(18) << std::left << "Galutinis(vid.)/"
        << std::left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < Eil.size(); i++)
    {
        output << std::setw(20) << std::left << Eil[i].Vardas
            << std::setw(20) << std::left << Eil[i].Pavarde
            << std::setw(18) << std::left << Eil[i].GP
            << count_median(Eil[i].paz) << std::endl;
    }
    output << "\n\n";
}

unsigned int countWordsInString(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

void read_from_file(std::vector<info>& Eil, int* pazymiu_sk)
{
    int student_counter = 0;
    int temp;
    std::ifstream fileRead;
    std::string buff;
    fileRead.open("studentai100000.txt.txt");
    if (fileRead.is_open())
    {
        getline(fileRead >> std::ws, buff);
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
            fileRead >> Eil.at(student_counter).egzas;
            //std::cout << Eil.at(student_counter).Vardas;
            Eil.at(student_counter).GP = Eil.at(student_counter).GP / *pazymiu_sk;
            Eil.at(student_counter).GP = Eil.at(student_counter).GP * 0.4 + 0.6 * Eil.at(student_counter).egzas;
            student_counter++;
        }
    }
    else { std::cout << "-\n"; }
}

int main()
{
    int pazymiu_sk;
    char temp;
    std::vector<info> Eil;
    read_from_file(Eil, &pazymiu_sk);
    print_student(Eil, pazymiu_sk);
    //system("pause");
    return 0;
}
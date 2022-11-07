#include "library.h"
#include "struktura.h"
//si funkcija skaiciuoja mediana
float count_median(vector<int> pazymiai)
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
void print_student(vector<info> Eil, int pazymiu_sk)
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

unsigned int countWordsInString(string const& str)
{
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}

void read_from_file(vector<info>& Eil, int* pazymiu_sk)
{
    int student_counter = 0;
    int temp;
    ifstream fileRead;
    string buff;
    fileRead.open("studentai100000.txt.txt");
    if (fileRead.is_open())
    {
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
            fileRead >> Eil.at(student_counter).egzas;
            //cout << Eil.at(student_counter).Vardas;
            Eil.at(student_counter).GP = Eil.at(student_counter).GP / *pazymiu_sk;
            Eil.at(student_counter).GP = Eil.at(student_counter).GP * 0.4 + 0.6 * Eil.at(student_counter).egzas;
            student_counter++;
        }
    }
    else { cout << "-\n"; }
}

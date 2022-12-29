#ifndef STRUC_H_INCLUDED
#define STRUC_H_INCLUDED
#include "mylib.h"

struct duom {
  string vardas;
  string pavarde;
  int paz_sk;
  vector <int> pazymiai;
  int egzaminas;
  double galutinis;
};

double vid_med (char tikrinimas, vector <duom> stud, int laikinas, int kiek);
void Nuskaitymas(vector <duom> &stud, int &kiek, string pavadinimas, char tikrinimas);
void Isvedimas(vector <duom> stud, int kiek, string pavadinimas_isv ,char tikrinimas);
void Generavimas(int dydis, string pavadinimas);
bool Palyginimas(duom pirmas, duom antras);
#endif // STRUC_H_INCLUDED

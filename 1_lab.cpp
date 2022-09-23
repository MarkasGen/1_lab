#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::sort;
using std::vector;

struct studentas {
  string s_vardas;
  string s_pavarde;
  int nd = 0;
  vector <int> nd_ivertis;
  int egzaminas_rez;
  double rez;
};
//Egzamino rezultatas
void getDataTerminal(studentas &first_st, int &temp) {

  cout << "Studento egzamino rezultatas (nuo 1 iki 10): ";
  cin >> first_st.egzaminas_rez;
  while (cin.fail() || first_st.egzaminas_rez > 10 || first_st.egzaminas_rez < 1) {
    cout << "Egzamino rezultatas turi buti intervale nuo 1 iki 10"<< endl;
    cout << "Bandykite is naujo: " << endl;
    cin.clear();
    cin.ignore(256, '\n');
    cin >> first_st.egzaminas_rez;
  }

  // Namu darbu ivertinimai
  int tempN;
  cout << "Paeiliui iveskite namu darbu rezultatus" << endl;
  bool endLoop = false;
  while (!endLoop) {
    first_st.nd++;
    cout << "Iveskite " << first_st.nd << " namu darbu rezultata, jei daugiau ju nera, iveskite 13: "; cin >> tempN;
    while (cin.fail() || tempN > 10 ||
        tempN < 1) {
      if (tempN == 13) {
        endLoop = true;
        break;
      } else {
        cout << "Namu darbu rezultatas turi buti intervale nuo 1 iki 10."<< endl;
        cout << "Bandykite is naujo: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> tempN;
      }
    }
    if (endLoop) break;
    first_st.nd_ivertis.push_back(tempN);
    temp += tempN;
  }
}

void getDataRandom(studentas &first_st, int &temp) {
  int tempN;
  first_st.egzaminas_rez = rand() % 10 + 1;
  cout << "Sugeneruotas egzamino rezultatas (nuo 1 iki 10): " << first_st.egzaminas_rez << endl;
  first_st.nd = rand() % 8 + 1;
  cout << "Namu darbu kiekis : " << first_st.nd << endl;
  for (int i = 0; i < first_st.nd; i++) {
    tempN = rand() % 10 + 1;
    first_st.nd_ivertis.push_back(tempN);
    cout << "Sugeneruotas " << i + 1 << " namu darbu rezultatas (nuo 1 iki 10): "<< tempN << endl;
    temp += tempN;
  }
}

void getDataMain(studentas &first_st, string vid_or_med) {
  int temp = 0;
  char yesOrNo;
  cout << "Studento vardas: ";
  cin >> first_st.s_vardas;
  cout << "Studento pavarde: ";
  cin >> first_st.s_pavarde;
  cout << "Ar norite, kad rezultatai butu sugeneruoti? (Y / N)";
  cin >> yesOrNo;
  while (yesOrNo != 'Y' && yesOrNo != 'N' && yesOrNo !=  'y' && yesOrNo != 'n') {
    cout << "Ivedama reiksme turi buti arba Y arba N" << endl;
    cout << "Bandykite is naujo: " << endl;
    cin.clear();
    cin.ignore(256, '\n');
    cin >> yesOrNo;
  }
  if (yesOrNo == 'N')
    getDataTerminal(first_st, temp);
  else
    getDataRandom(first_st, temp);

  // Mediana, vidurkis

  double mediOrAvg;
  if (vid_or_med == "vid") {
    if (first_st.nd_ivertis.size() == 0) mediOrAvg = 0;
    else mediOrAvg = double(temp) / double(first_st.nd);
  } else {
    // Mediana;
        if (first_st.nd_ivertis.size() == 0) 
        {
            mediOrAvg = 0;
        }
        else{
            sort(first_st.nd_ivertis.begin(), first_st.nd_ivertis.end());
            if (first_st.nd % 2 == 0)
            {
                mediOrAvg = (first_st.nd_ivertis[first_st.nd / 2 - 1] + first_st.nd_ivertis[first_st.nd / 2]) / 2;
            }
            else 
            {
                mediOrAvg = first_st.nd_ivertis[first_st.nd / 2];
            }
        }
  }
  first_st.rez = mediOrAvg * 0.4 + (double)first_st.egzaminas_rez * 0.6;
}

void printF(studentas *first_st, int student_kiekis, string vid_or_med) {
  printf("| %-10s %-10s Galutinis (%s.) |\n", "Vardas", "Pavarde",vid_or_med.c_str());
  cout << "|" << string(40, '-') << "|" << endl;
  for (int i=0; i<student_kiekis; i++)
  {
  printf("| %-10s %-10s %-16.2lf |\n", first_st[i].s_vardas.c_str(),first_st[i].s_pavarde.c_str(), first_st[i].rez);
  }
}

int main() {
  srand(time(NULL));
  int student_kiekis;
  cout << "Studentu kiekis";cin >> student_kiekis;
  while (cin.fail() || student_kiekis < 1) {
    cout << "Studentu skaicius turi buti NENEIGIAMAS SKAICIUS"<< endl;
    cout << "Bandykite is naujo: " << endl;
    cin.clear();
    cin.ignore(256, '\n');
    cin >> student_kiekis;
  }
  studentas first_st[student_kiekis];
  string vid_or_med;
  cout << "Pasirinkite, kaip bus atvaizduojami studentu rezultatai. (med / vid)";cin >> vid_or_med;
  while (vid_or_med != "vid" && vid_or_med != "med") {
    cout << "Ivedama reiksme turi buti arba vid arba med." << endl;
    cout << "Bandykite is naujo: " << endl;
    cin.clear();
    cin.ignore(256, '\n');
    cin >> vid_or_med;
  }
  for (int i=0; i<student_kiekis; i++)
  {
    getDataMain(first_st[i], vid_or_med);
  }
  printF(first_st, student_kiekis, vid_or_med);
  return 0;
}

#include "mylib.h"
#include "struc.h"

double vid_med (char tikrinimas, vector <duom> stud, int laikinas, int kiek)
{
  double vid;
  if (tolower(tikrinimas) == 'v') {
    if (stud[kiek].pazymiai.size() == 0) vid = 0;
    else vid = double(laikinas) / double(stud[kiek].paz_sk);
  }
  else
  {
    if (stud[kiek].pazymiai.size() == 0)
    {
      vid = 0;
    }
    else{
      sort(stud[kiek].pazymiai.begin(), stud[kiek].pazymiai.end());
      if (stud[kiek].paz_sk % 2 == 0)
      {
          vid = (stud[kiek].pazymiai[stud[kiek].paz_sk / 2 - 1] + stud[kiek].pazymiai[stud[kiek].paz_sk / 2]) / 2;
      }
      else
      {
          vid = stud[kiek].pazymiai[stud[kiek].paz_sk / 2];
      }
    }

  }
  stud[kiek].galutinis = vid * 0.4 + (double)stud[kiek].egzaminas * 0.6;
  return stud[kiek].galutinis;
}

void Nuskaitymas(vector <duom> &stud, int &kiek, string pavadinimas, char tikrinimas)
{
    try
    {
      float paz, s;
      ifstream df;
      df.open(pavadinimas);
      if(!df) throw std::invalid_argument("Failo nuskaityti nepavyko");
      string eil;
      if (df.is_open())
      {
        int sk;
        getline(df >> ws, eil);
        stringstream stream(eil);
        sk = (distance(istream_iterator<string>(stream), istream_iterator<string>())) - 3;
        while (true)
        {
          stud.resize(stud.size() + 1);
          df >> stud.at(kiek).vardas;
          if (df.eof()) { stud.pop_back(); break;}
          df >> stud.at(kiek).pavarde;
          stud.at(kiek).paz_sk=sk;
          s=0;
          for (int i = 0; i < stud.at(kiek).paz_sk; i++)
          {
            df >> paz;
            s+=paz;
            stud.at(kiek).pazymiai.push_back(paz);
          }
          df >> stud.at(kiek).egzaminas;
          stud[kiek].galutinis = vid_med(tikrinimas, stud, s, kiek);
          kiek++;
        }
      }
      df.close();
    }
    catch(const exception& e){
     cout << "Failo nuskaityti nepavyko" << endl;
  }
}

void Isvedimas(vector <duom> stud, int kiek, string pavadinimas_isv ,char tikrinimas) {
  ofstream rf;
  rf.open(pavadinimas_isv);
  for (int i=0; i<kiek;i++)
  {
      rf<<setw(20)<<left<<stud.at(i).vardas<<setw(20)<<left<<stud.at(i).pavarde<<fixed<<setprecision(2)<<setw(18)<<left<<stud.at(i).galutinis<<endl;
  }
  rf.close();
}

void Generavimas(int dydis, string pavadinimas){
    ofstream gf;
    gf.open(pavadinimas);
    int ndsk = rand() % 5 + 1;
    gf<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde";
    for(int i=0;i<ndsk;i++)gf<<setw(20)<<left<<"ND" + to_string(i+1);
    gf<<setw(20)<<left<<"Egz."<<endl;
    for(int i=0;i<dydis;i++){
        gf<<setw(20)<<left<<"Vardas" + to_string(i+1)<<setw(20)<<left<<"Pavarde" + to_string(i+1);
        for(int j=0;j<ndsk;j++){
            int paz = rand() % 10 + 1;
            gf<<setw(20)<<left<<paz;
        }
        int egz = rand() % 10 + 1;
        gf<<setw(20)<<left<<egz<<endl;
    }
    gf.close();
}

bool Palyginimas(duom pirmas, duom antras)
{
    if (pirmas.galutinis != antras.galutinis)
        return pirmas.galutinis > antras.galutinis;
    return pirmas.vardas > antras.vardas;
}

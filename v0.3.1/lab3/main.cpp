#include "library.h"
#include "struktura.h"

int main()
{
    srand(time(NULL));
    int kiek=0;
    vector <duom> stud;
    char tikrinimas;
    cout<<"Norint studento galutini bala skaiciuoti pagal mediana iveskite \"m\", o jei pagal vidurki - iveskite \"v\"\n";cin>>tikrinimas;
    while (tolower(tikrinimas) != 'v' && tolower(tikrinimas) != 'm') {
    cout<<"Turite ivesti \"v\" arba \"m\"!"<<endl;
    cin>>tikrinimas;
  }
    int dydis = 1000;
    while(dydis <= 10000000){
        string pavadinimas = "studentai" + to_string(dydis) + ".txt";
        string varg_isv = "vargsiukai" + to_string(dydis) + ".txt";
        string galv_isv = "galvociai" + to_string(dydis) + ".txt";
        vector <duom> vargsiukai;
        vector <duom> galvociai;
        auto start1 = std::chrono::high_resolution_clock::now();
        Generavimas(dydis,pavadinimas);
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;
        cout<<dydis<<" studentu failo generavimas uztruko: "<<diff1.count()<<endl;
        auto start2 = std::chrono::high_resolution_clock::now();
        Nuskaitymas(stud,kiek,pavadinimas,tikrinimas);
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff2 = end2 - start2;
        cout<<dydis<<" studentu failo nuskaitymas uztruko: "<<diff2.count()<<endl;
        auto start3 = std::chrono::high_resolution_clock::now();
        sort(stud.begin(), stud.end(),Palyginimas);
        auto end3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff3 = end3 - start3;
        cout<<dydis<<" studentu failo surusiavimas naudojant sort uztruko: "<<diff3.count()<<endl;
        auto start4 = std::chrono::high_resolution_clock::now();
        for(int i=0;i<dydis;i++){
            if(stud.at(i).galutinis < 5.00)vargsiukai.push_back(stud.at(i));
            else galvociai.push_back(stud.at(i));
        }
        auto end4 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff4 = end4 - start4;
        cout<<dydis<<" studentu failo surusiavimas skirstant i vargsiukus ir galvocius uztruko: "<<diff4.count()<<endl;
        int varg_dyd = vargsiukai.size();
        int galv_dyd = galvociai.size();
        auto start5 = std::chrono::high_resolution_clock::now();
        Isvedimas(vargsiukai, varg_dyd, varg_isv ,tikrinimas);
        auto end5 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff5 = end5 - start5;
        cout<<dydis<<" vargsiuku isvedimas uztruko: "<<diff5.count()<<endl;
        auto start6 = std::chrono::high_resolution_clock::now();
        Isvedimas(galvociai, galv_dyd, galv_isv, tikrinimas);
        auto end6 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff6 = end6 - start6;
        cout<<dydis<<" galvociu isvedimas uztruko: "<<diff6.count()<<endl;
        dydis = dydis*10;
    }
    return 0;
}

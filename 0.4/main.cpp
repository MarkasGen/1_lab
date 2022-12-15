#include "mylib.h"
#include "Funkcijos.h"

int main()
{
    srand(time(NULL));
    int kiek=0;
    vector <duom> stud;
    list <duom> stud_list;
    char tikrinimas;
    cout<<"Jei norite studento galutini bala skaiciuoti naudojant mediana iveskite \"m\", o jei norite galutini bala skaiciuoti naudojant vidurki iveskite \"v\"\n";cin>>tikrinimas;
    while (tolower(tikrinimas) != 'v' && tolower(tikrinimas) != 'm') {
    cout<<"Turite ivesti \"v\" arba \"m\"!"<<endl;
    cin>>tikrinimas;
  }
    int dydis = 1000;
    /*while(dydis <= 10000000){
        string pavadinimas = "studentai" + to_string(dydis) + ".txt";
        auto start1 = std::chrono::high_resolution_clock::now();
        Generavimas(dydis,pavadinimas);
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;
        cout<<dydis<<" studentu failo generavimui prireike: "<<diff1.count()<<endl;
        dydis=dydis*10;
    }
    dydis = 1000;*/
    while(dydis <= 10000000){
        string pavadinimas = "studentai" + to_string(dydis) + ".txt";
        string varg_isv = "vargsiukai" + to_string(dydis) + ".txt";
        string galv_isv = "galvociai" + to_string(dydis) + ".txt";
        string varg_isv_list = "vargsiukai_list" + to_string(dydis) + ".txt";
        string galv_isv_list = "galvociai_list" + to_string(dydis) + ".txt";
        vector <duom> vargsiukai;
        vector <duom> galvociai;
        list <duom> vargsiukai_list;
        list <duom> galvociai_list;
        auto start11 = std::chrono::high_resolution_clock::now();
        Nuskaitymas(stud,kiek,pavadinimas,tikrinimas);
        auto end11 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff11 = end11 - start11;
        auto start12 = std::chrono::high_resolution_clock::now();
        sort(stud.begin(), stud.end(),Palyginimas);
        //auto end3 = std::chrono::high_resolution_clock::now();
        //std::chrono::duration<double> diff3 = end3 - start3;
        //cout<<dydis<<" studentu failo surusiavimui naudojant sort prireike: "<<diff3.count()<<endl;
        //auto start4 = std::chrono::high_resolution_clock::now();
        Skirstymas(stud, vargsiukai, galvociai);
        auto end12 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff12 = end12 - start12;
        int varg_dyd = vargsiukai.size();
        int galv_dyd = galvociai.size();
        //auto start5 = std::chrono::high_resolution_clock::now();
        Isvedimas(vargsiukai, varg_dyd, varg_isv ,tikrinimas);
        //auto end5 = std::chrono::high_resolution_clock::now();
        //std::chrono::duration<double> diff5 = end5 - start5;
        //cout<<dydis<<" vargsiuku isvedimui prireike: "<<diff5.count()<<endl;
        //auto start6 = std::chrono::high_resolution_clock::now();
        Isvedimas(galvociai, galv_dyd, galv_isv, tikrinimas);
        //auto end6 = std::chrono::high_resolution_clock::now();
        //std::chrono::duration<double> diff6 = end6 - start6;
        //cout<<dydis<<" galvociu isvedimui prireike: "<<diff6.count()<<endl;
        auto start21 = std::chrono::high_resolution_clock::now();
        Nuskaitymas_list(stud_list,kiek,pavadinimas,tikrinimas);
        auto end21 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff21 = end21 - start21;
        auto start22 = std::chrono::high_resolution_clock::now();
        stud_list.sort(Palyginimas);
        Skirstymas_list(stud_list,vargsiukai_list,galvociai_list);
        auto end22 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff22 = end22 - start22;

        cout<<"\n"<<"Veiksmai su "<<dydis<<" failu: "<<endl;
        cout<<"\n"<<dydis<<" studentu failo nuskaitymui naudojant vector prireike: "<<diff11.count()<<endl;
        cout<<dydis<<" studentu failo surusiavimui skirstant i vargsiukus ir galvocius naudojant vector prireike: "<<diff12.count()<<endl;
        cout<<"Bendras sugaistas laikas: "<<diff11.count()+diff12.count()<<endl;
        cout<<"\n"<<dydis<<" studentu failo nuskaitymui naudojant list prireike: "<<diff21.count()<<endl;
        cout<<dydis<<" studentu failo surusiavimui skirstant i vargsiukus ir galvocius naudojant list prireike: "<<diff22.count()<<endl;
        cout<<"Bendras sugaistas laikas: "<<diff21.count()+diff22.count()<<endl;

        dydis = dydis*10;
        stud.clear();
        vargsiukai.clear();
        galvociai.clear();
        stud_list.clear();
        vargsiukai_list.clear();
        galvociai_list.clear();
    }
    return 0;
}

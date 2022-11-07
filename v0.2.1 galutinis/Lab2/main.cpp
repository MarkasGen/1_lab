#include "library.h"
#include "struktura.h"
int main()
{
    int pazymiu_sk;
    char temp;
    vector<info> Eil;
    read_from_file(Eil, &pazymiu_sk);
    print_student(Eil, pazymiu_sk);
    return 0;
}

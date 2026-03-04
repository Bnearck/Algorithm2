#include <iostream>
using namespace std;

// Tip bağımsız veri kabul eden increase fonksiyonu
void increase(void* data, int psize)
{
    if (psize == sizeof(char))
    {
        char* pchar = (char*)data;
        ++(*pchar);
    }
    else if (psize == sizeof(int))
    {
        int* pint = (int*)data;
        ++(*pint);
    }
}

int main()
{
    char a = 'x';
    int b = 1602;

    increase(&a, sizeof(a));
    increase(&b, sizeof(b));

    cout << a << ", " << b << '\n'; // Çıktı: y, 1603
    return 0;
}
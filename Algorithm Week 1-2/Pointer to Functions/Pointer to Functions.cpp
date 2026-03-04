#include <iostream>
using namespace std;

// --- GORSEL 3: FONKSIYON GOSTERICILERI (Pointers to Functions) ---
int addition(int a, int b) { return (a + b); }
int subtraction(int a, int b) { return (a - b); }

// Bu fonksiyon, parametre olarak baska bir fonksiyonun adresini alir
int operation(int x, int y, int (*functocall)(int, int)) {
    int g;
    g = (*functocall)(x, y); // Adresi verilen fonksiyonu cagirir
    return (g);
}

// --- GORSEL 2: VOID POINTER VE ARTIM (Increaser) ---
void increase(void* data, int psize) {
    if (psize == sizeof(char)) {
        char* pchar = (char*)data;
        ++(*pchar);
    }
    else if (psize == sizeof(int)) {
        int* pint = (int*)data;
        ++(*pint);
    }
}

int main() {
    // --- 1. FONKSIYON GOSTERICISI UYGULAMASI ---
    {
        cout << "--- Fonksiyon Gostericileri ---" << endl;
        int m, n;
        // minus adinda bir fonksiyon gostericisi tanimlayip subtraction'a esitliyoruz
        int (*minus)(int, int) = subtraction;

        m = operation(7, 5, addition);    // addition fonksiyonunu gonderdik
        n = operation(20, m, minus);      // minus (subtraction) gostericisini gonderdik
        cout << "Sonuc (n): " << n << "\n\n"; // Cikti: 8
    }

    // --- 2. VOID POINTER UYGULAMASI ---
    {
        cout << "--- Void Pointer (Increaser) ---" << endl;
        char a = 'x';
        int b = 1602;

        increase(&a, sizeof(a));
        increase(&b, sizeof(b));

        cout << a << ", " << b << "\n\n"; // Cikti: y, 1603
    }

    // --- 3. SABITLER (Gorsel 1: Const Pointers) ---
    {
        cout << "--- Const Pointers Tanımlamaları ---" << endl;
        int x = 10;
        int* p1 = &x;                   // non-const pointer to non-const int [cite: 393]
        const int* p2 = &x;             // non-const pointer to const int [cite: 393]
        int* const p3 = &x;             // const pointer to non-const int [cite: 393]
        const int* const p4 = &x;       // const pointer to const int [cite: 393]

        cout << "Pointers tanimlandi, hata yok." << endl;
    }

    return 0;
}
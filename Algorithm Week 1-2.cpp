#include <iostream>

using namespace std;

int main() {
    // --- 1. Temel Pointer Kullanımı ---
    {
        cout << "--- 1. BOLUM ---" << endl;
        int x = 100;
        cout << "x'in degeri: " << x << endl;

        int* pointer = &x;
        cout << "x'in adresi: " << pointer << "\n\n";
    }

    // --- 2. Tek Pointer ile Farklı Değişkenleri Değiştirme ---
    {
        cout << "--- 2. BOLUM ---" << endl;
        int firstvalue, secondvalue;
        int* mypointer;

        mypointer = &firstvalue;
        *mypointer = 10;

        mypointer = &secondvalue;
        *mypointer = 20;

        cout << "first value is: " << firstvalue << '\n';
        cout << "second value is: " << secondvalue << "\n\n";
    }

    // --- 3. İki Pointer Arası Etkileşimler ---
    {
        cout << "--- 3. BOLUM ---" << endl;
        int firstvalue = 5, secondvalue = 15;
        int* p1, * p2;

        p1 = &firstvalue;
        p2 = &secondvalue;

        *p1 = 10;
        *p2 = *p1;
        p1 = p2;
        *p1 = 20;

        // Ekstra bilgi: Son durumda firstvalue 10, secondvalue ise 20 oldu.
        cout << "first value is: " << firstvalue << '\n';
        cout << "second value is: " << secondvalue << "\n\n";
    }

    // --- 4. Pointer ve Diziler (Arrays) Arasındaki İlişki ---
    {
        cout << "--- 4. BOLUM ---" << endl;
        int numbers[5];
        int* p;

        p = numbers;
        *p = 10;
        p++;
        *p = 20;
        p = &numbers[2];
        *p = 30;
        p = numbers + 3;
        *p = 40;
        p = numbers;
        *(p + 4) = 50; //pointed to by (a+5)

        // a[5] = 0; (offset)
        cout << "Dizi elemanlari: ";
        for (int n = 0; n < 5; n++) {
            cout << numbers[n] << ", ";
        }
        cout << endl;

        int a;
        int y = 10;
        const int* k = &y;
        a = *k;
        // *p = x; ERROR Because we can only read the value ca not modify
    }
    {
        int t;
        int* p1 = &t; // All free
        const int* p2 = &t; // We can only read the value, can't modify
        int* const p3 = &t; // We can modify the value but only fixed location
        const int* const p4 = &t; // Fixed location and can't modify
    }
    {
        const char* foo = "hello";
        cout << *(foo + 2);
    }
    {
        char a;
        char* b;
        char** c;
        a = 'z'; // a location 1000 holds 'z'
        b = &a; // b location 9214 holds 1000
        c = &b; // c location 1245 holds 9214
    }



    return 0;
}
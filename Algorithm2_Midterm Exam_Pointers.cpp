#include <iostream>
using namespace std;

/* ─────────────────────────────────────────────
   Yardımcı Fonksiyonlar
───────────────────────────────────────────── */

int addition(int a, int b)
{
    return (a + b);
}

int subtraction(int a, int b)
{
    return (a - b);
}

// 2. Taşeron işçinin kendisi (3. parametre bir fonksiyon pointer'ı)
int operation(int x, int y, int (*functocall)(int, int))
{
    int g = (*functocall)(x, y); // İşçi, patronun verdiği talimata göre çalışıyor
    return g;
}


/* ─────────────────────────────────────────────
   MAIN
───────────────────────────────────────────── */

int main()
{
    cout << "Berkcan" << endl;

    /* ── Temel Pointer Kullanımı ── */

    int myvar = 25;
    int *foo  = &myvar;

    cout << *foo << endl;   // Değer: 25
    cout <<  foo << endl;   // Adres

    *foo  = 50;
    cout << myvar << endl;  // Changed by foo → 50

    int *ptr = foo;
    *ptr = 100;
    cout << *ptr << endl;   // 100


    /* ── Dizi ve Pointer Aritmetiği ── */

    int  myArray[5] = {1, 2, 3, 4, 5};
    int *ptr2        = myArray; // &myArray gerekmez; dizi adı zaten ilk elemanın pointer'ıdır

    cout << *(ptr2 + 4) << endl; // myArray[4] → 5


    /* ── Pointer Operatörleri (şu an yorum satırında) ── */

    int *ptrX;
    int  var3 = 20;
    ptrX = &var3;

    /*
        *ptrX++;    // önce dereference, sonra adresi artır
        cout << *ptrX << "\t" << ptrX << endl;
        *++ptrX;    // önce adresi artır, sonra dereference
        ++*ptrX;    // dereference et, değeri artır
        (*ptrX)++;  // dereference et, değeri artır (öncelik sırası netleştirilmiş hâli)
    */


    /* ── const Pointer Çeşitleri ── */

    int var4 = 100;
    int var5 = 200;
    int var6 = 300;
    int var7 = 400;
    int deneme;

    const int *ptr4 = &var4;
    deneme = *ptr4;
    // *ptr4 = deneme;   ← HATA: ptr4, var4'ü salt-okunur görür; değer değiştirilemez

    // int const *ptr5 = &var5;
    //   → Adres sabittir (ptr5 hep var5'i gösterir), ama var5'in değeri değiştirilebilir.

    // const int * const ptr6 = &var6;
    //   → Hem adres hem değer sabittir; hiçbiri değiştirilemez.

    // int *ptr7 = &var7;
    //   → Klasik pointer; hem adres hem değer serbestçe değiştirilebilir.


    /* ── String Literali ve Pointer ── */

    // C-string'ler sonunda '\0' tutan karakter dizileridir.
    const char *foo2 = "Hello";
    cout << *(foo2 + 4) << endl; // → 'o'


    /* ── Pointer'a Pointer ── */

    char  karakter = 'x';
    char *pointer1  = &karakter;
    char **pointer2 = &pointer1;

    cout << pointer2  << " / "   // pointer2'nin adresi  (pointer1'in adresi)
         << *pointer2 << " / "   // pointer1'in adresi   (karakter'in adresi)
         << **pointer2 << " / "  // karakter'in değeri   → 'x'
         << pointer1  << " / "   // karakter'in adresi
         << *pointer1 << " / "   // karakter'in değeri   → 'x'
         << karakter  << endl;   // karakter'in değeri   → 'x'


    /* ── Geçersiz / Tehlikeli Pointer Durumları ──
     *
     *  int *p;              → Henüz hiçbir adresi göstermiyor (belirsiz)
     *  int *q = myArray+20; → Dizinin sınırı dışı; tanımsız davranış
     *
     *  Dereference edilirse program çöker.
     *
     *  Çözüm → nullptr kullanımı:
     *
     *  int *p = nullptr;   ← C++ için en güvenli yöntem
     *  int *p = NULL;      ← C uyumlu alternatif
     *  int *p = 0;         ← eski C++ alternatifi
     *
     *  nullptr  → hiçbir yeri göstermez (boş pointer)
     *  void *   → türü belirsiz bir adresi gösterir (farklı kavram)
     */


    /* ── Fonksiyon Pointer'ı ── */

    int m, n;

    // subtraction fonksiyonunun adresini tutan pointer
    int (*minus)(int, int) = subtraction;

    m = operation( 7,  5, addition); // 7  + 5  = 12
    n = operation(20,  m, minus);    // 20 - 12 = 8

    cout << n << endl; // → 8

    return 0;
}

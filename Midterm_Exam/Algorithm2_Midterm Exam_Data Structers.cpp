#include <iostream>
using namespace std;

int main()
{
    // ──────────────────────────────────────────────
    // STRUCT - Temel Kullanım
    // ──────────────────────────────────────────────

    struct fruits {
        int weight;
        int price;
    } banana, melon, apple; // En basit struct yapısına bir örnek

    banana.weight = 3;
    banana.price  = 5;
    cout << banana.weight << "KG - $" << banana.price << endl;


    // ──────────────────────────────────────────────
    // STRUCT - Dizi (Array) Nesnesi
    // ──────────────────────────────────────────────

    struct movies_t {
        string title;
        int    year;
    } films[3]; // Struct'larda bir array nesnesi de oluşturabiliriz

    films[0].title = "Fight Club";
    films[0].year  = 1999;
    cout << films[0].title << " - " << films[0].year << endl;


    // ──────────────────────────────────────────────
    // STRUCT - Pointer Kullanımı
    // ──────────────────────────────────────────────

    movies_t  amovie;
    movies_t* pmovie;
    pmovie = &amovie; // movies_t struct'ında bir pointer ve değişken tanımladık

    pmovie->title = "Matrix"; // Bunu (*pmovie).title diyerek de yapabiliriz
    pmovie->year  = 1999;
    cout << pmovie->title << " - " << (*pmovie).year << endl;


    // ──────────────────────────────────────────────
    // STRUCT - İç İçe (Nested) Kullanım
    // ──────────────────────────────────────────────

    struct friends {
        string   surname;
        int      age;
        movies_t f_movie;
    } berkcan, berat;

    berkcan.surname         = "Kilic";
    berkcan.age             = 22;
    berkcan.f_movie.title   = "Recep İvedik";
    berkcan.f_movie.year    = 2008;

    cout << berkcan.surname      << " - "
         << berkcan.age          << " - "
         << berkcan.f_movie.title << " - "
         << berkcan.f_movie.year  << endl;


    // ──────────────────────────────────────────────
    // UNION
    // ──────────────────────────────────────────────

    /*
     * Union, belleği en cimri şekilde kullanmamızı sağlar.
     * İçine her türden veri koyabiliriz; union'ın büyüklüğü
     * içindeki en büyük verinin boyutu kadar olur.
     *
     * Örnek: int (4 byte) + short (2 byte) + char koyarsak
     * union boyutu 4 byte olur. Bu sayede o union'dan ya:
     *   - 1 adet int
     *   - 2 adet short
     *   - 4 adet karakter
     * oluşturabiliriz.
     */

    union mytypes {
        int sayi;
        struct {
            short k_sayi1; // İlk 2 byte'a yerleşir
            short k_sayi2; // Sonraki 2 byte'a yerleşir
        } s;
        char karakter[4];
    } mix;

    mix.sayi      = 4;
    mix.s.k_sayi1 = 1;
    mix.s.k_sayi2 = 2;
    mix.karakter[0] = 'b';


    // ──────────────────────────────────────────────
    // ENUM
    // ──────────────────────────────────────────────

    enum colors_t { black, blue, red, purple, pink, gray, orange } mycolor;
    mycolor = black;
    // mycolor = green; → Hata! colors_t içinde green tanımlı değil.

    /*
     * Özellikle belirtilmezse enum'un ilk elemanı 0'dır,
     * diğerleri +1 artarak ilerler: 0, 1, 2, 3 ...
     *
     * Aşağıdaki gibi başlangıç değeri özellikle belirtilebilir.
     * Bilgisayar bu değerleri hafızada birer integer olarak tutar.
     */

    enum months_t {
        january = 1, february, march,     april,
        may,         june,     july,      august,
        september,   october,  november,  december
    } mymonth[12]; // Dizi objesi de oluşturabiliriz

    return 0;
}
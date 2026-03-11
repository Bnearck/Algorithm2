#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// ==========================================
// 1. DATA STRUCTURES (STRUCTS)
// ==========================================
/* Bir nesneye ait birden çok özelliği aynı anda taşımak için paket yapma işlemidir.
   Sınıftan (class) farkı default olarak public olmasıdır, class ise default privatedir. */

struct fruits {
    int weight;
    string color;
} apple, banana, orange;

struct movies {
    string rate = "Good"; // Fix tanımlanabilir, ardından değiştirilebilir
    int year;
} fight_club, matrix, interstellar;

struct car {
    string model;
    int year;
} ford[3];

struct movies_t {
    string title;
    int year;
};

// ==========================================
// 2. NESTED DATA STRUCTURES
// ==========================================
struct friend_t {
    string name;
    int weight;
    movies_t favourite_film; // İç içe (nested) struct kullanımı
} emma, charlie;


// ==========================================
// 3. UNIONS
// ==========================================
/* Struct'ta her ayrı data type için bellekte ayrı alan açılır.
   Union'da ise hepsi ortak bir alanda (aralarındaki en büyüğünün boyutu kadar) depolanır.
   Aynı hamura bazen bütün bir ekmek, bazen iki parça poğaça muamelesi yapmak gibi! */

union mix_t {
    int variable1; // 4 byte
    struct vrbls {
        short variable2; // 2 byte
        short variable3; // 2 byte
    } variable2;
    char variable3[4]; // 4 byte
} mix;


// ==========================================
// 4. ENUMS
// ==========================================
/* Elimizdeki verileri klasörlemek gibidir. Daha organize olmamızı ve hatalardan korunmamızı sağlar. */

enum colors_t { red = 1, green, blue, yellow, purple, pink, black, orange } mycolor;

// Default 0'dan başlar ama isteğe göre 1'den başlatabiliriz
enum days_t { monday = 1, tuesday, wednesday, thursday, friday, saturday, sunday } myday;


// ==========================================
// MAIN FONKSİYONU (ÇALIŞTIRMA ALANI)
// ==========================================
int main() {

    // --- BASIC STRUCT TEST ---
    cout << "--- BASIC STRUCT ---" << endl;
    apple.weight = 300;
    banana.color = "Yellow";
    cout << "Apple Weight: " << apple.weight << "\nBanana Color: " << banana.color << "\n\n";

    fight_club.year = 1999;
    matrix.rate = "Very High"; // Sonradan değiştirdik
    cout << "Fight Club Year: " << fight_club.year << "\nFight Club Rate: " << fight_club.rate
        << "\nMatrix Rate: " << matrix.rate << "\n\n";


    // --- ARRAYS AND STRUCTS TEST ---
    /* (Konsolu çok meşgul etmemesi için yoruma alındı, test etmek istersen açabilirsin)
    cout << "--- ARRAYS AND STRUCTS ---" << endl;
    for (int n = 0; n < 3; n++) {
        cout << "What is your ford model? ";
        cin >> ford[n].model;
        cout << "What is your ford year? ";
        cin >> ford[n].year;
        cout << "Here is your ford: " << ford[n].model << " - " << ford[n].year << endl;
    }
    cout << endl;
    */


    // --- POINTERS AND STRUCTS TEST ---
    cout << "--- POINTERS AND STRUCTS ---" << endl;
    string mystr;
    movies_t movie1;
    movies_t* pmovie = &movie1; // Pointer ataması

    cout << "Enter your film: ";
    getline(cin, pmovie->title);
    cout << "Enter your film date: ";
    getline(cin, mystr);
    stringstream(mystr) >> pmovie->year; // Doğru tip dönüşümü

    cout << "Your film is: " << pmovie->title << " (" << pmovie->year << ")\n\n";


    // --- NESTED STRUCTS TEST ---
    cout << "--- NESTED STRUCTS ---" << endl;
    friend_t* fpointer1 = &emma;
    friend_t* fpointer2 = &charlie;

    emma.weight = 60;
    charlie.favourite_film.title = "V for Vendetta";

    // Pointer ile asıl struct'a ulaştık (->), içindeki struct'ın özelliğine ise nokta (.) ile eriştik.
    cout << "Charlie's favourite film is: " << fpointer2->favourite_film.title << "\n\n";


    // --- ENUMS TEST ---
    cout << "--- ENUMS ---" << endl;
    mycolor = blue; // Sadece colors_t içindeki değerleri alabilir

    cout << "Days as Integers: ";
    for (int n = 1; n < 8; n++) {
        cout << days_t(n) << " "; // Ekrana 1 2 3 4 5 6 7 yazdırılır
    }
    cout << "\n\nDays as Strings:\n";

    for (int n = 1; n < 8; n++) {
        switch (days_t(n)) {
        case 1: cout << "Monday" << endl; break;
        case 2: cout << "Tuesday" << endl; break;
        case 3: cout << "Wednesday" << endl; break;
        case 4: cout << "Thursday" << endl; break;
        case 5: cout << "Friday" << endl; break;
        case 6: cout << "Saturday" << endl; break;
        case 7: cout << "Sunday" << endl; break;
        }
    }

    // #WEEK 4 biter
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int * foo;
    foo = new int [5]; /* Burada hafızadan 5 birimlik alan ayıran bir dynmic memory yaptık new komutu sayesinde, bu 5 esneyemez 6 7 olamaz biz içine önceden tanımlaıdğımız için sabit kalır
    fakat eğer foo = (nothrow) int [i] diyip kullanıcıdan veri alsaydık kullanıcıdan veri ne akdar geleceğini bilmediğimiz için burda dynamic memory kullanırdık mesela kullanıcı
    i yerine 1000 verdi ya o program o esnada çalışırken hafızada 1000 yer kaplar ama tekrar program başlatılıp 50 yazdılığında bu sefer 50 birim yer kaplar dynamic memoryinn mantığı budur*/

    delete [] foo; //Burada ise işmiz bittikten sonra dynamic memoryi "Array" olarak siliyoruz ki hafızada tekrardan yer açılsın
    // delete foo; //Eğer tek elemanlık bir yer ayırdıysak böyle de silebiliriz ama dizi ayırdıysak yukarıdaki gibi silmemiz gerekiyor.

    /*Ayrıca delete operatörüne argüman olarak a daha önceden tahsis edilmiş bir dynamic memory pointerini verebilirz yada NULL pointeriniverebiliriz bunun dışında new ile
    açmadığımız herhangi bir bellek adresini silmeye kalkarsak program çöker*/

    int i,n;
    int *p;
    cout << "How many number would you like to type?" << endl;
    cin >> i;
    p = new (nothrow) int [i];
    if (p == nullptr)
    cout << "Error: memory could not be allocated";
    else{
        for (n=0; n<i; n++)
        {
            cout << "Enter number: ";
            cin >> p[n];
        }
        cout << "You have entered: ";
        for (n=0; n<i; n++)
        {
        cout << p[n] << ", ";
        }
        delete[]p;
        }
        return 0;

        /* dilinde bu durum c++ den farklı olarak malloc  calloc reallloc ve free methodları ile kütüphane üzerinden halledilird/
        bu methodları halen cpp de <cstdlib> yazarak kullanabiliriz fakat new ile açtıysak delete alloc ile açtıysak free ile
        belleği kapatmalıyız bu iki yöntem birbirine karıştırılmadan kulanılmalıdır. */
    
}   
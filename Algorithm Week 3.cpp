#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    //DATA STRUCTERS - UNİONS - ENUMS

	//DATA STRUCTERS

	/*Bir nesneye ait birde çok özelliği aynı anda taşımak için aslında bir nevi paket yapma işlemidir
	sınıfdan farkı ise default olarak publictir dışarıdan herkes erişebilir ama class default olarak privatedir dışarıdan
		rastegele erişemezsin*/

	/*
	
	struct fruits {
		int weight;
		string color;
	}apple, banana, orange;

	apple.weight = 300;
	banana.color = "Yellow";

	cout << apple.weight << endl << banana.color << endl;

	struct movies {
		string rate = "Good"; //Fix tanımlayabilir ardından değiştirilebilir
		int year;
	}fight_club, matrix, interstellar;

	fight_club.year = 1999;
	matrix.rate = "Very High"; //sonradan değiştirdik

	cout << fight_club.year << endl << fight_club.rate << endl << matrix.rate << endl;

	*/

	//ARRAYS AND DATA STRUCTERS

	/*

	 struct car {
		string model;
		int year;
	}ford[3];

	for (int n = 0; n < 3; n++)
	{
		cout << "What is yout ford model";
		cin >> ford[n].model;
		cout << "What is yout ford year";
		cin >> ford[n].year;

		cout << "Here is your ford: " << ford[n].model << "-" << ford[n].year << endl;
    }

	*/

	//POİNTERS AND DATA STRUCTERS

	/*

	struct movies_t {
		string title;
		int year;
	}; //bu şekilde bir şey tanımlamadan da bırakabiliriz

	string mystr;

	movies_t movie1;
	movies_t* pmovie;
	pmovie = &movie1;

	cout << "Enter Your film ";
	getline(cin, pmovie->title);
	cout << "Enter your film date ";
	getline(cin, mystr);
	(stringstream)mystr >> pmovie->year;

	cout << "Your film is: " << pmovie->title << " " << pmovie->year << endl; //bu örnekte poniter zorunlu değildi

	*/

	//NESTED DATA STRUCTERS

	/*
	
	struct friend_t {
		string name;
		int weight;
		movies_t favourite_film;//Burada nested structers kullanıyorum
	}emma, charlie;

	friend_t* fpointer1, *fpointer2;
	fpointer1 = &emma;
	fpointer2 = &charlie;
	
	emma.weight = 60;
	charlie.favourite_film.title = "V for Vendetta";

	cout << "Charlies favourite film is: " << fpointer2->favourite_film.title << endl; //burada charlienin 3 özellğinden film olanına pointer ile eiştik ama film structunun içindeki 2 özellikten biri olan title ye "." ile eriştik.

	*/

	//UNİONS

	/*Bu unions normal programlamada nerdeyse hiç kullanılmıyor işlevi gereği fakat ağlarda veya gömülü sistemlerde falan çalışıyorsan
	hayat kurtarıcı olabiliyor mantığı ise çok basit structda her bir ayrı data type için bellekte bir alan açılıyor union da ise hepsi
	ortak bir alanda (aralarındaki en büyüğünün boyutu kadar) depolanıyor şu ramdeki adresleri gösteren dikdörtgen örneğini düşün
	structa mesela 3 variable için 3 tane farklı dikdörtgen kullanıyoruz 3 farklı adres ama unionda tek bir dikdörtgene bu 3 variableyi
	sığdırıyoruz yani bir int 4byte yer kaplıyorya bunu 2 short 2 short olarak bölüpde kullanabiliyoruz*/

	union mix_t{
		int variable1; //4 byte
		struct vrbls {
			short variable2; // 2 byte
			short variable3; // 2 byte
		}variable2;
		char variable3[4]; // 1 1 1 1 (4) byte
	}mix;

	//Aynı hamura bazen bütün bir ekmek, bazen iki parça poğaça, bazen de dört küçük kurabiye muamelesi yapmak gibi!

	//ENUMS

	/* aslında elimizdek iverileri klasörlemek gibidir daha organize ve düznli olmamızı hatalardan korunmamızı sağlar*/

	enum colors_t { red=1, green, blue, yellow, purple, pink, black, orange } mycolor;

	mycolor = blue; //mycolor clors_t içindeki renklerden birini alabilir mesela gray alamaz hata verir

	enum days_t { monday=1, tuesday, wednesday, thursday, friday, saturday, sunday } myday; /*default 0 dan başlar ama biz isteğe
	göre 1 den başlatabiliriz*/


	for (int n = 1; n < 8; n++)
	{
		cout << days_t(n) << endl; //burada ekrana günler değil 1 2 3 4 5 6 7 yazıdırlır çünkü enum her bir günü sayısal bir değer olarak tutar
	}

	for (int n = 1; n < 8; n++) //bu şekilde günler yazdırılabilir ama biraz amele işi
	{
		switch (days_t(n)) {
		case 1: cout << "Monday" << endl;
			break;
		case 2: cout << "Tuesday" << endl;
			break;
		case 3: cout << "Wednesday" << endl;
			break;
		case 4: cout << "Thursday" << endl;
			break;
		case 5: cout << "Friday" << endl;
			break;
		case 6: cout << "Saturday" << endl;
			break;
		case 7: cout << "Sunday" << endl;
			break;
		
		}
	}

	//#WEEK 4 biter

};
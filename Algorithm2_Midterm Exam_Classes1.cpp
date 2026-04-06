#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
public:
    // Fonksiyonların ne yapacağını burada tanımlıyoruz
    void setValues(int w, int h) { //Set values fonksiyonunu void setValues(int w, int h) şeklinde yazıp "Prototip" şeklinde bırakabilirdik,
                                   //Bu durumda bu fonksiyonu classın dışında detaylı tanımlamamız gerekirdi aşağıdaki örnekte olduu gibi
        width = w;
        height = h;
    }
    int area() { //Area fonksiyonunu ise class içinde direkt inline oalrak tam tanımlı bir şekilde tanımladık
        return width * height;
    }

    /*void Rectangle::set_values (int x, int y) {
  width = x;
  height = y; FONKSİYONUN DIŞARIDA DETAYLI TANIMLADIK */
};

class Triangle {
    int edge1, edge2, edge3;
public:
    Triangle();
    Triangle(int, int, int);
    int area (void)
    {
        return (edge1*edge2*edge3);
    }
};

Triangle::Triangle(){ //Constructoru sadece dışarıdanda tanımlayabildiğmizi göstermek için dışarıdan tanımladık içeri sadece prototip yazdık
    edge1 = 3;        //İlerleyen örneklerde constructorları inline oalrak da tanımlayacağız
    edge2 = 4;
    edge3 = 5;
};

Triangle::Triangle(int a, int b, int c) : edge1(a), edge2(b), edge3(c){ //Ayrıca burada daha profesyönel bir yol olan direkt tek satırda değişkenlere değer atamayı görüyoruz
}; 



int main() {
    Rectangle rect1; // Nesne oluşturma
    Rectangle rect2;

    rect1.setValues(3, 5);
    cout << "Alan: " << rect1.area() << endl;

    rect2.setValues(10, 15);
    cout << "Alan: " << rect2.area() << endl; /* Görüldüğü üzere her class üzerinden üretilmiş nesnesin kendi width ve heighti vardır ve ona göre işlem yapılır
    burada rec1 için width height 3 5 iken rect2 nesnesi için bunlar 10 ve 15dir yani biri diğerini etkilemez kendi içlerinde özeldir*/

    Triangle tri1; //Constructor sayesinde parametre atamadığımız için otoamtik olarak parametreler 3,4,5 olarak atandı
    Triangle tri2 (5,10,15); //Buradada constructor sayesinde setValue gibi bir fonksiyon kullanmadan direkt tri2 nesnesini edge1,edge2,edge3 değişkenlerine 5,10,15 atayabilidk

    //Tek parametre göndermek istersek tri2() yaptığımızda C++ derleyicisi bunun nesnemi fonksiyonmu olduğunu anlayamaz ve hata verir bu yüzden tri2{} yapıyoruz
    cout << tri1.area() << " - " << tri2.area() << endl;
    return 0;
}
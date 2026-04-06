#include <iostream>
using namespace std;

// ─────────────────────────────────────────────
// CLASS: Rectangle
// ─────────────────────────────────────────────
class Rectangle {
    int width, height;

public:
    // Fonksiyonu class içinde inline olarak tanımladık
    void setValues(int w, int h) {
        width  = w;
        height = h;
        // Not: setValues'u sadece prototip olarak bırakıp
        // aşağıdaki gibi dışarıda da tanımlayabilirdik:
        // void Rectangle::setValues(int x, int y) { width = x; height = y; }
    }

    // area() de inline tanımlı
    int area() {
        return width * height;
    }
};

// ─────────────────────────────────────────────
// CLASS: Triangle
// ─────────────────────────────────────────────
class Triangle {
    int edge1, edge2, edge3;

public:
    Triangle();              // Default constructor prototipi
    Triangle(int, int, int); // Parametreli constructor prototipi

    int area() {
        return (edge1 * edge2 * edge3);
    }
};

// Default constructor — dışarıda tanımlandı (içeride sadece prototip var)
// İlerleyen örneklerde constructorları inline olarak da tanımlayacağız
Triangle::Triangle() {
    edge1 = 3;
    edge2 = 4;
    edge3 = 5;
}

// Parametreli constructor — initializer list kullanımı (daha profesyonel yol)
Triangle::Triangle(int a, int b, int c) : edge1(a), edge2(b), edge3(c) {}

// ─────────────────────────────────────────────
// MAIN
// ─────────────────────────────────────────────
int main() {

    // Rectangle nesneleri
    // Her nesnenin kendi width/height'i vardır, biri diğerini etkilemez
    Rectangle rect1, rect2;

    rect1.setValues(3, 5);
    cout << "rect1 Alan: " << rect1.area() << endl; // 15

    rect2.setValues(10, 15);
    cout << "rect2 Alan: " << rect2.area() << endl; // 150

    // Triangle nesneleri
    Triangle tri1;          // Default constructor → edge1=3, edge2=4, edge3=5
    Triangle tri2(5, 10, 15); // Parametreli constructor → setValues'a gerek yok
    // Not: Tek parametrede tri2() yazılırsa derleyici nesne mi fonksiyon mu
    //      anlayamaz; bu yüzden tri2{} sözdizimi kullanılır.

    cout << "tri1 Alan: " << tri1.area() << " | "
         << "tri2 Alan: " << tri2.area() << endl;

    return 0;
}
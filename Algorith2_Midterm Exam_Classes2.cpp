#include <iostream>
using namespace std;

class CVector {
public:
    int x, y;
    CVector() {}
    CVector(int a, int b) : x(a), y(b) {}
};

CVector operator+ (const CVector& lhs, const CVector& rhs) {
    CVector temp;
    temp.x = lhs.x + rhs.x;
    temp.y = lhs.y + rhs.y;
    return temp;
}

class Dummy {
public:
    bool isitme(Dummy& param);
};

bool Dummy::isitme(Dummy& param) {
    return (&param == this);
}

class Dummy2 {
public:
    static int n;
    Dummy2() { n++; }
};
int Dummy2::n = 0;

class MyClass {
public:
    static int sayac;
    int x;
    MyClass(int val) : x(val) { sayac++; }
    // HATA DÜZELTME: const nesnelerle çalışabilmesi için 'const' eklendi
    int get() const { return x; } 
};
int MyClass::sayac = 0;

class MyClass2 {
    int o;
public:
    MyClass2(int val2) : o(val2) {}
    const int& get() const { return o; }
};

// HATA DÜZELTME: MyClass yerine MyClass2 kullanılmalı
void print(const MyClass2& arg) {
    cout << arg.get() << endl;
}

template <class T>
class mycontainer
{
    T element;
    public:
    mycontainer (T arg) {element = arg;}
    T increase () {return ++element;}
};

template <>
class mycontainer <char>
{
    char element;
    public:
    mycontainer (char arg) {element = arg;}
    char uppercase()
    {
        if ((element>='a') && (element <='z'))
        element += 'A'-'a';
        return element;
    }
};

int main() {
    CVector foo(3, 1);
    CVector c_bar(1, 2); // 'bar' ismini aşağıda MyClass2 için sakladık
    CVector result = foo + c_bar;
    cout << result.x << " , " << result.y << endl;

    Dummy a;
    Dummy* b = &a;
    if (b->isitme(a)) cout << "yes, &a is b" << endl;

    Dummy2 a2;
    Dummy2 b2[5];
    Dummy2* ptr = new Dummy2;
    cout << "Dummy2 static n: " << Dummy2::n << endl;
    delete ptr;

    const MyClass deneme(10);
    cout << deneme.x << " - " << "Sayac: " << MyClass::sayac << endl;

    // HATA DÜZELTME: İsim çakışması giderildi ve doğru tip kullanıldı
    MyClass2 bar_obj(10); 
    print(bar_obj);

    mycontainer<int> myint (7);
    mycontainer <char> mychar ('j');
    cout << myint.increase() << endl;
    cout << mychar.uppercase() << endl;

    return 0;
}
#include <iostream>
using namespace std;

class Complex { //новий клас для комплексних чисел, який забезпечує операції над ними

private:
    double real; //оголошення приватної змінної real типу double
    double imaginary; //оголошення приватної змінної imaginary типу double

public:
    Complex() : real(0.0), imaginary(0.0) {} //конструктор для класу без аргументів
    Complex(double r, double i) : real(r), imaginary(i) {} //конструктор для класу з двома double аргументами, він ініціалізує змінну real через r та змінну imaginary через і
    Complex(int r, int i) : real(static_cast<double>(r)), imaginary(static_cast<double>(i)) {}//конструктор для класу з двома цілими аргументами, перетворює r і i на double, ініціалізує змінні
    

    Complex operator+(const Complex& other) { //визначає + оператора для класу, приймає const посилання на інший аргумент і повертає новий об'єкт
        return Complex(real + other.real, imaginary + other.imaginary);//створює об'єкт класу шляхом додавання real частин imaginary та інших об'єктів 
    }
    Complex operator-(const Complex& other) { //визначає - оператора для класу, приймає const посилання на інший аргумент і повертає новий об'єкт
        return Complex(real - other.real, imaginary - other.imaginary); //створює об'єкт класу шляхом віднімання real частин та imaginary та інших від поточного об'єкта
    }
    Complex operator*(const Complex& other) { // визначає * оператора для класу, приймає const посилання на інший аргумент і повертає новий об'єкт
        double resultReal = real * other.real - imaginary * other.imaginary; // обчислює дійсну частину добутку двох комплексних чисел за формулою (a + bi) * (c + di) = (ac - bd) + (ad + bc)i.
        double resultImaginary = real * other.imaginary + imaginary * other.real; // обчислює уявну частину добутку двох комплексних чисел за тією самою формою 
        return Complex(resultReal, resultImaginary); // створює новий об'єкт класу, використовуючи значення resultReal та resultImaginary
    }
    void calculation() { //функція calculation, яка не приймає аргументів та нічого не повертає
        cout << real << (imaginary >= 0 ? " + " : " - ") << abs(imaginary) << "i" << endl; // друкує комплексне число у зазначеному форматі
    }

    friend istream& operator>>(istream& in, Complex& c) { //оператор для введення чисел для класу
        cout << "Введiть дiйсну частину числа: ";
        in >> c.real; //введення дійсної частину числа
        cout << "Введiть уявну частину числа: ";
        in >> c.imaginary; //введення уявної частини числа
        return in;

    }
};
int main() {
    setlocale(LC_CTYPE,"ukr"); // цей рядок для того, щоб виводити українською мовою
    
    Complex num1; // створює об'єкт класу з назвою num1
    Complex num2; // створює об'єкт класу з назвою num2


    cout << "Введiть два числа з плаваючою комою: " << endl;
    cin >> num1;

    cout << "Введiть два цiлi числа: " << endl;
    cin >> num2;



    Complex sum = num1 + num2; // за допомогою + оператора, обчислює суму та записує результат в об'єкт sum
    Complex difference = num1 - num2; // за допомогою - оператора, обчислює різницю та записує результат в об'єкт difference
    Complex product = num1 * num2; // за допомогою * оператора, обчислює добуток та записує результат в об'єкт product

    cout << "Додавання: "; //вивід суми комплексних чисел
    sum.calculation(); //виклик функції calculation

    cout << "Рiзниця: "; //вивід різниці комплексних чисел
    difference.calculation(); //виклик функції calculation

    cout << "Множення: "; //вивід добутку комплексних чисел
    product.calculation(); //виклик функції calculation

    return 0;
}




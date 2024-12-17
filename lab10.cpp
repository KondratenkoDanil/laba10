#include <iostream>
using namespace std;

int main() {
    double x = 10;              // Введіть значення x
    double numerator, denominator, y;

    // Обчислення чисельника: 3000 + x
    numerator = 3000 + x;

    // Асемблерна вставка для обчислення знаменника: x^2 + 2.6x - 7.5
    __asm {
        finit                  // Очищення регістрів співпроцесора
        fld x                  // Завантажуємо x у стек
        fmul st(0), st(0)      // x^2
        fld x                  // Завантажуємо x знову
        fmul dword ptr[coef]   // 2.6x
        fadd st(0), st(1)      // Додаємо x^2 + 2.6x
        fsub dword ptr[const]  // Віднімаємо 7.5
        fstp denominator       // Збереження результату у denominator
    }

    // Перевірка на ділення на нуль
    if (denominator != 0) {
        y = numerator / denominator;
        cout << "Результат y = " << y << endl;
    }
    else {
        cout << "Помилка: ділення на нуль!" << endl;
    }

    return 0;
}

const double coef = 2.6;       // Коефіцієнт для множення
const double const = 7.5;      // Константа для віднімання

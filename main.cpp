#include <iostream>
#include <cmath>
using namespace std;

// ================= ПРОТОТИПИ ФУНКЦІЙ =================
//
// ---- Proc14 ----
bool inputTriple(double &a, double &b, double &c);          // введення трьох чисел
void ShiftRight3(double &A, double &B, double &C);          // правий циклічний зсув
void outputTriple(const double &a, const double &b, const double &c);
void task_Proc14();                                         // завдання Proc14

// ---- Proc43 ----
bool inputPositiveTriple(double &a, double &b, double &c);  // введення трьох додатних
bool IsTriangle(double a, double b, double c);              // перевірка трикутника
void printTriangleResult(double a, double b, double c);
void task_Proc43();                                         // завдання Proc43

// ---- Завдання 2: Integer13 з ЛР2 ----
// Дано тризначне число n. Закреслюємо першу цифру зліва і приписуємо її справа.
bool in_n(int &n);                                          // введення n з перевіркою
int calc_Integer13(int n);                                  // обчислення результату
void out_res_Int13(int n, int res);                         // виведення результату
void task_Integer13();                                      // завдання Integer13


// ====================== main =========================

int main()
{
    int choice;

    do {
        cout << "====== МЕНЮ ЛР4 ======" << endl;
        cout << "1 - Proc14: правий циклiчний зсув (двi трiйки чисел)" << endl;
        cout << "2 - Proc43: перевiрка, чи можна утворити трикутник (3 набори)" << endl;
        cout << "3 - Integer13 (з ЛР2): перенос першої цифри тризначного числа в кiнець" << endl;
        cout << "0 - Вихiд" << endl;
        cout << "Ваш вибiр: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Помилка вводу! Спробуйте ще раз." << endl << endl;
            continue;
        }

        cout << endl;

        switch (choice) {
        case 1:
            task_Proc14();
            break;
        case 2:
            task_Proc43();
            break;
        case 3:
            task_Integer13();
            break;
        case 0:
            cout << "Завершення роботи програми." << endl;
            break;
        default:
            cout << "Невiрний пункт меню. Спробуйте ще раз." << endl;
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}


// ================= РЕАЛІЗАЦІЇ ФУНКЦІЙ =================
//
// ----------- Proc14: ShiftRight3 ---------------------

// Введення трьох чисел з перевіркою діапазону [-100; 100]
bool inputTriple(double &a, double &b, double &c)
{
    cout << "Введiть три числа (в дiапазонi [-100; 100]):" << endl;
    cout << "A = ";
    cin >> a;
    cout << "B = ";
    cin >> b;
    cout << "C = ";
    cin >> c;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Помилка: введено нечислове значення!" << endl;
        return false;
    }

    if (a < -100 || a > 100 || b < -100 || b > 100 || c < -100 || c > 100) {
        cout << "Помилка: усi числа повиннi належати дiапазону [-100; 100]." << endl;
        return false;
    }

    return true; // все добре
}

// Правий циклічний зсув: A -> B, B -> C, C -> A
void ShiftRight3(double &A, double &B, double &C)
{
    double temp = C;
    C = B;
    B = A;
    A = temp;
}

// Виведення трійки чисел
void outputTriple(const double &a, const double &b, const double &c)
{
    cout << "A = " << a << "; B = " << b << "; C = " << c << endl;
}

// Задача Proc14: виконати зсув для двох наборів
void task_Proc14()
{
    double A1, B1, C1;
    double A2, B2, C2;

    cout << "--- Proc14: правий циклiчний зсув для двох трiйок ---" << endl;

    cout << "=== Перший набiр (A1, B1, C1) ===" << endl;
    if (!inputTriple(A1, B1, C1)) {
        cout << "Обчислення не виконуються через помилку вводу." << endl;
        return;
    }

    cout << "=== Другий набiр (A2, B2, C2) ===" << endl;
    if (!inputTriple(A2, B2, C2)) {
        cout << "Обчислення не виконуються через помилку вводу." << endl;
        return;
    }

    cout << endl << "Початковi значення:" << endl;
    cout << "Набiр 1: ";
    outputTriple(A1, B1, C1);
    cout << "Набiр 2: ";
    outputTriple(A2, B2, C2);

    // Виконуємо правий циклічний зсув для кожної трійки
    ShiftRight3(A1, B1, C1);
    ShiftRight3(A2, B2, C2);

    cout << endl << "Пiсля правого циклiчного зсуву:" << endl;
    cout << "Набiр 1: ";
    outputTriple(A1, B1, C1);
    cout << "Набiр 2: ";
    outputTriple(A2, B2, C2);
}


// ----------- Proc43: IsTriangle ----------------------

// Введення трьох додатних чисел (0; 100]
bool inputPositiveTriple(double &a, double &b, double &c)
{
    cout << "Введiть три додатнi числа (0 < x <= 100):" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Помилка: введено нечислове значення!" << endl;
        return false;
    }

    // Додатність + обмеження діапазону
    if (a <= 0 || a > 100 || b <= 0 || b > 100 || c <= 0 || c > 100) {
        cout << "Помилка: усi числа повиннi бути додатнiми i не бiльшими за 100." << endl;
        return false;
    }

    return true;
}

// Функція, що перевіряє можливість утворити трикутник
bool IsTriangle(double a, double b, double c)
{
    // Умова трикутника: кожна сторона < суми двох інших
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Виведення результату
void printTriangleResult(double a, double b, double c)
{
    cout << "Сторони: a = " << a << ", b = " << b << ", c = " << c << " -> ";
    if (IsTriangle(a, b, c))
        cout << "трикутник iснує." << endl;
    else
        cout << "утворити трикутник НЕ можна." << endl;
}

// Задача Proc43: перевірити 3 набори чисел
void task_Proc43()
{
    double a1, b1, c1;
    double a2, b2, c2;
    double a3, b3, c3;

    cout << "--- Proc43: перевiрка, чи можна утворити трикутник ---" << endl;

    cout << "=== Набiр 1 ===" << endl;
    if (!inputPositiveTriple(a1, b1, c1)) {
        cout << "Обчислення не виконуються через помилку вводу." << endl;
        return;
    }

    cout << "=== Набiр 2 ===" << endl;
    if (!inputPositiveTriple(a2, b2, c2)) {
        cout << "Обчислення не виконуються через помилку вводу." << endl;
        return;
    }

    cout << "=== Набiр 3 ===" << endl;
    if (!inputPositiveTriple(a3, b3, c3)) {
        cout << "Обчислення не виконуються через помилку вводу." << endl;
        return;
    }

    cout << endl << "Результати перевiрки:" << endl;
    printTriangleResult(a1, b1, c1);
    printTriangleResult(a2, b2, c2);
    printTriangleResult(a3, b3, c3);
}


// -------- Завдання 2: Integer13 (з ЛР2) ---------------
//
// Дано тризначне число n (100..999).
// Закреслити першу цифру зліва і приписати її справа: abc -> bca.

// введення n з перевіркою
bool in_n(int &n)
{
    cout << "Integer13. Введiть тризначне додатнє число n (100..999): ";
    cin >> n;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Помилка: введено нецiле число." << endl;
        return false;
    }

    if (n < 100 || n > 999) {
        cout << "Помилка: n повинно бути тризначним додатнiм числом." << endl;
        return false;
    }

    return true;
}

// обчислення результату (та сама формула, що в ЛР2)
int calc_Integer13(int n)
{
    // (n % 100) * 10 + (n / 100) – переносимо першу цифру в кінець
    return (n % 100) * 10 + (n / 100);
}

// виведення результату
void out_res_Int13(int n, int res)
{
    cout << "Початкове n = " << n
         << ", пiсля перенесення першої цифри в кiнець: " << res << endl;
}

// повна задача Integer13 з використанням трьох функцій
void task_Integer13()
{
    int n;
    if (!in_n(n)) {
        cout << "Обчислення не виконуються через некоректнi данi." << endl;
        return;
    }

    int result = calc_Integer13(n);
    out_res_Int13(n, result);
}

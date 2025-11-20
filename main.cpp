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
        cout << "====== LAB4 MENU ======" << endl;
        cout << "1 - Proc14: right cyclic shift (two triples of numbers)" << endl;
        cout << "2 - Proc43: check if a triangle can be formed (3 sets)" << endl;
        cout << "3 - Integer13 (from Lab2): move the first digit of a three-digit number to the end" << endl;
        cout << "0 - Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input error! Try again." << endl << endl;
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
            cout << "Program finished." << endl;
            break;
        default:
            cout << "Invalid menu item. Try again." << endl;
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
    cout << "Enter three numbers in range [-100; 100]:" << endl;
    cout << "A = ";
    cin >> a;
    cout << "B = ";
    cin >> b;
    cout << "C = ";
    cin >> c;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: non-numeric value entered!" << endl;
        return false;
    }

    if (a < -100 || a > 100 || b < -100 || b > 100 || c < -100 || c > 100) {
        cout << "Error: all numbers must belong to range [-100; 100]." << endl;
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

    cout << "--- Proc14: right cyclic shift for two triples ---" << endl;

    cout << "=== First set (A1, B1, C1) ===" << endl;
    if (!inputTriple(A1, B1, C1)) {
        cout << "Calculations are not performed due to input error." << endl;
        return;
    }

    cout << "=== Second set (A2, B2, C2) ===" << endl;
    if (!inputTriple(A2, B2, C2)) {
        cout << "Calculations are not performed due to input error." << endl;
        return;
    }

    cout << endl << "Initial values:" << endl;
    cout << "Set 1: ";
    outputTriple(A1, B1, C1);
    cout << "Set 2: ";
    outputTriple(A2, B2, C2);

    // Виконуємо правий циклічний зсув для кожної трійки
    ShiftRight3(A1, B1, C1);
    ShiftRight3(A2, B2, C2);

    cout << endl << "After right cyclic shift:" << endl;
    cout << "Set 1: ";
    outputTriple(A1, B1, C1);
    cout << "Set 2: ";
    outputTriple(A2, B2, C2);
}


// ----------- Proc43: IsTriangle ----------------------

// Введення трьох додатних чисел (0; 100]
bool inputPositiveTriple(double &a, double &b, double &c)
{
    cout << "Enter three positive numbers (0 < x <= 100):" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: non-numeric value entered!" << endl;
        return false;
    }

    // Додатність + обмеження діапазону
    if (a <= 0 || a > 100 || b <= 0 || b > 100 || c <= 0 || c > 100) {
        cout << "Error: all numbers must be positive and not greater than 100." << endl;
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
    cout << "Sides: a = " << a << ", b = " << b << ", c = " << c << " -> ";
    if (IsTriangle(a, b, c))
        cout << "triangle exists." << endl;
    else
        cout << "cannot form a triangle." << endl;
}

// Задача Proc43: перевірити 3 набори чисел
void task_Proc43()
{
    double a1, b1, c1;
    double a2, b2, c2;
    double a3, b3, c3;

    cout << "--- Proc43: check if a triangle can be formed ---" << endl;

    cout << "=== Set 1 ===" << endl;
    if (!inputPositiveTriple(a1, b1, c1)) {
        cout << "Calculations are not performed due to input error." << endl;
        return;
    }

    cout << "=== Set 2 ===" << endl;
    if (!inputPositiveTriple(a2, b2, c2)) {
        cout << "Calculations are not performed due to input error." << endl;
        return;
    }

    cout << "=== Set 3 ===" << endl;
    if (!inputPositiveTriple(a3, b3, c3)) {
        cout << "Calculations are not performed due to input error." << endl;
        return;
    }

    cout << endl << "Check results:" << endl;
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
    cout << "Integer13. Enter a three-digit positive number n (100..999): ";
    cin >> n;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: non-integer value entered." << endl;
        return false;
    }

    if (n < 100 || n > 999) {
        cout << "Error: n must be a three-digit positive number." << endl;
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
    cout << "Initial n = " << n
         << ", after moving the first digit to the end: " << res << endl;
}

// повна задача Integer13 з використанням трьох функцій
void task_Integer13()
{
    int n;
    if (!in_n(n)) {
        cout << "Calculations are not performed due to invalid data." << endl;
        return;
    }

    int result = calc_Integer13(n);
    out_res_Int13(n, result);
}

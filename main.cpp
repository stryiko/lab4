#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

// ================= ОГОЛОШЕННЯ ФУНКЦІЙ (до main) =================

// Proc43: логічна функція — чи можна утворити трикутник з a,b,c
bool IsTriangle(double a, double b, double c);

// Proc14: процедура — правий циклічний зсув A->B, B->C, C->A
void ShiftRight3(double &A, double &B, double &C);

// Процедури-завдання (кожне — окремий сценарій з введенням/виводом)
void task_Proc14();   // правий циклічний зсув для двох трійок
void task_Proc43();   // перевірка трикутника для трьох наборів

// Меню
void show_menu();
void run_menu();


// =============================== main ===============================
int main() {
    cout << "ЛР №4 — Функції в C++ (варіанти: Proc14, Proc43)\n";
    run_menu();
    return 0;
}


// ============== ВИЗНАЧЕННЯ ФУНКЦІЙ (після main) ===================

// Proc43: умова існування трикутника — сума будь-яких двох сторін > третьої
bool IsTriangle(double a, double b, double c) {
    return (a > 0 && b > 0 && c > 0) &&
           (a + b > c) && (a + c > b) && (b + c > a);
}

// Proc14: правий циклічний зсув трьох чисел
void ShiftRight3(double &A, double &B, double &C) {
    double t = C;
    C = B;
    B = A;
    A = t;
}

// Завдання Proc14
void task_Proc14() {
    cout << "\n--- Proc14: Правий циклічний зсув для двох наборів ---\n";

    double A1, B1, C1, A2, B2, C2;

    cout << "Введіть перший набір (A1 B1 C1) у діапазоні [-100,100]: ";
    if (!(cin >> A1 >> B1 >> C1) ||
        fabs(A1) > 100 || fabs(B1) > 100 || fabs(C1) > 100)
    {
        cout << "Некоректні дані. Обчислення перервано.\n";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Введіть другий набір (A2 B2 C2) у діапазоні [-100,100]: ";
    if (!(cin >> A2 >> B2 >> C2) ||
        fabs(A2) > 100 || fabs(B2) > 100 || fabs(C2) > 100)
    {
        cout << "Некоректні дані. Обчислення перервано.\n";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // без циклів, як вимагається для завдання 1
    ShiftRight3(A1, B1, C1);
    ShiftRight3(A2, B2, C2);

    cout << "Після зсуву:\n";
    cout << "  Набір 1: " << A1 << " " << B1 << " " << C1 << "\n";
    cout << "  Набір 2: " << A2 << " " << B2 << " " << C2 << "\n";
}

// Завдання Proc43
void task_Proc43() {
    cout << "\n--- Proc43: Перевірка можливості утворити трикутник ---\n";

    auto read_set = [](const char* label, double &a, double &b, double &c)->bool{
        cout << "Введіть " << label << " (a b c), додатні, у межах (0,100]: ";
        if (!(cin >> a >> b >> c)) return false;
        return (a > 0 && b > 0 && c > 0 && a <= 100 && b <= 100 && c <= 100);
    };

    double a1,b1,c1,a2,b2,c2,a3,b3,c3;
    if (!read_set("набір 1",a1,b1,c1) ||
        !read_set("набір 2",a2,b2,c2) ||
        !read_set("набір 3",a3,b3,c3))
    {
        cout << "Некоректні дані. Обчислення перервано.\n";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Набір 1: " << (IsTriangle(a1,b1,c1) ? "Можна" : "Не можна") << " утворити трикутник\n";
    cout << "Набір 2: " << (IsTriangle(a2,b2,c2) ? "Можна" : "Не можна") << " утворити трикутник\n";
    cout << "Набір 3: " << (IsTriangle(a3,b3,c3) ? "Можна" : "Не можна") << " утворити трикутник\n";
}

// Меню
void show_menu() {
    cout << "\n=========== МЕНЮ ==========\n";
    cout << "1 — Proc14: Правий циклічний зсув (2 набори)\n";
    cout << "2 — Proc43: Чи можна утворити трикутник (3 набори)\n";
    cout << "0 — Вихід\n";
    cout << "Ваш вибір: ";
}

void run_menu() {
    while (true) {
        show_menu();
        int cmd;
        if (!(cin >> cmd)) { // захист від сміттєвого вводу
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Введіть номер пункту меню.\n";
            continue;
        }
        switch (cmd) {
            case 1: task_Proc14();  break;
            case 2: task_Proc43();  break;
            case 0: cout << "Готово. Успіхів!\n"; return;
            default: cout << "Невідомий пункт.\n";
        }
    }
}
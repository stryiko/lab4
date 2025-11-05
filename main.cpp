#include <iostream>
#include <limits>

// -------------------- ОГОЛОШЕННЯ (перед main) --------------------

// Proc14: правий циклічний зсув трійки чисел (вхід/вихідні параметри)
void ShiftRight3(double& A, double& B, double& C);

// Proc43: True, якщо зі сторін a,b,c можна утворити трикутник
bool IsTriangle(double a, double b, double c);

// Допоміжне: безпечне читання дійсного числа з діапазоном [-100;100]
bool readDouble(const char* prompt, double& x);

// Окремі «задачі» для демонстрації
void task_Proc14();
void task_Proc43();

int main() {
    std::cout << "Меню:\n"
                 "1 - Proc14: ShiftRight3 для двох наборiв\n"
                 "2 - Proc43: IsTriangle для трьох наборiв\n"
                 "0 - Вихiд\n"
              << std::endl;

    int choice;
    std::cout << "Ваш вибiр: ";
    if (!(std::cin >> choice)) return 0;

    switch (choice) {
        case 1: task_Proc14(); break;
        case 2: task_Proc43(); break;
        default: std::cout << "Вихiд." << std::endl; break;
    }

    return 0;
}

// -------------------- ВИЗНАЧЕННЯ (після main) --------------------

// Proc14: правий циклічний зсув (A->B, B->C, C->A)
void ShiftRight3(double& A, double& B, double& C) {
    double t = C;
    C = B;
    B = A;
    A = t;
}

// Proc43: умова існування трикутника (тільки додатні довжини)
bool IsTriangle(double a, double b, double c) {
    // Додатність та нерівності трикутника
    return (a > 0 && b > 0 && c > 0) &&
           (a < b + c && b < a + c && c < a + b);
}

// Ввід дійсного з контролем діапазону [-100;100]
bool readDouble(const char* prompt, double& x) {
    std::cout << prompt;
    if (!(std::cin >> x)) return false;
    if (x < -100.0 || x > 100.0) {
        std::cout << "Помилка: значення поза дiапазоном [-100;100].\n";
        return false;
    }
    return true;
}

// Демонстрація Proc14 для двох трійок: (A1,B1,C1) і (A2,B2,C2)
void task_Proc14() {
    std::cout << "\nProc14: правий циклiчний зсув трьох чисел (A->B, B->C, C->A)\n";

    double A1,B1,C1, A2,B2,C2;

    // Набір 1
    if (!readDouble("A1 = ", A1) ||
        !readDouble("B1 = ", B1) ||
        !readDouble("C1 = ", C1)) {
        std::cout << "Введення перервано.\n"; return;
    }
    ShiftRight3(A1,B1,C1);
    std::cout << "Пiсля зсуву (набір 1): A1=" << A1 << "  B1=" << B1 << "  C1=" << C1 << "\n\n";

    // Набір 2
    if (!readDouble("A2 = ", A2) ||
        !readDouble("B2 = ", B2) ||
        !readDouble("C2 = ", C2)) {
        std::cout << "Введення перервано.\n"; return;
    }
    ShiftRight3(A2,B2,C2);
    std::cout << "Пiсля зсуву (набір 2): A2=" << A2 << "  B2=" << B2 << "  C2=" << C2 << "\n";
}

// Демонстрація Proc43 для трьох наборів сторін
void task_Proc43() {
    std::cout << "\nProc43: перевiрка можливостi утворити трикутник (тiльки додатнi довжини)\n";

    double a1,b1,c1, a2,b2,c2, a3,b3,c3;

    // Набір 1
    if (!readDouble("a1 = ", a1) ||
        !readDouble("b1 = ", b1) ||
        !readDouble("c1 = ", c1)) { std::cout << "Введення перервано.\n"; return; }
    std::cout << "Набiр 1 -> " << (IsTriangle(a1,b1,c1) ? "True" : "False") << "\n\n";

    // Набір 2
    if (!readDouble("a2 = ", a2) ||
        !readDouble("b2 = ", b2) ||
        !readDouble("c2 = ", c2)) { std::cout << "Введення перервано.\n"; return; }
    std::cout << "Набiр 2 -> " << (IsTriangle(a2,b2,c2) ? "True" : "False") << "\n\n";

    // Набір 3
    if (!readDouble("a3 = ", a3) ||
        !readDouble("b3 = ", b3) ||
        !readDouble("c3 = ", c3)) { std::cout << "Введення перервано.\n"; return; }
    std::cout << "Набiр 3 -> " << (IsTriangle(a3,b3,c3) ? "True" : "False") << "\n";
}

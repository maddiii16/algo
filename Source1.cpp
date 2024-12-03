#include <iostream>
#include <string>

using namespace std;

// Проверка корректности ввода числа
int checking_command_number() {
    int number;
    while (true) {
        cin >> number;
        if (!cin.fail() && cin.peek() == '\n') { // Проверка ввода
            return number;
        }
        cout << "Ошибка! Введите корректное число: ";
        cin.clear();
        cin.ignore(10000, '\n'); // Очищаем буфер ввода
    }
}

// Главное меню
int menu() {
    int k = -1;
    while (true) {
        cout << "///////  Меню  ///////" << endl
            << "1. Добавить трубу" << endl
            << "2. Добавить КС" << endl
            << "3. Просмотр объектов" << endl
            << "4. Редактировать трубу" << endl
            << "5. Редактировать КС" << endl
            << "6. Сохранить данные" << endl
            << "7. Загрузить данные" << endl
            << "0. Выход" << endl
            << "Введите команду которую вы бы хотели выполнить (от 0 до 7): ";
        k = checking_command_number(); // Вызов функции без аргументов
        if (k >= 0 && k <= 7) { // Проверяем диапазон
            switch (k) {
            case 1:
                cout << "Вы выбрали: Добавить трубу" << endl;
                break;
            case 2:
                cout << "Вы выбрали: Добавить КС" << endl;
                break;
            case 3:
                cout << "Вы выбрали: Просмотр объектов" << endl;
                break;
            case 4:
                cout << "Вы выбрали: Редактировать трубу" << endl;
                break;
            case 5:
                cout << "Вы выбрали: Редактировать КС" << endl;
                break;
            case 6:
                cout << "Вы выбрали: Сохранить данные" << endl;
                break;
            case 7:
                cout << "Вы выбрали: Загрузить данные" << endl;
                break;
            case 0:
                cout << "Вы выбрали: Выход. Завершение программы." << endl;
                return 0;
            }
        }
        else {
            cout << "Ошибка! Введите число от 0 до 7." << endl;
        }
    }
}

// Точка входа
int main() {
    menu(); // Запуск меню
    return 0;
}

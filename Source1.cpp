#include <iostream>
#include <string>

using namespace std;

// �������� ������������ ����� �����
int checking_command_number() {
    int number;
    while (true) {
        cin >> number;
        if (!cin.fail() && cin.peek() == '\n') { // �������� �����
            return number;
        }
        cout << "������! ������� ���������� �����: ";
        cin.clear();
        cin.ignore(10000, '\n'); // ������� ����� �����
    }
}

// ������� ����
int menu() {
    int k = -1;
    while (true) {
        cout << "///////  ����  ///////" << endl
            << "1. �������� �����" << endl
            << "2. �������� ��" << endl
            << "3. �������� ��������" << endl
            << "4. ������������� �����" << endl
            << "5. ������������� ��" << endl
            << "6. ��������� ������" << endl
            << "7. ��������� ������" << endl
            << "0. �����" << endl
            << "������� ������� ������� �� �� ������ ��������� (�� 0 �� 7): ";
        k = checking_command_number(); // ����� ������� ��� ����������
        if (k >= 0 && k <= 7) { // ��������� ��������
            switch (k) {
            case 1:
                cout << "�� �������: �������� �����" << endl;
                break;
            case 2:
                cout << "�� �������: �������� ��" << endl;
                break;
            case 3:
                cout << "�� �������: �������� ��������" << endl;
                break;
            case 4:
                cout << "�� �������: ������������� �����" << endl;
                break;
            case 5:
                cout << "�� �������: ������������� ��" << endl;
                break;
            case 6:
                cout << "�� �������: ��������� ������" << endl;
                break;
            case 7:
                cout << "�� �������: ��������� ������" << endl;
                break;
            case 0:
                cout << "�� �������: �����. ���������� ���������." << endl;
                return 0;
            }
        }
        else {
            cout << "������! ������� ����� �� 0 �� 7." << endl;
        }
    }
}

// ����� �����
int main() {
    menu(); // ������ ����
    return 0;
}

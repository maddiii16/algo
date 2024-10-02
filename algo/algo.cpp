#include <iostream>
#include <string>

using namespace std;

struct pipe
{
    string name;
    float length;
    int diametr;
    bool repair;
};

struct compression_station
{
    string name;
    int shopsnumber;
    int workinshopnumber;
    int effectiveness;
};

int checking_command_number()
{
    int number;
    cin >> number;
    while (true)
    {
        if ((!(cin >> number) || (cin.peek() != '\n')) && 0 < number && number > 7);
        {
            cout << "ќшибка! ¬ведите корректное число от 0 до 7";
            cin.clear();
            cin.ignore(max, '\n');
        }
        cin >> number;
    }
    return number;
}

int menu()
{

}
#include <iostream>
#include <string>

using namespace std;

struct pipe
{
    string name = "";
    float length = 0.0;
    int diameter = 0;
    bool repair = 0;
};

struct compression_station
{
    string name = "";
    int shopsnumber = 0;
    int workinshopnumber = 0;
    int effectiveness = 0;
};

template <typename T>
T checking_number(T a, T b)
{
    T number = 0;
    while ((cin >> number).fail() || cin.peek() != '\n' || number < a || number > b) {
            cout << "Error! Incorrect number. Try again: ";
            cin.clear();
            cin.ignore(77777, '\n');
    }
    return number;
}

pipe add_pipe() {
    pipe new_pipe;

    cout << "Enter the pipe name: ";
    cin.ignore();
    getline(cin, new_pipe.name);
    cout << "Enter the length of the pipe: ";
    new_pipe.length = checking_number(0.0, 100000.0);
    cout << "Enter the diameter of the pipe: ";
    new_pipe.diameter = checking_number(1, 50000);
    cout << "Enter the repair of the pipe (0 = not in repair, 1 = in repair): ";
    new_pipe.repair = checking_number(0, 1);

    return new_pipe;
}

compression_station add_cs() {
    compression_station new_cs;

    cout << "Enter the compression_station name: ";
    cin.ignore();
    getline(cin, new_cs.name);
    cout << "Enter the number of workshops: ";
    new_cs.shopsnumber = checking_number(0, 100000000);
    cout << "Enter the number of workshops in operation:";
    new_cs.workinshopnumber = checking_number(0, new_cs.shopsnumber);
    cout << "Enter the CS efficiency factor (from 0 to 100): ";
    new_cs.effectiveness = checking_number(0.0, 100.0);

    return new_cs;
}

void view_pipe(pipe new_pipe) {
    if (new_pipe.name == "") {
        cout << "Error! No pipe has been added yet." << endl;
    }
    else {
        cout << "Pipe Information" << endl;
        cout << "Name: " << new_pipe.name << endl;
        cout << "Length: " << new_pipe.length << endl;
        cout << "Diameter: " << new_pipe.diameter << endl;
        cout << "Status: " << (new_pipe.repair ? "In repair" : "Not in repair") << endl;
        cout << "" << endl;
    }
}

void view_cs(compression_station new_cs) {
    if (new_cs.name == "") {
        cout << "Error! No compression station has been added yet." << endl;
    }
    else {
        cout << "Compression Station Information" << endl;
        cout << "Name: " << new_cs.name << endl;
        cout << "Total workshops: " << new_cs.shopsnumber << endl;
        cout << "Workshops in operation: " << new_cs.workinshopnumber << endl;
        cout << "Efficiency factor: " << new_cs.effectiveness << "%" << endl;
    }
}

void edit_pipe(pipe new_pipe) {
    if (new_pipe.name == "") {
        cout << "Error! No pipe has been added yet." << endl;
    }
    else {
        cout << "Current repair status: " << (new_pipe.repair ? "In repair" : "Not in repair") << endl;
        cout << "Enter the new repair status (0 = not in repair, 1 = in repair): ";
        new_pipe.repair = checking_number(0, 1);
        cout << "The repair status has been updated to: " << (new_pipe.repair ? "In repair" : "Not in repair") << endl;
    }
}

void edit_cs_work(compression_station new_cs) {
    if (new_cs.name == "") {
        cout << "Error! No compression station has been added yet." << endl;
    }
    else {
        cout << "The current state of the CS operation: number of workshops - " << (new_cs.shopsnumber) << ", number of workshops in operation - " << (new_cs.workinshopnumber) << endl;
        cout << "Enter a new number of workshops in operation): ";
        new_cs.workinshopnumber = checking_number(0, new_cs.shopsnumber);
        cout << "The job status has been updated to: number of workshops - " << (new_cs.shopsnumber) << ", number of workshops in operation - " << (new_cs.workinshopnumber) << endl;
    }
}



int main() {
    pipe new_pipe;
    compression_station new_cs;

    int k = -1;
    while (true) {
        cout << "     Menu" << endl
            << "1. Add the pipe" << endl
            << "2. Add CS" << endl
            << "3. Viewing objects" << endl
            << "4. Edit the pipe" << endl
            << "5. Edit CS" << endl
            << "6. Save data" << endl
            << "7. Upload data" << endl
            << "0. Exit" << endl
            << "Enter the command you would like to execute (from 0 to 7): ";
        k = checking_number(0, 7);
        switch (k) {
        case 1:
            cout << "You have chosen: Add the pipe" << endl;
            new_pipe = add_pipe();
            break;
        case 2:
            cout << "You have chosen: Add CS" << endl;
            new_cs = add_cs();
            break;
        case 3:
            cout << "You have chosen: Viewing objects" << endl;
            view_pipe(new_pipe);
            view_cs(new_cs);
            break;
        case 4:
            cout << "You have chosen: Edit the pipe" << endl;
            edit_pipe(new_pipe);
            break;
        case 5:
            cout << "You have chosen: Edit CS" << endl;
            edit_cs_work(new_cs);
            break;
        case 6:
            cout << "You have chosen: Save data" << endl;
            break;
        case 7:
            cout << "You have chosen: Upload data" << endl;
            break;
        case 0:
            cout << "You have chosen: Exit. Completion of the program." << endl;
            return 0;
        }
    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void provide_information(){
    cout << "Welcome to mini Expression Calculator!\n"
"\n"
"This calculator supports simple operations with two numbers.\n"
"\n"
"Usage:\n"
"  <program_name> <first_number> <operator> <second_number>\n"
"\n"
"Example:\n"
"  <program_name> 12 + 5\n"
"\n"
"Commands:\n"
"  help     Show this help message\n"
"  history  Show saved calculation history\n"
"  clear    Clear saved calculation history\n"
"\n"
"Supported operators:\n"
"  +   Add\n"
"  -   Subtract\n"
"  *   Multiply\n"
"  /   Divide\n"
"\n"
"Important:\n"
"  - Only expressions with two numbers are supported.\n"
"  - Division by zero is not allowed.\n"
"  - Invalid input will produce an error message.\n";
}

void provide_history(){
    ifstream file("history.txt");
    string line;
    while (getline(file, line)){
        cout << line;
        cout << "\n";
    }
    file.close();
}

void clear_history(){
    ofstream file("history.txt");
    file.close();
}

void store(string operation){
    ofstream file("history.txt", ios::app);
    file << operation << "\n";
    file.close();
}

bool p_converting(string element){
    bool n = false;
    bool p = true;
    for (int i = 0; i < element.length(); i++){
        if (element[i] >= 48 && element[i] <= 57){
            n = true;
            continue;
        }
        else if ((n && p) && (element[i] == '.')){
            p = false;
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

int main(int argc, char const* argv[]) {

    if (argc == 1){
        cout << "No commands\n";
        return 1;
    }
    string first_element = argv[1];
    if (argc == 2){
        if (first_element == "help"){
            provide_information();
            return 0;
        }
        else if (first_element == "history"){
            provide_history();
            return 0;
        }
        else if (first_element == "clear"){
            clear_history();
            return 0;
        }
        else {
            cout << "Incorrect input. If you want help, write help.\n";
            return 1;
        }
    }
    else if (argc == 4){
        if (!p_converting(first_element)) {
            cout << "Incorrect input. If you want help, write help.\n";
            return 1;
        }
        if (!p_converting(argv[3])){
            cout << "Incorrect input. If you want help, write help.\n";
            return 1;
        }
        string operation = argv[2];
        double fn = stod(first_element);
        double sn = stod(argv[3]);
        if (operation == "+"){
            cout << fn << " + " << sn << " = " << fn + sn << "\n";
            store(to_string(fn) + " + " + to_string(sn) + " = " + to_string(fn + sn));
        }
        else if (operation == "-"){
            cout << fn << " - " << sn << " = " << fn - sn << "\n";
            store(to_string(fn) + " - " + to_string(sn) + " = " + to_string(fn - sn));
        }
        else if (operation == "*"){
            cout << fn << " * " << sn << " = " << fn * sn << "\n";
            store(to_string(fn) + " * " + to_string(sn) + " = " + to_string(fn * sn));
        }
        else if (operation == "/"){
            if (sn == 0){
                cout << "Incorrect input. If you want help, write help.\n";
                return 1;
            }
            cout << fn << " / " << sn << " = " << fn / sn << "\n";
            store(to_string(fn) + " / " + to_string(sn) + " = " + to_string(fn / sn));
        }
        else {
            cout << "Incorrect input. If you want help, write help.\n";
            return 1;
        } 
    }
    else {
        cout << "Incorrect input. If you want help, write help.\n";
        return 1;
    }
    return 0;
}
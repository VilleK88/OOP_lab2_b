#include <iostream>
#include <string>
#include "utils/RunningAverage.h"
using namespace std;

int INPUT_LEN = 32;
string handle_input();
bool get_input(string& user_input);
bool validate_integer(const string& user_input, int& num);

int main() {
    RunningAverage run_avg(0);
    bool continue_loop = true;
    while (continue_loop) {
        string user_input = handle_input();
        int num = 0;
        if (validate_integer(user_input, num)) {
            if (num != 0) {
                run_avg.add_value(num);
                run_avg.print_list();
                const double avg = run_avg.get_average();
                cout << "Average: " << avg << "\n";
            }
            else
                continue_loop = false;
        }
    }

    return 0;
}

string handle_input() {
    string user_input;
    bool input_received = false;
    while (!input_received) {
        cout << "Enter number: ";
        input_received = get_input(user_input);
    }
    return user_input;
}

bool get_input(string& user_input) {
    if (getline(cin, user_input)) {
        if (user_input.size() > INPUT_LEN) {
            cout << "Input too long (max " << INPUT_LEN << " characters).\n";
            return false;
        }
        if (user_input.empty()) {
            cout << "Empty input.\n";
            return false;
        }
        return true;
    }
    return false;
}

bool validate_integer(const string& user_input, int& num) {
    try {
        size_t index = 0;
        const int value = stoi(user_input, &index);
        if (index != user_input.length()) {
            cout << "Error: only numbers allowed.\n";
            return false;
        }
        num = value;
        return true;
    }
    catch (const invalid_argument&) {
        cout << "Error: only numbers allowed.\n";
        return false;
    }
}
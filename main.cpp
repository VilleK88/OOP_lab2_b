#include <iostream>
#include <string>
#include "utils/RunningAverage.h"

int constexpr INPUT_LEN = 32;
std::string handle_input();
bool get_input(std::string& user_input);
bool validate_integer(const std::string& user_input, int& num);

int main() {
    RunningAverage run_avg(5);
    bool continue_loop = true;
    while (continue_loop) {
        std::string user_input = handle_input();
        int num = 0;
        if (validate_integer(user_input, num)) {
            if (num != 0) {
                run_avg.add_value(num);
                const double avg = run_avg.get_average();
                std::cout << "Average: " << avg << ".\n";
            }
            else {
                const double avg = run_avg.get_average();
                std::cout << "Average: " << avg << ".\n";
                continue_loop = false;
            }
        }
    }
    return 0;
}

std::string handle_input() {
    std::string user_input;
    bool input_received = false;
    while (!input_received) {
        std::cout << "Enter number: ";
        input_received = get_input(user_input);
    }
    return user_input;
}

bool get_input(std::string& user_input) {
    if (getline(std::cin, user_input)) {
        if (user_input.size() > INPUT_LEN) {
            std::cout << "Input too long (max " << INPUT_LEN << " characters).\n";
            return false;
        }
        if (user_input.empty()) {
            std::cout << "Empty input.\n";
            return false;
        }
        return true;
    }
    return false;
}

bool validate_integer(const std::string& user_input, int& num) {
    try {
        size_t index = 0;
        const int value = stoi(user_input, &index);
        if (index != user_input.length()) {
            std::cout << "Error: only integer numbers allowed.\n";
            return false;
        }
        num = value;
        return true;
    }
    catch (const std::invalid_argument&) {
        std::cout << "Error: only integer numbers allowed.\n";
        return false;
    }
}
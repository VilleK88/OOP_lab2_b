#include "RunningAverage.h"
#include <iostream>
#include <deque>

RunningAverage::RunningAverage(const int initial_speed) {
    speed = initial_speed;
}

deque<int> RunningAverage::get_list() {
    return num_list;
}

void RunningAverage::print_list() const {
    const int len = static_cast<int>(num_list.size());
    for (int i = 0; i < len; i++) {
        if (i + 1 < len)
            cout << num_list[i] << ", ";
        else
            cout << num_list[i] << ".\n";
    }
}

void RunningAverage::add_value(const int num) {
    if (num_list.size() < 5) {
        num_list.push_back(num);
    }
    else {
        num_list.erase(num_list.begin());
        num_list.push_back(num);
    }
}

double RunningAverage::get_average() const {
    double sum = 0;
    for (const int num : num_list) {
        sum += static_cast<double>(num);
    }
    const double avg = sum / static_cast<double>(num_list.size());
    return avg;
}
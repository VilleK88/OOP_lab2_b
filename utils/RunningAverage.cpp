#include "RunningAverage.h"
#include <iostream>
#include <deque>

RunningAverage::RunningAverage(const int size) {
    deque_size = size;
}

deque<int> RunningAverage::get_list() {
    return num_list;
}

void RunningAverage::print_list_and_avg() const {
    const int len = static_cast<int>(num_list.size());
    for (int i = 0; i < len; i++) {
        if (i + 1 < len)
            cout << num_list[i] << ", ";
        else
            cout << num_list[i] << ".\n";
    }

    const double avg = get_average();
    cout << "Average: " << avg << "\n";
}

void RunningAverage::add_value(const int num) {
    if (num_list.size() < deque_size) {
        num_list.push_back(num);
    }
    else {
        num_list.pop_front();
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

bool RunningAverage::list_is_empty() const {
    if (num_list.empty())
        return true;
    return false;
}
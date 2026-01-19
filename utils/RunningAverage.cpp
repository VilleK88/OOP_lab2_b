#include <iostream>
#include <vector>
#include "RunningAverage.h"

RunningAverage::RunningAverage(const float initial_speed) {
    speed = initial_speed;
}

void RunningAverage::accelerate(const float amount) {
    speed += amount;
}

float RunningAverage::getSpeed() const {
    return speed;
}

vector<float> RunningAverage::get_list() {
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

void RunningAverage::add_to_list(const float num) {
    if (num_list.size() < 5) {
        num_list.push_back(num);
    }
    else {
        num_list.erase(num_list.begin());
        num_list.push_back(num);
    }
}

float RunningAverage::calc_avg() const {
    float sum = 0;
    for (const float num : num_list) {
        sum += num;
    }
    const float avg = sum / static_cast<float>(num_list.size());
    return avg;
}
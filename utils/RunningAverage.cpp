#include "RunningAverage.h"
#include <deque>

RunningAverage::RunningAverage(const int size) : deque_size(size){}

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
    if (!num_list.empty()) {
        double sum = 0;
        for (const int num : num_list) {
            sum += static_cast<double>(num);
        }
        const double avg = sum / static_cast<double>(num_list.size());
        return avg;
    }
    return 0;
}
#ifndef RUNNINGAVERAGE_H
#define RUNNINGAVERAGE_H
#include <deque>

class RunningAverage {
private:
    std::deque<int> num_list;
    int deque_size;
public:
    explicit RunningAverage(int size);
    void add_value(int num);
    [[nodiscard]] double get_average() const;
};

#endif
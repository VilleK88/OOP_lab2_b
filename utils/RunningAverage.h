#ifndef RUNNINGAVERAGE_H
#define RUNNINGAVERAGE_H
#include <deque>
using namespace std;

class RunningAverage {
private:
    deque<int> num_list;
    int deque_size;
public:
    explicit RunningAverage(int size);
    deque<int> get_list() ;
    void print_list_and_avg() const;
    void add_value(int num);
    [[nodiscard]] double get_average() const;
    [[nodiscard]] bool list_is_empty() const;
};

#endif
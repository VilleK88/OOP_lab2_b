#ifndef RUNNINGAVERAGE_H
#define RUNNINGAVERAGE_H
#include <deque>
using namespace std;

class RunningAverage {
private:
    deque<int> num_list;
    int speed;
public:
    explicit RunningAverage(int initial_speed);
    deque<int> get_list() ;
    void print_list() const;
    void add_value(int num);
    [[nodiscard]] double get_average() const;
};

#endif
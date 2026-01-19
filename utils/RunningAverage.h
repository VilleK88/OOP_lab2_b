#ifndef RUNNINGAVERAGE_H
#define RUNNINGAVERAGE_H
#include <vector>
using namespace std;

class RunningAverage {
private:
    vector<float> num_list;
    float speed;
public:
    explicit RunningAverage(float initial_speed);
    void accelerate(float amount);
    [[nodiscard]] float getSpeed() const;
    vector<float> get_list() ;
    void print_list() const;
    void add_to_list(float num);
    [[nodiscard]] float calc_avg() const;
};

#endif
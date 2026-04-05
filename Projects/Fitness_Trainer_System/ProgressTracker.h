#ifndef PROGRESSTRACKER_H
#define PROGRESSTRACKER_H

#include <string>
using namespace std;

class ProgressTracker {
private:
    double weight;
    double bodyFat;
    int workoutDays;

public:
    ProgressTracker();

    void setWeight(double w);
    void setBodyFat(double bf);
    void setWorkoutDays(int days);

    double getWeight() const;
    double getBodyFat() const;
    int getWorkoutDays() const;

    bool saveToFile(const string& filename);
    bool loadFromFile(const string& filename);
};

#endif

#include "ProgressTracker.h"
#include <fstream>

// Constructor
ProgressTracker::ProgressTracker() : weight(0), bodyFat(0), workoutDays(0) {}

// Setters
void ProgressTracker::setWeight(double w) { weight = w; }
void ProgressTracker::setBodyFat(double bf) { bodyFat = bf; }
void ProgressTracker::setWorkoutDays(int days) { workoutDays = days; }

// Getters
double ProgressTracker::getWeight() const { return weight; }
double ProgressTracker::getBodyFat() const { return bodyFat; }
int ProgressTracker::getWorkoutDays() const { return workoutDays; }

// Save to file
bool ProgressTracker::saveToFile(const string& filename) {
    ofstream fout(filename);
    if (!fout) return false;

    fout << weight << "\n" << bodyFat << "\n" << workoutDays << "\n";
    fout.close();
    return true;
}

// Load from file
bool ProgressTracker::loadFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin) return false;

    fin >> weight >> bodyFat >> workoutDays;
    fin.close();
    return true;
}

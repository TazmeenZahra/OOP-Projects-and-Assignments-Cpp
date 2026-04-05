#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
using namespace std;

class UserProfile {
private:
    string name;
    char gender;
    double height;
    double weight;
    int age;
    string activityLevel;
    double targetWeight;

public:
    UserProfile(const string &name, char gender, double height, double weight,
                int age, const string &activityLevel, double targetWeight = 0)
        : name(name), gender(gender), height(height), weight(weight),
          age(age), activityLevel(activityLevel), targetWeight(targetWeight) {}

    string getName() const { return name; }
    char getGender() const { return gender; }
    double getHeight() const { return height; }
    double getWeight() const { return weight; }
    int getAge() const { return age; }
    string getActivityLevel() const { return activityLevel; }
    double getTargetWeight() const { return targetWeight; }

    double calculateBMI() const {
        return weight / ((height / 100) * (height / 100));
    }

    double calculateBMR() const {
        if (gender == 'M')
            return 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
        return 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
    }

    double calculateDailyCalories() const {
        double bmr = calculateBMR();
        if (activityLevel == "sedentary") return bmr * 1.2;
        if (activityLevel == "moderate") return bmr * 1.55;
        if (activityLevel == "active") return bmr * 1.725;
        return bmr * 1.9;
    }

    void updateWeight(double newWeight) {
        weight = newWeight;
        cout << "Weight updated to: " << weight << " kg\n";
    }

    void displayProfile() const {
        cout << "\n=== User Profile ===" << endl;
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Age: " << age << endl;
        cout << "Activity Level: " << activityLevel << endl;
        cout << "Target Weight: " << targetWeight << " kg" << endl;
        cout << "BMI: " << calculateBMI() << endl;
        cout << "Daily Calorie Needs: " << calculateDailyCalories() << " kcal" << endl;
    }
};

#endif

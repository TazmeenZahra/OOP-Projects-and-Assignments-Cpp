#include <iostream>
#include <string>
#include "Member.h"
#include "NutritionPlan.h"
#include "ExercisePlan.h"
#include "ProgressTracker.h"


using namespace std;

void displayMainMenu() {
    cout << "\n=== Fitness Tracker Main Menu ===" << endl;
    cout << "1. View Profile" << endl;
    cout << "2. Nutrition Plan" << endl;
    cout << "3. Exercise Plan" << endl;
    cout << "4. Track Progress" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    // === Setup ===
    cout << "=== Fitness Tracker Setup ===" << endl;
    string name;
    char gender;
    double height, weight, targetWeight;
    int age;
    string activityLevel;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Gender (M/F): ";
    cin >> gender;
    cout << "Height (cm): ";
    cin >> height;
    cout << "Current weight (kg): ";
    cin >> weight;
    cout << "Target weight (kg): ";
    cin >> targetWeight;
    cout << "Age: ";
    cin >> age;
    cout << "Activity level (sedentary/moderate/active/superactive): ";
    cin >> activityLevel;
    cin.ignore(); // Clear newline

    // === Initialize classes ===
    UserProfile user(name, gender, height, weight, age, activityLevel, targetWeight);
    NutritionPlan nutrition;
    ExercisePlan exercise;
    ProgressTracker progress;

    // Try to load previous progress
    if (progress.loadFromFile("progress.txt")) {
        cout << "\nPrevious progress loaded successfully.\n";
    } else {
        cout << "\nNo saved progress found.\n";
    }

    // === Main Menu Loop ===
    int choice;
    do {
        displayMainMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            user.displayProfile();
            break;

        case 2: {
            cout << "\n=== Nutrition Plan ===" << endl;
            double dailyCalories = user.calculateDailyCalories();
            cout << "Daily Calorie Target: " << dailyCalories << " kcal\n";
            nutrition.generateMealPlan(dailyCalories);
            nutrition.displayFoodDatabase();
            break;
        }

        case 3: {
            cout << "\n=== Exercise Plan ===" << endl;
            string goal = (user.getWeight() > user.getTargetWeight()) ? "weight loss" : "muscle gain";
            cout << "Goal: " << goal << endl;
            exercise.generateWorkoutPlan(goal, 5);
            exercise.displayExerciseDatabase();
            break;
        }

        case 4: {
            cout << "\n=== Track Progress ===" << endl;
            double w, bf;
            int days;
            cout << "Enter current weight (kg): ";
            cin >> w;
            cout << "Enter body fat percentage: ";
            cin >> bf;
            cout << "Enter workout days this week: ";
            cin >> days;
            cin.ignore();

            progress.setWeight(w);
            progress.setBodyFat(bf);
            progress.setWorkoutDays(days);

            if (progress.saveToFile("progress.txt"))
                cout << "Progress saved successfully.\n";
            else
                cout << "Error saving progress.\n";

            cout << "\n=== Current Progress ===" << endl;
            cout << "Weight: " << progress.getWeight() << " kg\n";
            cout << "Body Fat: " << progress.getBodyFat() << " %\n";
            cout << "Workout Days: " << progress.getWorkoutDays() << "\n";
            break;
        }

        case 5:
            cout << "Exiting Fitness Tracker. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

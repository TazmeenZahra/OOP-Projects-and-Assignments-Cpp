#include <iostream>
#include <string>
#include "ExercisePlan.h"
using namespace std;

struct Exercise
{
    string name;
    int caloriesPerHour;
    string intensity;
    string muscleGroup;
    string equipment;
};

class ExercisePlan
{
private:
    Exercise exerciseDatabase[20];
    int exerciseCount;

public:
    ExercisePlan() : exerciseCount(0)
    {
        initializeDatabase();
    }

    void initializeDatabase()
    {
        // Cardio exercises
        addExerciseToDatabase("Running (8 km/h)", 600, "high", "cardio", "none");
        addExerciseToDatabase("Cycling (15 km/h)", 500, "medium", "cardio", "bicycle");
        addExerciseToDatabase("Swimming", 400, "medium", "full body", "none");

        // Strength exercises
        addExerciseToDatabase("Weight Training", 300, "medium", "full body", "weights");
        addExerciseToDatabase("Push-ups", 350, "medium", "upper body", "none");
        addExerciseToDatabase("Squats", 400, "medium", "lower body", "none");
    }

    void addExerciseToDatabase(string name, int calories, string intensity,
                               string muscleGroup, string equipment)
    {
        if (exerciseCount < 20)
        {
            exerciseDatabase[exerciseCount] = {name, calories, intensity, muscleGroup, equipment};
            exerciseCount++;
        }
    }

    void generateWorkoutPlan(string goal, int days)
    {
        cout << "\n=== " << days << "-Day " << goal << " Workout Plan ===" << endl;

        if (goal == "weight loss")
        {
            cout << "\nFocus: High-intensity cardio with some strength training" << endl;
            for (int i = 1; i <= days; i++)
            {
                cout << "\nDay " << i << ": ";
                if (i % 2 == 0)
                {
                    cout << "30 min Running + 20 min Weight Training" << endl;
                }
                else
                {
                    cout << "45 min Cycling + Core Exercises" << endl;
                }
            }
        }
        else
        { // muscle gain
            cout << "\nFocus: Strength training with progressive overload" << endl;
            for (int i = 1; i <= days; i++)
            {
                cout << "\nDay " << i << ": ";
                if (i % 2 == 0)
                {
                    cout << "Upper Body (Push-ups, Pull-ups, Bench Press)" << endl;
                }
                else
                {
                    cout << "Lower Body (Squats, Deadlifts, Lunges)" << endl;
                }
            }
        }

        cout << "\nRest Days: 1-2 days per week for recovery" << endl;
    }

    int calculateCaloriesBurned(string exercise, double duration)
    {
        for (int i = 0; i < exerciseCount; i++)
        {
            if (exerciseDatabase[i].name == exercise)
            {
                return exerciseDatabase[i].caloriesPerHour * duration;
            }
        }
        return 0;
    }

    void displayExerciseDatabase()
    {
        cout << "\n=== Exercise Database ===" << endl;
        for (int i = 0; i < exerciseCount; i++)
        {
            cout << exerciseDatabase[i].name << ": "
                 << exerciseDatabase[i].caloriesPerHour << " kcal/hour, "
                 << exerciseDatabase[i].intensity << " intensity, "
                 << exerciseDatabase[i].muscleGroup << ", "
                 << "Equipment: " << exerciseDatabase[i].equipment << endl;
        }
    }
};

#include <iostream>
#include <string>
#include "NutritionPlan.h"
using namespace std;

struct FoodItem 
{
    string name;
    int calories;
    double protein;
    double carbs;
    double fats;
};

class NutritionPlan
{
private:
    FoodItem foodDatabase[50];
    int foodCount;

public:
    NutritionPlan() : foodCount(0)
    {
        initializeDatabase();
    }

    void initializeDatabase()
    {
        // Basic foods
        addFoodToDatabase("Apple", 52, 0.3, 14.0, 0.2);
        addFoodToDatabase("Banana", 89, 1.1, 22.8, 0.3);
        addFoodToDatabase("Chicken Breast", 165, 31.0, 0.0, 3.6);
        addFoodToDatabase("Salmon", 208, 20.0, 0.0, 13.0);
        addFoodToDatabase("Brown Rice", 112, 2.6, 23.5, 0.9);
    }

    void addFoodToDatabase(string name, int calories, double protein, double carbs, double fats)
    {
        if (foodCount < 50)
        {
            foodDatabase[foodCount] = {name, calories, protein, carbs, fats};
            foodCount++;
        }
    }

    FoodItem *searchFood(string name)
    {
        for (int i = 0; i < foodCount; i++)
        {
            if (foodDatabase[i].name == name)
            {
                return &foodDatabase[i];
            }
        }
        return nullptr;
    }

    void generateMealPlan(double targetCalories)
    {
        cout << "\n=== Suggested Meal Plan (~" << targetCalories << " kcal) ===" << endl;

        // Breakfast
        double breakfastCal = targetCalories * 0.25;
        cout << "\nBreakfast (" << breakfastCal << " kcal):" << endl;
        cout << "- Oatmeal with banana and almonds" << endl;
        cout << "- Greek yogurt" << endl;

        // Lunch
        double lunchCal = targetCalories * 0.35;
        cout << "\nLunch (" << lunchCal << " kcal):" << endl;
        cout << "- Grilled chicken breast" << endl;
        cout << "- Brown rice" << endl;
        cout << "- Steamed vegetables" << endl;

        // Dinner
        double dinnerCal = targetCalories * 0.3;
        cout << "\nDinner (" << dinnerCal << " kcal):" << endl;
        cout << "- Baked salmon" << endl;
        cout << "- Quinoa" << endl;
        cout << "- Salad" << endl;

        // Snacks
        double snackCal = targetCalories * 0.1;
        cout << "\nSnacks (" << snackCal << " kcal):" << endl;
        cout << "Mixed nuts" << endl;
        cout << "Fresh fruits" << endl;
    }

    void displayFoodDatabase()
    {
        cout << "\n=== Food Database ===" << endl;
        for (int i = 0; i < foodCount; i++)
        {
            cout << foodDatabase[i].name << ": "
                 << foodDatabase[i].calories << " kcal, "
                 << "P:" << foodDatabase[i].protein << "g, "
                 << "C:" << foodDatabase[i].carbs << "g, "
                 << "F:" << foodDatabase[i].fats << "g" << endl;
        }
    }
};

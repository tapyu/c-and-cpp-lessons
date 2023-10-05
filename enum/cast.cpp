#include <iostream>

using namespace std;

// Define an enum named 'Color' with three named constants.
enum class Color
{
    RED,
    GREEN,
    BLUE
};

enum Constants
{
    DEFAULT_VALUE = 0,
    GRAVITY = 10
};

int main() {
    // Declare a variable of type 'Color' and initialize it with 'Color::GREEN'.
    Color selected_color = Color::BLUE;


    // Check the value of 'selected_color' and perform actions accordingly.
    switch (selected_color) {
        case Color::RED:
            cout << "You selected Red." << endl;
            break;
        case Color::GREEN:
            cout << "You selected Green." << endl;
            break;
        case Color::BLUE:
            cout << "You selected BLUE." << endl;
            break;
        default:
            cout << "Invalid color selection." << endl;
            break;
    }

    Constants status = DEFAULT_VALUE;
    
    int istatus         = status; // `enum` values can be used without explicit casting (i.e., implicit casting) in most contexts (bad)
    int iselected_color = static_cast<int>(selected_color); // `enum class` require explicit casting when used in contexts where an integral value is expected (good)

    cout << "The integer of the status is "         << istatus         << endl;
    cout << "The integer of the selected_color is " << iselected_color << endl;

    return 0;
}
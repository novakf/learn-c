#include <iostream>
#include "lib.cpp"

int main() {
    int orig_hours, b;

    std::cin >> orig_hours >> b;

    int converted_hours = convert_hours(orig_hours);

    if (converted_hours < 0 || converted_hours > 12 || b < 0 || b > 59) { 
        std::cout << "введены недопустимые данные"; 
        return 1;
    }

    std::cout << converted_hours;
    psep();

    std::cout << choose_ending(hour_words, converted_hours);
    psep();

    if (b != 0) {
        std::cout << b;
        psep();
        
        std::cout << choose_ending(minute_words, b);
        psep();
    }

    print_day_stage(orig_hours, b);

    return 0;
}

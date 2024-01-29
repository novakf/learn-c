enum day_enum {MORNING, DAY, EVENING, NIGHT,};

const char *hour_words[3] = {"час", "часа", "часов"};
const char *minute_words[3] = {"минута", "минуты", "минут"};
const char *day_stage[4] = {"утра", "дня", "вечера", "ночи"};

const char *choose_ending(const char **words, int num) {
    if (num == 11 || num == 12 || num == 13 || num == 14) return words[2];

    if (num % 10 == 1) return words[0];
    else if (num % 10 > 1 && num % 10 < 5) return words[1];
    else return words[2];
};

int convert_hours(int hours) {
    return hours % 12;
}

void psep() {
    std::cout << ' ';
}

int is_morning(int hours) {
    return hours > 5 && hours < 12; 
}

int is_day(int hours) {
    return hours >= 12 && hours < 18; 
}

int is_evening(int hours) {
    return hours >= 18 && hours < 24; 
}

int is_night(int hours) {
    return hours >= 0 && hours <= 5; 
}

void print_day_stage(int hours, int minute) {
    if (minute == 0 && hours == 0) std::cout << "полночь";
    else if (minute == 0 && hours == 12) std::cout << "полдень";
    else if (is_morning(hours)) std::cout << day_stage[MORNING]; 
    else if (is_day(hours)) std::cout << day_stage[DAY]; 
    else if (is_evening(hours)) std::cout << day_stage[EVENING]; 
    else std::cout << day_stage[NIGHT];

    if (minute == 0) {
        psep();
        std::cout << "ровно";
    }

}

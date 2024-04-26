#ifndef WORDCLOCK_H
#define WORDCLOCK_H

std::string getTimeInWords() {
    std::time_t currentTime = std::time(nullptr);
    std::tm* timePtr = std::localtime(&currentTime);

    int hour = timePtr->tm_hour;
    int minute = timePtr->tm_min;

    std::string hours[] = {"Eins", "Eins", "Zwei", "Drei", "Vier", "Fünf", "Sechs", "Sieben", "Acht", "Neun", "Zehn", "Elf", "Zwölf"};
    std::string timeInWords;

    if (hour > 12) {
        hour = hour + 1;
    }

    if (minute < 5 && hour == 1) {
        timeInWords = "Ein Uhr";
    } else if (minute >= 5 && minute <= 9) {
        timeInWords = "Fünf nach " + hours[hour % 13];
    } else if (minute >= 10 && minute <= 14) {
        timeInWords = "Zehn nach " + hours[hour % 13];
    } else if (minute >= 15 && minute <= 19) {
        timeInWords = "Viertel " + hours[(hour + 1) % 13];
    } else if (minute >= 20 && minute <= 24) {
        timeInWords = "Zehn vor Halb " + hours[(hour + 1) % 13];
    } else if (minute >= 25 && minute <= 29) {
        timeInWords = "Fünf vor Halb " + hours[(hour + 1) % 13];
    } else if (minute >= 30 && minute <= 34) {
        timeInWords = "Halb " + hours[(hour + 1) % 13];
    } else if (minute >= 35 && minute <= 39) {
        timeInWords = "Fünf nach Halb " + hours[(hour + 1) % 13];
    } else if (minute >= 40 && minute <= 44) {
        timeInWords = "Fünf vor Dreiviertel " + hours[(hour + 1) % 13];
    } else if (minute >= 45 && minute <= 49) {
        timeInWords = "Dreiviertel " + hours[(hour + 1) % 13];
    } else if (minute >= 50 && minute <= 54) {
        timeInWords = "Zehn vor " + hours[(hour + 1) % 13];
    } else if (minute >= 55 && minute <= 59) {
        timeInWords = "Fünf vor " + hours[(hour + 1) % 13];
    } else if (minute == 0 && hour == 0) {
        timeInWords = "Mitternacht";
    } else {
        timeInWords = hours[hour % 13]  + " Uhr";
    }

    return timeInWords;
}

#endif

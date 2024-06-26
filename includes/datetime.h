#ifndef DATETIME_H
#define DATETIME_H

std::string getGermanDate(){
    //Get current time from Home Assistant
    std::tm haTimestamp = id(homeassistant_time).now().to_c_tm();

    //Get current time locally
    //std::time_t currentTime = std::time(nullptr);
    //std::tm* haTimestamp = std::localtime(&currentTime);

    // Array of day names and months
    const char* german_months[] = {"Januar", "Februar", "März", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember"};
    const char* german_days[] = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};

    //Get the day of the week and month
    int currentWeekday = haTimestamp.tm_wday;
    int currentMonth = haTimestamp.tm_mon;
    int currentDay = haTimestamp.tm_mday;
    int currentYear = haTimestamp.tm_year + 1900;

    const char* currentMonthName = german_months[currentMonth];
    const char* currentWeekdayName = german_days[currentWeekday];

    std::string germanDate = std::string(currentWeekdayName) + ", " + std::to_string(currentDay) + ". " + std::string(currentMonthName) + " " + std::to_string(currentYear);

    return germanDate;
}

#endif
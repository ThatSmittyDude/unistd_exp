#include <stdio.h>
#include <time.h>

int main() {
    time_t raw_time;
    struct tm *time_info;
    char buffer[80];

    // 1. Get current system time
    time(&raw_time);

    // 2. Convert to local time structure
    time_info = localtime(&raw_time);

    // 3. Format the time using %I (12-hour) and %p (AM/PM)
    // %I = Hour (01-12)
    // %M = Minute (00-59)
    // %S = Second (00-59)
    // %p = AM or PM
    strftime(buffer, sizeof(buffer), "%a %b %d %I:%M:%S %p %Z", time_info);

    // 4. Print the result
    printf("%s\n", buffer);

    return 0;
}

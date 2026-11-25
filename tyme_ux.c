#include <unistd.h>
#include <time.h>

int main() {
    time_t raw_time;
    struct tm *time_info;
    char buffer[32];

    // 1. Get current system time
    time(&raw_time);

    // 2. Convert to local time structure
    time_info = localtime(&raw_time);

    // 3. Format the time using %I (12-hour) and %p (AM/PM)
    // %I = Hour (01-12)
    // %M = Minute (00-59)
    // %S = Second (00-59)
    // %p = AM or PM
    strftime(buffer, sizeof(buffer), "%a %b %d %I:%M:%S %p %Z %Y\n", time_info);

    // 4. Print the result	//unistd.h
    write(1, buffer, 32);	//313	extern ssize_t write (int __fd, const void *__buf, size_t __n) __wur

    return 0;
}

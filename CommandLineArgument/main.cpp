// Name of program mainreturn.cpp
#include <iostream>
using namespace std;

/// logs all messages below this level, level 0 turns off LOG
#ifndef LOG_LEVEL
#define LOG_LEVEL 5  // 0:off, 1:error, 2:warning, 3: info, 4: debug, 5:verbose
#endif
#define _LOG_FORMAT_SHORT(debug, format) "[" debug "]: " format "\n"

/// short log
#define log_s(level, debug, format, ...) \
if (level <= LOG_LEVEL)            \
printf(_LOG_FORMAT_SHORT(debug, format), ##__VA_ARGS__)


int main(){
    log_s(2, "ERROR", "fatal error occurred");
    log_s(2, "INFO", "x=%d and name=%s",2, "ali");

}
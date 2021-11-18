





# include <iostream>
# include <unistd.h>
#include <string>
using namespace std;

enum class Color { normal, red, green, bold };


string setColor(Color c) {
    switch (c) {
        case Color::normal: return "\033[0m";
        case Color::red:    return "\033[0;31m";
        case Color::green:  return "\033[0;32m";
        case Color::bold:   return "\033[1m";
        default: return "";
    }
}

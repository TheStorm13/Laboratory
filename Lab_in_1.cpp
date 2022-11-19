#include <iostream>
#include <string>
#include <iomanip>

int get_second() {
    std::string str = "";
    bool state = true;
    std::cout << "Enter the seconds: ";
    while (state) {
        getline(std::cin, str);
        if (str.find_first_not_of("1234567890") != -1 || (str.empty()) || stoi(str) < 0) {
            std::cout << "You entered the wrong value. Enter it again: " << std::endl;
        } else state = false;
    }
    return stoi(str);
}

void time(unsigned int all_seconds){
    unsigned int hours= all_seconds/3600;
    all_seconds%=3600;
    unsigned int minutes=all_seconds/60;
    all_seconds%=60;
    unsigned int seconds=all_seconds;
    std::cout.fill('0');
    std::cout<<std::setw(2)<<hours<<":"<<std::setw(2)<<minutes<<":"<<std::setw(2)<<seconds<< std::endl;
}
int main() {
    std::string ex = "";
    while (ex != "Exit") {
        unsigned int seconds= get_second();
        time(seconds);
        std::cout << "To exit, type 'Exit'. If you want to continue, press Enter. " << std::endl;
        getline(std::cin, ex);
    }
    return 0;
}
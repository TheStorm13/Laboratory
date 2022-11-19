#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> read_file(std::vector<std::string> array) {
    std::string alphabet = " ,";
    std::string str;
    std::ifstream file("INPUT.TXT"); // окрываем файл для чтения
    if (file.is_open()) {
        for (int i = 0; i < 9; ++i) {
            getline(file, str);
            alphabet += str + ',';
        }
        getline(file, str);
    }
    array.push_back(alphabet);
    array.push_back(str);
    file.close();
    return array;
}

int string_count(std::vector<std::string> array) {
    int count = 0;
    int upper = 1;
    std::string alphabet = array[0];
    std::string str = "aA. AA";
    for (int i = 0; i < str.size(); ++i) {
        int touch = 1;
        for (int j = 0; touch != 0; ++j) {
            if (alphabet[j] == ',') touch = 1;
            else if(  ){



                count += touch;
                std::cout << " " << count << upper << str[i];
                touch = 0;
            } else touch += 1;
        }
    }
    std::cout << alphabet << std::endl << str << std::endl;
    return count;
}

void record_file(int count) {
    std::ofstream file("OUTPUT.TXT");
    if (file.is_open()) {
        file << count;
    }
    file.close();
    std::cout << "The result of the program was recorded in the file." << std::endl;
}

int main() {
    std::vector<std::string> array;
    array = read_file(array);
    int count = string_count(array);
    record_file(count);
    return 0;
}
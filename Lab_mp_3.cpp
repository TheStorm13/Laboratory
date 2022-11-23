#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

// Проверка на целое число
int get_size() {
    std::string str = "";
    bool state = true;
    double number;
    std::size_t pos{};

    std::cout << "Enter the size of the array: ";

    while (state) {
        getline(std::cin, str);

        try {
            number = stoi(str, &pos);

            if (pos != str.size() ||  number < 2) {
                //std::cerr << "1\n";
                throw std::invalid_argument("Argument is invalid\n");
            }
            state = false;
        }
        catch (...) {
            std::cout << "You entered the wrong value. Enter it again: ";
        }
    }
    return number;
}

vector<int> array_filling(int size_array) {
    vector<int> array;
    srand(time(0));
    while (array.size() < size_array) {
        int random = rand() % 100;
        array.push_back(random);
    }
    return array;

}

/*
vector<int> merge(vector<int> array_first, vector<int> array_second) {
    vector<int> buffer = {};
    while (array_first.empty() == false or array_second.empty() == false) {
        if (array_first.size() > 0 && array_second.empty()) {
            buffer.push_back(array_first[0]);
            array_first.erase(array_first.begin());
        }
        else if (array_second.size() > 0 && array_first.empty()) {
            buffer.push_back(array_second[0]);
            array_second.erase(array_second.begin());
        }
        else if (array_first[0] < array_second[0]) {
            buffer.push_back(array_first[0]);
            array_first.erase(array_first.begin());
        }
        else if (array_first[0] >= array_second[0]) {
            buffer.push_back(array_second[0]);
            array_second.erase(array_second.begin());
        }
    }
    return buffer;
}
void merge_sorting(vector<vector<int>> array,int limit) {
    if (array.size() % 2 == 1) {
        if (array[1][0] > array[0][0]) {
            array[1] = {array[0][0],array[1][0]};
            array.erase(array.begin());
        }
        else {
            array[1] = { array[1][0],array[0][0]};
            array.erase(array.begin());
        }
    }
    int steps = 1;
    for (int i = 2; steps < array.size();i*2) {
        steps +=1;
    }
    vector<int> buffer;
    while(array.size() != 1) {
        int stop_point = array.size();
        for (int j = 1; j < stop_point; ++j){
            buffer = merge(array[0], array[1]);
            array.erase(array.begin());
            array.erase(array.begin());
            array.push_back(buffer);
            buffer = {};
        }
    }

        for (int j = 0; j < limit; ++j) {
            cout << array[0][j] << "    ";
    }
        cout << endl;
}

vector<int> merge(vector<int> array) {
    int steps = 1;
    for (int i = 2; steps < array.size(); i * 2) {
        steps += 1;
    }
    vector<int> buffer = {};
    for (int i = 1; i <= steps; ++i) {
        for (int j = 0; j < steps; ++j) {


        }

    }

    return array;
}
*/

vector<int> merge_sort(vector<int> array_first, vector<int> array_second) {
    vector<int> buffer = {};
    while (array_first.empty() == false or array_second.empty() == false) {
        if (array_first.size() > 0 && array_second.empty()) {
            buffer.push_back(array_first[0]);
            array_first.erase(array_first.begin());
        } else if (array_second.size() > 0 && array_first.empty()) {
            buffer.push_back(array_second[0]);
            array_second.erase(array_second.begin());
        } else if (array_first[0] < array_second[0]) {
            buffer.push_back(array_first[0]);
            array_first.erase(array_first.begin());
        } else if (array_first[0] >= array_second[0]) {
            buffer.push_back(array_second[0]);
            array_second.erase(array_second.begin());
        }
    }
    return buffer;
}

vector<int> merge(vector<int> array, int begin, int end) {
    int mi = (end + begin) / 2;

    if (begin == end)
        return {array[begin]};
    else
        return merge_sort(merge(array, begin, mi), merge(array, mi + 1, end));
}


int main() {
    string ex = "";
    while (ex != "Exit") {
        vector<int> arr = {};
        int size_array = get_size();
        arr = array_filling(size_array);
        int limit = 20 < arr.size() ? 20 : arr.size();

        limit = limit < arr.size() ? limit : arr.size();
        cout << "Initial array" << endl;
        for (int i = 0; i < limit; ++i) {
            cout << arr[i] << "    ";
        }
        cout << endl << "Sorted array by merge" << endl;
        arr = merge(arr, 0, arr.size() - 1);


        //arr = merge({1,2,3,4}, 0, arr.size() - 1);

        for (int i = 0; i < limit; ++i) {
            cout << arr[i] << "    ";
        }

        cout << endl << "To exit, type 'Exit'. If you want to continue, type anything else. " << endl;
        getline(cin, ex);// Ввод слова при необходимости выхода
    }
    return 0;
}


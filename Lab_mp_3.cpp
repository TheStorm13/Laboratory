#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

// Проверка на целое число
int get_size() {
    string str1 = "";
    getline(cin, str1);// Ввод строки
    // Проверка. Если строка содержит не только цифры, то ошибка
    if (str1.find_first_not_of("1234567890") != -1) {
        cout << "Вы ввели неправильное значение. Введите его еще раз:" << endl;
        return get_size();
    } else {
        int str_i = stoi(str1);// Преобразование строки в int
        // Проверка на положительное число
        if (str_i < 2) {
            cout << "Вы ввели слишком маленькое значение. Введите его еще раз:" << endl;
            return get_size();
        } else {
            return str_i;
        }
    }
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
    //cout << begin <<" "<< end <<" "<< mi << endl;
    if (begin == end) return {array[begin]};
    else return merge_sort(merge(array, begin, mi), merge(array, mi + 1, end));
}


int main() {
    setlocale(LC_ALL, "Russian");
    string ex = "";
    while (ex != "Exit") {
        cout << "Пожалуйста, введите количество выводимых элементов: " << endl;
        int limit = get_size();
        cout << "Пожалуйста, введите количество элементов в массиве: " << endl;
        int size_array = get_size();
        vector<int> arr = array_filling(size_array);

        limit = limit < arr.size() ? limit : arr.size();
        cout << "Изначальный массив" << endl;
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i] << "    ";
        }
        cout << endl << "Отсортированный массив" << endl;
        arr = merge(arr, 0, arr.size() - 1);


        //arr = merge({1,2,3,4}, 0, arr.size() - 1);

        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i] << "    ";
        }

        cout << "Для выхода введите 'Exit'. Если хотите продолжить нажмите Enter. " << endl;
        getline(cin, ex);// Ввод слова при необходимости выхода
    }
    return 0;
}


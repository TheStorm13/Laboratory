#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


using namespace std;
//Первая версия-----------------------------------------------------------------
/*
// Проверка на целое число
double check_double() {
    string str1 = "";
    getline(cin, str1);// Ввод строки
    // Проверка. Если строка содержит не только цифры, то ошибка
    if (str1.find_first_not_of(".1234567890") != -1 || (str1.empty())) {
        cout << "You entered the wrong value. Enter it again:" << endl;
        return check_double();
    } else {
        double integer = stod(str1);
        if (integer > 0) {
            return integer;
        } else {
            cout << "You entered the wrong value. Enter it again:";
            return check_double();
        }
    }
}

double check_double_x() {
    string str1 = "";
    getline(cin, str1);// Ввод строки
    // Проверка. Если строка содержит не только цифры, то ошибка
    if (str1.find_first_not_of("-.1234567890") != -1 || (str1.empty())) {
        cout << "You entered the wrong value. Enter it again:" << endl;
        return check_double();
    } else {
        double x = stod(str1);
        if (x > -1 && x < 1) {
            return x;
        } else {
            cout << "You entered the wrong value. Enter it again:";
            return check_double_x();
        }
    }
}

vector<double> array_add(vector<double> array, double x, int n, double Sn, double S, double a) {
    array.push_back(x);
    array.push_back(n);
    array.push_back(Sn);
    array.push_back(S);
    array.push_back(a);
    return array;
}

double element_row(double x, int n) {
    double member1 = 1;
    for (int i = 0; i < n; ++i) {
        member1 = member1 * x;
    }
    double member2 = 0;
    for (int i = 1; i <= n; ++i) {
        member2 += (1.0 / i);
    }
    if (n % 2 == 0) {
        return (-1) * member1 * member2;
    } else {
        return member1 * member2;
    }
}

double error(double an, double s, int n) {
    if (n % 2 == 0) {
        return (an / s);
    } else {
        return (-1) * (an / s);
    }

}

int main() {
    setlocale(LC_ALL, "Russiаn");
    string ex = "";
    vector<double> array = {};
    while (ex != "Exit") {
        cout << "Enter the value of x:  ";
        double x = check_double_x();
        cout << "Enter the value of the error or the number of iterations:  ";
        double a = check_double();
        cout << "Iteration|  " << "Member iteration|   " << "Current amount|     " << "Accuracy|   " << endl;
        bool while_flag;
        if (a == int(a)) {
            int n = 1;
            double s = 0;
            double an1;
            while (n < a + 2) {
                bool flag = 0;
                int j = 0;
                while (array.empty() == false && flag == 0 && j < array.size() ) {
                    if (x == array[j] && n == array[j + 1]) {
                        cout << "Arr ";
                        cout << setw(9) << n << "|" << setw(18) << array[j + 2] << "|" << setw(16) << array[j + 3]
                             << "|" << setw(14) << array[j + 4]
                             << "|" << endl;
                        s = array[j + 3];
                        an1 = array[j + 2];
                        flag = 1;
                        while_flag = 1;
                        n += 1;
                    }
                    j += 5;
                }
                if (flag == 0) {
                    if (while_flag == 1) {
                        n += 1;
                        while_flag = 0;
                    }
                    s == 0 ? s = element_row(x, n) : s;
                    double an = element_row(x, n);
                    double error1 = error(an, s, n - 1);
                    if (n != 1) {
                        array = array_add(array, x, n - 1, an1, s, error1);
                        cout << "Cul ";
                        cout << setw(9) << n - 1 << "|" << setw(18) << an1 << "|" << setw(16) << s << "|" << setw(14)
                             << error1
                             << "|" << endl;
                    }
                    an1 = an;
                    s += an;
                    n += 1;
                }
            }
        } else {;
            double error1 = 100000000000000000;
            int n = 1;
            double s = 0;
            double an1;
            while (error1 >= a) {
                bool flag = 0;
                int j = 0;
                while (!array.empty() && flag == 0 && j < array.size()) {
                    if (x == array[j] && n == array[j + 1] ) {
                        cout << "Arr ";
                        cout << setw(9) << n << "|" << setw(18) << array[j + 2] << "|" << setw(16) << array[j + 3]
                             << "|" << setw(14) << array[j + 4]
                             << "|" << endl;
                        s = array[j + 3];
                        an1 = array[j + 2];
                        error1=array[j+4];
                        while_flag = 1;
                        flag = 1;
                        n += 1;
                    }
                    j += 5;
                }
                if (flag == 0) {
                    if (while_flag == 1) {
                        n += 1;
                        while_flag = 0;
                    }
                    s == 0 ? s = element_row(x, n) : s;
                    double an = element_row(x, n);
                    error1 = error(an, s, n - 1);
                    if (n != 1) {
                        array = array_add(array, x, n - 1, an1, s, error1);
                        cout << "Cul ";
                        cout << setw(9) << n - 1 << "|" << setw(18) << an1 << "|" << setw(16) << s << "|" << setw(14)
                             << error1
                             << "|" << endl;
                    }
                    an1 = an;
                    s += an;
                    n += 1;
                }
            }
        }
        cout << "To exit, type 'Exit'. If you want to continue, press Enter.  " << endl;
        getline(cin, ex);// Ввод слова при необходимости выхода
    }
    return 0;
}
*/

//Вторая версия-----------------------------------------------------------------
double input_double() {
    string str_number;
    bool state=true;
    cout<<"::"<<endl;
    while (state) {
        getline(cin,str_number);
        if (str_number.find_first_not_of("-.1234567890") != -1 || (str_number.empty())||stod(str_number)) {
            cout << "You entered the wrong value. Enter it again:" << endl;

        }else state = false;
    }
    return number;
}


int check_integer() {

    return number;
}

vector<long double>
array_add(vector<long double> array, long double x, int n, long double Sn, long double S, long double a) {
    array.push_back(x);
    array.push_back(n);
    array.push_back(Sn);
    array.push_back(S);
    array.push_back(a);
    return array;
}

int main() {

    return 0;
}
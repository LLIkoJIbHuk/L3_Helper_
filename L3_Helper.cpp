﻿#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "stdlib.h"
#include "string.h"
#include <vector>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;

int menu(void) {
    cout << "\n|-----------------------------------------------|"
        "\n|              ---------МЕНЮ---------           |"
        "\n|-----------------------------------------------|"
        "\n|-1-|               Начать ввод                 |"
        "\n|-2-|                  Помощь                   |"
        "\n|-3-|               О программе                 |"
        "\n|-4-|                  Выход                    |"
        "\n|-----------------------------------------------|"
        "\n|           Введите номер пункта меню:          |"
        "\n|-----------------------------------------------|" << endl;
    
    int choice;
    cin >> choice;
    return choice;
}

int help(void) {
    cout << "\n|-------------------------------------------------|"
        "\n| # |                  Помощь                 | # |"
        "\n|-------------------------------------------------|"
        "\n 1) Вводятся данные из таблиц S1-S3 в двоичной системе счисления"
        "\n 2) Выводятся диапазоны A = 0001 до 1111, а так же таблицы по отдельности" << endl;
    return 0;
}

int about(void) {
    cout << "\n|-------------------------------------------------|"
        "\n| ? |               О программе               | ? |"
        "\n|-------------------------------------------------|"
        "\n                                                   "
        "\n|-------------------------------------------------|"
        "\n|                    L3_Helper                    |"
        "\n|-------------------------------------------------|"
        "\n|    Dev by   |       https://t.me/b4ns8hfb4      |"
        "\n|    GitHub   |   https://github.com/LLIkoJIbHuk  |"
        "\n|-------------------------------------------------|"
        "\n|                   |11.10.2024|                  |"
        "\n|-------------------------------------------------|" 
        "\n| <<Я не программист, и код пишу только потому,   |"
        "\n|         что его никто не пишет кроме меня>>     |"
        "\n|                               <c> ValdikSS      |"
        "\n|-------------------------------------------------|"<< endl;
    return 0;
}

int end(void) {
    cout << "\n|-------------------------------------------------|"
        "\n| # |Для перехода в меню нажмите любую клавишу| # |"
        "\n|-------------------------------------------------|" << endl;
    _getch();
    return 0;
}

// Функция для преобразования двоичной строки в десятичное число
int binToDec(const string& bin) {
    return stoi(bin, nullptr, 2);
}

// Функция для преобразования десятичного числа в двоичную строку
string decToBin(int dec, int bits = 4) {
    bitset<4> bin(dec);
    return bin.to_string();
}

// Обработка списков (изменено для отдельного вывода результатов по массивам)
void processList(const vector<pair<string, string>>& pairs,
    const vector<int>& arr1, const vector<string>& arr1_bin,
    const vector<int>& arr2, const vector<string>& arr2_bin,
    const vector<int>& arr3, const vector<string>& arr3_bin) {
    for (const auto& p : pairs) cout << p.first << " xor " << p.second << endl;
    cout << endl;

    // Функция для обработки массива
    auto processArray = [&](const vector<int>& arr, const vector<string>& arr_bin) {
        for (const auto& p : pairs) {
            int idx1 = binToDec(p.first);
            int idx2 = binToDec(p.second);
            cout << arr_bin[idx1] << " xor " << arr_bin[idx2] << " = " << decToBin(arr[idx1] ^ arr[idx2]) << endl;
        }
        cout << endl;
        };

    cout << "Результаты по таблице S1:" << endl;
    processArray(arr1, arr1_bin);
    cout << "Результаты по таблице S2:" << endl;
    processArray(arr2, arr2_bin);
    cout << "Результаты по таблице S3:" << endl;
    processArray(arr3, arr3_bin);
    cout << "---------------------\n";
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 16;
    vector<int> array1(SIZE), array2(SIZE), array3(SIZE);
    vector<string> array1_bin(SIZE), array2_bin(SIZE), array3_bin(SIZE);

    // Два списка пар координат (без изменений)

    vector<pair<string, string>> xorPairs0 = {
        {"0000", "0001"}, {"0001", "0000"}, {"0010", "0011"}, {"0011", "0010"},
        {"0100", "0101"}, {"0101", "0100"}, {"0110", "0111"}, {"0111", "0110"},
        {"1000", "1001"}, {"1001", "1000"}, {"1010", "1011"}, {"1011", "1010"},
        {"1100", "1101"}, {"1101", "1100"}, {"1110", "1111"}, {"1111", "1110"}

    };

    vector<pair<string, string>> xorPairs1 = {
        {"0000", "0010"}, {"0010", "0000"}, {"0011", "0001"}, {"0001", "0011"},
        {"0100", "0110"}, {"0110", "0100"}, {"0111", "0101"}, {"0101", "0111"},
        {"1000", "1010"}, {"1010", "1000"}, {"1011", "1001"}, {"1001", "1011"},
        {"1100", "1110"}, {"1110", "1100"}, {"1111", "1101"}, {"1101", "1111"}
    };

    vector<pair<string, string>> xorPairs2 = {
        {"0000", "0011"}, {"0011", "0000"}, {"0010", "0001"}, {"0001", "0010"},
        {"0100", "0111"}, {"0111", "0100"}, {"0101", "0110"}, {"0110", "0101"},
        {"1000", "1011"}, {"1011", "1000"}, {"1001", "1010"}, {"1010", "1001"},
        {"1100", "1111"}, {"1111", "1100"}, {"1101", "1110"}, {"1110", "1101"}
    };

    vector<pair<string, string>> xorPairs3 = {
        {"0000", "0100"}, {"0100", "0000"}, {"0011", "0111"}, {"0111", "0011"},
        {"0010", "0110"}, {"0110", "0010"}, {"0001", "0101"}, {"0101", "0001"},
        {"1000", "1100"}, {"1100", "1000"}, {"1011", "1111"}, {"1111", "1011"},
        {"1010", "1110"}, {"1110", "1010"}, {"1001", "1101"}, {"1101", "1001"}

    };
    vector<pair<string, string>> xorPairs4 = {
        {"0000", "0101"}, {"0101", "0000"}, {"0011", "0110"}, {"0110", "0011"},
        {"0010", "0111"}, {"0111", "0010"}, {"0001", "0100"}, {"0100", "0001"},
        {"1000", "1101"}, {"1101", "1000"}, {"1011", "1110"}, {"1110", "1011"},
        {"1010", "1111"}, {"1111", "1010"}, {"1001", "1100"}, {"1100", "1001"}

    };

    vector<pair<string, string>> xorPairs5 = {
        {"0000", "0110"}, {"0110", "0000"}, {"0001", "0111"}, {"0111", "0001"},
        {"0010", "0100"}, {"0100", "0010"}, {"0011", "0101"}, {"0101", "0011"},
        {"1000", "1110"}, {"1110", "1000"}, {"1001", "1111"}, {"1111", "1001"},
        {"1010", "1100"}, {"1100", "1010"}, {"1011", "1101"}, {"1101", "1011"}

    };

    vector<pair<string, string>> xorPairs6 = {
        {"0000", "0111"}, {"0111", "0000"}, {"0011", "0100"}, {"0100", "0011"},
        {"0010", "0101"}, {"0101", "0010"}, {"0001", "0110"}, {"0110", "0001"},
        {"1000", "1111"}, {"1111", "1000"}, {"1011", "1100"}, {"1100", "1011"},
        {"1010", "1101"}, {"1101", "1010"}, {"1001", "1110"}, {"1110", "1001"}

    };
    vector<pair<string, string>> xorPairs7 = {
        {"0000", "1000"}, {"1000", "0000"}, {"0011", "1011"}, {"1011", "0011"},
        {"0010", "1010"}, {"1010", "0010"}, {"0001", "1001"}, {"1001", "0001"},
        {"0100", "1100"}, {"1100", "0100"}, {"0111", "1111"}, {"1111", "0111"},
        {"0101", "1101"}, {"1101", "0101"}, {"0110", "1110"}, {"1110", "0110"}

    };
    vector<pair<string, string>> xorPairs8 = {
        {"0000", "1001"}, {"1001", "0000"}, {"0011", "1010"}, {"1010", "0011"},
        {"0010", "1011"}, {"1011", "0010"}, {"0001", "1000"}, {"1000", "0001"},
        {"0100", "1101"}, {"1101", "0100"}, {"0111", "1110"}, {"1110", "0111"},
        {"0101", "1100"}, {"1100", "0101"}, {"0110", "1111"}, {"1111", "0110"}

    };
    vector<pair<string, string>> xorPairs9 = {
        {"0000", "1010"}, {"1010", "0000"}, {"0011", "1001"}, {"1001", "0011"},
        {"0010", "1000"}, {"1000", "0010"}, {"0001", "1011"}, {"1011", "0001"},
        {"0100", "1110"}, {"1110", "0100"}, {"0111", "1101"}, {"1101", "0111"},
        {"0101", "1111"}, {"1111", "0101"}, {"0110", "1100"}, {"1100", "0110"}

    };
    vector<pair<string, string>> xorPairs10 = {
        {"0000", "1011"}, {"1011", "0000"}, {"0011", "1000"}, {"1000", "0011"},
        {"0010", "1001"}, {"1001", "0010"}, {"0001", "1010"}, {"1010", "0001"},
        {"0100", "1111"}, {"1111", "0100"}, {"0111", "1100"}, {"1100", "0111"},
        {"0101", "1110"}, {"1110", "0101"}, {"0110", "1101"}, {"1101", "0110"}

    };
    vector<pair<string, string>> xorPairs11 = {
        {"0000", "1100"}, {"1100", "0000"}, {"0011", "1111"}, {"1111", "0011"},
        {"0010", "1110"}, {"1110", "0010"}, {"0001", "1101"}, {"1101", "0001"},
        {"0100", "1000"}, {"1000", "0100"}, {"0111", "1011"}, {"1011", "0111"},
        {"0101", "1001"}, {"1010", "0110"}, {"0110", "1010"}, {"1001", "0101"}

    };
    vector<pair<string, string>> xorPairs12 = {
        {"0000", "1101"}, {"1101", "0000"}, {"0011", "1110"}, {"1110", "0011"},
        {"0010", "1111"}, {"1111", "0010"}, {"0001", "1100"}, {"1100", "0001"},
        {"0100", "1001"}, {"1001", "0100"}, {"0111", "1010"}, {"1010", "0111"},
        {"0101", "1000"}, {"1000", "0101"}, {"0110", "1011"}, {"1011", "0110"}

    };
    vector<pair<string, string>> xorPairs13 = {
        {"0000", "1110"}, {"1110", "0000"}, {"0011", "1101"}, {"1101", "0011"},
        {"0010", "1100"}, {"1100", "0010"}, {"0001", "1111"}, {"1111", "0001"},
        {"0100", "1010"}, {"1010", "0100"}, {"0111", "1001"}, {"1001", "0111"},
        {"0101", "1011"}, {"1011", "0101"}, {"0110", "1000"}, {"1000", "0110"}

    };
    vector<pair<string, string>> xorPairs14 = {
        {"0000", "1111"}, {"1111", "0000"}, {"0011", "1100"}, {"1100", "0011"},
        {"0010", "1101"}, {"1101", "0010"}, {"0001", "1110"}, {"1110", "0001"},
        {"0100", "1011"}, {"1011", "0100"}, {"0111", "1000"}, {"1000", "0111"},
        {"0101", "1010"}, {"1010", "0101"}, {"0110", "1001"}, {"1001", "0110"}

    };
    

    int choice;
    do {
        system("cls");
        choice = menu();
        switch (choice) {
        case 1: system("cls");
            cout << "\n|-------------------------------------------------|"
                "\n|V|Введите данные из таблиц S1 - S3 в ДЕСЯТИЧНОЙ|V|"
                "\n|-------------------------------------------------|" << endl;

            // Ввод значений для трех массивов в десятичной системе (без изменений)
            cout << "Введите " << SIZE << " значений для таблицы S1 (в десятичной системе счисления):" << endl;
            for (int i = 0; i < SIZE; ++i) cin >> array1[i];
            cout << "Введите " << SIZE << " значений для таблицы S2:" << endl;
            for (int i = 0; i < SIZE; ++i) cin >> array2[i];
            cout << "Введите " << SIZE << " значений для таблицы S3" << endl;
            for (int i = 0; i < SIZE; ++i) cin >> array3[i];

            // Преобразование в двоичную систему (для вывода)
            transform(array1.begin(), array1.end(), array1_bin.begin(), [&](int val) { return decToBin(val); });
            transform(array2.begin(), array2.end(), array2_bin.begin(), [&](int val) { return decToBin(val); });
            transform(array3.begin(), array3.end(), array3_bin.begin(), [&](int val) { return decToBin(val); });

            cout << "\nA = 0001\n" << endl;
            processList(xorPairs0, array1, array1_bin, array2, array2_bin, array3, array3_bin);
            cout << "\nA = 0010\n" << endl;
            processList(xorPairs1, array1, array1_bin, array2, array2_bin, array3, array3_bin);
            cout << "\nA = 0011\n" << endl;
            processList(xorPairs2, array1, array1_bin, array2, array2_bin, array3, array3_bin);
            cout << "\nA = 0100\n" << endl;
            processList(xorPairs3, array1, array1_bin, array2, array2_bin, array3, array3_bin);
            cout << "\nA = 0101\n" << endl;
            processList(xorPairs4, array1, array1_bin, array2, array2_bin, array3, array3_bin);
            cout << "\nA = 0110\n" << endl;
            processList(xorPairs5, array1, array1_bin, array2, array2_bin, array3, array3_bin);
            cout << "\nA = 0111\n" << endl;
            processList(xorPairs6, array1, array1_bin, array2, array2_bin, array3, array3_bin);
            cout << "\nA = 1000\n" << endl;
            processList(xorPairs7, array1, array1_bin, array2, array2_bin, array3, array3_bin);
            cout << "\nA = 1001\n" << endl;
            processList(xorPairs8, array1, array1_bin, array2, array2_bin, array3, array3_bin);
            cout << "\nA = 1010\n" << endl;
            processList(xorPairs9, array1, array1_bin, array2, array2_bin, array3, array3_bin);
            cout << "\nA = 1011\n" << endl;
            processList(xorPairs10, array1, array1_bin, array2, array2_bin, array3, array3_bin);
            cout << "\nA = 1100\n" << endl;
            processList(xorPairs11, array1, array1_bin, array2, array2_bin, array3, array3_bin);
            cout << "\nA = 1101\n" << endl;
            processList(xorPairs12, array1, array1_bin, array2, array2_bin, array3, array3_bin);
            cout << "\nA = 1110\n" << endl;
            processList(xorPairs13, array1, array1_bin, array2, array2_bin, array3, array3_bin);
            cout << "\nA = 1111\n" << endl;
            processList(xorPairs14, array1, array1_bin, array2, array2_bin, array3, array3_bin);
            end();
            break;
        case 2:system("cls");
            help();
            end();
            break;
        case 3: system("cls");
            about();
            end();
            break;
        case 4: system("cls");
            cout << "\n|-------------------------------------------------|"
                "\n| * |            Вы успешно вышли!            | * |"
                "\n|-------------------------------------------------|" << endl;
            break;
        default: system("cls");
            cout << "\n|-------------------------------------------------|"
                "\n| ! |        Такого пункта в меню нет         | ! |"
                "\n|-------------------------------------------------|" << endl;
            end();
        }
    } while (choice != 4);

    return 0;

}
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void createAndFillFile(const string& filename, const string& S, const string& T)
{
    ofstream fin(filename);

    fin << S;
    fin << "\n";
    fin << T;

    fin.close();
}

void createEmptyFile(const string& filename)
{
    ofstream fout(filename);
    fout.close();
}

void fillEmptyFile(const string& filename, const string& OUTPUT)
{
    ofstream fin(filename);

    fin << OUTPUT;
    fin << " ";

    fin.close();
}

void search(const string& filename, string pattern, string str)
{
    string OUTPUT;
    int strLen = str.length();
    int patternLen = pattern.length();
    int strHash = 0, patternLenHash = 0;
    int x = 10/*Константа, основа для степеню*/,powerOfX = pow(x, patternLen - 1);
    int i = 0, j = 0, k = 0; // Змiннi для циклiв

    while (i < patternLen) { // Обчислюю значення хешу для строки та паттерну
        strHash += str[i] * pow(x, patternLen - i - 1);
        patternLenHash += pattern[i] * pow(x, patternLen - i - 1);
        i++;
    }

    while (j < strLen - patternLen + 1) { // Головний цикл
        if (strHash == patternLenHash) {
            bool isHashEqual = true;
            while (k < patternLen) {
                if (pattern[k] != str[k + j]) {
                    isHashEqual = false;
                    break;
                }
                k++;
            }
            if (isHashEqual) {
                OUTPUT = OUTPUT + to_string(j) + " ";
            }
        }
        strHash = (strHash - str[j] * powerOfX) * x + str[patternLen + j];
        j++;
    }
    fillEmptyFile(filename,OUTPUT); // Передаю значення у функцiю та друкую у файлi
}

int main()
{

    string str = "ababbababa";
    string T = "aba";

    string InputFile = "../INPUT.txt";
    string OutputFile = "../OUTPUT.txt";;
    createAndFillFile(InputFile,str,T);
    createEmptyFile(OutputFile);


    search(OutputFile,T, str);
    return 0;
}

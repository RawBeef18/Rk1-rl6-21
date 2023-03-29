#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <ctime>
#include <cstdlib>


void buildTree(int height) {
    int max_Stars = 1 + 2 * (height - 1);
    for (int i = 0; i <= height; i++) {
        int row_Stars = 1 + 2 * (i - 1);
        int space = (max_Stars - row_Stars) / 2;
        std::cout << std::string(space, ' ');
        for (int j = 0; j < row_Stars; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;



    }
}
void WorkWithFile::readFromFile(const char* fileName) {
    std::string line;
    std::ifstream in(fileName);
    std::string* data = new std::string();
    if (in.is_open()) {
        while (getline(in, line)) {
            data->append(line);
     }
    }
    in.close();
    dataOfFile = (char*)data->c_str();
}
void WorkWithFile::writeStatInfoToFile(const char* outFile) {
    std::map<char, int> m;

    for (int i = 0;*(dataOfFile+i) != '\0'; i++) {
        if (m.find(*(dataOfFile + i)) == m.end()) {
            m[*(dataOfFile + i)] = 1;
        }
        else {
            m[*(dataOfFile + i)] += 1;
        }
    }
    std::ofstream out(outFile);
    if (out.is_open()) {
        for (auto const& item : m)
        {
            out << item.first << '\t' << item.second << std::endl;
        }
    }
    out.close();
}

void WorkWithFile::prepareTestFile(const char* fileName) {
    char alphabet[27] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z', ' '};

    std:: string res = "";
    for (int i = 0; i < 256; i++)
        res = res + alphabet[rand() % 27];
    std::ofstream out(fileName);
    if (out.is_open()) {
        out << res << std::endl;
    }
    out.close();

}
void sourceFileTask1(const char* fileName) {
    WorkWithFile wf;
    wf.writeStatInfoToFile(fileName);
}
WorkWithFile::WorkWithFile() {
    prepareTestFile("sourceFile_task1.txt");
    readFromFile("sourceFile_task1.txt");
}

WorkWithFile::~WorkWithFile() {
    delete[] dataOfFile;
}
char* convertDecToBin(int number) {
    char bits[32];
    int num = 0;
    while (number) {
        if (number % 2 == 1) {
            bits[num] = '1';
        }
        else {
            bits[num] = '0';
        }
        number /= 2;
        num++;

    }
    char* newMas = new char[num + 1];
    newMas[num] = '\0';
    for (int i = 0; num > 0; i++, num--) {
        newMas[i] = bits[num - 1];
    }
    return newMas;
}
void writeToFile(const char& fileName, const char* strNum) {
    std::ofstream out(&fileName);
    if (out.is_open()) {
        out << strNum << std::endl;
    }
    else {
        std::cout << "Error opening file" << std::endl;
    }
    out.close();
}
//char* convertBitToHex(const char* binNum) {
  //  int sizeOfBinNum = strlen(binNum);
    //int sizeBin = sizeOfBinNum;
    //if (sizeOfBinNum % 4 != 0) {
      //  sizeOfBinNum += sizeOfBinNum % 4;
    //}
    //char* buff = new char[sizeOfBinNum];
    //std::unordered_map <char, char> binToHexMap{
      //  {'0000', '0'} ,{'0001', '1'} , {'0010', '2'},
        //{'0011', '3'} ,{'0100', '4'} , {'0101', '5'},
        //{'0110', '6'} ,{'0111', '7'} , {'1000', '8'},
        //{'1001', '9'} ,{'1010', 'A'} , {'1011', 'B'},
        //{'1100', 'C'} ,{'1101', 'D'} , {'1110', 'E'},
        //{'1111', 'F'}
    //};
    //for (int i = 0; i < sizeOfBinNum; i++) {
      //  buff[i] = '0';
    //}
    //for (int i = 0; i < sizeBin; i++) {
      //  buff[i] = binNum[i];
    //}
    //return buff;
//}
void randFill(float* ar, int N) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        ar[i] = rand() % 101;
    }
}
std::vector<float> averStr2DArray(const float* ar, int colCount, int rowCount) {
    std::vector<float> avgs(rowCount);
    for (int i = 0; i < rowCount; i++) {
        float sum = 0;
        for (int j = 0; j < colCount; j++) {
            sum += ar[i * colCount + j];
        }
        avgs[i] = sum / colCount;
    }
    std::ofstream out("result_task5.txt");
    if (out.is_open()) {
        for (int i = 0; i < rowCount; i++)
            out << "[" << i << "]" << "  :  " << "[" << avgs[i]<< "]" << std::endl;
    }
    out.close();
    return avgs;
}
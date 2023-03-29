
#include <iostream>
#include "Header.h"
#include <fstream>





int main()
{
    setlocale(LC_ALL, "Russian");
    buildTree(10);//task4
    sourceFileTask1("result_task1.txt");
    char* newMas = convertDecToBin(1675);
    writeToFile(*"result_task2", newMas);
    //char* buff;
    //const char arr[] = { "0000" };
    //buff = convertBitToHex(arr);
    //writeToFile(*"result_task3", buff);
    const int colCount = 5;
    const int rowCount = 10;
    float ar[rowCount][colCount];
    randFill(*ar, 50);
    averStr2DArray(*ar, 5, 10);

    return 0;
}

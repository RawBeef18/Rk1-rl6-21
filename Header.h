#pragma once
#include <vector>
void buildTree(int height);
struct charcount {
	char symbol;
	int counter;
};
class WorkWithFile {
private:
	char* dataOfFile;
	void readFromFile(const char* fileName);	
	void prepareTestFile(const char* fileName);

public:
	WorkWithFile();
	~WorkWithFile();

	void writeStatInfoToFile(const char* outFile);
};
void sourceFileTask1(const char* fileName);
char* convertDecToBin(int number);
void writeToFile(const char& fileName, const char* strNum);
//char* convertBitToHex(const char* binNum);
void randFill(float* ar, int N);
std::vector<float> averStr2DArray(const float* ar, int colCount, int rowCount);

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

struct Student {
    public:
        string name;
        string rawString;
        tm birthday;
};

tm stringToDate(const string& dateString) {
    tm time = {};
    istringstream ss(dateString);
    ss >> get_time(&time, "%d.%m.%Y");
    return time;
}

string tmToString(const tm& time_struct) {
    ostringstream oss;
    oss << put_time(&time_struct, "%d.%m.%Y");
    return oss.str();
}

void splitBySpace(const string& str, string result[]) {
    istringstream iss(str);
    string token1;
    string token2;
    string token3;
    iss >> token1;
    iss >> token2;
    iss >> token3;
    result[0] = token1 + ' ' + token2;
    result[1] = token3;
}

int compareDates(const tm& date1, const tm& date2) {
    if (date1.tm_year < date2.tm_year) return -1;
    if (date1.tm_year > date2.tm_year) return 1;
    if (date1.tm_mon < date2.tm_mon) return -1;
    if (date1.tm_mon > date2.tm_mon) return 1;
    if (date1.tm_mday < date2.tm_mday) return -1;
    if (date1.tm_mday > date2.tm_mday) return 1;
    return 0;
}

void Swap(Student& x, Student& y) {
    Student temp = x;
    x = y;
    y = temp;
}

int CountLines() {
	ifstream file;
	string rubish;
	file.open("./source.txt");
	int count = 0;
	while (getline(file, rubish)) 
		count++;
	file.close();
	return count;
}

void hoareSort(Student* array, int left, int right) {
    int l = left;
    int r = right;
    Student mid = array[(l + r) / 2];
    do {
        while (compareDates(array[l].birthday, mid.birthday) == 1)
            ++l;
        while (compareDates(array[r].birthday, mid.birthday) == -1)
            --r;
        if (l <= r) {
            Swap(array[l], array[r]);
            ++l;
            --r;
        }
    } while (l < r);
    if (left < r)
        hoareSort(array, left, r);
    if (l < right)
        hoareSort(array, l, right);
}

void hoareSort(Student* array, int n) {
    hoareSort(array, 0, n-1);
}

void writeToFile(const Student arr[], int size, const string& filename) {
    ofstream outputFile(filename); 
    for (int i = 0; i < size; ++i) {
        outputFile << arr[i].rawString << endl;
    }
    outputFile.close();
}

int main() {
    int n = CountLines();
    ifstream file("./source.txt");
    string line;
    Student* studentList = new Student[n];
    string splittedString[2];
    int i = 0;
    while (!file.eof()) {
        getline(file, line);
        splitBySpace(line, splittedString);
        Student currentStudent;
        currentStudent.rawString = line;
        currentStudent.name = splittedString[0];
        currentStudent.birthday = stringToDate(splittedString[1]);
        studentList[i++] = currentStudent;
    }
    file.close();
    hoareSort(studentList, n);
    writeToFile(studentList, n, "./output.txt");
    return 0;
}
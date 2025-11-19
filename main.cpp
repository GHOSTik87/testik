#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Date {
    int day;
    int month;
    int year;
};

Date parse_date(std::string date) {
    Date date1;
    date1.day = stoi(date.substr(0, 2));
    date1.month = stoi(date.substr(3, 2));
    date1.year = stoi(date.substr(6, 4));
    return date1;
}

std::vector<Date> Read_file(std::string file_path) {
    std::fstream file;
    file.open(file_path);
    std::string line;
    std::vector<Date> date;
    if (!file.is_open()) {
        throw 8;
    }
    while (getline(file, line)) {
        date.push_back(parse_date(line));
    }
    file.close();
    return date;
}

int main() {
    std::vector<Date> date;

    try {
        date = Read_file("C:\\Projects\\untitled\\polka.txt");
        for (int i = 0; i < date.size(); i++) {
            std::cout << date[i].day << "/" << date[i].month << "/" << date[i].year << std::endl;
        }
    }
    catch (int error) {
    if (error == 8) {
        std::cout << "The file did not open" << std::endl;
    }
    }
}

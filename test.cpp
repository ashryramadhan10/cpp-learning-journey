#include <iostream>
#include <cstring>

// structs declaration
struct Point;
struct Label;
struct DataPoint;

// methods declaration
DataPoint* createDataPoint(const char*, const int, const int);
void deleteDataPoint(DataPoint**);

struct Point {
    int x;
    int y;
};

struct Label {
    char* str;
};

struct DataPoint {
    Label label;
    Point point;
};

int main(int argc, char* argv[]) {

    DataPoint* dataPoint = createDataPoint("testing", 1, 1);

    std::cout << dataPoint->label.str << std::endl;

    deleteDataPoint(&dataPoint);
    return 0;
}

DataPoint* createDataPoint(const char* label, const int xCoordinate, const int yCoordinate) {
    DataPoint* dataPoint = new DataPoint();
    dataPoint->label.str = new char[strlen(label)+1];
    memcpy(dataPoint->label.str, label, sizeof(*dataPoint->label.str)*strlen(label)+1);

    dataPoint->point.x = xCoordinate;
    dataPoint->point.y = yCoordinate;

    return dataPoint;
}

void deleteDataPoint(DataPoint** dataPoint) {
    if (*dataPoint) {
        std::cout << "before delete: " << (*dataPoint)->point.x << std::endl;
        delete[] (*dataPoint)->label.str;
        delete (*dataPoint);
        *dataPoint = nullptr; // Set to nullptr after deletion for safety
        std::cout << "Data Point successfully deleted" << std::endl;
    }
}
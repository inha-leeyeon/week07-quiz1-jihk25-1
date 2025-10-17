#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Point.h"
#include "Square.h"


//The first line should input a number (int type) indicating the number of stored squares.
//Starting from the second line, enter the name of the square, x-axis coordinates, y-axis coordinates, and side length in sequence.

//==Point==//

Point::Point(int x,int y):x(x),y(y){}

int Point::getX() const{return x;}
int Point::getY() const{return y;}
void Point::setX(int x){
    this->x = x;
}
void Point::setY(int y){
    this->y = y;
}

//==Square--//

Square::Square(const string, int x, int y, unsigned int s):Point(x,y), side{0},area{0},name{0}{
    setSide(s);
}

unsigned int Square::getSide() const{
    return side;
}
unsigned int Square::getArea() const{
    return area;
}
string Square::getName() const{
    return name;
}
void Square::setSide(unsigned int s){
    side = s;
}
void Square::setArea(unsigned int s){
   area = side*side;
}
void Square::setName(string name){
    this->name = name;
}

//==function==//
static inline int maxX(const Square& s) { return s.getX() + static_cast<int>(s.getSide()); }
static inline int maxY(const Square& s) { return s.getY() + static_cast<int>(s.getSide()); }

static bool lessArea(const Square& a, const Square& b) {
    if (a.getArea() != b.getArea()) return a.getArea() < b.getArea();
    if (a.getX() != b.getX()) return a.getX() < b.getX();
    if (a.getY() != b.getY()) return a.getY() < b.getY();
    return a.getName() < b.getName();
}
static bool lessMaxX(const Square& a, const Square& b) {
    int ax = maxX(a), bx = maxX(b);
    if (ax != bx) return ax < bx;
    if (a.getX() != b.getX()) return a.getX() < b.getX();
    if (a.getY() != b.getY()) return a.getY() < b.getY();
    return a.getName() < b.getName();
}
static bool lessMaxY(const Square& a, const Square& b) {
    int ay = maxY(a), by = maxY(b);
    if (ay != by) return ay < by;
    if (a.getX() != b.getX()) return a.getX() < b.getX();
    if (a.getY() != b.getY()) return a.getY() < b.getY();
    return a.getName() < b.getName();
}

static void insertByArea(std::vector<Square>& arr, const Square& s) {
    std::size_t i = 0;
    while (i < arr.size() && !lessArea(s, arr[i])) ++i;
    arr.insert(arr.begin() + static_cast<long long>(i), s);
}
static void insertByMaxX(std::vector<Square>& arr, const Square& s) {
    std::size_t i = 0;
    while (i < arr.size() && !lessMaxX(s, arr[i])) ++i;
    arr.insert(arr.begin() + static_cast<long long>(i), s);
}
static void insertByMaxY(std::vector<Square>& arr, const Square& s) {
    std::size_t i = 0;
    while (i < arr.size() && !lessMaxY(s, arr[i])) ++i;
    arr.insert(arr.begin() + static_cast<long long>(i), s);
}



int main() {
    using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Square> byArea;
    vector<Square> byMaxX;
    vector<Square> byMaxY;
    byArea.reserve(N);
    byMaxX.reserve(N);
    byMaxY.reserve(N);

    for (int i = 0; i < N; ++i) {
        string name; int x, y; unsigned int side;
        cin >> name >> x >> y >> side;
        Square s(name, x, y, side);
        insertByArea(byArea, s);
        insertByMaxX(byMaxX, s);
        insertByMaxY(byMaxY, s);
    }

    cout << '\n';

    // Order of Area//
    cout << "Squares in increasing order of area\n";
    for (const auto& s : byArea) {
        cout << s.getName() << '(' << s.getX() << ", " << s.getY() << ") "
             << "side=" << s.getSide() << ", area=" << s.getArea() << '\n';
    }

    cout << "\n";

    // Order of X//
    cout << "Squares in increasing order of max x-coordinate\n";
    for (const auto& s : byMaxX) {
        cout << s.getName() << '(' << maxX(s) << ", " << s.getY() << ") "
             << "side=" << s.getSide() << ", area=" << s.getArea() << '\n';
    }

    cout << "\n";

    // Order of Y//
    cout << "Squares in increasing order of max y-coordinate\n";
    for (const auto& s : byMaxY) {
        cout << s.getName() << '(' << s.getX() << ", " << maxY(s) << ") "
             << "side=" << s.getSide() << ", area=" << s.getArea() << '\n';
    }

    return 0;
}
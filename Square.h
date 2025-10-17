#pragma once
#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;


class Square : public Point {
  public:
  	Square(const string, int, int, unsigned int = 0);
  	unsigned int getSide() const;
  	unsigned int getArea() const;
  	string getName() const;
  	void setSide(unsigned int);
  	void setArea(unsigned int);
  	void setName(string);
  private:
  	unsigned int side; 
  	unsigned int area{ 0 };
  	string name;
  };
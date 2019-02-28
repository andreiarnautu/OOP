/**
  *  Worg
  */
#include <string>
#include <vector>
#include <iostream>

const double PI = 3.14159265359;

class Shape {
public:
  int height, index;
  double area, volume;
};

class Circle : public Shape {
public:
  int radius;

  void ComputeData() {
    this->area = (double)this->radius * this->radius * PI;
    this->volume = this->area * this->height;
  }
};

class Rectangle : public Shape {
public:
  int side_length_1, side_length_2;

  void ComputeData() {
    this->area = this->side_length_1 * this->side_length_2;
    this->volume = this->area * this->height;
  }
};

class Square : public Shape {
public:
  int side_length;

  void ComputeData() {
    this->area = this->side_length * this->side_length;
    this->volume = this->area * this->height;
  }
};

class Triangle : public Shape {
public:
  int side_length_1, side_length_2;

  void ComputeData() {
    this->area = (double)this->side_length_1 * this->side_length_2 / 2;
    this->volume = this->area * this->height;
  }
};

void AddNewShape(std::vector<Circle > &circles, std::vector<Rectangle > &rectangles, std::vector<Square > &squares, std::vector<Triangle > &triangles, int &current_index, double &jam, double &cream) {
  std::string s; std::cin >> s;

  //  Mai mergeau puse mici functii prin clase in loc sa le las in if-uri. Too late for that now.

  if (s == "cerc") {
    Circle circle;
    std::cin >> circle.radius;
    std::cin >> circle.height;
    circle.index = current_index++;
    circle.ComputeData();

    jam += circle.volume * 2;
    cream += circle.volume;

    std::cout << "Gem = " << circle.volume * 2 << "; Frisca = " << circle.volume << '\n';

    circles.push_back(circle);

  } else if (s == "dreptunghi") {
    Rectangle rectangle;
    std::cin >> rectangle.side_length_1 >> rectangle.side_length_2;
    std::cin >> rectangle.height;
    rectangle.index = current_index++;
    rectangle.ComputeData();

    jam += rectangle.volume * 2;
    cream += rectangle.volume;

    std::cout << "Gem = " << rectangle.volume * 2 << "; Frisca = " << rectangle.volume << '\n';

    rectangles.push_back(rectangle);
  } else if (s == "patrat") {
    Square square;
    std::cin >> square.side_length;
    std::cin >> square.height;
    square.index = current_index++;
    square.ComputeData();

    jam += square.volume * 2;
    cream += square.volume;

    std::cout << "Gem = " << square.volume * 2 << "; Frisca = " << square.volume << '\n';

    squares.push_back(square);
  } else if (s == "triunghi") {
    Triangle triangle;
    std::cin >> triangle.side_length_1 >> triangle.side_length_2;
    std::cin >> triangle.height;
    triangle.index = current_index++;
    triangle.ComputeData();

    jam += triangle.volume * 2;
    cream += triangle.volume;

    std::cout << "Gem = " << triangle.volume * 2 << "; Frisca = " << triangle.volume << '\n';

    triangles.push_back(triangle);
  }
}

void Remove(std::vector<Circle > &circles, std::vector<Rectangle > &rectangles, std::vector<Square > &squares, std::vector<Triangle > &triangles, double &jam, double &cream) {
  int index_to_delete; std::cin >> index_to_delete;

  for (auto iterator = circles.begin(); iterator != circles.end(); iterator++) {
    if (iterator->index == index_to_delete) {
      jam -= iterator->volume * 2; cream -= iterator->volume;
      circles.erase(iterator); return;
    }
  }

  for (auto iterator = rectangles.begin(); iterator != rectangles.end(); iterator++) {
    if (iterator->index == index_to_delete) {
      jam -= iterator->volume * 2; cream -= iterator->volume;
      rectangles.erase(iterator); return;
    }
  }

  for (auto iterator = squares.begin(); iterator != squares.end(); iterator++) {
    if (iterator->index == index_to_delete) {
      jam -= iterator->volume * 2; cream -= iterator->volume;
      squares.erase(iterator); return;
    }
  }

  for (auto iterator = triangles.begin(); iterator != triangles.end(); iterator++) {
    if (iterator->index == index_to_delete) {
      jam -= iterator->volume * 2; cream -= iterator->volume;
      triangles.erase(iterator); return;
    }
  }
}

int main() {
  int current_index = 1;
  double jam = 0, cream = 0;

  std::string command;
  //  Cum se face un singur vector care sa stocheze toate formele?
  std::vector<Circle > circles;
  std::vector<Rectangle > rectangles;
  std::vector<Square > squares;
  std::vector<Triangle > triangles;

  while (true) {
    std::cin >> command;
    if (command == "STOP") {
      break;
    } else if (command == "ADD") {
      AddNewShape(circles, rectangles, squares, triangles, current_index, jam, cream);
    } else if (command == "REMOVE") {
      Remove(circles, rectangles, squares, triangles, jam, cream);
    } else if (command == "TOTAL") {
      std::cout << "In total: gem = " << jam << "; frisca = " << cream << '\n';
    }
  }

  return 0;
}

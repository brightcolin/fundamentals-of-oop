#include <iostream>
#include <vector>
#include <iomanip>
#include "CP_EquilateralTriangle.h"
#include "CP_Square.h"
#include "CP_RegularPentagon.h"
#include "CP_RegularHexagon.h"
#include "CP_Circle.h"

using namespace std;

int main() {
    vector<Shape*> shapes;
    int cmd;
    cout << fixed << setprecision(4);
    cout << "===== Shape Calculator =====" << endl;

    while (true) {
        cout << "\n1. Equilateral Triangle  2. Square\n"
             << "3. Regular Pentagon      4. Regular Hexagon\n"
             << "5. Circle                0. Exit\n"
             << "Enter the shape number: ";
        
        if (!(cin >> cmd) || cmd == 0) break;

        Shape* shape = nullptr;
        double param;

        if (cmd >= 1 && cmd <= 4) {
            cout << "Enter the side length: ";
            cin >> param;
            if (cmd == 1)      shape = new EquilateralTriangle(param);
            else if (cmd == 2) shape = new Square(param);
            else if (cmd == 3) shape = new RegularPentagon(param);
            else if (cmd == 4) shape = new RegularHexagon(param);
        } else if (cmd == 5) {
            cout << "Enter the radius: ";
            cin >> param;
            shape = new Circle(param);
        } else {
            cout << "Invalid command." << endl;
            continue;
        }

        if (shape) {
            cout << "\n> " << shape->name() << " details:" << endl;
            cout << "Perimeter: " << shape->perimeter() << endl;
            cout << "Area: " << shape->area() << endl;
            cout << "Drawing:" << endl;
            shape->draw();
            shapes.push_back(shape);
        }
    }

    double totalP = 0, totalA = 0;
    for (Shape* s : shapes) {
        totalP += s->perimeter();
        totalA += s->area();
    }

    cout << "\n===== Summary =====" << endl;
    cout << "Total Shapes: " << shapes.size() << endl;
    cout << "Total Perimeter: " << totalP << endl;
    cout << "Total Area: " << totalA << endl;

    for (Shape* s : shapes) delete s;
    system("pause");
    return 0;
}
#include <iostream>
#include <vector>
#include "CP_Circle.h"
#include "CP_Rect.h"
#include "CP_Triangle.h"
using namespace std;

int main() {

    vector<CP_Shape*> scene;
    int type;

    cout << "========= 欢迎使用图形拼图系统 =========" << endl;
    cout << "提示：请先添加多个图形及其坐标，最后输入 0 开始拼合渲染。" << endl;

    while (true) {
        cout << "\n选择图形 (1:圆 2:矩形 3:三角形 0:生成拼图): ";
        if (!(cin >> type) || type == 0) break;

        char c;
        int x, y;
        cout << "输入填充字符 (如 * 或 #): "; cin >> c;
        cout << "输入位置坐标 (x y): "; cin >> x >> y;

        if (type == 1) {
            int r;
            cout << "输入半径: "; cin >> r;
            scene.push_back(new CP_Circle(x, y, r, c));
        }
        else if (type == 2) {
            int w, h;
            cout << "输入宽度和高度: "; cin >> w >> h;
            scene.push_back(new CP_Rect(x, y, w, h, c));
        }
        else if (type == 3) {
            int b, h;
            cout << "输入底边宽度: "; cin >> b;
            cout << "输入高度: ";    cin >> h;
            scene.push_back(new CP_Triangle(x, y, b, h, c));
        }
        cout << "添加成功！" << endl;
    }

    const int CANVAS_WIDTH = 60;
    const int CANVAS_HEIGHT = 25;

    cout << "\n正在拼合所有图形并生成画布...\n" << endl;

    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        for (int j = 0; j < CANVAS_WIDTH; j++) {
            char pixel = ' ';
            for (CP_Shape* s : scene) {
                if (s->mb_isIn(j, i)) {
                    pixel = s->getChar();
                }
            }
            cout << pixel;
        }
        cout << endl;
    }

    for (auto s : scene) {
        delete s;
    }
    scene.clear();

    cout << "\n渲染完毕！" << endl;
    system("pause");
    return 0;
}
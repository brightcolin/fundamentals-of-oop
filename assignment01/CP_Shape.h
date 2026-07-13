#ifndef CP_SHAPE_H
#define CP_SHAPE_H

class CP_Shape
{
    protected:
        char m_char;
        int m_x, m_y;
    public:
        CP_Shape(int x, int y, char c) : m_x(x), m_y(y), m_char(c) {};
        virtual ~CP_Shape() {};

        char getChar() {
            return m_char;
        }
        virtual void mb_show() = 0;
        virtual bool mb_isIn(int x, int y) = 0;
};

#endif

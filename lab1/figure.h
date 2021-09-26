
#ifndef FIGURE_H
#define FIGURE_H

class Figure {
public:
    virtual void Print (std::ostream &os) = 0;
    virtual size_t VerticesNumber() = 0;
    virtual double Area() = 0;
    virtual ~Figure() {};
};

#endif

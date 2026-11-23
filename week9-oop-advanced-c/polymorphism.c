#include <stdio.h>

// Base struct with a function pointer ("virtual method")
struct Shape {
    const char *type;
    double (*area)(const struct Shape *self);
};

// Derived struct 1: Circle
struct Circle {
    struct Shape base;
    double radius;
};

double circleArea(const struct Shape *self) {
    const struct Circle *c = (const struct Circle*)self;
    return 3.14159 * c->radius * c->radius;
}

void initCircle(struct Circle *c, double radius) {
    c->base.type = "Circle";
    c->base.area = circleArea;
    c->radius = radius;
}

// Derived struct 2: Rectangle
struct Rectangle {
    struct Shape base;
    double width;
    double height;
};

double rectangleArea(const struct Shape *self) {
    const struct Rectangle *r = (const struct Rectangle*)self;
    return r->width * r->height;
}

void initRectangle(struct Rectangle *r, double width, double height) {
    r->base.type = "Rectangle";
    r->base.area = rectangleArea;
    r->width = width;
    r->height = height;
}

int main() {
    struct Circle c1;
    struct Rectangle r1;

    initCircle(&c1, 5.0);
    initRectangle(&r1, 4.0, 6.0);

    // Polymorphic array of base Shape pointers
    struct Shape *shapes[2];
    shapes[0] = (struct Shape*)&c1;
    shapes[1] = (struct Shape*)&r1;

    printf("--- Polymorphic Area Calculation ---\n");
    for (int i = 0; i < 2; i++) {
        printf("%s Area: %.2f\n", shapes[i]->type, shapes[i]->area(shapes[i]));
    }

    return 0;
}
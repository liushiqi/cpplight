//
// Created by liu onchangeable.
//

#include "utils/Shape.h"
#include "utils/Scene.h"
#include "shapes/HalfSpace.h"
#include "shapes/Circle.h"
#include "shapes/UnionShape.h"

int main() {
    auto *halfSpace = new HalfSpace(0.5, 0.5, 0.0, 0.1, 0.8);
    auto *circle = new Circle(0.5, 0.5, 0.1, 2.0);
    auto *intersect = new UnionShape(halfSpace, circle);
    auto *scene = new Scene();
    scene->add(intersect);
    scene->flush();
    scene->print("temp.png");
    delete intersect;
    delete circle;
    delete halfSpace;
    delete scene;
    return 0;
}
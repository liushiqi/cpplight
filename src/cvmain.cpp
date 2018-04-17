//
// Created by liu on 18-1-10.
//

#include "utils/Scene.h"
#include "shape/HalfSpace.h"
#include "shape/Circle.h"
#include "shape/UnionShape.h"

int main() {
    auto *halfSpace = new HalfSpace(0.5, 0.5, 0.0, 0.1, 2.0);
    auto *circle = new Circle(0.5, 0.5, 0.1, 2.0);
    auto *intersect = new UnionShape(circle, halfSpace);
    auto *scene = new Scene();
    scene->add(intersect);
    scene->flush();
    scene->display("temp");
    delete intersect;
    delete circle;
    delete halfSpace;
    delete scene;
    return 0;
}
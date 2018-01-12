//
// Created by liu onchangeable.
//

#include "shape/Shape.h"
#include "shape/Scene.h"
#include "shape/HalfSpace.h"
#include "shape/Circle.h"
#include "shape/IntersectShape.h"

int main() {
    auto *halfSpace = new HalfSpace(0.5, 0.5, 0.0, 0.1, 2.0);
    auto *circle = new Circle(0.5, 0.5, 0.1, 2.0);
    auto *intersect = new IntersectShape(halfSpace, circle);
    auto *scene = new Scene();
    scene->add(intersect);
    scene->flush();
    scene->print("temp.png");
    scene->setSize(512, 768);
    scene->flush();
    scene->print("temp1.png");
    delete circle;
    delete halfSpace;
    delete scene;
    return 0;
}
//
// Created by liu onchangeable.
//

#include "shape/Shape.h"
#include "shape/Scene.h"
#include "shape/HalfSpace.h"

int main() {
    auto *halfSpace = new HalfSpace(0.5, 0.5, 0.0, 0.1, 1.0);
    auto *circle = new Circle(0.8, 0.8, 0.1, 2.0);
    auto *scene = new Scene();
    scene->add(circle);
    scene->flush();
    scene->print("temp.png");
    delete circle;
    delete halfSpace;
    delete scene;
    return 0;
}
//
// Created by liu onchangeable.
//

#include "shape/Shape.h"
#include "shape/Scene.h"
#include "shape/HalfSpace.h"

int main() {
    auto *halfSpace = new HalfSpace(0.5, 0.5, 0.0, 0.1, 1.0);
    auto *scene = new Scene();
    scene->add(halfSpace);
    scene->flush();
    scene->print("temp.png");
    scene->remove(halfSpace);
    scene->flush();
    scene->print("temp1.png");
    delete halfSpace;
    delete scene;
    return 0;
}
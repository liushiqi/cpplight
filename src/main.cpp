//
// Created by liu on 17-12-24.
//

#include "shape/Shape.h"
#include "shape/Scene.h"
#include "shape/Rectangle.h"

int main() {
    auto *scene = new Scene();
    scene->add(new Circle(0.5, 0.5, 0.1, 2.0));
    scene->flush();
    scene->print("temp.png");
    delete scene;
    return 0;
}
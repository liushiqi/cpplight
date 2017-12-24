//
// Created by liu on 17-12-24.
//

#include "shape/Shape.h"
#include "shape/Scene.h"
#include "shape/SubtractShape.h"

int main() {
    auto *scene = new Scene();
    scene->add(new SubtractShape(new Circle(0.6, 0.5, 0.20, 0.8), new Circle(0.4, 0.5, 0.20, 1.0)));
    scene->flush();
    scene->print("temp.png");
    delete scene;
    return 0;
}
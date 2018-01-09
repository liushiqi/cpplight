//
// Created by liu on 17-12-24.
//

#include "shape/Shape.h"
#include "shape/Scene.h"
#include "shape/Rectangle.h"

int main() {
    auto *rectangle = new Rectangle(0.6, 0.6, 0.2, 0.1, 0.1 * M_PI, 2.0);
    auto *scene = new Scene();
    scene->add(rectangle);
    scene->flush();
    scene->print("temp.png");
    scene->setSize(512, 1024);
    scene->flush();
    scene->print("temp1.png");
    delete rectangle;
    delete scene;
    return 0;
}
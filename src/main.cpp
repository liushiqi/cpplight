//
// Created by liu on 17-12-24.
//

#include "shape/Shape.h"
#include "shape/Scene.h"
#include "shape/Rectangle.h"

int main() {
    auto *scene = new Scene();
    scene->add(new Rectangle(0.5, 0.5, 0.2, 0.1, 0.1 * M_PI, 2.0));
    scene->flush();
    scene->print("temp.png");
    scene->setSize(1024, 512);
    scene->flush();
    scene->print("temp1.png");
    delete scene;
    return 0;
}
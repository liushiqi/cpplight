//
// Created by liu onchangeable.
//

#include "shape/Shape.h"
#include "shape/Scene.h"
#include "shape/Rectangle.h"

int main() {
    auto *scene = new Scene();
    scene->add(new Circle(0.5, 0.5, 0.1, 2.0));
    scene->add(new Rectangle(0.8, 0.2, 0.1, 0.1, 0.1 * M_PI, 2.0));
    scene->flush();
    scene->print("temp.png");
    /*scene->setSize(1024, 512);
    scene->flush();
    scene->print("temp1.png");*/
    delete scene;
    return 0;
}
//
// Created by liu on 18-1-10.
//

#include <ml.h>
#include <highgui.h>
#include "shape/Scene.h"
#include "shape/HalfSpace.h"
#include "shape/Circle.h"

int main() {
    auto *halfSpace = new HalfSpace(0.5, 0.5, 0.0, 0.1, 1.0);
    auto *circle = new Circle(0.8, 0.8, 0.1, 2.0);
    auto *scene = new Scene();
    scene->add(circle);
    scene->flush();
    scene->display("temp", 1000);
    scene->setSize(512, 768);
    scene->flush();
    scene->display("temp");
    delete circle;
    delete halfSpace;
    delete scene;
    return 0;
}
//
// Created by liu on 18-1-10.
//

#include <ml.h>
#include <highgui.h>
#include "shape/Scene.h"
#include "shape/HalfSpace.h"
#include "shape/Circle.h"
#include "shape/IntersectShape.h"

int main() {
    auto *halfSpace = new HalfSpace(0.5, 0.5, 0.0, 0.1, 1.0);
    auto *circle = new Circle(0.5, 0.5, 0.1, 2.0);
    auto *intersect = new IntersectShape(halfSpace, circle);
    auto *scene = new Scene();
    scene->add(intersect);
    scene->flush();
    scene->display("temp", 1000);
    scene->setSize(512, 768);
    scene->flush();
    scene->display("temp");
    delete intersect;
    delete circle;
    delete halfSpace;
    delete scene;
    return 0;
}
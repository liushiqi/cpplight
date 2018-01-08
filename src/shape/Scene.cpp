//
// Created by liu on 17-12-23.
//

#include <algorithm>
#include <iostream>
#include "../svpng.inc"
#include "Scene.h"

Scene::Scene(unsigned int width, unsigned int height) : height(height), width(width), distribution(0.0f, 1.0f) {
    graph = new unsigned char[width * height * 3];
}

Scene::~Scene() {
    for (auto shape : shapes) {
        delete shape;
    }
    delete[] graph;
}

void Scene::add(Shape *shape) {
    shapes.push_back(shape);
}

double Scene::trace(const Point &point, double degree) {
    Line line(point, std::cos(degree), std::sin(degree));
    double minDistance = std::numeric_limits<double>::max();
    double emissive = 0.0f;
    for (auto shape : shapes) {
        auto points = shape->intersect(line);
        if (points.size() > 1) {
            auto poi = *(points.begin()++);
            if (poi.distance < minDistance) {
                emissive = poi.emissive;
                minDistance = poi.distance;
            }
        }
    }
    return emissive;
}

double Scene::sample(const Point &point) {
    double sum = 0.0;
    for (int i = 0; i < N; ++i) {
        double degree = M_PI * 2 * (i + distribution(engine)) / N;
        sum += trace(point, degree);
    }
    return sum / N;
}

void Scene::flush() {
    int scaling = std::min(width, height);
    unsigned char *p = graph;
    Point point = Point(0.0f, 0.0f);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x, p += 3) {
            point.setPosition((double) x / scaling, (double) y / scaling);
            p[0] = p[1] = p[2] = (unsigned char) std::min(sample(point) * 255.0, 255.0);
        }
    }
}

void Scene::print(std::string filename) {
    svpng(fopen(filename.c_str(), "wb"), width, height, graph, 0);
}

void Scene::setSize(unsigned int width, unsigned int height) {
    delete[] graph;
    this->width = width;
    this->height = height;
    graph = new unsigned char[width * height * 3];
}

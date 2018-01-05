//
// Created by liu on 17-12-23.
//

#include <algorithm>
#include <iostream>
#include "../svpng.inc"
#include "Scene.h"

Scene::Scene() : distribution(0.0f, 1.0f) {}

Scene::~Scene() {
    for (auto shape : shapes) {
        delete shape;
    }
}

void Scene::add(Shape *shape) {
    shapes.push_back(shape);
}

std::pair<double, double> Scene::distance(const Point &point) {
    auto minDistance = shapes.front()->distance(point);
    for (auto &shape : shapes) {
        auto distance = shape->distance(point);
        if (minDistance.first > distance.first) {
            minDistance = distance;
        }
    }
    return minDistance;
}

double Scene::oldTrace(const Point &point, double degree) {
    double trace = 0.001, dx = std::cos(degree), dy = std::sin(degree);
    Point tracedPoint(point);
    for (int i = 0; i < MAX_TRACE_STEP && trace < MAX_TRACE_DISTANCE; ++i) {
        tracedPoint.setPosition(point.x + dx * trace, point.y + dy * trace);
        auto pair = distance(tracedPoint);
        if (pair.first < EPSILON) {
            return pair.second;
        }
        trace += pair.first;
    }
    return 0.0;
}

double Scene::trace(const Point &point, double degree) {
    Line line(point, std::cos(degree), std::sin(degree));
    std::set<std::pair<Point, double>, Compare> insertedPoints;
    Shape *minimumShape = *shapes.begin();
    for (auto shape : shapes) {
        auto points = shape->intersect(line);
        for (auto &pointMessage : points) {
            if ((*(points.begin()++)).second > pointMessage.second)
                minimumShape = shape;
            insertedPoints.insert(pointMessage);
        }
    }
    if (insertedPoints.size() == 1) {
        return 0;
    } else {
        return minimumShape->getEmissive();
    }
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
    unsigned char *p = graph;
    Point point = Point(0.0f, 0.0f);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x, p += 3) {
            point.setPosition((double) x / width, (double) y / height);
            p[0] = p[1] = p[2] = (unsigned char) std::min(sample(point) * 255.0, 255.0);
        }
    }
}

void Scene::print(std::string filename) {
    svpng(fopen(filename.c_str(), "wb"), width, height, graph, 0);
}

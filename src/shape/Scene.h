//
// Created by liu on 17-12-23.
//

#ifndef CPPLIGHT_SCENE_H
#define CPPLIGHT_SCENE_H

#include <vector>
#include "Shape.h"
#include "Circle.h"

class Scene {
    public:
        static constexpr int width = 512;
        static constexpr int height = 512;
        static constexpr int N = 64;

        static constexpr int MAX_TRACE_STEP = 64;
        static constexpr double MAX_TRACE_DISTANCE = 2.0;
        static constexpr double EPSILON = 1e-6;

        Scene();

        ~Scene();

        void add(Shape *shape);

        std::pair<double, double> distance(const Point &point);

        double oldTrace(const Point &point, double degree);

        double trace(const Point& point, double degree);

        double sample(const Point &point);

        void flush();

        void print(std::string filename);

    private:
        std::vector<Shape *> shapes;
        unsigned char graph[width * height * 3];
        std::default_random_engine engine;
        std::uniform_real_distribution<double> distribution;

};

#endif //CPPLIGHT_SCENE_H

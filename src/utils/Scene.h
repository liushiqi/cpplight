//
// Created by liu on 17-12-23.
//

#ifndef CPPLIGHT_SCENE_H
#define CPPLIGHT_SCENE_H

#include <vector>
#include "Shape.h"

class Scene {
    public:
        static constexpr int N = 256;
        static constexpr double EPSILON = 1e-12;

        Scene(unsigned int width = 512, unsigned int height = 512);

        ~Scene();

        void add(Shape *shape);

        Shape *remove(Shape *shape);

        double trace(const Point &point, double degree);

        double sample(const Point &point);

        void flush();

        void print(std::string filename);

        void setSize(unsigned int width, unsigned int height);

#ifdef HAVE_OPENCV
        void display(const std::string &windowName, int waitTime = 0);
#endif

    private:
        unsigned int height = 512;
        unsigned int width = 512;
        std::vector<Shape *> shapes;
        std::default_random_engine engine;
        std::uniform_real_distribution<double> distribution;
        unsigned char *graph;

};

#endif //CPPLIGHT_SCENE_H

//
// Created by liu on 17-12-24.
//

#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../src/shape/Circle.h"
#include "../src/shape/Rectangle.h"

using namespace boost;
using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE(test_cases)

    BOOST_AUTO_TEST_CASE(circle) {
        Circle circle = Circle(0.5, 0.5, 0.1, 2.0);
        Line line = Line(Point(0.0, 0.0), std::sqrt(2) / 2, std::sqrt(2) / 2);
        auto list = circle.intersect(line);
        BOOST_CHECK_EQUAL((++list.begin())->x, 0.5 - std::sqrt(2.0) / 20);
    }

    BOOST_AUTO_TEST_CASE(rectangle) {
        Rectangle rectangle = Rectangle(0.5, 0.5, 0.1, 0.1, 0.0, 2.0);
        Line line = Line(Point(0.5, 1.0), 0.0, -1.0);
        auto list = rectangle.intersect(line);
        BOOST_CHECK_EQUAL((++list.begin())->x, 0.5);
    }

    BOOST_AUTO_TEST_CASE(rectangle_no_insersect) {
        Rectangle rectangle = Rectangle(0.5, 0.5, 0.1, 0.1, 0.0, 2.0);
        Line line = Line(Point(0.5, 1.0), std::sqrt(2) / 2, std::sqrt(2) / 2);
        auto list = rectangle.intersect(line);
        BOOST_CHECK_EQUAL(list.size(), 1);
    }

BOOST_AUTO_TEST_SUITE_END()
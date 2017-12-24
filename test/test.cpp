//
// Created by liu on 17-12-24.
//

#define BOOST_TEST_MODULE maintest

#include <boost/test/unit_test.hpp>
#include "../src/shape/Circle.h"

using namespace boost;
using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE(universe_suite)

    BOOST_AUTO_TEST_CASE(circle) {
        Circle circle = Circle(0.5, 0.5, 0.1, 2.0);
        Point point = Point(0.0, 0.0);
        BOOST_CHECK(std::abs(circle.distance(point).first - 0.60710678) < 1e-6);
    }

    BOOST_AUTO_TEST_CASE(fail) {
        BOOST_CHECK(0 == 1);
    }

BOOST_AUTO_TEST_SUITE_END()
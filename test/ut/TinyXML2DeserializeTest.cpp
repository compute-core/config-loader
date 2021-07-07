//
// Created by netcan on 2021/07/06.
//

#include <catch2/catch.hpp>
#include <tinyxml2.h>
#include <iostream>
#include "ReflectedStruct.h"
#include "DeserializeXMLConfig.h"
#include <config-loader/ConfigLoader.h>
using namespace Catch;
using namespace tinyxml2;
using namespace CONFIG_LOADER_NS;

SCENARIO("deserialize a xml to obj") {
    WHEN("deserialize a plain point config") {
        Point point;
        Deserializable<Point, TinyXML2Tag> deserializer;
        auto res = deserializer.load(point, [] {
            return POINT_CONFIG;
        });
        REQUIRE(res == Result::SUCCESS);
        REQUIRE(point.x == 1.2);
        REQUIRE(point.y == 3.4);
    }

    WHEN("deserialize a nest rect config") {
        Rect rect;
        Deserializable<Rect, TinyXML2Tag> deserializer;
        auto res = deserializer.load(rect, [] {
            return RECT_CONFIG;
        });
        REQUIRE(res == Result::SUCCESS);
        REQUIRE(rect.p1.x == 1.2);
        REQUIRE(rect.p1.y == 3.4);
        REQUIRE(rect.p2.x == 5.6);
        REQUIRE(rect.p2.y == 7.8);
        REQUIRE(rect.color == 0x12345678);
    }

    WHEN("deserialize a complex rect config") {
        SomeOfPoints someOfPoints;
        Deserializable<SomeOfPoints, TinyXML2Tag> deserializer;
        auto res = deserializer.load(someOfPoints, [] {
            return SOME_OF_POINTS_CONFIG;
        });
        REQUIRE(res == Result::SUCCESS);
        REQUIRE_THAT(someOfPoints.name,
                     Equals("Some of points"));
        REQUIRE(someOfPoints.points.size() == 3);
        double pointsV[] = {
                1.2, 3.4,
                5.6, 7.8,
                2.2, 3.3
        };
        for (size_t i = 0; i < someOfPoints.points.size(); ++i) {
            REQUIRE(someOfPoints.points[i].x == pointsV[i * 2]);
            REQUIRE(someOfPoints.points[i].y == pointsV[i * 2 + 1]);
        }
    }

}

#pragma once
#include <vector>
#include <string>
#include <map>

struct VectorData {
    struct Geometry {
        enum class Type { Point, LineString, Polygon };
        Type type;
        // Nested for polygons/rings
        std::vector<std::vector<double>> coordinates; 
    };

    struct Feature {
        Geometry geometry;
        // Key-value pairs for feature properties
        std::map<std::string, std::string> attributes; 
    };

    std::vector<Feature> features;

    VectorData() = default;
    void addFeature(const Feature& feature) {
        features.push_back(feature);
    }
};

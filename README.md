<img src="https://github.com/Robertcsollei/TerraKit/blob/main/resources/TerraKit.png" alt="TerraKit" style="width: 100%; height: 64px;">

A lightweight, cross-platform Globe-first GIS viewer/editor.

## Overview

TerraKit is an experimental GIS toolkit and viewer I’m building with a globe-first focus. The goal is to provide a minimal, clear, and hackable foundation for geospatial visualization—without the heavy overhead of a full GIS stack.

- Cross-platform: Desktop (Windows/Linux/macOS) via C++/OpenGL, Web via WebAssembly/WebGL2.
- Globe-first: Starts with a 3D Earth viewer and will evolve into a lightweight GIS editor.
- Minimal footprint: Favors explicit, testable components over opaque “engine magic.”
- Hackable: Designed to be extended, embedded, or repurposed in other geospatial projects.

## Why TerraKit?

To explore geospatial rendering pipelines (LOD tiles, terrain shaders, atmospheric effects).
To provide a GIS base layer that can grow into tools for analysis, paleo-channel detection, environmental simulation, etc.
To serve as a learning project and reference for others who want to see how a GIS viewer can be built from scratch.

## Planned Features

✅ Basic 3D globe (with tiled raster imagery)
✅ Camera controls (orbit / pan / zoom)
✅ Simple layer system (imagery + vector overlays)

## Roadmap

 - DEM-based terrain (elevation tiles, shading)
 - Atmospheric rendering (space-to-ground transitions)
 - Vector data overlays (GeoJSON, shapefiles via converter)
 - Minimal edit tools (draw, measure, annotate)
 - Paleochannel & hydrology plugins (future)
 - Export/import to common GIS formats

## Dependencies

C++20, CMake
SDL2 (window/context/input)
GLM (math)
glad (OpenGL loader)
stb_image (textures)
(Planned) GDAL for raster/vector I/O

## Getting Started
```
git clone https://github.com/yourname/TerraKit.git
cd TerraKit
cmake -B build
cmake --build build
./build/TerraKit
```

## Philosophy


TerraKit is not trying to replace full-blown GIS systems (QGIS, Cesium, ArcGIS). Instead, it’s a small, explicit toolkit for experimenting with geospatial data, rendering pipelines, and cross-platform GIS apps. Think of it as a sandbox or base layer you can grow from.




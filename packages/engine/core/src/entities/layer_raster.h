#pragma once
#include "entities/layer.h"
#include "data/raster_data.h"

class LayerRaster : public Layer {

public:
LayerRaster(const std::string& name = "Raster layer")
	: Layer(name) {}

~LayerRaster() override = default;


public:
void setRasterData(const std::shared_ptr<RasterData>& data);
std::shared_ptr<RasterData> getRasterData() const {  return rasterData; }

private:
    std::shared_ptr<RasterData> rasterData;

};
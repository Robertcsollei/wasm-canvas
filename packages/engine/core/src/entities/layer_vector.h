#pragma once
#include "entities/layer.h"
#include "data/vector_data.h"

class LayerVector : public Layer {

public:
	LayerVector(const std::string& name = "Vector layer")
		: Layer(name) {}

	~LayerVector() override = default;


public:
	void setVectorData(const std::shared_ptr<VectorData>& data);
	std::shared_ptr<VectorData> getVectorData() const { return vectorData; }

private:
	std::shared_ptr<VectorData> vectorData;

};

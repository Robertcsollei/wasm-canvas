#pragma once
#include <string>
#include <memory>
#include <core/uuid.h>

class LayerManager;

class Layer : public std::enable_shared_from_this<Layer> {

public:
	Layer(const std::string& name);
	Layer(const std::string& name, uuids::uuid uuid);
	virtual ~Layer() = default;

	const std::weak_ptr<Layer>& parent() const { return m_parent; }
	void setParent(const std::shared_ptr<Layer>& parent) { m_parent = parent; }
	void resetParent() { m_parent.reset(); }

public:
	bool isEffectivelyVisible();

protected:
	std::weak_ptr<Layer> m_parent;

private:
	friend class LayerManager;

	bool m_visible = true;
	std::string m_name;
	const uuids::uuid m_uuid;
};
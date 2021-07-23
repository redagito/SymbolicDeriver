#pragma once

#include <memory>
#include <string>

#include "INode.h"

// Represents a constant value
class ConstNode : public INode
{
public:
	ConstNode(std::string value);
	void accept(IVisitor& visitor);

	std::string getValue() const;

private:
	std::string m_value;
};
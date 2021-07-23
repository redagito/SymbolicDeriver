#pragma once

#include <memory>
#include <string>

#include "INode.h"

// Represents a variable
class VarNode : public INode
{
public:
	VarNode(std::string value);
	void accept(IVisitor& visitor);

	std::string getName() const;

private:
	std::string m_name;
};
#pragma once

#include <memory>

#include "INode.h"

// Represents an addition
class AddNode : public INode 
{
public:
	AddNode(std::shared_ptr<INode> left, std::shared_ptr<INode> right);
	void accept(IVisitor& visitor);

	std::shared_ptr<INode> getLeft();
	std::shared_ptr<INode> getRight();

private:
	std::shared_ptr<INode> m_left;
	std::shared_ptr<INode> m_right;
};
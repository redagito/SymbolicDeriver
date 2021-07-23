#include "AddNode.h"

#include "IVisitor.h"

AddNode::AddNode(std::shared_ptr<INode> left, std::shared_ptr<INode> right)
	: m_left(left), m_right(right)
{ }

void AddNode::accept(IVisitor& visitor)
{
	visitor.visit(*this);
}

std::shared_ptr<INode> AddNode::getLeft()
{
	return m_left;
}

std::shared_ptr<INode> AddNode::getRight()
{
	return m_right;
}
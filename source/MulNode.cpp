#include "MulNode.h"

#include "IVisitor.h"

MulNode::MulNode(std::shared_ptr<INode> left, std::shared_ptr<INode> right)
	: m_left(left), m_right(right)
{ }

void MulNode::accept(IVisitor& visitor)
{
	visitor.visit(*this);
}

std::shared_ptr<INode> MulNode::getLeft()
{
	return m_left;
}

std::shared_ptr<INode> MulNode::getRight()
{
	return m_right;
}
#include "ConstNode.h"

#include "IVisitor.h"

ConstNode::ConstNode(std::string value)
	: m_value(value)
{ }

void ConstNode::accept(IVisitor& visitor)
{
	visitor.visit(*this);
}

std::string ConstNode::getValue() const
{
	return m_value;
}
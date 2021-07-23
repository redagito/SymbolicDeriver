#include "VarNode.h"

#include "IVisitor.h"

VarNode::VarNode(std::string value)
	: m_name(value)
{ }

void VarNode::accept(IVisitor& visitor)
{
	visitor.visit(*this);
}

std::string VarNode::getName() const
{
	return m_name;
}
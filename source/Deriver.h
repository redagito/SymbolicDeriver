#pragma once

#include <memory>

#include "IVisitor.h"

class INode;
class AddNode;
class MulNode;
class ConstNode;
class VarNode;

// Traverses nodes and builds equation tree with first derivate
class Deriver : public IVisitor
{
public:
	void visit(AddNode& node);
	void visit(MulNode& node);
	void visit(ConstNode& node);
	void visit(VarNode& node);

	std::shared_ptr<INode> getResult() const;

private:
	std::shared_ptr<INode> m_result;
};
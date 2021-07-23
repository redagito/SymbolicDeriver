#pragma once

class AddNode;
class MulNode;
class ConstNode;
class VarNode;

// Visitor interface for traversing node tree
class IVisitor {
public:
	virtual ~IVisitor() {}
	virtual void visit(AddNode& node) = 0;
	virtual void visit(MulNode& node) = 0;
	virtual void visit(ConstNode& node) = 0;
	virtual void visit(VarNode& node) = 0;
};
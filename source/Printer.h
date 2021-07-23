#pragma once

#include <string>

#include "IVisitor.h"

// For printing formula trees
class Printer : public IVisitor
{
public:
	void visit(AddNode& node);
	void visit(MulNode& node);
	void visit(ConstNode& node);
	void visit(VarNode& node);

	std::string getText() const;

private:
	std::string m_text;
};
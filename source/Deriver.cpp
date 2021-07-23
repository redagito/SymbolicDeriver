#include "Deriver.h"

#include "AddNode.h"
#include "MulNode.h"
#include "ConstNode.h"
#include "VarNode.h"

void Deriver::visit(AddNode& node)
{
	Deriver left;
	Deriver right;

	node.getLeft()->accept(left);
	node.getRight()->accept(right);

	// f(x) = g(x) + h(x)
	// f'(x) = g'(x) + h'(x)
	m_result = std::make_shared<AddNode>(left.getResult(), right.getResult());
}

void Deriver::visit(MulNode& node)
{
	Deriver left;
	Deriver right;

	node.getLeft()->accept(left);
	node.getRight()->accept(right);

	// f(x) = g(x) * h(x)
	// f'(x) = g'(x) * h(x) + g(x) + h'(x)
	auto left_mul = std::make_shared<MulNode>(left.getResult(), node.getRight());
	auto right_mul = std::make_shared<MulNode>(node.getLeft(), right.getResult());
	m_result = std::make_shared<AddNode>(left_mul, right_mul);
}

void Deriver::visit(ConstNode& node)
{
	// f(x) = c
	// f'(x) = 0
	m_result = std::make_shared<ConstNode>("0");
}

void Deriver::visit(VarNode& node)
{
	// f(x) = x
	// f'(x) = 1
	m_result = std::make_shared<ConstNode>("1");
}

std::shared_ptr<INode> Deriver::getResult() const
{
	return m_result;
}
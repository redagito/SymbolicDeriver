#include "Printer.h"

#include <iostream>

#include "AddNode.h"
#include "MulNode.h"
#include "ConstNode.h"
#include "VarNode.h"

void Printer::visit(AddNode& node)
{
	node.getLeft()->accept(*this);
	auto left = getText();
	node.getRight()->accept(*this);
	auto right = getText();

	// Simplify
	if (left == "0" && right == "0") {
		m_text = "0";
	}
	else if (left == "0")
	{
		m_text = right;
	}
	else if (right == "0") 
	{
		m_text = left;
	}
	else
	{
		m_text = left + " + " + right;
	}
}

void Printer::visit(MulNode& node)
{
	node.getLeft()->accept(*this);
	auto left = getText();
	if (left == "0") 
	{
		m_text = "0";
		return;
	}

	node.getRight()->accept(*this);
	auto right = getText();
	if (right == "0")
	{
		m_text = "0";
		return;
	}

	if (left == "1")
	{
		m_text = right;
	}
	else if (right == "1")
	{
		m_text = left;
	}
	else
	{
		m_text = "(" + left + ") * (" + right + ")";
	}
}

void Printer::visit(ConstNode& node)
{
	m_text = node.getValue();
}

void Printer::visit(VarNode& node)
{
	m_text = node.getName();
}

std::string Printer::getText() const
{
	return m_text;
}
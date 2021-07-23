#pragma once

class IVisitor;

// Node interface for visitor pattern
class INode
{
public:
	virtual ~INode() {}
	virtual void accept(IVisitor& visitor) = 0;
};
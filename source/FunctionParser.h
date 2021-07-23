#pragma once

#include <string>
#include <memory>

#include "INode.h"

// Parse equation from string expression into tree and return root
// TODO Implement
std::shared_ptr<INode> parse(std::string function);
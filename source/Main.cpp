#include <iostream>
#include <memory>

#include "AddNode.h"
#include "MulNode.h"
#include "ConstNode.h"
#include "VarNode.h"

#include "Deriver.h"
#include "Printer.h"

int main(int argc, char** argv)
{
	// f(x) = 5 * x^2 + 7 * x
	// f'(x) = 5 * 2 * x + 7
	auto val_2 = std::make_shared<ConstNode>("2");
	auto val_5 = std::make_shared<ConstNode>("5");
	auto val_7 = std::make_shared<ConstNode>("7");
	auto var_x = std::make_shared<VarNode>("x");

	// x^2
	auto x_mul_x = std::make_shared<MulNode>(var_x, var_x);
	// 5 * x^2
	auto 5_mul_x_mul_x = std::make_shared<MulNode>(val_5, x_mul_x);

	// x * 7
	auto x_mul_7 = std::make_shared<MulNode>(var_x, val_7);
	// 5 * x^2 + x * 7
	auto eq = std::make_shared<AddNode>(5_mul_x_mul_x, x_mul_7);

	Deriver deriver; 
	Printer printer;
	
	// Print initial equation
	eq->accept(printer);
	std::cout << printer.getText() << std::endl;

	// Derive and print result
	eq->accept(deriver);
	deriver.getResult()->accept(printer);
	std::cout << printer.getText() << std::endl;

	return 0;
}
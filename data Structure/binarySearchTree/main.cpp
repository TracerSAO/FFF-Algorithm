#include <iostream>
#include <cstdlib>
#include "BST.h"

int main()
{
	BST world({ 5, 2, 3, 1, 8, 6, 7 });
	//std::cout << &world << std::endl;
	world.printf_Preorder_traversal(std::cout, world.getRoot()) << '\n';
	world.printf_Inorder_traversal(std::cout, world.getRoot()) << '\n';
	world.printf_Postorder_traversal(std::cout, world.getRoot()) << std::endl;
	world.printf_Level_traversal(std::cout, world.getRoot()) << std::endl;

	if (world.find(8)) std::cout << "world.find(8) true\n";
	else std::cout << "world.find(8) false\n";

	world.remove(8);
	world.printf_Preorder_traversal(std::cout, world.getRoot()) << std::endl;

	if (world.find(8)) std::cout << "world.find(8) true\n";
	else std::cout << "world.find(8) false\n";
	world.printf_Level_traversal(std::cout, world.getRoot()) << std::endl;

	system("pause");
}
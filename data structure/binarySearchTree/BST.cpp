#include "BST.h"

BST::BST() : _size(0), _root(nullptr) {}

BST::BST(const std::initializer_list<int>& ll) :
	_root(nullptr), _size(0)
{
	for (auto i = ll.begin(); i != ll.end(); i++)
		insert(*i);
	_size = ll.size();
}

//BST::BST(const BST& BST)
//{
//	// 按值拷贝 —— 将 BST 中的元素全部拷贝一份
//	// 果然，smart pointer 这种东西，是非常棒的 —— 它是直接把 按指针复制 的操作，从实际实现中提炼出来，作为一种通用功能来使用
//	// 太方便了!
//}
//
//BST& BST::operator=(const BST& BST)
//{
//	// 按值拷贝 —— 将 BST 中的元素全部拷贝一份
//
//}

BST::~BST()
{
	free();
}

void BST::free()
{
	if (nullptr == _root) return;

	BSTNode* tmp = _free(_root);
	delete tmp;
}

BSTNode* BST::_free(BSTNode*& node)
{
	if (nullptr == node)
		return nullptr;

	BSTNode* tmpLT = _free(node->_left);
	BSTNode* tmpRT = _free(node->_right);

	if (nullptr != tmpLT) delete tmpLT;
	if (nullptr != tmpRT) delete tmpRT;
	return node;
}

void BST::insert(int value)
{
	_insert(_root, value);
}

void BST::_insert(BSTNode*& node, int& val)
{
	if (nullptr == node) {
		node = new BSTNode(val);
		return;
	}

	if (node->_value > val)		 _insert(node->_left, val);
	else if (node->_value < val) _insert(node->_right, val);
	else						 return;
}

void BST::remove(int value)
{
	if (nullptr == _root) return;

	_root = _remove(_root, value);
}

BSTNode* BST::_remove(BSTNode*& node, int& val)
{
	if (nullptr == node) return nullptr;

	if (node->_value > val)      node->_left = _remove(node->_left, val);
	else if (node->_value < val) node->_right = _remove(node->_right, val);
	else {
		BSTNode* tmp;
		if (nullptr != node->_left && nullptr != node->_right) {	// 左右子节点都不为空，则左子节点合并到右子节点 —— 即：将左子节点插入到右子节点的最小的节点的后面
			tmp = _find_MIN(node->_right);
			tmp->_left = node->_left;
			tmp = node->_right;
		}
		else tmp = (nullptr == node->_left ? node->_right : node->_left);
		delete node;
		node = tmp;
	}

	return node;
}

BSTNode* BST::_find_MAX(BSTNode*& node)
{
	if (nullptr == node) return nullptr;
	if (nullptr == node->_right) return node;

	return _find_MAX(node->_right);
}

BSTNode* BST::_find_MIN(BSTNode*& node)
{
	if (nullptr == node) return nullptr;
	if (nullptr == node->_left) return node;

	return _find_MIN(node->_left);
}

bool BST::find(int val) const
{
	return _find(_root, val);
}

BSTNode* BST::getRoot()
{
	return _root;
}

bool BST::_find(const BSTNode* const& node, int& val) const
{
	if (nullptr == node) return false;

	if (node->_value == val) return true;
	if (node->_value > val)  return _find(node->_left, val);
	if (node->_value < val)  return _find(node->_right, val);
}

std::ostream& BST::printf_Preorder_traversal(std::ostream& out, const BSTNode* const& node) const
{
	if (nullptr == node) return out;

	out << node->_value << '_';
	printf_Preorder_traversal(out, node->_left);
	printf_Preorder_traversal(out, node->_right);

	return out;
}

std::ostream& BST::printf_Postorder_traversal(std::ostream& out, const BSTNode* const& node) const
{
	if (nullptr == node) return out;

	printf_Postorder_traversal(out, node->_left);
	printf_Postorder_traversal(out, node->_right);
	out << node->_value << '_';

	return out;
}

std::ostream& BST::printf_Inorder_traversal(std::ostream& out, const BSTNode* const& node) const
{
	if (nullptr == node) return out;

	printf_Inorder_traversal(out, node->_left);
	out << node->_value << '_';
	printf_Inorder_traversal(out, node->_right);

	return out;
}

std::ostream& BST::printf_Level_traversal(std::ostream& out, const BSTNode* const& node) const
{
	if (nullptr == node) return out;

	std::queue<const BSTNode*> levelQ;
	levelQ.push(node);

	while (!levelQ.empty()) {
		const BSTNode* tmp = levelQ.front();
		levelQ.pop();
		if (nullptr != tmp->_left)  levelQ.push(tmp->_left);
		if (nullptr != tmp->_right) levelQ.push(tmp->_right);

		out << tmp->_value << '_';
	}

	return out;
}


bool BST::isEmpty() const
{
	return _size == 0 ? true : false;
}

size_t BST::size() const
{
	return _size;
}

std::ostream& operator<<(std::ostream& out, const BST* const& BST)
{
	//return BST->printf_Preorder_traversal(out, BST->_root);
	return BST->printf_Postorder_traversal(out, BST->_root);
}

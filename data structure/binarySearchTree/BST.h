#pragma once

#include <cstdio>
#include <utility>
#include <queue>
#include <ostream>

struct BSTNode {
	BSTNode(int value) : _value(value), _left(nullptr), _right(nullptr) {}

	int _value;
	BSTNode* _left;
	BSTNode* _right;
};

class BST {
public:
	BST();
	BST(const std::initializer_list<int>& ll);
	//BST(const BST& BST);
	//BST& operator=(const BST& BST);
	~BST();

	bool isEmpty() const;
	size_t size() const;

	void insert(int value);
	void remove(int value);
	bool find(int value) const;
	BSTNode* getRoot();

private:
	void free();
	BSTNode* _free(BSTNode*& node);
	void _insert(BSTNode*& node, int& value);
	BSTNode* _remove(BSTNode*& node, int& value);
	BSTNode* _find_MIN(BSTNode*& node);
	BSTNode* _find_MAX(BSTNode*& node);		// 这里就有一个疑问啦，_find_MAX 不会修改 成员属性，但是，它返回的却是一个 非 const 的指向成员的指针
	bool _find(const BSTNode* const& node, int& value) const;

public:
	std::ostream& printf_Preorder_traversal(std::ostream& out, const BSTNode* const& node) const;
	std::ostream& printf_Postorder_traversal(std::ostream& out, const BSTNode* const& node) const;
	std::ostream& printf_Inorder_traversal(std::ostream& out, const BSTNode* const& node) const;
	std::ostream& printf_Level_traversal(std::ostream& out, const BSTNode* const& node) const;


private:
	size_t _size;
	BSTNode* _root;

	friend std::ostream& operator<<(std::ostream& out, const BST* const& BST);
};


//#ifndef BST_H
//#define BST_H
//
//#include <cstdio>
//#include <cstdlib>
//#include <cstdbool>
//#include <cassert>
//#include <iostream>
//#include <stack>
//
//template<class commonType> class BSTNode
//{
//public:
//    BSTNode() = default;
//    ~BSTNode();
//
//    // get-Interface
//    CommonType getCommonType() const;
//    BSTNode* getLeftNode() const;
//    BSTNode* getRightNode() const;
//    // set-Interface
//    void setCommonType();
//    void setLeftNode();
//    void setRightNode();
//
//private:
//    CommonType value;
//    BSTNode* leftNext = NULL;
//    BSTNode* rightNext = NULL;
//
//};

//template<class commonType> class BST
//{
//public:
//    BST();
//    BST(int n);
//    BST(BSTNode* root);
//    BST(int n, BSTNode* root);
//    ~BST();
//
//    // get-Interface
//    int getSize() const;
//    BSTNode* getRoot() const;
//    // set-Interface
//    void setSize();
//    void setRoot();
//
//    // function-Interface
//    bool isEmpty() const;       // 判断 tree 是否为空
//    bool contains(BSTNode const& node) const;   // 判断元素在 tree 中是否存在
//    void preOrder() const;      // 前序遍历
//    void inOrder() const;       // 中序遍历
//    void postOrder() const;     // 后序遍历
//    commonType minmu() const;   // 返回 tree 最小值
//    commonType maxmu() const;   // 返回 tree 最大值
//    bool addNode(commonType const& element);             // 向 tree 中添加元素
//    bool removeMIN();           // 移除 tree 中最小值
//    bool removeMAX();           // 移除 tree 中最大值
//    bool removeNode(commonType const& element);          // 移除 tree 中任意节点
//
//private:
//    bool _contains(BSTNode const& node) const;
//    void _preOrder() const;
//    void _preOrderStack() const;
//    void _inOrder() const;
//    void _inOrderStack() const;
//    void _postOrder() const;
//    void _postOrderStack() const;
//    commonType _minmum() const;
//    commonType _maxmum() const;
//    bool _addNode();
//    bool _removeMIN();
//    bool _removeMAX();
//    bool _removeNode(commonType const& element);
//
//private:
//    int size = 0;
//    BSTNode* root = NULL;
//};
//
//#endif // BST_H


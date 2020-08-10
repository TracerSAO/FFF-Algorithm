#ifndef BST_H
#define BST_H

#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cassert>
#include <iostream>
#include <stack>

template<class commonType> class BSTNode
{
public:
    BSTNode() =default;
    ~BSTNode();

    // get-Interface
    CommonType getCommonType() const;
    BSTNode* getLeftNode() const;
    BSTNode* getRightNode() const;
    // set-Interface
    void setCommonType();
    void setLeftNode();
    void setRightNode();    

private:
    CommonType value;
    BSTNode *leftNext = NULL;
    BSTNode *rightNext = NULL;

};

template<class commonType> class BST
{
public:
    BST();
    BST(int n);
    BST(BSTNode *root);
    BST(int n, BSTNode *root);
    ~BST();

    // get-Interface
    int getSize() const;
    BSTNode* getRoot() const;
    // set-Interface
    void setSize();
    void setRoot();

    // function-Interface
    bool isEmpty() const;       // 判断 tree 是否为空
    bool contains(BSTNode const &node) const;   // 判断元素在 tree 中是否存在
    void preOrder() const;      // 前序遍历
    void inOrder() const;       // 中序遍历
    void postOrder() const;     // 后序遍历
    commonType minmu() const;   // 返回 tree 最小值
    commonType maxmu() const;   // 返回 tree 最大值
    bool addNode(commonType const &element);             // 向 tree 中添加元素
    bool removeMIN();           // 移除 tree 中最小值
    bool removeMAX();           // 移除 tree 中最大值
    bool removeNode(commonType const &element);          // 移除 tree 中任意节点

private:
    bool _contains(BSTNode const &node) const;
    void _preOrder() const;
    void _preOrderStack() const;
    void _inOrder() const;
    void _inOrderStack() const;
    void _postOrder() const;
    void _postOrderStack() const;
    commonType _minmum() const;
    commonType _maxmum() const;
    bool _addNode();
    bool _removeMIN();
    bool _removeMAX();
    bool _removeNode(commonType const &element);

private:
    int size = 0;
    BSTNode *root = NULL;
};

#endif // BST_H
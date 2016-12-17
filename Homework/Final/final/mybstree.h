//Kyle Hatfield
//mybstree.h



#ifndef MYBSTREE_H
#define MYBSTREE_H

#include "abstractbstree.h"

const int INIT_TO_ZERO = 0;

template <class T>
class MyBSTree: public AbstractBSTree<T> {

	class TreeNode
	{
		T m_data;
		TreeNode* m_right;
		TreeNode* m_left;

    //default constuctor
    //inline
    TreeNode() : m_left(NULL), m_right(NULL), m_data(NULL){}

    //auzilary constructor
    //inline
    TreeNode(T& x, TreeNode* lefty, TreeNode* righty) 
      : m_left(lefty), m_right(righty), m_data(x){}


	};
	TreeNode* m_root;
	int m_size;

  //------------------------Constructors----------

  //Default constructor
  //INLINE
  MyBSTree() : m_root(NULL), m_size(INIT_TO_ZERO) {}

  //-------------------Big 3----------------------
  //Destructor
  //INLINE
  ~MyBSTree(){};

  //Operator=
  const MyBSTree<T>& operator= (const MyBSTree<T>& rhs);

  //copy constructor
  MyBSTree(const MyBSTree<T>& rhs);




  //---------------------accessors----------------


  //size
	virtual int size() const;

  //isEmpty
	virtual bool isEmpty() const;

  //height
  virtual int height() const;

  //findMax
  virtual const T& findMax() const throw (Oops);

  //findMin
  virtual const T& findMin() const throw (Oops);

  //find 
  //super complex
  virtual int find(const T&);

  //-------------------------Mutator---------------

  //clear
  virtual void clear();

  //nodeInsert
  void nodeInsert(const T& x, TreeNode* &t);

  //insert
  virtual void insert(const T& x);

  //remove
  virtual void remove(const T& x);

  //nodeRemove
  void nodeRemove(const T& x, TreeNode* root);


  //---------------------------Output--------------

  //printPreOrder
  virtual void printPreOrder();

  //printPostOrder
  virtual void printPostOrder();

  //print 
  //essentially prettyPrint
  virtual void print() const;

  //preorderTraverse
  void preorderTraverse(TreeNode *node);

  //postorderTraverse
  void postorderTraverse(TreeNode *node);

  //prettyPrint
  void prettyPrint (const TreeNode* t, int pad);

  //clone
  TreeNode* clone(const TreeNode* t);

  //determineHeight
  int determineHeight(TreeNode* t, int &height, int &runningHeight);

};
#endif
#include "mybstree.hpp"

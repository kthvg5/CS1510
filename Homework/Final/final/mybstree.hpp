//Kyle Hatfield Final Project
//05/11/2015
//mybstree.hpp

using namespace std;
  
//Operator=
template <class T>
const MyBSTree<T>& MyBSTree<T>::operator=(const MyBSTree<T>& rhs)
{
	clear();
	m_root = clone(rhs.m_root);
	return;
}


//copy constructor
template <class T>
MyBSTree<T>::MyBSTree(const MyBSTree& rhs)
{
	*this = rhs;
}





  //---------------------accessors----------------

template <class T>
int MyBSTree<T>::size() const
{
	return m_size;
}

//isEmpty
template <class T>
bool MyBSTree<T>::isEmpty() const
{
	bool empty = false;
	if(m_root == NULL)
		empty = true;
	return empty;
}


  //height
template <class T>
int MyBSTree<T>::height() const
{
	int depth;
	if(m_root == NULL)
		return 0;
	else
	{
		depth = determineHeight(m_root, 1, 1);
	}
	return depth;
}

//determineHeight
template <class T>
int MyBSTree<T>::determineHeight(TreeNode* t, int &height, int &runningHeight)
{
	if(t -> m_left !=NULL)
	{
		runningHeight++;
		t=t->m_left;
		if (runningHeight > height)
		{
			height = runningHeight;
		}
		return determineHeight(t, height, runningHeight);
	}
	if(t -> m_right !=NULL)
	{
		runningHeight++;
		t=t->m_right;
		if (runningHeight > height)
		{
			height = runningHeight;
		}
	return determineHeight(t, height, runningHeight);
	}
	runningHeight--;
	return height;

}

//findMax
template <class T>
const T& MyBSTree<T>::findMax() const throw (Oops)
{
	TreeNode* seeker = m_root;
	if(m_root == NULL)
	{
		cout << "OOPS! : Tree is Empty!!" << endl;
		return NULL;
	}
	else
	{
		while(seeker -> m_right != NULL)
			seeker = seeker -> m_right;
	}
	return seeker -> m_data;
}



  //findMin
template <class T>
const T& MyBSTree<T>::findMin() const throw (Oops)
{
	TreeNode* seeker = m_root;
	if(m_root == NULL)
	{
		cout << "OOPS! : Tree is Empty!!" << endl;
		return NULL;
	}
	else
	{
		while(seeker -> m_left != NULL)
			seeker = seeker -> m_left;
	}
	return seeker -> m_data;
}

  //find 
  //super complex
template <class T>
int MyBSTree<T>::find(const T& x)
{
	TreeNode* sleuth = m_root;
	int depth = 1;
	T current;
	if (m_root == NULL)
		return -1;
	else
		while(sleuth -> m_data != x && (sleuth != NULL))
		{
			if (x < sleuth -> m_data)
			{
				current = sleuth -> m_data;
				sleuth -> m_left;
				depth++;
			}
			else if (x > sleuth -> m_data)
			{
				current = sleuth -> m_data;
				sleuth -> m_right;
				depth++;
			}

		}
		if (x != current)
			depth *= -1;
		return depth;
}

  //-------------------------Mutator---------------

//clear
template <class T>
void MyBSTree<T>::clear()
{
	while (m_root != NULL)
		remove(m_root->m_data);
	return;
}

  //insertNode
template <class T>
void MyBSTree<T>::nodeInsert(const T& x, TreeNode* &t)
{
	if(t==NULL)
		t = new TreeNode(x, NULL, NULL);
	else if(x < t -> m_data)
		insert(x, t -> m_left);
	else if(x > t -> m_data)
		insert(x, t -> m_right);
	else
		return;
}

//insert
template <class T>
void MyBSTree<T>::insert(const T& x)
{
	insertNode(x, m_root);
	return;
}


	//nodeRemove
template <class T>
void MyBSTree<T>::nodeRemove(const T& x, TreeNode* root)
{
	if(x < root->m_data) root->m_left = Delete(x, root->m_left);
	else if (x > root->m_data) root->m_right = Delete(x, root->m_right);	
	else
	{
		// Case 1:  No child
		if(root->m_left == NULL && root->m_right == NULL)
		{ 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->m_left == NULL) 
		{
			TreeNode *temp = root;
			root = root->m_right;
			delete temp;
		}
		else if(root->m_right == NULL)
		{
			TreeNode *temp = root;
			root = root->m_left;
			delete temp;
		}
		// case 3: 2 children
		else 
		{ 
			TreeNode *temp = findMax(root->m_left);
			root->m_data = temp->m_data;
			root->m_left = Delete(temp->m_data, root->m_left);
		}
	}
	return;
}

  //remove
  template <class T>
  void MyBSTree<T>::remove(const T& x)
  {
  	if(m_root == NULL)
			return;
		else nodeRemove(x, m_root);
		return;
  }

  //---------------------------Output--------------
  //printPreOrder
  template <class T>
  void MyBSTree<T>::printPreOrder()
  {
  	preorderTraverse(m_root);
  	cout << endl;
  	return;
  }

template <class T>
void MyBSTree<T>::preorderTraverse(TreeNode *node)
{
  if(node != NULL)
  {
    cout << node->m_data << " ";
    preorderTraverse(node->m_left);
    preorderTraverse(node->m_right);
  }
  return;
}


  //printPostOrder
template <class T>
void MyBSTree<T>::printPostOrder()
{
	postorderTraverse(m_root);
  cout << endl;
  return;
}
template <class T>
void MyBSTree<T>::postorderTraverse(TreeNode *node)
{
  if(node != NULL)
  {
      postorderTraverse(node->m_left);
      postorderTraverse(node->m_right);
      cout << node->item << " ";
  }
  return;
}

 

  //print 
  //essentially prettyPrint
 template <class T>
 void MyBSTree<T>::print() const
 {
 	this.prettyPrint(m_root, INIT_TO_ZERO);
 	return;
 }
//PRETTY PRINT!! 
template <class T>
void MyBSTree<T>::prettyPrint (const TreeNode* t, int pad)
{
 string s(pad, ' ');
 if (t == NULL)
     cout << endl;
 else{
   prettyPrint(t->right, pad+4);
   cout << s << t->data << endl;
   prettyPrint(t->left, pad+4);
 }  
 return;
}

//clone
template <class T>
TreeNode MyBSTree<T>::clone(const TreeNode* t)
{
 if (t == NULL)
     return NULL;
 else{
     return new TreeNode(t->data, clone(t->left),clone(t->right));
 }  
}


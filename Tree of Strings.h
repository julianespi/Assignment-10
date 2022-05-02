#pragma once
template <class T>
class binary_tree_node
{
private:
	T data;
	binary_tree_node* left;
	binary_tree_node* right;

public:
	binary_tree_node(const T& init_data = T(), binary_tree_node* init_left = NULL, binary_tree_node* init_right = NULL)
	{
		data = init_data;
		left = init_left;
		right = init_right;
	}

	T getData() const
	{
		return data;
	}

	void setData(T newData)
	{
		data = newData;
	}

	binary_tree_node*& getLeft()
	{
		return left;
	}

	void setLeft(binary_tree_node* newLeft)
	{
		left = newLeft;
	}

	binary_tree_node*& getRight()
	{
		return right;
	}

	void setRight(binary_tree_node* newRight)
	{
		right = newRight;
	}

	bool isLeaf() const
	{
		return (left == NULL && right == NULL);
	}
};



template<class Item>
void print_tree(const string& prefix, binary_tree_node<Item>* node, bool isLeft, bool root, bool last)
{
	if (node != NULL)
	{
		cout << prefix;
		if (!root)
		{
			if (isLeft)
			{
				if (node->isLeaf())
					cout << char(192) << string(3, char(196));
				else
					cout << char(195) << string(3, char(196));
			}
			else
			{
				if (last)
					cout << char(192) << string(3, char(196));
				else
					cout << char(195) << string(3, char(196));
			}
			cout << " " << node->getData() << '\n';
		}
		else
			cout << "    " << node->getData() << '\n';


		// enter the next tree level - left and right branch
		string s = "    ";
		s[0] = char(179);
		print_tree(prefix + (isLeft ? s : "    "), node->getLeft(), true, false, false);
		print_tree(prefix + (isLeft ? s : "    "), node->getRight(), false, false, true);
	}
}

template<class Item>
void delete_tree(binary_tree_node<Item>* leaf) // Recursive
{
	if (leaf == NULL) // Xtra-point 10 points
		return;

	/* first delete both subtrees */
	delete_tree(leaf->getLeft());
	delete_tree(leaf->getRight());

	/* then delete the node */
	cout << "\n\t\tDeleting: " << leaf->getData();
	delete leaf;

}

void treeofStrings()
{
	system("cls");

	cout << "n\t1. Growing a tree (strings)\n";
	binary_tree_node<string>* root = nullptr;

	root = new binary_tree_node<string>;
	root->setData("trunk");

	cout << "\n\tA> root (trunk) with no branches.\n\n";
	print_tree("\t\t", root, false, true, false);
	//	system("pause");

	binary_tree_node<string>* branch1 = new binary_tree_node<string>;
	branch1->setData("branch #1");

	binary_tree_node<string>* branch2 = new binary_tree_node<string>;
	branch2->setData("branch #2");

	cout << "\n\tB> " << root->getData() << " grows two branches...\n\n";
	root->setLeft(branch1);
	root->setRight(branch2);
	print_tree("\t\t", root, false, true, false);
	//	system("pause");


	binary_tree_node<string>* leftLeaf1 = new binary_tree_node<string>;
	leftLeaf1->setData("leaf #1");
	root->getLeft()->setLeft(leftLeaf1);
	binary_tree_node<string>* leftLeaf2 = new binary_tree_node<string>;
	leftLeaf2->setData("leaf #2");
	root->getLeft()->setRight(leftLeaf2);

	cout << "\n\tC> " << root->getLeft()->getData() << " grows two leaves: " << leftLeaf1->getData() << " and " << leftLeaf2->getData() << ".\n\n";
	print_tree("\t\t", root, false, true, false);
	cout << '\n';
	//	system("pause");

	binary_tree_node<string>* rightLeaf1 = new binary_tree_node<string>;
	rightLeaf1->setData("leaf #3");
	root->getRight()->setLeft(rightLeaf1);
	binary_tree_node<string>* rightLeaf2 = new binary_tree_node<string>;
	rightLeaf2->setData("leaf #4");
	root->getRight()->setRight(rightLeaf2);

	cout << "\n\tD> " << root->getRight()->getData() << " grows two leaves: " << rightLeaf1->getData() << " and " << rightLeaf2->getData() << ".\n\n";
	print_tree("\t\t", root, false, true, false);
	cout << '\n';
	//	system("pause");

	binary_tree_node<string>* fruit = new binary_tree_node<string>;
	fruit->setData("apple");
	leftLeaf1->setLeft(fruit);
	cout << "\n\tE> " << root->getLeft()->getLeft()->getData() << " sprouts and yields a fruit (" << fruit->getData() << ").\n\n";
	print_tree("\t\t", root, false, true, false);
	cout << '\n';
	//	system("pause");

	binary_tree_node<string>* fruit2 = new binary_tree_node<string>;
	fruit2->setData("orange");
	binary_tree_node<string>* fruit3 = new binary_tree_node<string>;
	fruit3->setData("coconut");
	rightLeaf1->setLeft(fruit2);
	rightLeaf1->setRight(fruit3);
	cout << "\n\tF> " << root->getRight()->getLeft()->getData() << " sprouts and yields two fruits (" << fruit2->getData() << " and " << fruit3->getData() << ").\n\n";
	print_tree("\t\t", root, false, true, false);
	cout << '\n';
	//	system("pause");

	cout << "\n\tG> Delete tree (recursive).\n";
	delete_tree<string>(root);
	cout << '\n';
	root = NULL;
	if (root != NULL)
	{
		cout << '\n';
		print_tree("\t\t", root, false, true, false);
	}
}
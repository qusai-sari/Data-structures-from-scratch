#pragma once
#include <vector>
#include <algorithm>

class SLL
{

	struct node
	{
		int data;
		node *link;

	public:
		node(int val)
		{
			data = val;
			link = nullptr;
		}
	};

	node *head;
	node *tail;
	int _size;

public:
	// Constructor and Destructor

	SLL()
	{
		head = tail = nullptr;
		_size = 0;
	}

	SLL(const SLL &sll) : SLL()
	{
		if (sll.empty())
		{
			head = tail = nullptr;
			_size = 0;
			return;
		}

		node *nodeInThisSLL = head = getNewNode();
		node *nodeInSLLToBeCopied = sll.head;

		while (nodeInSLLToBeCopied != nullptr)
		{
			nodeInThisSLL->data = nodeInSLLToBeCopied->data;

			nodeInSLLToBeCopied = nodeInSLLToBeCopied->link;

			if (nodeInSLLToBeCopied != nullptr)
			{
				nodeInThisSLL->link = getNewNode();
				nodeInThisSLL = nodeInThisSLL->link;
			}
		}
		tail = nodeInThisSLL;
	}

	SLL &operator=(const SLL &sll)
	{
		if (&sll == this)
			return *this;

		clear();

		if (sll.empty())
			return *this;

		node *nodeInThisSLL = head = getNewNode();
		node *nodeInSLLToBeCopied = sll.head;

		while (nodeInSLLToBeCopied != nullptr)
		{
			nodeInThisSLL->data = nodeInSLLToBeCopied->data;

			nodeInSLLToBeCopied = nodeInSLLToBeCopied->link;

			if (nodeInSLLToBeCopied != nullptr)
			{
				nodeInThisSLL->link = getNewNode();
				nodeInThisSLL = nodeInThisSLL->link;
			}
		}
		tail = nodeInThisSLL;

		return *this;
	}

	~SLL() { clear(); }

	// Methods

private:
	node *getNewNode()
	{
		++_size;
		return new node(0);
	}

	void indexValidation(int index, bool isSizeAllowed = false, bool isEmptyAllowed = false) const
	{
		if (!isEmptyAllowed && empty())
			throw std::out_of_range("There is no node!");

		if (index < 0)
			throw std::out_of_range("Index can't be negative!");

		if (isSizeAllowed)
		{
			if (index > _size)
				throw std::out_of_range("Index is bigger than the size!");
		}
		else
		{
			if (index >= _size)
				throw std::out_of_range("This index is out of range!");
		}
	}

	node *getNode(int index) const
	{
		indexValidation(index);

		int currentIn = 0;
		node *currentNode = head;
		while (currentIn < index)
		{
			currentNode = currentNode->link;
			++currentIn;
		}
		return currentNode;
	}

public:
	// Size
	int size() const { return _size; }

	// Check
	bool empty() const { return head == nullptr; }

	// Add
	void push_front(int val)
	{
		if (empty())
		{
			head = tail = getNewNode();
		}
		else
		{
			node *ptr = head;
			head = getNewNode(); // New head
			head->link = ptr;	 // Link the new head to the last one
		}

		// New first node data assignment.
		head->data = val;
	}

	void push_back(int val)
	{
		if (empty())
		{
			head = tail = getNewNode();
		}
		else
		{
			tail->link = getNewNode(); // After this, "tail" points to the before final node
			tail = tail->link;
		}

		// New final node data assignment.
		tail->data = val;
	}

	void insert(int index, int val)
	{
		indexValidation(index, true, true);

		if (index == _size || empty())
		{
			push_back(val);
		}
		else if (index == 0)
		{
			push_front(val);
		}
		else
		{
			node *newNode = getNewNode();
			node *nodeBefore = getNode(index - 1);

			newNode->data = val;

			newNode->link = nodeBefore->link; // New node points to the node of "index";
			nodeBefore->link = newNode;		  // Node before the node of "index" points to the new node;
		}
	}

	// Remove
	void pop_back()
	{
		if (empty())
			throw std::out_of_range("There is no node!");

		if (_size == 1)
		{
			delete tail;
			tail = head = nullptr;
		}
		else
		{
			node *BeforeFinalNode = getNode(_size - 2);

			delete tail;
			tail = BeforeFinalNode;
			tail->link = nullptr;
		}
		--_size;
	}

	void pop_front()
	{
		if (empty())
			throw std::out_of_range("There is no node to pop!");

		if (_size == 1)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			node *afterHeadNode = head->link;

			delete head;
			head = afterHeadNode;
		}
		--_size;
	}

	void erase(int index)
	{
		indexValidation(index);

		if (index == _size - 1)
		{
			pop_back();
		}
		else if (index == 0)
		{
			pop_front();
		}
		else
		{
			node *nodeBeforeNodeTobeErased = getNode(index - 1);
			node *nextNode = nodeBeforeNodeTobeErased->link->link;

			delete nodeBeforeNodeTobeErased->link;
			nodeBeforeNodeTobeErased->link = nextNode; // Node before the node to be erased link points to the node next to it;
			--_size;
		}
	}

	void clear()
	{
		while (head != nullptr)
		{
			node *nextNode = head->link;
			delete head;
			head = nextNode;
		}
		tail = head;
		_size = 0;
	}

	// Modify
	void set(int index, int val)
	{
		indexValidation(index);
		getNode(index)->data = val;
	}

	void reverse()
	{
		if (empty())
			throw std::out_of_range("There is no node!");
		if (_size == 1)
			return;

		node *before = nullptr;
		node *current = head;
		node *next = nullptr;

		tail = head;

		while (current != nullptr)
		{
			next = current->link;
			current->link = before;
			before = current;
			current = next;
		}

		head = before;
	}

	void sortSLL()
	{
		if (empty())
			throw std::out_of_range("There is no node!");

		std::vector<int> nodesVals(_size);

		node *currentNode = head;

		for (int i = 0; i < _size; ++i)
		{
			nodesVals[i] = currentNode->data;
			currentNode = currentNode->link;
		}

		std::sort(nodesVals.begin(), nodesVals.end());

		currentNode = head;
		for (int i = 0; i < _size; ++i)
		{
			currentNode->data = nodesVals[i];
			currentNode = currentNode->link;
		}
	}

	// Retrieve
	int front() const
	{
		if (empty())
			throw std::out_of_range("There is no node!");
		return head->data;
	}

	int back() const
	{
		if (empty())
			throw std::out_of_range("There is no node!");
		return tail->data;
	}

	int get(int index) const
	{
		indexValidation(index);
		return getNode(index)->data;
	}

	// Search
	int search(int val) const
	{
		if (empty())
			throw std::out_of_range("There is no node!");

		int index = -1;
		node *_node = head;
		for (int i = 0; i < _size; ++i)
		{
			if (val == _node->data)
			{
				index = i;
				break;
			}
			_node = _node->link;
		}

		return index;
	}
};

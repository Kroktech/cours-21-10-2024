#include <iostream>
struct IntNode
{
	IntNode* pNext;
	IntNode* pPrevious;
	int value;
	IntNode() :pNext(nullptr), pPrevious(nullptr)
	{}
};



void show(IntNode* n0)
{
	IntNode* currentnode = n0;
	while (currentnode != nullptr)
	{
		std::cout << currentnode->value;
		currentnode = currentnode->pNext;
	}
}
void pushFront(IntNode* Firstnode , IntNode* NewFirstnode)
{
	NewFirstnode->pPrevious = nullptr;
	Firstnode->pPrevious = NewFirstnode;
	NewFirstnode->pNext = Firstnode;
	
	
}

void pushback(IntNode* Lastnode, IntNode* NewLastnode)
{
	NewLastnode->pPrevious = Lastnode;
	Lastnode->pNext = NewLastnode;
	NewLastnode->pNext = nullptr;


}


struct IntList
{
	IntNode* pFirstNode;
	IntNode* pLastNode;

	IntList() : pFirstNode(nullptr), pLastNode(nullptr)
	{}
	~IntList()
	{
		IntNode* currentnode = pFirstNode;
		int i = 0;
		std::cout << std::endl;
		while (!isEmpty())
		{
			popBack();
			++i;
		}
			std::cout << i<< std::endl;

		

	}
	bool isEmpty()
	{
		return pFirstNode == nullptr;
	}
	void pushFront(int value)
	{
		IntNode* newfirstnode = new IntNode;
		newfirstnode->value = value;
		if (isEmpty())
		{

			pLastNode = newfirstnode;
			
			
		}
		else
		{

			::pushFront(pFirstNode, newfirstnode);

		}
		pFirstNode = newfirstnode;
	}
	void pushback(int value)
	{
		IntNode* newlastnode = new IntNode;
		newlastnode->value = value;
		if (isEmpty())
		{
			
			
			pFirstNode = newlastnode;
			
		}
		else
		{
			
			::pushback(pLastNode, newlastnode);
			
		}
		pLastNode = newlastnode;
	}
	void show()
	{

		::show(pFirstNode);
	}
	int popBack()
	{
		int value = pLastNode->value;
		IntNode* poppedNode = pLastNode;
		IntNode* newlastnode = pLastNode->pPrevious;
		if (newlastnode == nullptr)
			pFirstNode = nullptr;
		else
			newlastnode->pNext = nullptr;
		
		pLastNode = newlastnode;
		delete poppedNode;
		return value;

	}
	int popFront()
	{
		int value = pFirstNode->value;
		IntNode* poppedNode = pFirstNode;
		IntNode* newfirstnode = pFirstNode->pNext;
		if (newfirstnode == nullptr)
			pLastNode = nullptr;
		else
			newfirstnode->pPrevious = nullptr;

		pFirstNode = newfirstnode;
		delete poppedNode;
		return value;
	}
	bool contains(int value)
	{
		IntNode* currentnode = pFirstNode;
		while (currentnode != nullptr )
		{
			if (currentnode->value == value)
				return true;
			else
				currentnode = currentnode->pNext;
			
				
		}
		return false;

	}
};


int main()
{
	
	IntList List;
	
	List.pushback(3);
	List.pushback(4);
	List.pushFront(1);

	//int val = List.popBack();
	//std::cout << val << std::endl;
	
	List.show();
	std::cout <</* val <<*/ std::endl;
	std::cout << List.contains(5);
	//std::cout <</* val <<*/ std::endl;
	//int val2 = List.popFront();
	//std::cout << val2 << std::endl;
	//List.show();
}

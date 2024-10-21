#include <iostream>
struct IntNode
{
	IntNode* pNext;
	IntNode* pPrevious;
	int value;
	IntNode() :pNext(nullptr), pPrevious(nullptr)
	{}
};

void changeNodeValueToTwelve(IntNode* n0)
{
	n0->value = 12;
}

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
void pushfront2(IntNode* Firstnode, int value)
{
	IntNode* newfirstnode = new IntNode;
	newfirstnode->value = value;
	pushFront(Firstnode, newfirstnode);
}
void pushback(IntNode* Lastnode, IntNode* NewLastnode)
{
	NewLastnode->pPrevious = Lastnode;
	Lastnode->pNext = NewLastnode;
	NewLastnode->pNext = nullptr;


}
//void pushback2(IntNode* lastnode,int value)
//{
//	/*IntNode* newnode=nullptr;
//	newnode->pPrevious = nullptr;
//	newnode->pPrevious = lastnode;
//	lastnode->pNext = newnode;
//	newnode->pNext = nullptr;
//	newnode->value = value;*/
//    IntNode* newlastnode = new IntNode;
//	newlastnode->value = value;
//	pushback(lastnode, newlastnode);
//}

struct IntList
{
	IntNode* pFirstNode;
	IntNode* pLastNode;

	IntList() : pFirstNode(nullptr), pLastNode(nullptr)
	{}
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
};


int main()
{
	//IntList p1;
	//IntNode n1;
	//IntNode n2;
	////liste a 2 element 
	//n1.pPrevious = nullptr;
	//n1.pNext = &n2;
	//n1.value = 1;

	//n2.pPrevious = &n1;
	//n2.pNext = nullptr;
	//n2.value = 2;
	//
	//show(&n1);
	//std::cout << std::endl;

	////add element 0
	///*IntNode n0;*/
	///*n0.pPrevious = nullptr;
	//n0.pNext = &n1;
	//n1.pPrevious = &n0;*/
	///*n0.value = 0;*/
	///*pushFront(&n1, &n0);*/
	///*show(&n0);
	//std::cout << std::endl;*/
	////add element 3
	///*IntNode n3;*/
	///*n3.pPrevious = &n2;
	//n3.pNext = nullptr;
	//n2.pNext = &n3;*/
	///*n3.value = 3;*/
	///*pushback(&n2, &n3);*/
	//pushfront2(&n1, 0);
	//p1.pushback(3);
	//show(&n1);

	//return 0;
	IntList List;
	
	List.pushback(3);
	List.pushback(4);
	List.pushFront(1);

	int val = List.popBack();
	std::cout << val << std::endl;
	List.show();

}

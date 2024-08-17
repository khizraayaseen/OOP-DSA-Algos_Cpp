#include<iostream>
using namespace std;

// BLOCK 
template<class T>
class block
{
	class bnode
	{
	public:
		T startingbytesid;
		T totalbytes;
		bnode* next;
	public:
		bnode()
		{
			startingbytesid = 0;
			totalbytes = 0;
			next = nullptr;
		}
	};
	T memory;
	bnode* head;
	bnode* tail;

public:
	block()
	{
		head = tail = nullptr;
		memory = 102399;
	}

	void blockreservememory()
	{
		bnode* temp = new bnode;

		int startbyteid;
		cout << "Enter Start Byte Id: ";
		cin >> startbyteid;
		temp->startingbytesid = startbyteid;
		cout << endl;

		int totalbyte;
		cout << "Enter Total No of Bytes: ";
		cin >> totalbyte;
		temp->totalbytes = totalbyte;
		cout << endl;

		int count = 0;
		bnode* current = new bnode;
		current->next = head;
		if (!head)
		{
			temp->startingbytesid = 0;
			temp->next = tail;
			memory = memory - totalbyte;

			cout << "A Memory Block has been created!!" << endl;
			cout << "Starting from " << temp->startingbytesid << endl;
			cout << "Size: " << temp->totalbytes << endl;
			cout << endl;

			poolprint();
		}
		else
		{
			for (int i = 0; current->next != nullptr; i++)
			{
				count = count + current->totalbytes;
				current = current->next;
			}
			temp->startingbytesid = count;
			temp->totalbytes = totalbyte;
			temp->next = tail;

			memory = memory - totalbyte;

			cout << "A Memory Block has been created!!"<<endl;
			cout << "Starting from " << temp->startingbytesid << endl;
			cout<< "Size: " << temp->totalbytes << endl;
			cout << endl;

			poolprint();
		}
	}

	void programmemoryreserve(int size)
	{

		bnode* current = new bnode;
		current->next = head;
		if (size < memory && size != 0)
			{
			while (this->totalbytes != 0)
			{
				cout << "(Strategy Fit) MEMORY BLOCK exits!!!" << endl << endl;
				current->totalbytes = current->totalbytes - size;
				memory = memory - size;
				current = current->next;
			}
			}
		else
		{
			cout << "NO (Strategy fit) MEMORY BLOCK exits for now!!!" << endl << endl;
		}
		poolprint();
	}

	void poolprint()
	{
		bnode* temp = new bnode;
		temp->next = head;
		cout << "In pool: " << endl;

		for (int i = 0; temp->next != nullptr; i++)
		{
			cout << "Starting byte: " << temp->startingbytesid << endl;
			cout << "Total byte: " << temp->totalbytes << endl;
			memory = memory - temp->totalbytes;
			temp = temp->next;
		}

		cout << "Remaining memory: " << memory << endl << endl;
	}

	void pooldelete(int id)
	{
		bnode* temp = new bnode;
		temp->next = head;
		for (int i = 0; temp->next != nullptr; i++)
		{
			if (temp->startingbytesid == id)
			{
				cout << "Program deleted!!" << endl;
				memory= memory + temp->totalbytes;
				delete temp;
				break;
			}
			else
			{
				cout << "Program ID does'nt exits" << endl;
			}
			temp = temp->next;
		}
		poolprint();
	}

};

//Program
template<class T>
class program : public block <T>
{
private:
	class pnode
	{
	public:
		int id;
		int size;
		pnode* next;
		pnode* nextprogram;

	public:
		pnode()
		{
			id = 0;
			size = 0;
			next = nextprogram = nullptr;
		}
	};

	pnode* head;
	pnode* tail;

public:
	 block <int> LinkedListOfBlocks;
	program()
	{
		head = tail = nullptr;
	}

	void getprogram()
	{
		int Id; int pnext = 0;
		pnode* temp = new pnode;
		cout << "Enter Program Id: ";
		cin >> Id;
		temp->id = Id;
		

		int s;
		cout << "Enter Size (Program): ";
		cin >> s;
		temp->size = s;
		cout << endl;

		/*temp->nextprogram = LinkedListOfBlocks;*/
		LinkedListOfBlocks.programmemoryreserve(s);
	}

};

//MEMORY MANAGEMENT SYSTEM
template<class T>
class MemoryManagementSystem
{
private:
	class mnode
	{
	protected:
		T data;
		mnode* next;
	public:
		mnode()
		{
			data = 0;
			next = nullptr;
		}
	};
	mnode* head;
	mnode* tail;
public:
	block <int> pool;
	program <int> progs;

	int sizeOfMemory;
	string strategy;

public:
	MemoryManagementSystem()
	{
		sizeOfMemory = 102399;
		strategy = "FirstFit";
	}
	void insertprogram()
	{
		progs.getprogram();
	}
	void insertmemory()
	{
		pool.blockreservememory();
	}
	void deleteit()
	{
		int i;
		cout << "Enter (Program) id you want to delete: ";
		cin >> i;
		pool.pooldelete(i);
	}

};

int main()
{
	cout << "------WELCOME TO MEMORY MANAGEMENT SYSTEM------" << endl;
	int s = 5;

	MemoryManagementSystem <int> M;
	while (s != 0)
	{
		cout << "------------------------------" << endl;
		cout << "What do you want to do?" << endl;
		cout << "(1) New Program" << endl;
		cout << "(2) Memory block" << endl;
		cout << "(3) Delete memory block" << endl;
		cout << "Enter '0' to exit" << endl;
		cout << "--------------------------------" << endl;

		cout << "Enter: ";
		cin >> s;

		if (s == 1)
		{
			M.insertprogram();
		}
		if (s == 2)
		{
			M.insertmemory();
		}
		if (s == 3)
		{
			M.deleteit();
		}
		if (s == 0)
		{
			cout << "EXIT";
		}
	}

	return 0;
}
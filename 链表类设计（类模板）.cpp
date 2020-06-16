#include <iostream>
#include <iomanip>
using namespace std;


typedef int elementType;
typedef struct node
{
    elementType data;
    node* next;
} LList, *PList;

template <class T> 
class linkedList
{
public:
    linkedList();
    virtual ~linkedList();
    void insert(int value);
    bool initiate();
    bool isEmpty();
    bool remove(int pos,int& value);
    void print();
    int Length();
private:
    LList *head;
    int len;
};

template <class T> 
linkedList<T>::linkedList():len(0) {}

template <class T> 
linkedList<T>::~linkedList()
{
	PList temp;
	while(!head->next)
	{
		temp=head->next;
		delete head;
	  	head=temp;
	}
	delete head;
  	head=NULL;
}

template <class T> 
void linkedList<T>::insert(int value)
{
	len++;
	PList p=head;
	int i=0;
	while(p!=NULL && i<len-1)
	{
		p=p->next;
		i++;
	}
	PList q=new node();
	q->data=value;
	q->next=p->next;
	p->next=q;
}

template <class T> 
bool linkedList<T>::initiate()
{
	head=new node();
	head->next=NULL;
	if(head) return true;
	else return false;
}

template <class T> 
bool linkedList<T>::isEmpty()
{
	if(!head->next) return true;
	else return false;
}

template <class T> 
bool linkedList<T>::remove(int pos,int& value)
{
	int i=1;
	if(head==NULL || head->next==NULL || pos>len)
	{
		cout<<"pos > len, failed"<<endl;
		return false;
	}
	if(pos<=0)
	{
		cout<<"pos <= 0, failed"<<endl;
		return false;
	}
	
	PList p=head->next,q=head;
	while(p)
	{
		if(i==pos)
		{
			q->next=p->next;
			value=p->data;
			delete p;
			len--;
			return true;
		}
		else
		{
		  	i++;
			q=p;
			p=p->next;
		}
	}
  	return false;
}

template <class T> 
int linkedList<T>::Length()
{
	if(!head->next)  return -1;
	else  return len;
}

template <class T> 
void linkedList<T>::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    LList* tmp = head->next;
    while(tmp)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}



int main(int argc, char* argv[])
{
    linkedList<int> L1;
    int n;
    int val;
    //初始化链表
    if(!L1.initiate())
        return 0;

    cin>>n;//输入链表中数据个数
    for(int i=0; i<n; i++) //输入n个数，并插入链表
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度
    cout << "data：" ;
    L1.print();//打印链表

    cin>>n;//输入需要删除的数据的位置
    if (L1.remove(n,val))
    {
        //删除位置n的数据，并将删除的数据值放在val中
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length：" << L1.Length()<< endl;//输出链表长度
        cout<< "data：" ;
        L1.print();//打印链表
    }

    return 0;
}


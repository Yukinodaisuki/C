#include <iostream>
#include <iomanip>
using namespace std;

typedef int elementType;
typedef struct node
{
    elementType data;
    node* next;
} LList, *PList;

class linkedList
{
public:
    linkedList();//���캯��
    virtual ~linkedList();//����������ע��Ҫ���������нڵ����Դ
    void insert( int value );//���棺�����ʼ������ʹ�ã�
    bool initiate();//��ʼ��������ʹ��new��������ͷ��㡣�������ʧ�ܣ��򷵻�false�����򷵻�true
    bool isEmpty();//�жϵ������Ƿ�Ϊ��
    //ɾ���������е�pos��Ԫ�ؽ�㣬����ɾ���Ľڵ��ֵ����value�С�
    //ע�⣺�������Ϊ�ա�ɾ��λ�ô��������ȡ��Լ�ɾ��λ��Ϊ0���������Ҫ��ֹɾ���������Ӧ��Ϣ
    bool remove( int pos, int& value );
    void print();//˳���ӡ����������ǵ�����Ϊ�գ������ Empty
    int Length();//���ص������ȡ�����ǵ�����Ϊ�գ��򷵻�-1
private:
    LList *head;
    int len;
};

//���ڴ˴��������г�Ա������ʵ��
linkedList::linkedList():len(0) {}

linkedList::~linkedList()
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

void linkedList::insert(int value)
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

bool linkedList::initiate()
{
	head=new node();
	head->next=NULL;
	if(head) return true;
	else return false;
}

bool linkedList::isEmpty()
{
	if(!head->next) return true;
	else return false;
}

bool linkedList::remove(int pos,int& value)
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

int linkedList::Length()
{
	if(!head->next)  return -1;
	else  return len;
}



//��Ա����print
void linkedList::print()
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
    linkedList L1;
    int n;
    int val;
    //��ʼ������
    if(!L1.initiate())
        return 0;

    cin>>n;//�������������ݸ���
    for(int i=0; i<n; i++) //����n����������������
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length��" << L1.Length() << endl;//���������
    cout << "data��" ;
    L1.print();//��ӡ����

    cin>>n;//������Ҫɾ�������ݵ�λ��
    if (L1.remove(n,val))
    {
        //ɾ��λ��n�����ݣ�����ɾ��������ֵ����val��
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length��" << L1.Length()<< endl;//���������
        cout<< "data��" ;
        L1.print();//��ӡ����
    }

    return 0;
}


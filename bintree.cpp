#include<iostream>
using namespace std;
#include <vector>
template <class T>
struct BinTreeNode
{
    T data;
    BinTreeNode<T> *left, *right;
};
struct Elem
{
    int data;
    Elem* next;
};
template <typename T>
bool isEmpty(BinTreeNode<T>* root)
{
    return NULL == root;
}
template <typename T>
bool isLeaf(BinTreeNode<T>* root)
{
    return isEmpty(root->left)
           && isEmpty(root->right);
}
template <typename T>
int countTree(BinTreeNode<T>* root)
{
    if(isEmpty<T>(root))
        return 0;
    if(isLeaf<T>(root))
        return +1;
    else
        return 1 + countTree(root->left) + countTree(root->right);
}
template <typename T>
int countLeaf(BinTreeNode<T>* root)
{
    if(isEmpty<T>(root))
        return 0;
    if(isLeaf<T>(root))
        return +1;
    else
        return  countLeaf(root->left) + countLeaf(root->right);
}
template <typename T>
T maxLeaf(BinTreeNode<T>* root)
{
    if(isLeaf<T>(root))
        return root->data;
    else
        return max(maxLeaf(root->left) ,maxLeaf(root->right));
}
template <typename T>
int countTreeEven(BinTreeNode<T>* root)
{
    if(isEmpty<T>(root))
        return 0;
    if(isLeaf<T>(root))
    {
        if(root->data%2==0)
        return 1;
    else return 0;
    }
    else
    {
        if(root->data%2==0)
            return 1 + countTreeEven(root->left) + countTreeEven(root->right);
        else return 0 + countTreeEven(root->left) + countTreeEven(root->right);
    }
}
template<typename T>
int countTreePred(BinTreeNode<T>* root,bool (*pred)(const T&))
{
    if(isEmpty<T>(root))
        return 0;
    if(isLeaf<T>(root))
    {
        if(pred(root->data))
        return 1;
    else return 0;
    }
    else
    {
        if(pred(root->data))
            return 1 + countTreePred(root->left,pred) + countTreePred(root->right,pred);
        else return 0 + countTreePred(root->left,pred) + countTreePred(root->right,pred);
    }
}
template<typename T>
void listLeavesHelp(BinTreeNode<T>* root,vector<T>& vect)
{
     if(isLeaf(root)) vect.push_back(root->data);
    else
    {
    listLeavesHelp(root->left,vect);
    listLeavesHelp(root->right,vect);
    }
}
template<typename T>
vector<T>  listLeaves(BinTreeNode<T>* root)
{
    vector<T> listLeafs;
     listLeavesHelp(root,listLeafs);
    return listLeafs;
}
template <typename T>
T getAt(BinTreeNode<T>* root,int i)
{
    if(root==NULL)return NULL;
    if(i==0)return root->data;
    else
    getAt(root->right,i-1);
    getAt(root->left,i-1);
}
template <typename T>
int height(BinTreeNode<T>* root)
{
    if(isEmpty<T>(root))
        return 0;
    /*if(isLeaf<T>(root))
        return 1;*/
    else
        return 1 + max(height(root->left) , height(root->right));
}
template <typename T>
T getElement(string& s,BinTreeNode <T>* root)
{
    if(s.empty())return root->data;
    string::iterator it= s.begin();
    while(it!=s.end() && root!=NULL)
    {
        char command=*it;
        if(command=='R')
        {
            root=root->right;
            it++;
        }
        else
        {
            if(command=='L')
            {
                root=root->left;
                it++;
            }
        }
    }
    if(it!=s.end()) return 0;
    else return root->data;
}
template <typename T>
bool leftCopy(BinTreeNode<T> *root1,BinTreeNode<T> *root2)
{
    if(root1==NULL && root2==NULL)return true;
    if(root1->data!=root2->data)return false;
    else
    {
        if(root1->left && (root2->left==NULL || root2->right==NULL))return false;
        if(root1->left==NULL && (root2->left || root1->right))return false;
        return (leftCopy(root1->left,root2->left) && leftCopy(root1->left,root2->right));
    }
}
template <typename T>
bool counter(BinTreeNode<T> *root1,BinTreeNode<T> *root2)
{
    if(root1==NULL && root2==NULL)return true;
    if(root1==NULL && root2!=NULL)return false;
    if(root1 && root2==NULL)return false;
    if(root1->left && root1->right && root2->data!=2)return false;
    if(root1->left && root1->right==NULL && root2->data!=1)return false;
    if(root1->left==NULL && root1->right==NULL && root2->data!=0)return false;
    if(root1->left==NULL && root1->right && root2->data!=1)return false;
    else
    {
        return (counter(root1->left,root2->left) && counter(root1->right,root2->right));
    }
}
void zip(Elem* list1,Elem* list2,Elem* R,bool (*pred)(const int&,const int&))
{
    while(list1 && list2)
    {
        if(pred(list1->data,list2->data))
        {
            R->data=list1->data+list2->data;
            R=R->next;
        }
        list1=list1->next;
        list2=list2->next;
    }
}
int nthInOrder(BinTreeNode<int>* tree,int n)
{
    static int count=0;
    if(tree==NULL)return 0;
    if(count<n)
    {
        nthInOrder(tree->left,n);
        count++;
        if(count==n)return tree->data;
        nthInOrder(tree->right,n);

    }
}
void levelHelp(BinTreeNode<int>* tree,int level)
{
    if(tree==NULL)return;
    if(level==1)cout<<tree->data<<" ";
    else if(level>1)
    {
        levelHelp(tree->right,level-1);
        levelHelp(tree->left,level-1);
    }
}


void printLevelOrder(BinTreeNode<int>* tree)
{
    int h=height(tree);
    for(int i=1;i<=h;i++)
    {
        levelHelp(tree,i);
        cout<<endl;
    }
}
BinTreeNode<int> * createTree() {
	BinTreeNode<int> * l11 = new BinTreeNode<int>();
	l11->data = 5;
	l11->left = NULL;
	l11->right = NULL;

    BinTreeNode<int> *l12 =new BinTreeNode<int>() ;
    l12->data=4;
	l12->left = NULL;
	l12->right = NULL;

	BinTreeNode<int> * l1 = new BinTreeNode<int>();
	l1->data = 3;
	l1->left = l11;
	l1->right = l12;

	BinTreeNode<int> * r11 = new BinTreeNode<int>();
	r11->data = 6;
	r11->left = NULL;
	r11->right = NULL;

	BinTreeNode<int> * r12 =new BinTreeNode<int>();
	r12->data = 8;
	r12->left = NULL;
	r12->right = NULL;

	BinTreeNode<int> * r1 =new BinTreeNode<int>();
	r1->data = 2;
	r1->left = NULL;
	r1->right = NULL;

	BinTreeNode<int> * root = new BinTreeNode<int>();
	root->data = 1;
	root->left = l1;
	root->right = r1;

	return root;
}

BinTreeNode<int> * createTree2() {
	BinTreeNode<int> * l11 =new BinTreeNode<int>();
	l11->data = 5;
	l11->left = NULL;
	l11->right = NULL;

	BinTreeNode<int> * l12 =new BinTreeNode<int>();
	l12->data = 5;
	l12->left = NULL;
	l12->right = NULL;
BinTreeNode<int> * l1 =new BinTreeNode<int>();
	l1->data = 3;
	l1->left = l11;
	l1->right = l12;

    BinTreeNode<int> * r1l =new BinTreeNode<int>();
	r1l->data = 5;
	r1l->left = NULL;
	r1l->right = NULL;

	BinTreeNode<int> * r1r =new BinTreeNode<int>();
	r1r->data = 5;
	r1r->left = NULL;
	r1r->right = NULL;


	BinTreeNode<int> * r1 =new BinTreeNode<int>();
	r1->data = 3;
	r1->left = r1l;
	r1->right = r1r;

	BinTreeNode<int> * root =new BinTreeNode<int>();
	root->data = 1;
	root->left = l1;
	root->right = r1;

	return root;
}
bool isEven(const int& i)
    {
        return (i%2 == 0); }
#include "tests_problem1.cpp"
int main() {
     doctest::Context().run();
    BinTreeNode<int>* tree1=createTree();
    BinTreeNode<int>* tree2=createTree2();
	cout<<"countTreePred-even "<<countTreePred<int>(tree1,isEven)<<endl;
	cout<<"height "<<height<int>(tree1)<<endl;
	cout<<"countLeaf "<<countLeaf<int>(tree1)<<endl;
	cout<<"maxLeaf "<<maxLeaf<int>(tree1)<<endl;
	string command="LR";
	cout<<"getElement "<<endl<<getElement<int>(command,tree1)<<endl;
	vector<int> vect= listLeaves(tree1);
	for(vector<int>::iterator it=vect.begin();it!=vect.end();it++)
    {
        cout<<*it<<endl;
    }
    cout<<leftCopy<int>(tree1,tree2)<<endl;
    cout<<nthInOrder(tree1,3)<<endl;
    printLevelOrder(tree1);
	return 0;
}






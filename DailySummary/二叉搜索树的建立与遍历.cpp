#include <iostream>
using namespace std;

typedef int ElementType;
//typedef struct TNode *Position;
//typedef Position BinTree;
typedef struct TNode *BinTree;
struct TNode{
	ElementType Data;
	BinTree Left;
	BinTree Right; 
}; 

BinTree Insert(BinTree BST, ElementType X);
void PreOrder(BinTree BST);
void InOrder(BinTree BST);
void PostOrder(BinTree BST);
 
int main(){
	BinTree BST;
	ElementType X;
	int N, i;
	
	BST = NULL;
	cin >> N;
	for(i = 0; i < N; i++){
		cin >> X;
		BST = Insert(BST, X);
	}
	cout << "先序遍历" << endl;  
	PreOrder(BST);
	cout << endl << "中序遍历" << endl;
	InOrder(BST);
	cout << endl << "后序遍历"  << endl;
	PostOrder(BST);
	
	return 0;
}

BinTree Insert(BinTree BST, ElementType X){
	if(!BST){
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else if(X < BST->Data)
		BST->Left = Insert(BST->Left, X);
	else if(X > BST->Data)
		BST->Right = Insert(BST->Right, X);
	
	return BST;
}

void PreOrder(BinTree BST){
	if(!BST) return ;
	else{
		cout << BST->Data << " ";
		PreOrder(BST->Left);
		PreOrder(BST->Right);
	}
}

void InOrder(BinTree BST){
	if(!BST) return ;
	else{
		InOrder(BST->Left);
		cout << BST->Data << " ";
		InOrder(BST->Right);
	}
}

void PostOrder(BinTree BST){
	if(!BST) return ;
	else{
		PostOrder(BST->Left);
		PostOrder(BST->Right);
		cout << BST->Data << " ";
	}
}

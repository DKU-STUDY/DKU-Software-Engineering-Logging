// bst.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int bstSize = 100;

template <class Type>
class Element {
public:
  Type key;
};

template <class Type>
class BST {
public:
  BST(int size);
  void display();
  void Insert(const Element<Type>& x);
  Element<Type> *DeleteMax(Element<Type>&);
  void inorder();
private:
  Element<Type> *bst;
  int n;        // current size of BST
  int capacity; // Maximum allowable size of BST

  void bstEmpty() { cout << "bst Empty" << "\n"; };
  void bstFull() { cout << "bst Full"; };
  void inorder(int CurrentNodeIndex);
};


template <class Type>
BST<Type>::BST(int size = bstSize){
  capacity = size; n = 0;
  bst = new Element<Type>[capacity + 1]; // Don't want to use bst[0]
};

template <class Type>
void BST<Type>::display(){
  int i;
  for (i = 1; i <= n; i++) cout << i << ": " << bst[i].key << " ";
  cout << "\n";
}

template <class Type>
void BST<Type>::Insert(const Element<Type>& x){
  int i;
  if (n == capacity) { bstFull(); return; }   // �ʿ��ϴٸ� bst ũ�⸦ Ȯ��
  n++;
  for (i = n; 1; ) {
    if (i == 1) break; // at root
    if (x.key <= bst[i / 2].key) break;
    // move from parent to i
    bst[i] = bst[i / 2];
    i /= 2;
  }
  bst[i] = x;
}

template <class Type>
Element<Type>* BST<Type>::DeleteMax(Element<Type>& x){
  int i, j;
  if (!n) { bstEmpty(); return 0; }
  x = bst[1]; Element<Type> k = bst[n]; n--;

  for (i = 1, j = 2; j <= n; )
  {
    if (j < n) if (bst[j].key < bst[j + 1].key) j++;
    // j points to the larger child
    if (k.key >= bst[j].key) break;
    bst[i] = bst[j];
    i = j; j *= 2;
  }
  bst[i] = k;
  return &x;
}

template <class Type>
void BST<Type>::inorder(){
  int root = 1;   // ��Ʈ ����� ÷�� = 1
  cout << "\n���� ��ȸ: ";
  inorder(root);
  cout << "\n\n";
}

template <class Type>
void BST<Type>::inorder(int CurrentNodeIndex){
  if (CurrentNodeIndex <= n) {         // ��ȿ�� ����� ���
    inorder(2 * CurrentNodeIndex);      // ���� �ڽĳ��
    cout << bst[CurrentNodeIndex].key << "  ";
    inorder(2 * CurrentNodeIndex + 1);  // ������ �ڽĳ��
  }
}


int main(){
  BST<int> m(20);
  Element<int> a, b, c, d, e, f, g, h, i, j;

  a.key = 5; b.key = 3; c.key = 11; d.key = 3; e.key = 15;
  f.key = 2; g.key = 8; h.key = 22; i.key = 20; j.key = 9;

  m.Insert(a); m.Insert(b); m.Insert(c); m.Insert(d); m.Insert(e);
  m.Insert(f); m.Insert(g); m.Insert(h); m.Insert(i); m.Insert(j);

  m.inorder();    // 10���� ���� ������ �������� ������ȸ

  Element<int> x;  // �����Ǵ� ���Ұ� ����Ǵ� ����

  m.display();
  if (m.DeleteMax(x)) cout << x.key << "\n";
  m.display();
  if (m.DeleteMax(x)) cout << x.key << "\n";
  m.display();
  if (m.DeleteMax(x)) cout << x.key << "\n";
  m.display();
  if (m.DeleteMax(x)) cout << x.key << "\n";
  m.display();
  if (m.DeleteMax(x)) cout << x.key << "\n";
  m.display();
  if (m.DeleteMax(x)) cout << x.key << "\n";
  m.display();
  if (m.DeleteMax(x)) cout << x.key << "\n";
  m.display();
  if (m.DeleteMax(x)) cout << x.key << "\n";
  m.display();
  if (m.DeleteMax(x)) cout << x.key << "\n";
  m.display();
  if (m.DeleteMax(x)) cout << x.key << "\n";
  m.display();
  if (m.DeleteMax(x)) cout << x.key << "\n";  // �� ť���� �����ϰ� ��

  return 0;
}

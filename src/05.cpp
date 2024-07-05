#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define MAX_QUEUE_SIZE 100
using namespace std;

/* Class */
class binarynode {
protected:
	int	data;
	binarynode* left;
	binarynode* right;
public:
	/* Constructor & Destructor */
	binarynode(int _data = 0, binarynode* _left = NULL, binarynode* _right = NULL)  
		: data(_data), left(_left), right(_right) { }
	~binarynode() { }
	/* Method */
	void setdata(int _data) { 
		data = _data; 
	}
	void setleft(binarynode* _left) { 
		left = _left; 
	}
	void setright(binarynode* _right) { 
		right = _right; 
	}
	int	getdata() { 
		return data; 
	}
	binarynode* getleft() { 
		return left; 
	}
	binarynode* getright() { 
		return right; 
	}
	bool isleaf() { 
		return left == NULL && right == NULL; 
	}
};

class circularqueue {
private:
	int	front;
	int	rear;
	binarynode* data[MAX_QUEUE_SIZE];
public:
	/* Constructor & Destructor */
	circularqueue() 
		: front(0), rear(0) { }
	~circularqueue() { }
	/* Method */
	bool isempty() { 
		return front == rear; 
	}
	bool isfull() { 
		return (rear + 1) % MAX_QUEUE_SIZE == front; 
	}
	void enqueue(binarynode* n) {
		if (isfull()) {
			cout << "Error: ť�� ��ȭ�����Դϴ�.\n";
		}			
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}
	binarynode* dequeue() {
		if (isempty()) {
			cout << "Error: ť�� ��������Դϴ�.\n";
		}
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
};

class binarytree {
private:
	binarynode* root;
public:
	/* Constructor & Destructor */
	binarytree() 
		: root(NULL) { }
	~binarytree() { }
	/* Method : Bool */
	bool isempty() {
		return root == NULL;
	}
	/* Method : Set */
	void setroot(binarynode* node) { 
		root = node; 
	}
	/* Method : Get */
	binarynode* getroot() { 
		return root; 
	}
	int	getcount() { 
		return isempty() ? 0 : getcount(root); 
	}
	int getcount(binarynode* node) {
		if (node == NULL) return 0;
		return 1 + getcount(node->getleft()) + getcount(node->getright());
	}
	int	getleafcount() { 
		return isempty() ? 0 : getleafcount(root); 
	}
	int getleafcount(binarynode* node) {
		if (node == NULL) return 0;
		if (node->isleaf()) return 1;
		else return getleafcount(node->getleft()) + getleafcount(node->getright());
	}
	int	getheight() { 
		return isempty() ? 0 : getheight(root); 
	}
	int getheight(binarynode* node) {
		if (node == NULL) return 0;
		int	hLeft = getheight(node->getleft());
		int	hRight = getheight(node->getright());
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}
	/* Method : Evaluation */
	int	calcsize() { 
		return calcsize(root); 
	}
	int calcsize(binarynode* node) {
		if (node == NULL) return 0;
		return node->getdata() + calcsize(node->getleft()) + calcsize(node->getright());
	}
	int evaluate() { 
		return evaluate(root); 
	}
	int evaluate(binarynode* node) {
		if (node == NULL) return 0;
		if (node->isleaf()) return node->getdata();
		else {
			int op1 = evaluate(node->getleft());
			int op2 = evaluate(node->getright());
			switch (node->getdata()) {
			case '+': return op1 + op2;
			case '-': return op1 - op2;
			case '*': return op1 * op2;
			case '/': return op1 / op2;
			}
			return 0;
		}
	}
	/* Method : Traversal */
	void inorder() { 
		printf("\n%10s : ", "inorder");
		inorder(root); 
	}
	void inorder(binarynode* node) {
		if (node != NULL) {
			if (node->getleft() != NULL) inorder(node->getleft());
			printf("[%c] ", node->getdata());
			if (node->getright() != NULL) inorder(node->getright());
		}
	}
	void preorder() { 
		printf("\n%10s : ", "preorder");
		preorder(root); 
	}
	void preorder(binarynode* node) {
		if (node != NULL) {
			printf("[%c] ", node->getdata());
			if (node->getleft() != NULL) preorder(node->getleft());
			if (node->getright() != NULL) preorder(node->getright());
		}
	}
	void postorder() { 
		printf("\n%10s : ", "postorder");
		postorder(root); 
	}
	void postorder(binarynode* node) {
		if (node != NULL) {
			if (node->getleft() != NULL) postorder(node->getleft());
			if (node->getright() != NULL) postorder(node->getright());
			printf("[%c] ", node->getdata());
		}
	}	
	void levelorder() {
		printf("\n%10s : ", "levelorder");
		if (!isempty()) {
			circularqueue q;
			q.enqueue(root);
			while (!q.isempty()) {
				binarynode* n = q.dequeue();
				if (n != NULL) {
					printf("[%c] ", n->getdata());
					q.enqueue(n->getleft());
					q.enqueue(n->getright());
				}
			}
		}
		printf("\n");
	}

	/* Method : New(Homework) */
	bool isfull() {
		return getcount() == pow(2, getheight()) - 1;
	}
	/*
	1. ���̰� h�϶�, Ʈ���� �ּ� h�� ~ �ִ� 2^h - 1���� ��带 ������.
	2. �̶�, ����� ������ 0, 1, 3, 7, ..., 2^h - 1�� �� ��,
	   (��尡 �ش� ���̿��� ���� �� �ִ� �ִ� ������ ��) ��ȭ����Ʈ���� �ȴ�.
	3. ����� ������ 0���϶��� ��ȭ����Ʈ���� �����ϴ� �ɷ� ��������.
	*/
	
	bool isbalanced() {
		return isbalanced(root);
	}
	bool isbalanced(binarynode* node) {
		/* Base Case */
		if (node == NULL) 
			return true;
		/* Inductive Step */
		else 
			return 
			abs(getheight(node->getleft()) - getheight(node->getright())) < 2 &&
			isbalanced(node->getleft()) &&
			isbalanced(node->getright());
	}
	/*
	1. return isempty() ? true : isbalanced(root); ���� isempty() �޼ҵ�� �ᱹ
	   root == NULL ���θ� ������ ���̹Ƿ�, return isbalanced(root)�� �����ϴ�. 
	2. ����� ������ 0���϶��� balanced�� true�� �ȴٰ� ��������.	
	*/

	void reverse() {
		return reverse(root);
	}
	void reverse(binarynode* node) {
		/* Base Case */
		if (node == NULL)
			return;
		/* Inductive Step */
		//Recursion
		reverse(node->getleft());
		reverse(node->getright());
		//Swap
		binarynode* temp = node->getleft();
		node->setleft(node->getright());
		node->setright(temp);
	}
};

void main()
{
	binarytree tree;

	binarynode* d = new binarynode('D', NULL, NULL);
	binarynode* e = new binarynode('E', NULL, NULL);
	binarynode* b = new binarynode('B', d, e);
	binarynode* f = new binarynode('F', NULL, NULL);
	binarynode* c = new binarynode('C', f, NULL);
	binarynode* a = new binarynode('A', b, c);

	tree.setroot(a);
	printf("����� ���� = %d\n", tree.getcount());
	printf("�ܸ��� ���� = %d\n", tree.getleafcount());
	printf("Ʈ���� ���� = %d", tree.getheight());
	tree.inorder();
	tree.preorder();
	tree.postorder();
	tree.levelorder();

	binarytree tree2;
	//           +
	//       *       -
	//     3	   2   5   6
	binarynode* n1 = new binarynode(3, NULL, NULL);
	binarynode* n2 = new binarynode(2, NULL, NULL);
	binarynode* n3 = new binarynode('*', n1, n2);
	binarynode* n4 = new binarynode(5, NULL, NULL);
	binarynode* n5 = new binarynode(6, NULL, NULL);
	binarynode* n6 = new binarynode('-', n4, n5);
	binarynode* n7 = new binarynode('+', n3, n6);
	tree2.setroot(n7);
	printf("��� ��� = %d\n", tree2.evaluate());

	binarytree tree3;
	binarynode* m4 = new binarynode(200, NULL, NULL);
	binarynode* m5 = new binarynode(500, NULL, NULL);
	binarynode* m3 = new binarynode(100, m4, m5);
	binarynode* m2 = new binarynode(50, NULL, NULL);
	binarynode* m1 = new binarynode(0, m2, m3);
	tree3.setroot(m1);
	printf("���丮 �뷮 ��� ��� = %d KB\n", tree3.calcsize());
}
#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct node {

	int coefficient;
	int index;

} node;

node* new_node(int co, int In) {

	node* temp = (node*)calloc(1, sizeof(node));

	temp->coefficient = co;
	temp->index = In;

	return temp;

}

void print_term(int co, int In) {

	if (In > 0) {

		if (co == -1) {
			printf("-");
		}
		else {
			if (co != 1) {
				printf("%d", co);
			}
		}

		printf("X");
			
		if (In > 1) {
			printf("^%d", In);
		}
	}
	else {
		printf("%d", co);
	}

}

void print_sign(int x) {

	if (x > 0)
		printf("+");

}

void input(queue<node*>* q, queue<node*>* w) {

	node* temp;
	int co, In;

	// declare some temp varibles

	scanf("%d%d", &co, &In);

	while (1) {

		if (co == 0 && In == -1) {
			break;
		}

		temp = new_node(co, In);
		q->push(temp);
		w->push(temp);
		// origin output could be executed here too
		scanf("%d%d", &co, &In);

	}

}

void output(queue<node*>* q) {

	if (q->empty()) {
		printf("0");
		return;
	}

	int co = q->front()->coefficient;
	int In = q->front()->index;

	while (1) {

		print_term(co, In);

		q->pop();
		if (q->empty()) {
			break;
		}

		co = q->front()->coefficient;
		In = q->front()->index;

		print_sign(co);

	}

}

int main() {

	queue<node*> q1, q1q, q2, q2q, q3;
	// initiate all the queues

//	freopen("put.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	input(&q1, &q1q);
	input(&q2, &q2q);

	// input queues

	node* temp;
	int co, In;

	// declare some temp varibles

	while (!q1.empty() && !q2.empty()) {

		if (q1.front()->index == q2.front()->index) 
		{

			co = q1.front()->coefficient + q2.front()->coefficient;
			In = q1.front()->index;
			if (co) {
				temp = new_node(co, In);
				q3.push(temp);
			}

			q1.pop();
			q2.pop();

		}
		else {

			if (q1.front()->index > q2.front()->index) {

				q3.push(q1.front());
				q1.pop();

			}
			else {

				q3.push(q2.front());
				q2.pop();

			}

		}
	}

	while (!q1.empty()) {

		q3.push(q1.front());
		q1.pop();

	}

	while (!q2.empty()) {

		q3.push(q2.front());
		q2.pop();

	}

	// merge queue 1 & 2 into queue 3

	output(&q1q);
	printf("\n");
	output(&q2q);
	printf("\n");
	output(&q3);

	// output queues

}

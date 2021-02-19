#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct node {

	int coefficient;
	int index;
	struct node* next;

} queue_node;

typedef struct ptr {

	queue_node* head;
	queue_node* tail;

} queue_ptr;

int is_empty_queue(queue_ptr* q) {

	return q->head == q->tail;

}

void queue_init(queue_ptr* q) {

	q->head = (queue_node*)calloc(1, sizeof(queue_node));
	q->tail = q->head;
	q->tail->next = NULL;

}

queue_node* new_node(int co, int In) {

	queue_node* temp = (queue_node*)calloc(1, sizeof(queue_node));

	temp->coefficient = co;
	temp->index = In;
	temp->next = NULL;

	return temp;

}

void append_node(queue_ptr* q, queue_node* target) {

	q->tail->next = target;
	q->tail = target;

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

void input(queue_ptr* q) {

	queue_node* temp;
	int co, In;

	// declare some temp varibles

	scanf("%d%d", &co, &In);

	while (1) {

		if (co == 0 && In == -1) {
			break;
		}

		temp = new_node(co, In);
		append_node(q, temp);
		// origin output could be executed here too
		scanf("%d%d", &co, &In);

	}

}

void output(queue_ptr* q) {

	if (is_empty_queue(q)) {
		printf("0");
		return;
	}

	int co, In;

	queue_node* p = q->head->next;
	co = p->coefficient;
	In = p->index;

	while (p != NULL) {

		print_term(co, In);

		p = p->next;
		if (!p) {
			break;
		}

		co = p->coefficient;
		In = p->index;

		print_sign(co);

	}

}

int main() {

	queue_ptr q1, q2, q3;
	queue_init(&q1);
	queue_init(&q2);
	queue_init(&q3);

	// initiate all the queues

//	freopen("put.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	input(&q1);
	input(&q2);

	// input queues

	queue_node* p1 = q1.head->next;
	queue_node* p2 = q2.head->next;
	queue_node* temp;
	int co, In;

	// declare some temp varibles

	while (p1 != NULL && p2 != NULL) {

		if (p1->index == p2->index) {

			co = p1->coefficient + p2->coefficient;
			In = p1->index;
			if (co) {
				temp = new_node(co, In);
				append_node(&q3, temp);
			}

			p1 = p1->next;
			p2 = p2->next;

		}
		else {

			if (p1->index > p2->index) {

				append_node(&q3, new_node(p1->coefficient, p1->index));
				p1 = p1->next;

			}
			else {

				append_node(&q3, new_node(p2->coefficient, p2->index));
				p2 = p2->next;

			}

		}
	}

	while (p1 != NULL) {

		append_node(&q3, new_node(p1->coefficient, p1->index));
		p1 = p1->next;

	}

	while (p2 != NULL) {

		append_node(&q3, new_node(p2->coefficient, p2->index));
		p2 = p2->next;

	}

	// merge queue 1 & 2 into queue 3

	output(&q1);
	printf("\n");
	output(&q2);
	printf("\n");
	output(&q3);

	// output queues

}


/*
int queue_size(queue_ptr* q){
	int cnt = 0;
	queue_node* p = q->head->next;
	while(p != NULL){
		cnt++;
		p = p->next;
	}
	return cnt;
}

int either_empty(queue_ptr* q1, queue_ptr* q2){
	return is_empty_queue(q1) || is_empty_queue(q2);
}

queue_node* pop_node(queue_ptr* q){

	if(is_empty_queue(q)){
		return NULL;
	}

	queue_node* temp = q->head->next;

	q->head->next = temp->next;

	if (q->tail == temp) {
		q->tail = q->head;
	}

	return temp;

}
*/


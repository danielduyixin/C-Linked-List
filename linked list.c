#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int value;
	struct _node *next;
} Node;

void Sort(Node *head);

int Len(Node *head);

Node *Creat(Node *head);

int Find(Node *head, int findvalue);

void Print(Node *head);

Node *Add(Node *head, int index, int newvalue);

Node *Del(Node *head, int delvalue);

int main()
{
	Node *head = NULL;
	head = Creat(head);
	Print(head);
	int newindex, newvalue;
	printf("\n������ʲôλ�ü���ʲô��");
	printf("Ĭ�ϴ�1��ʼ\n");
	scanf("%d%d", &newindex, &newvalue);
	head = Add(head, newindex, newvalue);
	Print(head);
	Sort(head);
	printf("\n�������б�\n");
	Print(head);
	int findvalue, index;
	printf("\n������ҪѰ�ҵ�ֵ��");
	scanf("%d", &findvalue);
	index = Find(head, findvalue);
	printf("\n���������ҵ���\"%d\",λ����%2d\n", findvalue, index);
	int len, delvalue;
	len = Len(head);
	printf("\n������%-2d��Ԫ��\n\n", len);
	printf("����Ҫɾ����ֵ��");
	scanf("%d", &delvalue);
	head = Del(head, delvalue);
	printf("\nɾ��Ԫ�غ������\n");
	Print(head);
	printf("\n");
	return 0;
}

Node *Add(Node *head, int index, int newvalue)
{
	Node *p = head;
	Node *new, *new_head;
	int i = 0;
	if (index == 1) {
		new = (Node *) malloc(sizeof(Node));//����ͷ���
		new->next = head;
		new->value = newvalue;
		new_head = new;
		return new_head;
	}
	while (p != NULL) {
		if (i == index - 2) {
			new = (Node *) malloc(sizeof(Node));
			new->next = p->next;
			p->next = new;
			new->value = newvalue;
			break;
		}
		i++;
		p = p->next;
	}
	return head;
}

void Sort(Node *head)//�������� -- ѡ������ -- ����ֵ
{
	Node *p, *q;
	int len = Len(head);
	int i, t, min;
	p = head;
	for (i = 0; i < len; i++, p = p->next) {
		min = p->value;
		for (t = i + 1, q = p->next; t < len; t++, q = q->next) {
			if (q->value < min) {
				min = q->value;
				q->value = p->value;
				p->value = min;
			}
		}
	}
}

int Find(Node *head, int findvalue)
{
	Node *p = head;
	int index = 1;
	int length, i = 1;
	length = Len(head);
	while (i < length + 1) {
		if (p->value == findvalue) {
			index = i;
			break;
		}
		p = p->next;
		i++;
		index++;
	}
	return index;
}


int Len(Node *head)
{
	Node *p = head;
	int count = 1;
	while (1) {
		if (p->next != NULL) {
			count++;
			p = p->next;
		}
		else {
			break;
		}
	}
	return count;
}

Node *Del(Node *head, int delvalue)
{
	Node *p = head, *pre = NULL; //����head��Զ���ǵ�һ������Ҫ�ı�
	Node *new_head;
	int i = 0;
	int length;
	length = Len(head);
	if (delvalue == head->value) { //ɾ��ͷ���
		new_head = head->next;
		free(p);
		return new_head;
	}
	while (i < length) {
		pre = p;
		p = p->next;
		if (p->value == delvalue) {
			break;
		}
		i++;
	}
	pre->next = p->next;
	free(p);
	return head;
}

Node *Creat(Node *head)
{
	int number;
	struct _node *p, *q = NULL;
	printf("�������뿪ʼ\n");
	do {
		printf("������ֵ(����0����)��");
		scanf("%d", &number);
		p = (Node *) malloc(sizeof(Node));
		p->value = number;
		p->next = NULL;
		if (number != 0) {
			if (head != NULL) {
				q->next = p;
			}
			else {
				head = p;
			}
		}
		q = p;
	} while (number != 0);
	p = NULL;
	q->next = NULL;
	free(p);
	return head;
}

void Print(Node *head)
{
	Node *p = head;
	int i = 1;
	while (p != NULL) {
		if (i++ == 1) {
			printf("\n�������\n");
		}
		printf("%-5d", p->value);
		p = p->next;
	}
	printf("\n");
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack{
	int size;
	char *data;
}stack;
void create(stack *);
void push(stack * , char );
char pop(stack * );
char top(stack *);
int main(void)
{
	int test;
	int i;
	scanf("%d", &test);
	while(test){
		char ex[410];
		stack s1;
		s1.size = -1;
		s1.data = NULL;
		
		scanf("%s", ex);
		
		for(i=0 ; i < strlen(ex) ; i++) {
			if (ex[i] == '('){
				push(&s1, ex[i]);
			} else if (ex[i] == '-' | ex[i] == '+') {
				while(top(&s1) != '(' && top(&s1) != '+' && top(&s1) != '-'){
					printf("%c", pop(&s1));
				}
				push(&s1, ex[i]);
			} else if (ex[i] == '*' | ex[i] == '/' | ex[i] == '%') {
				while(top(&s1) != '(' && top(&s1) != '*' && top(&s1) != '/' && top(&s1) != '%') {
					printf("%c", pop(&s1));
				}
				push(&s1, ex[i]);
			} else if (ex[i] == '^') {
				push(&s1, ex[i]);
			} else if (ex[i] == ')') {
				while(top(&s1) != '(') {
					printf("%c", pop(&s1));
				}
				pop(&s1);
			} else {
				printf("%c", ex[i]);
			}
		}
		printf("\n");
		test--;
	}
	return 0;
}
 
void create(stack * s1)
{
	s1->data = (char*)malloc(sizeof(char));
	
	return ;
}	
 
void push(stack * s1, char val)
{
	(s1->size)++;
	s1->data = (char*)realloc(s1->data,sizeof(char)*((s1->size)+1));
	(s1->data)[s1->size]=val;
	return ;
}
 
char pop(stack* s1)
{
	if(s1->size == -1)
		return -1;
	
		return ((s1 -> data)[(s1->size)--]);
}
 
char top(stack * s1)
{
	if(s1 -> size == -1)
		return -1;
	return (s1 -> data)[s1 -> size];
}

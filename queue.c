#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int data;
    struct Queue *next;
}queue;

queue *head = NULL;

queue *newNode(int data){
    queue *temp = malloc(sizeof(queue));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void push(int data){
    queue *temp = newNode(data);

    if (head == NULL){
        head = temp;
    }else{
        queue* now = head;
        while (now->next != NULL){
            now = now->next;
        }
        now->next = temp;
    }
}

int pop(){
    if (head == NULL){
        return -1; //meaning that the stack is empty
    }
    queue* temp = head;
    head = head->next;
    int data = temp->data;
    free(temp);
    return data;
}

int main(int argc, char const *argv[]){

    for (int i = 0; i < 10; i++){
        printf("Push %d\n", i);
        push(i);
    }


    int n = 0;
    while (n != -1){
        n = pop();
        if (n == -1){
            printf("Queue empty\n");
        }else{
            printf("Poped %d\n", n);
        }
    }
    return 0;
}

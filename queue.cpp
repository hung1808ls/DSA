#include<iostream>
using namespace std;
#define max 100
struct queue{
    int front;
    int behind;
    int data[max];
};
int Isempty(queue* Q){
    return (Q->behind == Q->front);
}
int Isfull(queue* Q){
    return(Q->behind == max);
}
void Init(queue* Q){
    Q->front = 0;
    Q->behind = 0;
}
void push(queue* Q, int n){
    if (Isfull(Q)) return;
    Q->data[Q->behind++] = n;
}
int pop(queue* Q){
    if(Isempty(Q)) return -1;
    int n = Q->data[Q->front++];
}



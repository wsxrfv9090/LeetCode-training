#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

HuffmanNode* createHuffmanNode(char character, float frequency) {
    HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    if (node != NULL) {
        node->character = character;
        node->frequency = frequency;
        node->left = NULL;
        node->right = NULL;
    }
    else
        printf("ERROR:createHuffmanNode function memory alloction failed.\n");
    return node;
}

 LinkQueue Qinit(){
	 LinkQueue queue = (LinkQueue)malloc(sizeof(*queue));
     if (queue != NULL) {
         queue->QueueLength = 0;
         queue->front = NULL;
         queue->rear = NULL;
     }
     else
         printf("ERROR:Qinit function memory alloction failed.\n");
	 return queue;
}

 void InsertNode(LinkQueue queue, HuffmanNode data) {
     QLinkNode* newNode = (QLinkNode*)malloc(sizeof(QLinkNode));
     if (newNode == NULL) {
         printf("ERROR:InsertNode function memory allocation failed.\n");
         return;
     }
     newNode->data = data; // 设置数据
     newNode->next = NULL; // 新节点将是最后一个节点
     if (queue->rear != NULL){
         newNode->prev = queue->rear; // 新节点的前一个节点是当前的尾节
         queue->rear->next = newNode; // 更新当前尾节点的next
     }
     queue->rear = newNode; // 更新队列的尾指针
     if (queue->front == NULL)
         queue->front = newNode; // 如果队列为空，则新节点也是头节点
     queue->QueueLength++;
     return;
 }

 int LengthOfQueue(LinkQueue queue) {
     if (queue->front == NULL)
         return 0;
     QLinkNode* current = queue->front;
     int count = 0;
     while (current != NULL) {
         count++;
         current = current->next;
     }
     return count;
 }

 QLinkNode* FindMid(LinkQueue queue) {
     if (queue == NULL || queue->front == NULL)
         return NULL;
     QLinkNode* fast = queue->front;
     QLinkNode* slow = queue->front;
     if (fast->next != NULL) {
         while (fast != NULL && fast->next != NULL) {
             fast = fast->next->next;
             slow = slow->next;
         }
     }
     else
         printf("One element in FindMid variable queue.\n");
     return slow;
 }

 void FreeQueue(LinkQueue queue) {
     QLinkNode* current = queue->front;
     while (current != NULL) {
         QLinkNode* temp = current;
         current = current->next;
         free(temp);
     }
     free(queue);
 }

 LinkQueue merge(LinkQueue leftQ, LinkQueue rightQ) {
     LinkQueue newQueue = Qinit();
     QLinkNode* leftFlag = leftQ->front;
     QLinkNode* rightFlag = rightQ->front;

     while (leftFlag != NULL && rightFlag != NULL) {
         if (leftFlag->data.frequency <= rightFlag->data.frequency) {
             InsertNode(newQueue, leftFlag->data);
             leftFlag = leftFlag->next;
         }
         else if (rightFlag->data.frequency < leftFlag->data.frequency) {
             InsertNode(newQueue, rightFlag->data);
             rightFlag = rightFlag->next;
         }
     }
     while (leftFlag != NULL) {
         InsertNode(newQueue, leftFlag->data);
         leftFlag = leftFlag->next;
     }
     while (rightFlag != NULL) {
         InsertNode(newQueue, rightFlag->data);
         rightFlag = rightFlag->next;
     }
     return newQueue;
 }

 LinkQueue splitQ(LinkQueue queue, QLinkNode* Mid) {
     if (queue->front == NULL || Mid == NULL) {
         printf("ERROR:splitQfunction got Null as a variable.\n");
         return NULL;
     }
     else if (Mid == queue->front) {
         printf("Mid == queue->front\n");
         return NULL;
     }

     LinkQueue LstQueue = Qinit();
     LstQueue->front = Mid;
     LstQueue->rear = queue->rear;
     LstQueue->QueueLength = LengthOfQueue(LstQueue);

     QLinkNode* FstEnd = Mid->prev;
     Mid->prev = NULL;
     if (FstEnd != NULL) {
         FstEnd->next = NULL;
         queue->rear = FstEnd;
     }
     queue->QueueLength = LengthOfQueue(queue);

     return LstQueue;
 }

 LinkQueue process(LinkQueue queue) {
     if (queue->front == queue->rear)
         return queue;
     QLinkNode* mid = FindMid(queue);
     LinkQueue rightQueue = splitQ(queue, mid);
     LinkQueue SortedLeft = process(queue);
     LinkQueue SortedRight = process(rightQueue);
     LinkQueue MergedQueue = merge(SortedLeft, SortedRight);
     free(rightQueue);
     return MergedQueue;
 }

 LinkQueue MergeSort(LinkQueue queue) {
     if (queue == NULL) {
         printf("ERROR: Function MergeSort got a NULL as a variable.\n");
         return NULL;
     }
     LinkQueue SortedQueue = process(queue);
     FreeQueue(queue);
     return SortedQueue;
     }






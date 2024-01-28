#include "struct.h"
#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

int main() {
	OriginalData A = { 'A',8.19 };
	OriginalData B = { 'B',1.47 };
	OriginalData C = { 'C',3.83 };
	OriginalData D = { 'D',3.91 };
	OriginalData E = { 'E',12.25 };
	OriginalData F = { 'F',2.26 };
	OriginalData G = { 'G',1.71 };
	OriginalData H = { 'H',4.57 };
	OriginalData I = { 'I',7.1 };
	OriginalData J = { 'J',0.14 };
	OriginalData K = { 'K',0.41 };
	OriginalData L = { 'L',3.77 };
	OriginalData M = { 'M',3.34 };
	OriginalData N = { 'N',7.06 };
	OriginalData O = { 'O',7.26 };
	OriginalData P = { 'P',2.89 };
	OriginalData Q = { 'Q',0.09 };
	OriginalData R = { 'R',6.85 };
	OriginalData S = { 'S',6.36 };
	OriginalData T = { 'T',9.41 };
	OriginalData U = { 'U',2.58 };
	OriginalData V = { 'V',1.09 };
	OriginalData W = { 'W',1.59 };
	OriginalData X = { 'X',0.21 };
	OriginalData Y = { 'Y',1.58 };
	OriginalData Z = { 'Z',0.08 };
	OriginalData arr[26] = { A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z };

	HuffmanNode* huffmanNodesArray[26];
	for (int i = 0; i < 26; i++)
		huffmanNodesArray[i] = createHuffmanNode(arr[i].character, arr[i].frequency);
	LinkQueue Queue = Qinit();
	for (int i = 0; i < 26; i++)
		InsertNode(Queue, *huffmanNodesArray[i]);
	for (int i = 0; i < 26; i++)
		free(huffmanNodesArray[i]);


	Queue = MergeSort(Queue);
	



	QLinkNode* currentNode = Queue->front;
	while (currentNode != NULL) {
		QLinkNode* nextNode = currentNode->next;
		printf("%c %f\n", currentNode->data.character, currentNode->data.frequency);
		currentNode = nextNode; 
	}
	FreeQueue(Queue);
	return 0;
}
#pragma once
#include "struct.h"

LinkQueue Qinit();
HuffmanNode* createHuffmanNode(char character, float frequency);
void InsertNode(LinkQueue queue, HuffmanNode data);
void FreeQueue(LinkQueue queue);
int LengthOfQueue(LinkQueue queue);
LinkQueue MergeSort(LinkQueue queue);
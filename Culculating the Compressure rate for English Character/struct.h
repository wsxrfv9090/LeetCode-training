#pragma once
#ifndef HUFFMAN_H
#define HUFFMAN_H

typedef struct OriginalData {
    char character;
    float frequency;
}OriginalData;

typedef struct HuffmanNode {
    char character;
    float frequency;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
} HuffmanNode;

typedef struct QLinkNode {
    int SerNum;
    HuffmanNode data;
    struct QLinkNode* next;
    struct QLinkNode* prev;
} QLinkNode;

typedef struct {
    int QueueLength;
    QLinkNode* front, * rear;
}*LinkQueue;




#endif
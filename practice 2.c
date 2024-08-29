#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum frequency character
int findMin(int freq[], int size, int exclude) {
    int minIndex = -1;
    for (int i = 0; i < size; i++) {
        if (freq[i] != -1 && (minIndex == -1 || freq[i] < freq[minIndex]) && i != exclude) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Huffman coding algorithm
void huffmanCoding(char chars[], int freq[], int size) {
    int totalNodes = size * 2 - 1;  // Total number of nodes in the Huffman tree
    int left[totalNodes], right[totalNodes];  // Left and right child indices
    int parent[totalNodes];  // Parent indices

    for (int i = 0; i < totalNodes; i++) {
        parent[i] = -1;
    }

    int nextNode = size;

    for (int i = 0; i < size - 1; i++) {
        int min1 = findMin(freq, nextNode, -1);  // Find the smallest frequency
        int min2 = findMin(freq, nextNode, min1);  // Find the next smallest frequency

        // Create a new node with the sum of frequencies
        freq[nextNode] = freq[min1] + freq[min2];
        left[nextNode] = min1;
        right[nextNode] = min2;
        parent[min1] = parent[min2] = nextNode;

        freq[min1] = freq[min2] = -1;  // Mark as visited
        nextNode++;
    }

    // Print Huffman codes by traversing the tree
    char code[100];
    for (int i = 0; i < size; i++) {
        int current = i;
        int codeIndex = 0;

        while (parent[current] != -1) {
            if (left[parent[current]] == current) {
                code[codeIndex++] = '0';
            } else {
                code[codeIndex++] = '1';
            }
            current = parent[current];
        }
        code[codeIndex] = '\0';

        // Reverse the code since we built it backwards
        for (int j = 0; j < codeIndex / 2; j++) {
            char temp = code[j];
            code[j] = code[codeIndex - j - 1];
            code[codeIndex - j - 1] = temp;
        }

        printf("%c: %s\n", chars[i], code);
    }
}

// Driver code
int main() {
    char chars[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(chars) / sizeof(chars[0]);

    huffmanCoding(chars, freq, size);

    return 0;
}

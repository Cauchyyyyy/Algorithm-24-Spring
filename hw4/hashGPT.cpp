#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100000 // Adjusted size to handle larger input
#define MAX_STRING_LENGTH 1001 // Maximum length of a string

// Define a structure for a node in the hash table
typedef struct Node {
    char key[MAX_STRING_LENGTH];
    struct Node *next;
} Node;

// Define the hash table
Node *hashTable[TABLE_SIZE];

// Hash function to convert string to index
unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

// Function to insert a key into the hash table
void insert(const char *key) {
    unsigned long index = hash(key);

    // Check if the key already exists in the hash table
    Node *temp = hashTable[index];
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            // Key already exists, do not insert again
            return;
        }
        temp = temp->next;
    }

    // Key doesn't exist, insert it into the hash table
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Function to count the number of unique keys in the hash table
int countUnique() {
    int count = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *temp = hashTable[i];
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
    }

    return count;
}

int main() {
    int N;
    
    scanf("%d", &N);

    // Initialize the hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert strings into the hash table
    
    for (int i = 0; i < N; i++) {
        char str[MAX_STRING_LENGTH];
        scanf("%s", str);
        insert(str);
    }

    // Count the number of unique strings
    int uniqueCount = countUnique();
    printf("%d\n", uniqueCount);

    return 0;
}

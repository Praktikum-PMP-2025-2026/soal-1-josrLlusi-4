/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 4
 *   Hari dan Tanggal    : Rabu, 6 Mei 2026
 *   Nama (NIM)          : Jose Luis Fernando Saragi (13224013)
 *   Nama File           : soal1.c
 *   Deskripsi           : ada antrian sebanyak N dan ada waktu tunggu. tampilkan antrian dan total waktu tunggu
 * 
 */
// Source: https://www.geeksforgeeks.org/c/queue-using-linked-list-in-c/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//wait 21
// 0 3 8 10 sum = 21 yang 4 terajhir untuk wait setelah a04 (gak exist)

typedef struct Node{
    char id[100];
    int d;
    struct Node *next;
}Node;

typedef struct queue{
    struct Node *front;
    struct Node *rear;
}queue;

Node *createNode(char id[100], int d){
    Node *newnode = (Node *)malloc(sizeof(Node));
    if(newnode == NULL){
        return NULL;
    }

    strcpy(newnode->id, id);
    newnode->d = d;
    newnode->next = NULL;
    return newnode;
}

queue* createqueue(){
    queue *Queue = (queue*)malloc(sizeof(queue));
    Queue->front = NULL;
    Queue->rear = NULL;
    
    return Queue;

}

void enqueue(queue *Q, char id[100], int d){
    Node* temp = createNode(id, d);

    if(!temp){
        printf("Alokasi gagal");
        return;
    }
    Node* tempo = Q->front;

    if(Q->front == NULL){
        Q->front = temp;
        return;
    }

    while(tempo != NULL){
        if(tempo->next == NULL){
            tempo->next = temp;
            return;
        }
        tempo = tempo->next;

    }
    
}

void output(queue *Q){
    Node *temp = Q->front;
    printf("ORDER ");
    while(temp != NULL){
        printf("%s ", temp->id);
        temp = temp->next;
    }
    printf("\n");
}

void waktuTunggu(queue *Q, int* count, int* size){
    Node* temp = Q->front;
    int sizetemp = *size;
    int next = 0;
    int tempawal = temp->d;
    int tempnextnya = temp->next->d;
    *count = temp->d;
    *count = *count +  2 * tempawal + tempnextnya;

    temp = temp->next;

    while(temp->next != NULL){
        *count = *count + temp->d;
        temp = temp->next;
    }

}

int main() {
    int size;
    queue *Q = createqueue();
    char string[100];
    int data;
    int count = 1;
    int total = 0;

    scanf("%d", &size);
    getchar();

    while(count <= size){
        scanf("%s", &string);
        scanf("%d", &data);
        getchar();

        enqueue(Q, string, data);
        count++;
    }

    output(Q);

    waktuTunggu(Q, &total, &count);
    printf("WAIT %d", total);
    return 0;
}
 

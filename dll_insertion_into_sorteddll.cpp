/*bruteforce*/
#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* newNode=new DoublyLinkedListNode(data);
    DoublyLinkedListNode* current=head;
    DoublyLinkedListNode* tn;
    if(head==NULL){
        return newNode;
    }
    else{
        while(current!=NULL){
            tn=current->next;
            if (tn==NULL && newNode->data>=current->data){
                newNode->prev=current;
                current->next=newNode;
                return head;
            }
            else if (newNode->data>=current->data && newNode->data<=tn->data){
                newNode->next=tn;
                newNode->prev=current;
                tn->prev=newNode;
                current->next=newNode;
                return head;
                }
            else if (newNode->data < current->data){
                newNode->next=current;
                current->prev=newNode;
                newNode->prev=head;
                return newNode;
            }
            current=current->next;
    }
    


}
return head;
}

int main()

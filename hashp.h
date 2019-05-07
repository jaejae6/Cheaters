//
// Created by bethe on 4/29/2019.
//

#ifndef UNTITLED8_HASHP_H
#define UNTITLED8_HASHP_H

#include<iostream>
#include <list>
#include "math.h"
using namespace std;

class Hash
{


private:
    int BUCKET;    // No. of buckets

    struct Node{

        int index;
        Node *next;
    };
    Node *head;

    Node *array[100000];


    // Pointer to an array containing buckets
    list<int> *table;
public:
    Hash(int V);  // Constructor

    // inserts a key into hash table
    void insertItem(int fileNum , string x);

    // deletes a key from hash table
    void deleteItem(string key);

    // hash function to map values to key
    int hashFunction(string x) ;

    void displayHash();

    void displayArray(int size, vector<string> file);
};






Hash::Hash(int b)
{
    this->BUCKET = b;
    //table = new list<int>[BUCKET];
    head = NULL;

    for(int i= 0; i<b; i++)
    {
        array[i] = NULL;
    }

}

void Hash::insertItem(int fileNum , string x)
{
    Node *test = new Node;
    int index = hashFunction(x);


    if(array[index] == NULL)
    {
        Node *holder;
        test->index = fileNum;
        test->next = NULL;
        holder = test;
        array[index] = holder;
    }
    else
    {
        Node *holder = array[index];
        test->index = fileNum;
        test->next = holder;
        holder = test;
        array[index] = holder;
    }
    //table[index].push_back(fileNum);
}

void Hash::deleteItem(string key)
{
    // get the hash index of key
    int index = hashFunction(key);

    // find the key in (inex)th list
    for (int i = 0; i < BUCKET; i++) {

    }
}

int Hash:: hashFunction(string x)
{
    unsigned long long  result = 0;
    for(int i =0; i<x.length(); i++)
    {
        result += ( ( x[i] *  (long long)pow(31,i) )) %BUCKET;
        result = result % BUCKET;
    }

    //use method 2 from the Hashing powerpoint
    return result ;
}

void Hash::displayHash() {
    for (int i = 0; i < BUCKET; i++) {

        Node *temp = array[i];
        cout << i;
        while(temp != NULL)
        {
            cout << " -->file " << temp->index;
            temp = temp->next;
        }
        cout << endl;
    }
}
void Hash::displayArray( int size, vector<string>file ) {

    int array2[size][size];




    for(int i =0; i<size; i++)
    {
        for(int j =0; j<size; j++)
            array2[i][j] = 0;
    }

    for(int i =0; i<BUCKET; i++)
    {
        Node *temp = array[i];
        int count;
        //Node *temp1 = array[i]->next;

        while(temp != NULL)
        {
            Node *temp1 = temp->next;
            while (temp1 != NULL) {
                count = array2[temp->index][temp1->index];
                count++;
                array2[temp->index][temp1->index] = (count);
                temp1 = temp1->next;
            }
            count = 0;

            temp = temp->next;
        }

    }


    for (int i = 0; i < size; i++)
    {

        for (int j =0; j<size; j++)
        {
            if(array2[i][j] > 200 )
                cout << array2[i][j] << " : " << file[i] << ","<< file[j] << endl ;

        }

    }
}


#endif //UNTITLED8_HASHP_H

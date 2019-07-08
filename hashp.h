// Created by Jaelyn Bethea on 4/10/2019.
// //
// /* Student information for project:
//  *
//  * Replace <NAME> with your name.
//  *
//  * On my honor, Jaelyn Bethea, this programming project is my own work
//  * and I have not provided this code to any other student.
//  *
//  * Name: Jaelyn Bethea
//  * email address: betheajaelyn@utexas.edu
//  * UTEID: jnb2634
//  * Section 5 digit ID: 15975
//  *
//  */



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

    //displays the files that have over 200 matches 
    void displayArray(int size, vector<string> file);
};





//constructor for the hash table; hash table is created by using a linked list
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

//function that inserts string into the hast table
void Hash::insertItem(int fileNum , string x)
{
    Node *test = new Node;
    
    //gets the 'key' for the hash table
    int index = hashFunction(x);

    //checking to see there was anything at the head of the linked list
    if(array[index] == NULL)
    {
        Node *holder;
        test->index = fileNum;
        test->next = NULL;
        holder = test;
        array[index] = holder;
    }
    //adds to the linked list
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

//creates the key 
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


//displays the files that have more than 200 matches
void Hash::displayArray( int size, vector<string>file ) {

    //creates a 2D array to hold the number of matches
    int array2[size][size];



    //makes sure all matches start off with 0
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

        //traverses through the linked list 
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

    //displays the file names that have over 200 matches in-common 
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

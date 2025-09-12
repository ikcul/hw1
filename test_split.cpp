/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{
    Node* test = new Node(0, nullptr);
    Node* tail = test;

    for (int i = 1; i <= 20; i++){
        tail->next = new Node(i, nullptr);
        tail = tail->next;
    }

    Node* odds = nullptr;
    Node* evens = nullptr;

    split(test, odds, evens);

    std::cout << "Testing a linkedlist from 0 to 20" << std::endl;
    
    std::cout << "Odds list: ";
    Node* temp = odds;
    while (temp != nullptr){
        std::cout << temp->value << " ";
        Node* next = temp->next;
        delete temp;
        temp = next;
    }

    std::cout << std::endl;

    std::cout << "Evens list: ";
    temp = evens;
    while (temp != nullptr){
        std::cout << temp->value << " ";
        Node* next = temp->next;
        delete temp;
        temp = next;
    }

    std::cout << std::endl;

    //New test for Odds Only

    Node* testb = new Node(1, nullptr);
    Node* tailb = testb;

    for (int i = 3; i <= 20; i+=2){
        tailb->next = new Node(i, nullptr);
        tailb = tailb->next;
    }

    Node* oddsb = nullptr;
    Node* evensb = nullptr;

    split(testb, oddsb, evensb);

    std::cout << "Testing a linkedlist from 0 to 20" << std::endl;
    
    std::cout << "Odds list: ";
    Node* tempb = oddsb;
    while (tempb != nullptr){
        std::cout << tempb->value << " ";
        Node* nextb = tempb->next;
        delete tempb;
        tempb = nextb;
    }

    std::cout << std::endl;

    std::cout << "Evens list: ";
    tempb = evensb;
    while (tempb != nullptr){
        std::cout << tempb->value << " ";
        Node* nextb = tempb->next;
        delete tempb;
        tempb = nextb;
    }
    
    std::cout << std::endl;

    //Empty list

    Node* testc = nullptr;
    Node* oddsc = nullptr;
    Node* evensc = nullptr;

    split(testc, oddsc, evensc);

    std::cout << "Odds list: ";
    Node* tempc = oddsc;
    while (tempc != nullptr){
        std::cout << tempc->value << " ";
        Node* nextc = tempc->next;
        delete tempc;
        tempc = nextc;
    }

    std::cout << std::endl;

    std::cout << "Evens list: ";
    tempc = evensc; 
    while (tempc != nullptr){
        std::cout << tempc->value << " ";
        Node* nextc = tempc->next;
        delete tempc;
        tempc = nextc;
    }

    std::cout << std::endl;

    //Single Node list

    Node* testd = new Node(7, nullptr);
    Node* oddsd = nullptr;
    Node* evensd = nullptr;

    split(testd, oddsd, evensd);

    std::cout << "Odds list: ";
    Node* tempd = oddsd;
    while (tempd != nullptr){
        std::cout << tempd->value << " ";
        Node* nextd = tempd->next;
        delete tempd;
        tempd = nextd;
    }

    std::cout << std::endl;

    std::cout << "Evens list: ";
    tempd = evensd; 
    while (tempd != nullptr){
        std::cout << tempd->value << " ";
        Node* nextd = tempd->next;
        delete tempd;
        tempd = nextd;
    }

    std::cout << std::endl;

    return 0;
}

#pragma once
#include <cstdlib>
#include<iostream>
using namespace std;

namespace St{
    struct Student {
        std::string lastName;
        std::string firstName;
        int course;
        float average;

        Student(const std::string& last, const std::string& first, int crs, float avg)
            : lastName(last), firstName(first), course(crs), average(avg) {}

        friend std::ostream& operator<<(std::ostream& os, const Student& student) {
            os << "Student: " << student.lastName << student.firstName << ", Course: " << student.course << ", Average: " << student.average;
            return os;
        }

        bool operator==(const Student& other) const
        {
            return lastName == other.lastName && firstName == other.firstName && course == other.course && average == other.average;
        }
    };



    template <typename T>
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    template <typename T>
    class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        LinkedList() : head(nullptr), tail(nullptr) {}

        LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr) {
            Node<T>* otherCurrent = other.head;
            while (otherCurrent != nullptr) {
                push_tail(otherCurrent->data);
                otherCurrent = otherCurrent->next;
            }
        }

        LinkedList(int size) : head(nullptr), tail(nullptr) {
            for (int i = 0; i < size; ++i) {
                push_tail(rand());
            }
        }

        ~LinkedList() {
            while (head != nullptr) {
                pop_head();
            }
        }

        Node<T>* get_head() const {
            return head;
        }
        Node<T>* get_tail() const {
            return tail;
        } 

        LinkedList& operator=(const LinkedList& other) {
            if (this != &other) {
                while (head != nullptr) {
                    pop_head();
                }
                Node<T>* otherCurrent = other.head;
                while (otherCurrent != nullptr) {
                    push_tail(otherCurrent->data);
                    otherCurrent = otherCurrent->next;
                }
            }
            return *this;
        }

        void push_tail(const T& value)
        {
            Node<T>* newNode = new Node<T>(value);
            if (head == nullptr)
            {
                head = newNode;
            }
            else
            {
                Node<T>* current = head;
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                current->next = newNode;
                newNode->prev = current;
            }
        }

        void push_tail(const LinkedList& other)
        {
            Node<T>* otherCurrent = other.head;
            while (otherCurrent != nullptr)
            {
                push_tail(otherCurrent->data);
                otherCurrent = otherCurrent->next;
            }
        }

        void push_head(const T& value)
        {
            Node<T>* newNode = new Node<T>(value);
            if (head != nullptr)
            {
                head->prev = newNode;
                newNode->next = head;
            }
            head = newNode;
        }

        bool is_empty() const
        {
            return head == nullptr;
        }

        
        
    };
}

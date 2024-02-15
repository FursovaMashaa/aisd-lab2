#include <gtest/gtest.h>
#include<list.cpp>

using namespace std;
using namespace St;

TEST(StudentTest, EqualityOperatorTest) {
    LinkedList<Student> studentList;
    LinkedList<Student> studentList2;

    studentList.push_tail(Student("Andreev", "Daniil", 3, 4.8));
    studentList.push_tail(Student("Danilov", "Petr", 4, 4.8));
    studentList.push_tail(Student("Petrov", "Maksim", 5, 2.4));
    studentList.push_tail(Student("Maksimov", "Alexander", 2, 2.1));
    studentList.push_tail(Student("Alexandrov", "Fedor", 4, 4.7));

    studentList.push_tail(Student("Abb", "Ddd", 3, 4.8));
    studentList.push_tail(Student("BB", "BB", 4, 4.8));
    studentList.push_tail(Student("CC", "CC", 5, 2.4));

    studentList.push_head(studentList2);

    studentList.print();
}

// Test the push_tail function
TEST(LinkedListTest, PushTail) {
    LinkedList<int> list;
    list.push_tail(1);
    list.push_tail(2);
    list.push_tail(3);

    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
}

// Test the push_head function
TEST(LinkedListTest, PushHead) {
    LinkedList<int> list;
    list.push_head(3);
    list.push_head(2);
    list.push_head(1);

    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
}

// Test the push_tail with another LinkedList
TEST(LinkedListTest, PushTailWithLinkedList) {
    LinkedList<int> list1;
    list1.push_tail(1);
    list1.push_tail(2);
    list1.push_tail(3);

    LinkedList<int> list2;
    list2.push_tail(4);
    list2.push_tail(5);

    list1.push_tail(list2);

    EXPECT_EQ(list1[0], 1);
    EXPECT_EQ(list1[1], 2);
    EXPECT_EQ(list1[2], 3);
    EXPECT_EQ(list1[3], 4);
    EXPECT_EQ(list1[4], 5);
}


// Test the is_empty function
TEST(LinkedListTest, IsEmpty) {
    LinkedList<int> list;

    EXPECT_TRUE(list.is_empty());

    list.push_tail(1);

    EXPECT_FALSE(list.is_empty());
}

// Test the assignment operator
TEST(LinkedListTest, AssignmentOperator) {
    LinkedList<int> list1;
    list1.push_tail(1);
    list1.push_tail(2);
    list1.push_tail(3);

    LinkedList<int> list2;
    list2 = list1;

    EXPECT_EQ(list2[0], 1);
    EXPECT_EQ(list2[1], 2);
    EXPECT_EQ(list2[2], 3);
}

TEST(LinkedListTest, RemoveDuplicates) {
    LinkedList<Student> list;
    Student s1("Doe", "John", 1, 80.5);
    Student s2("Smith", "Jane", 2, 90.0);
    Student s3("Doe", "John", 1, 80.5);
    Student s4("Johnson", "David", 3, 75.2);
    Student s5("Smith", "Jane", 2, 90.0);

    list.push_tail(s1);
    list.push_tail(s2);
    list.push_tail(s3);
    list.push_tail(s4);
    list.push_tail(s5);

    list.remove_duplicates();

    // After removing duplicates, the list should contain only unique elements
    
    EXPECT_EQ(list[0], s1);
    EXPECT_EQ(list[1], s2);
    EXPECT_EQ(list[2], s4);
}


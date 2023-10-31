#include "1026_11125107.hpp"
#include "1026_11125107f.cpp"
#include "1026_11125107_Node.hpp"
#include "1026_11125107_Student.hpp"

using namespace std;



int main()
{
    Queue<Student> StudentQueue;//class:Stack-type:Student(class)
    Student *studentArray = new Student[3];
    // 使用動態分配的陣列
    studentArray[0] = Student(1, "Alice");
    studentArray[1] = Student(2, "Bob");
    studentArray[2] = Student(3,"Jack");
    for(int i=0;i<3;i++)
    {
        StudentQueue.Push(studentArray[i]);
    }
    cout<<"The front students data:\n";
    StudentQueue.Front() -> data.Print();
    cout<<"The rear students data:\n";
    StudentQueue.Rear() -> data.Print();

    StudentQueue.Pop();
    cout<<"After popped student's data:\n";
    StudentQueue.Front() -> data.Print();
    return 0;
}
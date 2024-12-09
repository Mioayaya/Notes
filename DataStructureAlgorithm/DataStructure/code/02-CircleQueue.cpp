// 循环队列，链表实现
// @data: 2024/12/09
#include <iostream>
#include <vector>
#include <queue>

typedef struct Node {
  int data;
  struct Node *next;
}Node;

class CircleQueue {
private:
  Node *front,*back;
  int length;
public:
  // 初始化
  CircleQueue() {
    Init();
  }
  // 重载通过数组初始化
  CircleQueue(std::vector<int> dataList) {
    Init();
    for(int data : dataList) {
      Push(data);
    }
  }

  // 析构函数
  ~CircleQueue() {
    Node *p = front;
    while(p!=nullptr) {
      Node *current = p;
      p = p->next;
      delete current;
    }
    front = back = nullptr;
  }

  // 入队
  bool Push(int data) {
    if(Full()) {
      Node *p = new Node;
      back->data = data;
      p->next = back->next;
      back->next = p;
      back = p;
    }else {
      back->data = data;
      back = back->next;
    }
    length++;
    return true;
  }

  // 不需要返回值
  bool Pop() {
    if(Empty()) return false;
    front = front->next;
    length--;
    return true;
  }

  // 出队重载
  bool Pop(int &res) {
    if(Empty()) return false;
    res = front->data;
    front = front->next;
    length--;
    return true;
  }

  // 队列是否为空
  bool Empty() {
    return front == back;
  }

  bool Full() {
    return back->next == front;
  }

  // 返回队列长度
  int Size() { 
    return length; 
  }

  // 返回链表长度
  int Length() {
    Node *p = front->next;
    int count = 0;
    while(p!=front) {
      count++;
    }
    return count;
  }
  
  // 返回头结点
  Node* Front() {
    return front;
  }

  // 返回尾结点
  Node* Back() {
    return back;
  }
private:
  void Init() {
    front = back = new Node;
    back->next = front;
    length = 0;   
  }
};

int main() {  
  std::vector<int> dataList = {1,2,3,4,5,6,7,8,9};
  CircleQueue *circleQueue = new CircleQueue();
  CircleQueue *testQueue = new CircleQueue(dataList);

  circleQueue->Push(1);
  circleQueue->Push(2);
  circleQueue->Push(3);
  circleQueue->Push(4);
  circleQueue->Push(5);
  circleQueue->Pop();
  circleQueue->Pop();
  circleQueue->Pop();
  circleQueue->Pop();
  circleQueue->Pop();
  
  return 0;  
}
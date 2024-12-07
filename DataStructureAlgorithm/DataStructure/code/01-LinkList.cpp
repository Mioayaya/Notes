// 链表
// data: 2024/12/07
#include <iostream>
#include <vector>

typedef struct Node {
  int data;
  struct Node *next;
}Node;

class LinkList {
public:
  std::string name;
private:
  Node *head,*tail;
  int length;

public:
  // 通过数组建立链表
  LinkList(std::string name,std::vector<int> dataList,bool type) {
    this->head = new Node;
    this->head->next = nullptr;
    this->name = name;
    this->length = 0;
    this->tail = head;
    // type为true 头插，false 尾插
    type ? InsertByHand(dataList) : InsertByTail(dataList);
    UpdateLengthAndTail();
  }

  ~LinkList() {
    Node *p = head;    
    while(p!=nullptr) {
      Node *current = p;
      p = p->next;
      delete current;
    }
    head = tail = nullptr;
  }

  // 头插法, head->node1 -->  head->newNode->node1
  void InsertByHand(std::vector<int> dataList) {
    for(int value: dataList) {
      Node *current = new Node;
      current->data = value;
      current->next = head->next;
      head->next = current;
    }     
  }

  // 尾插法
  void InsertByTail(std::vector<int> dataList) {
    Node *p = head;
    for(int i=0;i<dataList.size();i++) {
      Node *current = new Node;
      current->data = dataList[i];
      current->next = nullptr;
      p->next = current;
      p = p->next;
    }
  }

  // 插入结点 默认在尾部插入
  void Insert(int data) {
    Node *current = new Node;
    current->data = data;
    current->next = nullptr;
    tail->next = current;
    tail = current;
    length++;
  }

  // 在某个结点后面插入
  void Insert(int data,Node *node) {
    Node *current = new Node;
    current->data = data;
    current->next = node->next;
    node->next = current;
    if(node == tail) tail = current;  // 被插入结点是尾结点，更新尾结点
    length++;
  }

  // 删除结点  
  void DeleteNode(Node *p) {
    // 可以将下一个结点的data赋值给p，转而删除p->next
    // 如果当前结点是最后一个结点，直接删除，更新尾结点
    if(p == tail) {
      Node *prev = head;          
      while (prev->next != tail) prev = prev->next;
      // 删除尾节点
      prev->next = nullptr;
      delete p;
      tail = prev;
      length--;
      return;
    }

    Node *pnext = p->next;
    if(pnext == tail) tail = p; // 如果pnext即尾结点被删除了，需要更新尾结点
    p->data = pnext->data;
    p->next = pnext->next;
    delete pnext;
    length--;
  }

  Node* GetTail() {
    return tail;
  }

  // 按序号查找结点
  Node* GetElemByNum(int num) {
    if(num > length) return nullptr; // 超出链表长度返回空结点
    int count = num;
    Node *p = head;
    while(count--) p = p->next;
    return p;
  }

  // 按值查找结点
  Node* GetElemByValue(int value) {
    Node *p = head;
    while(p != nullptr) {
      if(p->data == value) return p;
      p = p->next;
    }
    return nullptr;
  }

  // 修改某个结点的数值
  void Modify(Node *p,int data) {
    p->data = data;
  }

  // 更新链表长度和尾结点
  void UpdateLengthAndTail() {
    Node *p = head->next;
    int count = 0;
    while(p!=nullptr) {
      if(p->next == nullptr) tail = p;  // 如果p的下一个结点是nullptr，说明p是最后一个结点
      p = p->next;
      count++;
    }
    this->length = count;
  }

  // 返回链表长度
  int GetLength() {    
    return this->length;
  }

  // 打印链表
  void PrintLink() {
    Node *p = head->next;
    while(p!=nullptr) {
      std::cout<< p->data << " ";
      p = p->next;
    }
    std::cout<<"length: "<<length<<std::endl<<std::endl;
  }
};

void TestFunction(LinkList *link) {
  std::cout<< link->name << ": "<< std::endl;
  std::cout<< "初始化:"; 
  link->PrintLink();

  std::cout<< "Insert(23): "<<std::endl;
  link->Insert(23);
  link->PrintLink();

  std::cout<< "查找序号3,并且在3号后插入99"<<std::endl;
  Node *p = link->GetElemByNum(3);
  link->Insert(99,p);
  link->PrintLink();

  std::cout<< "查找值为7的结点,并且在该结点后插入114"<<std::endl;
  p = link->GetElemByValue(7);
  link->Insert(114,p);
  link->PrintLink();

  std::cout<< "删除值为7的结点"<<std::endl;
  link->DeleteNode(p);
  link->PrintLink();

  std::cout<< "删除尾结点"<<std::endl;
  p = link->GetTail();
  link->DeleteNode(p);
  link->PrintLink();

}

int main() 
{
  std::vector<int> dataList = {1,2,3,4,5,6,7,8,9,10};
  LinkList *linkHand = new LinkList("头插法",dataList,true);
  LinkList *linkTail = new LinkList("尾插法",dataList,false);

  linkHand->PrintLink();
  linkTail->PrintLink();

  TestFunction(linkTail);

  delete linkHand;
  delete linkTail;
  
  return 0;
}

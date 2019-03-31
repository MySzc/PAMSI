#include <iostream>
#include "stack.h"
#include "queue.h"
#include "priorityqueue.h"
#include "linkedlist.h"
#include "hashmap.h"
#include <list>
#include <stack>
#include <queue>
#include <map>


int main() {

    std::cout << "Starting up..." << std::endl;

    std::cout << std::endl << std::endl << "Running test: STACK" << std::endl << std::endl;

    Stack<int> s;
    std::stack<int> stds;

    stds.push(10);
    stds.push(11);
    stds.push(12);
    stds.pop();
    stds.pop();
    stds.pop();
    stds.pop();


    s.push(10);
    s.push(11);
    s.push(12);
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    std::cout << std::endl << std::endl << "Running test: QUEUE" << std::endl << std::endl;

    Queue<int> q;
    std::queue<int> stdq;

    stdq.push(1);
    stdq.push(2);
    stdq.push(3);
    stdq.pop();
    stdq.pop();
    stdq.pop();
    stdq.pop();

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();


    std::cout << std::endl << std::endl << "Running test: PRIORITYQUEUE" << std::endl << std::endl;

    PriorityQueue<int> pq;
    std::priority_queue<int> stdpq;

    stdpq.push(2);
    stdpq.push(2);
    stdpq.push(53);
    stdpq.push(0);
    stdpq.push(122);
    stdpq.push(7);
    stdpq.push(5);
    stdpq.pop();
    stdpq.pop();
    stdpq.pop();
    stdpq.pop();
    stdpq.pop();
    stdpq.pop();
    stdpq.pop();
    stdpq.pop();

    pq.enqueue(2,3);
    pq.enqueue(4,2);
    pq.enqueue(5,1);
    pq.enqueue(1,1);
    pq.enqueue(5,0);
    pq.enqueue(2,10);
    pq.enqueue(55,8);
    pq.enqueue(9,11);
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();


    std::cout << std::endl << std::endl << "Running test: DOUBLELINKEDLIST" << std::endl << std::endl;

    List<int> l;
    std::list<int> stdl;

    stdl.push_back(3);
    stdl.push_back(4);
    stdl.push_front(2);
    stdl.push_front(1);
    stdl.remove(2);
    stdl.insert(stdl.begin(), 1);


    l.pushBack(3);
    l.pushBack(4);
    l.pushFront(2);
    l.pushFront(1);
    l.remove(2);
    l.insert(2,1);



    std::cout << std::endl << std::endl << "Running test: HASHMAP" << std::endl << std::endl;

    Map<int, int> m_i;
    Map<std::string, int> m_ss;
    Map<std::string, std::string> m_s;

    std::map<int,int> stdm;

    m_i.insert(0, 5);
    m_i.insert(5, 75);
    m_i.insert(85, 23);
    m_i.insert(100, 100);
    m_i.remove(0);

    m_ss.insert("test", 1);
    m_ss.insert("ttest", 129);
    m_ss.remove("test");


    m_s.insert("Marka", "BMW");
    m_s.insert("Silnik", "Benzyna");
   // m_s.remove("Marka");   <- nie dziala



    return 0;
}

enum QUEUE_STATUS
{
    QUEUE_STATUS_NORMAL,
    QUEUE_STATUS_EMPTY,
    QUEUE_STATUS_FULL
};

// 队列，顺序存储, C++实现
template <typename T> class SqQueue
{
public:
    static const int qSize = 5;

    SqQueue() : front(0), rear(0)
    {
        // 
    }

    int getQueueLen()
    {
        return ((rear - front + qSize) % qSize);
    }

    QUEUE_STATUS enQueue(const T &val)
    {
        if ((rear + 1) % qSize == front)
        {
            return QUEUE_STATUS_FULL;
        }

        data[rear] = val;
        rear = (rear + 1) % qSize;

        return QUEUE_STATUS_NORMAL;
    }

    QUEUE_STATUS deQueue(T &val)
    {
        if (rear == front)
        {
            return QUEUE_STATUS_EMPTY;
        }

        val = data[front];
        front = (front + 1) % qSize;

        return QUEUE_STATUS_NORMAL;
    }

private:
    int front;
    int rear;
    T data[qSize];
};

// 用栈实现队列
#include <stack>

template <typename T> class StackQueue
{
public:

    int getQueueLen()
    {
        return (pushStack.size() + popStack.size());
    }

    void enQueue(const T &val)
    {
        pushStack.push(val);
    }

    QUEUE_STATUS deQueue(T &val);

private:
    std::stack<T> pushStack;
    std::stack<T> popStack;
};

template <typename T> QUEUE_STATUS StackQueue<T>::deQueue(T &val)
{
    if (popStack.empty())
    {
        while (!pushStack.empty())
        {
            popStack.push(pushStack.top());
            pushStack.pop();
        }
    }

    if (popStack.empty())
    {
        return QUEUE_STATUS_EMPTY;
    }

    val = popStack.top();
    popStack.pop();

    return QUEUE_STATUS_NORMAL;
}


// 测试

#include <iostream>

void test_SqQueue()
{
    QUEUE_STATUS qStatus = QUEUE_STATUS_NORMAL;

    // test SqQueue
    SqQueue<int> sq;

    for (int i = 0; !qStatus && i <= 10; ++i)
    {
        qStatus = sq.enQueue(i);
    }

    int val;

    for (int j = 0; j <= 10; ++j)
    {
        val = 0xFFFFFFFF;
        qStatus = sq.deQueue(val);
        std::cout << qStatus << "  " << val << std::endl;

        if (j < 3)
        {
            sq.enQueue(j+6);
        }
    }

    std::cout << std::endl;

    // test StackQueue
    StackQueue<int> stq;

    qStatus = QUEUE_STATUS_NORMAL;

    for (int i = 0; i <= 3; ++i)
    {
        stq.enQueue(i);
    }

    for (int j = 0; j <= 10; ++j)
    {
        val = 0xFFFFFFFF;
        qStatus = stq.deQueue(val);
        std::cout << qStatus << "  " << val << std::endl;

        if (j < 3)
        {
            stq.enQueue(j + 6);
        }
    }
}

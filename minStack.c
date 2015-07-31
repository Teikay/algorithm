/**
 * 设计包含min函数的栈
 * 定义栈的数据结构，要求添加一个函数，能够得到栈的最小元素。
 * 要求函数 min、push以及pop 的时间复杂度都是 O(1)。
 * @brief
 *     Stack is a LIFO data structure. When some element is 
 *     poped from the stack, the status will recover to the
 *     original status as before that element was pushed.So
 *     we can recover the minimum element,too.
 */
#include<stdlib.h>

typedef struct MinStackElement
{
    int data;
    int min;
}MinStackElement;

typedef struct MinStack
{
    MinStackElement* data;
    int size;
    int top;
}MinStack;

MinStack MinStackInit(int maxSize)
{
    MinStack stack;
    stack.data = (MinStackElement*)malloc(sizeof(MinStackElement)*maxSize);
    stack.size = maxSize;
    stack.top = 0;
    return stack;
}

void MinStackFree(MinStack stack)
{
    if(stack.data)
    {
        free(stack.data);
    }
}

void MinStackPush(MinStack stack, int d)
{
    if(stack.top == stack.size) error("out of stack space!");

    MinStackElement* p = stack.data + stack.top;
    p->data = d;
    if(stack.top == 0)
        p->min = d;
    else
    {
        int frontMin = stack.data[stack.top -1].min;
        p->min = (d < frontMin ? d : frontMin);
    }
    stack.top++;
}

int MinStackPop(MinStack stack)
{
    if(stack.top == 0) error("stack is empty!");
    return stack.data[--stack.top].data;
}

int MinStackMin(MinStack stack)
{
    if(stack.top == 0) error("stack is empty!");
    return stack.data[stack.top-1].min;
}


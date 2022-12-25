//用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的
//功能。(若队列中没有元素，deleteHead 操作返回 -1 ) 
//
// 
//
// 示例 1： 
//
// 输入：
//["CQueue","appendTail","deleteHead","deleteHead"]
//[[],[3],[],[]]
//输出：[null,null,3,-1]
// 
//
// 示例 2： 
//
// 输入：
//["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
//[[],[],[5],[2],[],[]]
//输出：[null,-1,null,null,5,2]
// 
//
// 提示： 
//
// 
// 1 <= values <= 10000 
// 最多会对 appendTail、deleteHead 进行 10000 次调用 
// 
// Related Topics 栈 设计 队列 👍 572 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

/*
 * it is seems that we should use array
 * to implement a stack. maybe it will
 * use more memory relatively, but it
 * uses less time
 */

#define MAX_STACK_SIZE 10000

typedef struct {
    int data[MAX_STACK_SIZE]
    int pos;
} Stack;

static Stack * new_stack()
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->pos = -1;

	return stack;
}

static void stack_push(Stack *stack, int e)
{
	stack->pos += 1;
	stack->data[stack->pos] = e;
}

static bool stack_pop(Stack *stack, int *e)
{
	if (stack->pos < 0)
		return false;

	*e = stack->data[stack->pos];
	stack->pos -= 1;

	return true;
}

typedef struct {
    	Stack *push_stack;
	Stack *pop_stack;
} CQueue;


CQueue* cQueueCreate() {
	CQueue *queue = (CQueue *)malloc(sizeof(CQueue));
	queue->push_stack = new_stack();
	queue->pop_stack = new_stack();

	return queue;
}

void cQueueAppendTail(CQueue* obj, int value) {
	stack_push(obj->push_stack, value);
}

int cQueueDeleteHead(CQueue* obj) {
	int e;
	if(obj->pop_stack->pos < 0)
		while(stack_pop(obj->push_stack, &e))
			stack_push(obj->pop_stack, e);
	bool result = stack_pop(obj->pop_stack, &e);
	return result ? e : -1;
}

void cQueueFree(CQueue* obj) {
	free(obj->push_stack);
	free(obj->pop_stack);
	free(obj);
}


/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/
//leetcode submit region end(Prohibit modification and deletion)

//定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。 
//
// 
//
// 示例: 
//
// MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.min();   --> 返回 -3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.min();   --> 返回 -2.
// 
//
// 
//
// 提示： 
//
// 
// 各函数的调用总次数不超过 20000 次 
// 
//
// 
//
// 注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/ 
// Related Topics 栈 设计 👍 366 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

#define MAX_STACK_SIZE 20000

typedef struct {
	int min_stack[MAX_STACK_SIZE];
	int main_stack[MAX_STACK_SIZE];
	int min_pos;
	int main_pos;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
	stack->min_pos = -1;
	stack->main_pos = -1;
	return stack;
}

void minStackPush(MinStack* obj, int x) {
	obj->main_stack[++(obj->main_pos)] = x;
	if (obj->min_pos == -1
			|| obj->min_stack[obj->min_pos] >= x)
		obj->min_stack[++(obj->min_pos)] = x;
}

void minStackPop(MinStack* obj) {
	if (obj->main_pos == -1)
		return;

	int x = obj->main_stack[(obj->main_pos)--];
	if (x == obj->min_stack[obj->min_pos])
		obj->min_pos -= 1;
}

int minStackTop(MinStack* obj) {
	if (obj->main_pos == -1)
		return -1;

	return obj->main_stack[obj->main_pos];
}

int minStackMin(MinStack* obj) {
	if (obj->min_pos == -1)
		return -1;

	return obj->min_stack[obj->min_pos];
}

void minStackFree(MinStack* obj) {
	free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackMin(obj);
 
 * minStackFree(obj);
*/
//leetcode submit region end(Prohibit modification and deletion)

//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈
//的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。 
//
// 
//
// 示例 1： 
//
// 输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
//输出：true
//解释：我们可以按以下顺序执行：
//push(1), push(2), push(3), push(4), pop() -> 4,
//push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
// 
//
// 示例 2： 
//
// 输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
//输出：false
//解释：1 不能在 2 之前弹出。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= pushed.length == popped.length <= 1000 
// 0 <= pushed[i], popped[i] < 1000 
// pushed 是 popped 的排列。 
// 
//
// 注意：本题与主站 946 题相同：https://leetcode-cn.com/problems/validate-stack-sequences/ 
// Related Topics 栈 数组 模拟 👍 359 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

typedef struct {
	int *arr;
	int pos;
	int capacity;
} Stack;

Stack * new_stack(int capacity)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->arr = (int *)malloc(sizeof(int) * capacity);
	stack->pos = -1;
	stack->capacity = capacity;

	return stack;
}

void stack_push(Stack *stack, int e)
{
	if (stack->capacity <= stack->pos + 1)
		return;

	stack->pos += 1;
	stack->arr[stack->pos] = e;
}

int stack_peek(Stack *stack)
{
	if (stack->pos == -1)
		return -1;

	return stack->arr[stack->pos];
}

bool stack_pop(Stack *stack)
{
	if (stack->pos == -1)
		return false;

	stack->pos -= 1;

	return true;
}

void stack_free(Stack *stack)
{
	free(stack->arr);
	free(stack);
}


bool validateStackSequences(int *pushed, int pushed_size,
			    int *popped, int popped_size)
{
	if (pushed_size == 0 || popped_size == 0)
		return true;

	// simulate stack pop and push
	int k = 0;
	Stack *helper = new_stack(pushed_size);
	for (int i = 0; i < pushed_size; i++) {
		stack_push(helper, pushed[i]);

		while (helper->pos != -1 && stack_peek(helper) == popped[k]) {
			stack_pop(helper);
			k++;
		}
	}

	bool result = helper->pos == -1;
	stack_free(helper);

	return result;

}
//leetcode submit region end(Prohibit modification and deletion)

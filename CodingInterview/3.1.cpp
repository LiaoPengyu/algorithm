class Node {
 public:
  int pre, val;
  Node() {pre = val = -1;};
  Node(int p, int v):pre(p), val(v) {};
};
int const stackSize = 300;
int indexUsed = 0;
int stackPointer[] = {-1, -1, -1};
Node buffer[stackSize * 3];

void push(int stackNum, int val) {
  int p = stackPointer[stackNum];
  stackPointer[stackNum] = indexUsed;
  buffer[indexUsed].val = val;
  buffer[indexUsed++].pre = p;
}
int pop(int stackNum) {
  int p = stackPointer[stackNum];
  int ret = buffer[p].val;
  stackPointer[stackNum] = buffer[p].pre;
  buffer[p].val = -1;
  indexUsed--;
  return ret;
}
int peek(int stackNum) {
  return buffer[stackPointer[stackNum]].val;
}
bool isEmpty(int stackNum) {
  return stackPointer[stackNum] == -1;
}

#include <cstdio>
using namespace std;

int main()
{
  int size;
  scanf("%d", &size);

  int heap[size + 1];
  for (int i = 1; i <= size; i++)
    scanf("%d", &heap[i]);

  for (int i = 1; i <= size; i++)
  {
    int parentKey = i / 2;
    int leftKey = i * 2;
    int rightKey = i * 2 + 1;
    printf("node %d: key = %d, ", i, heap[i]);
    if (1 <= parentKey && parentKey <= size)
      printf("parent key = %d, ", heap[parentKey]);
    if (1 <= leftKey && leftKey <= size)
      printf("left key = %d, ", heap[leftKey]);
    if (1 <= rightKey && rightKey <= size)
      printf("right key = %d, ", heap[rightKey]);
    printf("\n");
  }

  return 0;
}

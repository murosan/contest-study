#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
  stack<int> st;
  string c;

  while (cin >> c)
    if (c == "+" || c == "-" || c == "*")
    {
      int v1 = st.top(); st.pop();
      int v2 = st.top(); st.pop();

      if (c == "+") st.push(v1 + v2);
      else if (c == "-") st.push(v2 - v1);
      else if (c == "*") st.push(v1 * v2);
    }
    else
      st.push(stoi(c));

  cout << st.top() << endl;
  return 0;
}

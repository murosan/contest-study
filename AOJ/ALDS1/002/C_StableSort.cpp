#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

using card = pair<char, int>;

vector<card> bubble_sort(vector<card> v, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = n - 1; j > i; j--)
      if (v[j].second < v[j - 1].second)
        swap(v[j], v[j - 1]);
  }
  return v;
}

vector<card> selection_sort(vector<card> v, int n)
{
  for (int i = 0; i < n; i++)
  {
    int minIndex = i;
    for (int j = i; j < n; ++j)
      if (v[j].second < v[minIndex].second)
        minIndex = j;
    swap(v[i], v[minIndex]);
  }
  return v;
}

bool is_stable(vector<card> v, vector<card> original)
{
  for (int i = 0; i < v.size(); i++)
    for (int j = i + 1; j < v.size(); j++)
      for (int a = 0; a < v.size(); a++)
        for (int b = a + 1; b < v.size(); b++)
          if (original[i].second == original[j].second && original[i] == v[b] && original[j] == v[a])
            // if (v[i].second == v[j].second && v[i] == original[b] && v[j] == original[a])
            return false;
  return true;
}

void printCards(vector<card> v, string delim)
{
  for (int i = 0; i < v.size() - 1; i++)
    cout << v[i].first << v[i].second << delim;
  cout << v[v.size() - 1].first << v[v.size() - 1].second << endl;
}

int main()
{
  int n;
  string tmp;
  vector<card> bubble, selection;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    bubble.push_back(card(tmp[0], (int)tmp[1] - 48));
    selection.push_back(card(tmp[0], (int)tmp[1] - 48));
  }

  bubble = bubble_sort(bubble, n);
  selection = selection_sort(selection, n);

  printCards(bubble, " ");
  printf("Stable\n");
  printCards(selection, " ");
  if (is_stable(selection, bubble))
    printf("Stable\n");
  else
    printf("Not stable\n");
  return 0;
}

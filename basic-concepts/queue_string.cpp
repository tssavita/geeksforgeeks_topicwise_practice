#include <iostream>
#include <string>
#include <queue>
#include <stack>

// from http://www.java2s.com/Tutorial/Cpp/0420__queue-stack/Aqueueforstringspushemptyfrontpop.htm

using namespace std;
int main()
{
  queue<string> q;

  cout << "Pushing one two three four\n";
  q.push("one");
  q.push("two");
  q.push("three");
  q.push("four");

  cout << "Now, retrieve those values in FIFO order.\n";
  while(!q.empty()) {
    cout << "Popping ";
    cout << q.front() << "\n";
    q.pop();
  }
  cout << endl;


  return 0;
}

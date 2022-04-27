#include <iostream>
#include <map>

using namespace std;

int main() {
  bool finished = false;
  int option;
  string task;
  string description;
  map<string,string> tasks;

  while(!finished) {
    cout << "\nTasks:\n";
    for(auto element = tasks.cbegin(); element != tasks.cend(); ++element) {
      cout << "- " << element->first << ": " << element->second << endl;;
    }

    cout << "\n1: Add task\n";
    cout << "2: Delete task\n";
    cout << "0: Finish\n";
    cin >> option;

    switch (option) {
    case 1:
      cout << "Task: ";
      cin.ignore();
      getline(cin, task);
      cout << "Description: ";
      getline(cin, description);
      tasks.insert(pair<string,string>(task, description));
      break;
    case 2:
      cout << "Task: ";
      cin.ignore();
      getline(cin, task);
      tasks.erase(task);
      break;
    case 0:
      finished = true;
      cout << "Finished\n\n";
      break;
    default:
      cout << "Invalid option\n\n";
      break;
    }
  }
  
}
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <cstring>
#include <fstream>
#include <sstream>
#define MAX 100
using namespace std;
string queue_array[MAX];
string queue_array1[MAX];
int rear1 = 0;
int fron1 = 0;
int rear = 0;
int fron = 0;

void enqueue(string a) {
  if (fron == 0) {
    fron = 1;
  }
  rear += 1;
  queue_array[rear] = a;
  return;
}

void dequeue() { fron += 1; }

void enqueue1(string a) {
  if (fron1 == 0) {
    fron1 = 1;
  }
  rear1 += 1;
  queue_array1[rear1] = a;
  return;
}

void dequeue1() { fron1 += 1; }

void display(float array[], string arr[100], int n) {
  cout << "\nS.NO     NAME OF STUDENT"
       << "                                   "
       << "CGPA\n\n";
  cout << "_______________________________________________________________\n\n";
  for (int i = 0; i < n; i++) {
    cout << i + 1 << ".";
    for (int k = 7; k > (i + 1) / 10; k--) {
      cout << " ";
    }
    cout << arr[i];
    for (int j = 50; j > arr[i].length(); j--) {
      cout << " ";
    }
    cout << array[i] << "\n";
  }

  return;
}
void display1(string a[100], string ar[100], string arr[100], int arrr[100],
              int n) {
  int a1, c;
  cout << "\nS/NO.     BLOCK"
       << "                "
       << " BED TYPE               NO.OF ROOMS\n\n";
  cout << "___________________________________________________________________"
          "\n\n";
  for (int i = 0; i < n; i++) {
    cout << i + 1 << ".";
    c = 0;
    a1 = i + 1;
    while (a1 > 0) {
      a1 = a1 / 10;
      c++;
    }
    for (int j = 0; j < 10 - c; j++) cout << " ";
    cout << a[i];

    for (int j = 20; j > a[i].length(); j--) {
      cout << " ";
    }
    cout << arr[i] << " BEDDED " << ar[i];
    for (int j = 20; j > ar[i].length() + arr[i].length(); j--) {
      cout << " ";
    }
    cout << arrr[i] << "\n";
  }

  return;
}
void heapify(float arr[], string a[], int n, int i) {
  int largest = i;    // Initialize largest as root
  int l = 2 * i + 1;  // left = 2*i + 1
  int r = 2 * i + 2;  // right = 2*i + 2

  // If left child is larger than root
  if (l < n && arr[l] > arr[largest]) largest = l;

  // If right child is larger than largest so far
  if (r < n && arr[r] > arr[largest]) largest = r;

  // If largest is not root
  if (largest != i) {
    swap(arr[i], arr[largest]);
    swap(a[i], a[largest]);

    // Recursively heapify the affected sub-tree
    heapify(arr, a, n, largest);
  }
}

void heapSort(float arr[], string a[], int n) {
  // Build heap (rearrange array)
  for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, a, n, i);

  // One by one extract an element from heap
  for (int i = n - 1; i >= 0; i--) {
    // Move current root to end
    swap(arr[0], arr[i]);
    swap(a[0], a[i]);

    // call max heapify on the reduced heap
    heapify(arr, a, i, 0);
  }
}

int main() {
  cout << "DSA Project " << endl;
  cout << "B.K.TRIPATHY  Slot-G2" << endl;
  cout << "TOPIC-Hostel Room allotment procedure";
  cout << "\n\n";
  cout << "|-------------------ROOM ALLOTMENT FOR THE ACADEMIC YEAR "
          "2017-2018-------------------|\n";
  ofstream alloted("alloted.csv");
  ofstream roommod("roommod.csv");
  ofstream roommod1("roommod1.csv");
  ifstream myfile("CGPA.csv");
  ifstream myfile1("Students count.csv");
  ifstream myfile2("ROOMS.csv");
  string line;
  string no;
  string line1;
  int no_of_students;
  int c = 0, i;
  float temp[100];
  string student[100];
  string rank[100];
  float grade[100];
  if (myfile1.is_open()) {
    while (getline(myfile1, no)) {
      stringstream sStream(no);
      sStream >> no_of_students;
    }
    myfile1.close();
  }
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      i = 0;
      while (line[i] != '\0') {
        if (line[i] == ',') {
          student[c] = line.substr(0, i);
          break;
        }
        i++;
      }
      rank[c] = line.substr(i + 1);
      stringstream sStream(rank[c]);
      stringstream sStream5(rank[c]);
      sStream5 >> temp[c];
      sStream >> grade[c];
      c++;
    }
    myfile.close();
  }
  string temp_s;
  cout << "\nNUMBER OF STUDENTS WHO ARE ELIGIBLE FOR ROOM COUNSELLING - "<<no_of_students;
  cout<< "\n\n";
  cout << "STUDENTS TAKING PART IN THE COUNSELLING:\n";
  display(grade, student, c);
  heapSort(grade, student, c);
  cout << "\nRank list in order of increasing CGPA:\n";
  display(grade, student, c);
  for (int i = c - 1; i >= 0; i--) {
    temp_s = student[i];
    enqueue(temp_s);
  }
  for (int i = c - 1; i >= 0; i--) {
    temp_s = student[i];
    enqueue1(temp_s);
  }
  string block[100];
  string roomtype[100];
  string members[100];
  string no1[100];
  int mem[100];
  int no_of_rooms[100];
  int d = 0, e = 0, f = 0;
  if (myfile2.is_open()) {
    while (getline(myfile2, line1)) {
      f = 0;
      d = 0;
      i = 0;
      while (line1[i] != '\0') {
        if (line1[i] == ',') {
          if (d == 0) {
            block[e] = line1.substr(0, i);

            d++;
            f = i;
          } else if (d == 1) {
            roomtype[e] = line1.substr(f + 1, i - f - 1);
            d++;
            f = i;
          } else if (d == 2) {
            members[e] = line1.substr(f + 1, i - f - 1);
            stringstream sStream4(members[e]);
            sStream4 >> mem[e];
            break;
          }
        }

        i++;
      }
      no1[e] = line1.substr(i + 1);
      stringstream sStream2(no1[e]);
      sStream2 >> no_of_rooms[e];
      e++;
    }
    myfile2.close();
  }
  int A[100];
  string ch;
  cout << "\n\nALLOTMENT->" << endl;
  for (int i = 0; i < c; i++) {
    int g = 0, h = 0;
    int option;
    cout << student[c - i - 1] << "\n";
    cout << "Rank-" << i + 1 << endl;
    cout << "Rooms available:" << endl;
    display1(block, roomtype, members, no_of_rooms, e);
    while (1) {
      cout << "\nNUMBER OF STUDENTS NOT ALLOTED ROOM YET - "<<no_of_students;
      cout <<"\n\n";
      cout << "\nChoose your preferred room (ENTER THE SERIAL NO. OF THE ROOM "
              "FROM THE ROOM LIST :"
           << endl;
      cin >> option;
      for (int j = 0; j < e; j++) {
        if (option == j + 1) {
          g++;
          A[i] = option;
          if (no_of_rooms[j] != 0) {
            no_of_rooms[j] -= 1;
            no_of_students -= mem[j];
            cout << "Status- Block "<<block[option]<<" Room No. "<<
            (rand()%20+100)*(j+1)<<"\nRoom successfully alloted!" << endl;
            h++;
            break;
          } else {
            cout << "Status- Room not available" << endl;
          }
        }
      }
      if (h != 0) break;
    }

    alloted << student[c - i - 1] << "," << grade[c - i - 1] << ","
            << block[option] << "," << members[option] << " BEDDED"
            << "," << roomtype[option] << "," << endl;
    dequeue();
    if (g == 0) cout << "Wrong choice, please try again." << endl;
  }
  for (int k = 0; k < e; k++) {
    roommod << block[k] << "," << roomtype[k] << "," << members[k] << ","
            << no_of_rooms[k] << "," << endl;
  }
  cout << "Room allotment procedure completed!" << endl;
  cout << "\n";
  cout << "\nOPEN THE alloted.csv FILE TO VIEW THE LIST OF STUDENTS AND WHICH "
          "ROOMS THEY ARE ALLOTED\n";
  cout
      << "\nOPEN THE roommod.csv FILE TO VIEW THE MODIFIED LIST OF THE ROOMS\n";
  int z;
  cout << "\n_\n_ _ \n_ \n_ _\n_\n_ _ \n_ \n_ _\n_\n_ _ \n_ \n_ _\n_\n_ _ \n_ "
          "\n_ _\n_\n_ _ \n_ \n_ _\n_\n_ _ \n_ \n_ _\n_\n_ _ \n_ \n_ _\n_\n_ _ "
          "\n_ \n_ _\n_\n_ _ \n_ \n_ _\n_\n_ _ \n_ \n_ _\n_\n_ _ \n_ \n_ "
          "_\n_\n_ _ \n_ \n_ _\n_\n_ _ \n_ \n_ _\n_\n_ _ \n_ \n_ _";
  cout << "\n|------------------------- ACADEMIC YEAR 2017-2018 HAS ENDED "
          "----------------------------|\n";
  cout << "\nSTUDENTS MAY VACATE THEIR ROOOM AND FOLLOW ROOM ALLOTMENT "
          "PROCEDURE FOR THE FOLLOWING YEAR\n";
  cout << "\n|------------------- ROOM DEALLOTMENT FOR THE ACADEMIC YEAR "
          "2017-2018 -------------------|\n\n";
  for (int i = 0; i < c; i++) {
    cout << student[c - i - 1] << "\n ";
    cout << "Do you wish to de-allot your room(Y/N)\n";
    cin >> ch;
    if (ch == "y" || ch == "Y") {
      for (int j = 0; j < e; j++) {
        if (A[i] == j + 1) {
          no_of_rooms[j] += 1;
        }
      }
      cout << "\nROOM SUCCESSFULLY DE-ALLOTED\n";
    }
    dequeue1();
  }
  for (int k = 0; k < e; k++) {
    roommod1 << block[k] << "," << roomtype[k] << "," << members[k] << ","
             << no_of_rooms[k] << "," << endl;
  }
  cout << "Room de-allotment procedure completed!" << endl;
  cout << "\n";
  cout << "\nOPEN THE roommod1.csv FILE TO VIEW THE MODIFIED LIST OF ROOMS\n";
  cout << "Hit an integer to exit" << endl;
  cin >> z;
  roommod.close();
  alloted.close();
  return 0;
}

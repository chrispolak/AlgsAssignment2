// AlgsAssignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <list>
#include <vector> 
#include <iomanip>
using namespace std;

void PrintNums(vector<int> nums) {
    for (int n : nums) {
        cout << n << " ";
    }
    cout << "\n";
}

vector<int> GetNums() {
    vector<int> numbers;
    string s;
    string delimiter = " ";
    int pos = 0;
    string sub;

    cout << "Input Numbers (Separated by Spaces): \n";
    std::getline(std::cin, s);
    s = s + " ";                                                        //Adds a space for splitting

    while ((pos = s.find(delimiter)) != std::string::npos) {
        sub = s.substr(0, pos);
        numbers.push_back(stoi(sub));
        s.erase(0, pos + delimiter.length());
    }
    return numbers;
}

void Shuffle(vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        int j = rand() % a.size();
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}

vector<int> Merge(vector<int> a, vector<int> b, int iteration) {
    vector<int> c;
    int i = 0;

    cout << "\nMERGE STEP: \n";

    cout << "Left Side: \n";
    for (int n : a) {
        cout << n << " ";
    }

    cout << "\n";

    cout << "Right Side: \n";
    for (int n : b) {
        cout << n << " ";
    }
    cout << "\n";

    while (a.size() > 0 && b.size() > 0) {
        if (a[0] > b[0]) {
            c.push_back(b[0]);
            b.erase(b.begin());
        }
        else {
            c.push_back(a[0]);
            a.erase(a.begin());
        }

    }
    while (a.size() > 0) {
        c.push_back(a[0]);
        a.erase(a.begin());
    }
    while (b.size() > 0) {
        c.push_back(b[0]);
        b.erase(b.begin());
    }

    cout << "Result: \n";

    PrintNums(c);
    return c;
}



vector<int> MergeSort(vector<int> nums, int interation) {
    vector<int> aOne;
    vector<int> aTwo;
    int i = 0;

    if (nums.size() == 1) {
        return nums;
    }
    for (int num : nums) {
        if (i <= (nums.size() / 2)-1) {
            aOne.push_back(num);
        }
        else {
            aTwo.push_back(num);
        }
        i++;
    }
   
    aOne = MergeSort(aOne, interation +1);
    aTwo = MergeSort(aTwo, interation + 1);
    return Merge(aOne, aTwo, interation);
}

int Partition(vector<int> &nums, int low, int high) {
    int pivot = nums[low];
    int k = high;
    for (int i = high; i > low; i--) {
        cout << "Checking: " << nums[i] << "\n";
        if (nums[i] > pivot) {
            cout << "Swapping \n";
            swap(nums[i], nums[k--]);
        }
        cout << "New Array \n";
        PrintNums(nums);
    }
    int tmp = nums[low];
    nums[low] = nums[k];
    nums[k] = tmp;
    nums[k] = tmp;
    cout << "\n";
    return k;
}

void QuickSort(vector<int> &nums, int low, int high) {
    if (low < high) {
        int pivot = Partition(nums, low, high);
        QuickSort(nums, low, pivot - 1);
        QuickSort(nums, pivot + 1, high);
    }
}

int main()
{
    srand(time(NULL));
    bool running = true;
    char choice;
    vector<int> numbers;
    numbers = GetNums();
    system("CLS");
;   while (running) {
        cout << "Current Numbers: \n";
        for (int n : numbers) {
            cout << n << " ";
        }
        cout << "\n";
        cout << "Choose An Option: \n" << "M = Merge Sort | Q = Quick Sort | S = Shuffle \n";
        cin >> choice;
        switch (choice) {
            case 'm':
                numbers = MergeSort(numbers, 0);
                cout << "Sorted Array: ";
                PrintNums(numbers);
                break;
            case 'q':
                QuickSort(numbers, 0, numbers.size()-1);
                cout << "Sorted Array: ";
                PrintNums(numbers);
                break;
            case 's':
                Shuffle(numbers);
                break;
            default:
                cout << "Error";
                break;
        }

        //At End
        cout << "Press Enter To Continue";
        cin.ignore();
        getchar();
        system("CLS");
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

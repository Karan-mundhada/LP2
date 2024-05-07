#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void selection_sort(vector<int>& array)
{
    int i, j;
    for( i = 0; i < array.size()-1; i++)
    {
        int mini = i;
        for( j = i+1; j < array.size(); j++)
        {
            if(array[j] < array[mini])
            {
                mini = j;
            }
        }
        swap(array[i], array[mini]);
    }
}

void bubble_sort(vector<int>& arr)
{
    int i, j;
    for(i = 0; i < arr.size()-1; i++)
    {
        for(j = 0; j < arr.size(); j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void insertion_sort(vector<int>& arr)
{
    int i;
    for(i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        for(int j = i-1; j >= 0; j--)
        {
            if(key < arr[j])
            {
                swap(arr[j+1], arr[j]);
            }
            
            
        }
    }
}


int main()
{
    cout<<"Input no of  elements: ";
    int n; cin>>n; vector<int> v(n);
    cout<<"\nEnter the array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "Selection Sort : ";
    selection_sort(v);

    for(auto i: v)
        cout << i << "  ";

    cout << endl;

    cout << "Bubble Sort : ";
    bubble_sort(v);

    for(auto i: v)
        cout << i << "  ";

        
    cout << endl;

    cout << "Insertion Sort : ";
    insertion_sort(v);

    for(auto i: v)
        cout << i << "  ";

        
    cout << endl;
}
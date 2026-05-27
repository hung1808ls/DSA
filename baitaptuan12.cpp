#include<iostream>
using namespace std;

void vundong(int a[], int i, int n)
{
    int key = a[i];
    int j = 2*i + 1;

    while(j < n)
    {
        if(j + 1 < n && a[j] < a[j+1])
            j++;

        if(key >= a[j])
            break;

        a[i] = a[j];

        i = j;
        j = 2*i + 1;

    }
    a[i] = key;
    // hien thi trang thai sau moi buoc
    for(int k = 0; k < n; k++){
        cout << a[k] << " ";
    }
    cout << endl;
}

int main()
{
    int a[]=  {32, 51, 27, 83, 96, 11, 45, 75, 66};
    int size = sizeof(a) / sizeof(a[0]);
    for(int i = size / 2 - 1; i >= 0; i--){
        vundong(a, i, size);
    }
    // in heap sau khi tao
    cout << "Heap: ";
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";

    return 0;
}
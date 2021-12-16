#include <iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
class int_buffer
{
public:
    int_buffer(size_t size);
    int_buffer(const int * source,size_t size);
    int_buffer(const int_buffer& rhs);
    int_buffer(int_buffer& rhs);
    int_buffer&operator=(const int_buffer&rhs);
    int_buffer&operator=(int_buffer&rhs);
    int & operator [](size_t index);
    const int&operator [](size_t index) const;
    size_t size() const;
    int* begin();
    int* end();
    const int* begin() const ;
    const int* end() const ;
    int_buffer();
    void f(int_buffer buf)
    {
        for(int *i =buf.begin(); i!=buf.end(); i++)
        {
            int_buffer* b = new int_buffer;
            int_buffer* b2 = new int_buffer[10];
            int_buffer* b1 = new int_buffer(i,10);
            cout<<b1;
            delete b1;
            delete b;
            delete []b2;

        }
        for(const int *i =buf.begin(); i!=buf.end(); i++)
        {

        }
    }
};
class int_sorted
{
public:
    int_sorted() {}
    size_t size() const;
    const int begin() const;
    const int  end()const;
    int_sorted merge(const int_sorted& merge_with) const;
    int insert(int value)
    {

    }
    void merge(int array[], int const left, int const mid, int const right)
    {
        int  const subArrayOne = mid - left + 1;

        int const subArrayTwo = right - mid;
        int *leftArray = new int[subArrayOne],

        *rightArray = new int[subArrayTwo];



        // Copy data to temp arrays leftArray[] and rightArray[]

        for (int i = 0; i < subArrayOne; i++)

            leftArray[i] = array[left + i];

        for (int j = 0; j < subArrayTwo; j++)

            rightArray[j] = array[mid + 1 + j];

        int indexOfSubArrayOne = 0, // Initial index of first sub-array

            indexOfSubArrayTwo = 0; // Initial index of second sub-array

        int indexOfMergedArray = left;
        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
        {

            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
            {

                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];

                indexOfSubArrayOne++;

            }

            else
            {

                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];

                indexOfSubArrayTwo++;

            }

            indexOfMergedArray++;

        }

        while (indexOfSubArrayOne < subArrayOne)
        {

            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }
        while (indexOfSubArrayTwo < subArrayTwo)
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
    }
    void issorted(int arr[],int n)
    {
        bool isSort=true;
        for(int i=0; i<n; i++)
        {
            if(arr[i]>arr[i+1])
            {
                isSort=false;
            }
        }
        cout<<(isSort? "the array already sorted ":"array is not sorted")<<endl;
    }
    void sort(int arr[],int const begin ,int const end)
    {
        if(begin>=end)
            return;
        ptrdiff_t half =(end-begin)/2;
        const  int mid =begin+half;
        sort(arr,begin,mid);
        sort(arr,mid+1,end);
        merge(arr,begin,mid,end);
    }
};
void selection_sort(int arr[],int n)
{
    int i,j,min_;
    for( i=0; i<n-1; i++)
    {
        min_=i;
        for( j=i+1; j<n; j++)
        {
            if(arr[j]<arr[min_])
            {
                min_=j;
            }
            swap(arr[min_],arr[i]);
        }
    }
}
int main()
{
    int ra,n=100000;
    int a[n],b[n];
    for(int i=0; i<n; i++)
    {
        ra=rand();
        cout<<ra;
        a[i]=ra;
        b[i]=ra;
    }
    string t;

    cout<<endl<<"if you want to sort using selection sort enter sortSelection"<<endl;
    cin>>t;
    if(t=="sortSelection")
    {
        selection_sort(a,n);
    }
    else cout<<"."<<endl;
    cout<<endl<<"if you want to sort using merge sort enter sortMerge"<<endl;
    cin>>t;
    if(t=="sortMerge")
    {

        int_sorted s;
        s.sort(b,0,n);
    }
    cout<<"if you want to print the array a enter printA :"<<endl;
    cin>>t;
    if(t=="printA")
    {
        for(int i=0; i<n; i++)
        {
            cout<<a[i]<<"  ";
        }
        cout<<endl;
    }
    else cout<<"."<<endl;
    cout<<"if you want to print the array b enter printB :"<<endl;
    cin>>t;
    if(t=="printB")
    {
        for(int i=0; i<n; i++)
        {
            cout<<a[i]<<"  ";
        }
        cout<<endl;
    }
    else cout<<"."<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<b[i]<<"  ";
    }
    cout<<endl;
    return 0;
}

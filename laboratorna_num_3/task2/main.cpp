#include <iostream>
#include <ctime>
using namespace std;

void randomPermutation(int size,int *arr) {
    srand(time(NULL));
    for(int temp,j,i=size-1;i>=0;i--) {
        j=rand() % (i+1);/*Для першого числа - n варіантів, для другого n-1 і тд.*/
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}

int sumFunction(int currentElement) {
    int sum=0,rank=currentElement;
    int i=0;
    while (i<rank) {
        sum += currentElement % 10;
        currentElement /= 10;
        rank /= 10;
    }
    return sum;
}
bool compare(int first, int second) {
    int sumfirst = sumFunction(first);
    int sumsecond = sumFunction(second);
    if (sumfirst>sumsecond) {
        return true;
    }
    else if (sumfirst==sumsecond) {
        return (first>second);
    }
    return false;
}

void sortingFunction(int *arr,int size) {
    for(int i=1;i<size;i++) {
        for(int temp,j=i-1;j>=0 &&/*Критерія сортування*/ compare(arr[j],arr[j+1]) ;j--) {
            /*Додатковий критерій. Якщо не рівне, то проходить перевірку. Якщо рівне, то порівнюється*/
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

        }
    }
}

int main() {
    const int size=200;
    int arr[size];
    int i=1,j=0,k=0;
    while (i<=size) {
        arr[i-1]=i;
        i++;
    }
    randomPermutation(size,arr);
    while (j<size) {
        cout<<arr[j]<<"\t";
        j++;
    }
    sortingFunction(arr,size);
    cout<<endl<<endl;
    while (k<size) {
        cout<<arr[k]<<"\t";
        k++;
    }
    return 0;
}
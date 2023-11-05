/*
find the single missing element in the array.

it the array is of ist n natural numbers
*/

#include<iostream>
using namespace std;


class Array{
    public:
        int* arr;
        int len;
        int size;
    public:
        Array(int size):size(size),arr(new int[size]()),len(0){}
        Array(int size, initializer_list<int> elements ):size(size),arr(new int[size]()){
            int i=0;
            for(int element : elements){
                arr[i] = element;
                if(i==size){
                    break;
                }i++;
            }len=i;
        }

        //functions
        int findMissing();
};

int Array::findMissing(){
    //find single missing element in the array
    //if the array is of ist n natural numbers.

    //sum of n natural numbers is (n*(n+1))/2

    int sumOfNumbers = 0;
    int sumOfArray = 0;
    int missingNumber;
    int n = arr[len-1];
    sumOfNumbers = (n*(n+1))/2;
    int i=0;
    while(i<len){
        sumOfArray+=arr[i++];
    }
    if(sumOfNumbers>sumOfArray){
        missingNumber=sumOfNumbers-sumOfArray;
        return missingNumber;
    }return -1;
}

int Missing(Array a){
    //find single missing element in the array
    //if the array is of ist n natural numbers.

    //sum of n natural numbers is (n*(n+1))/2

    int sumOfNumbers = 0;
    int sumOfArray = 0;
    int missingNumber;
    int n = a.arr[a.len-1];
    sumOfNumbers = (n*(n+1))/2;
    int i=0;
    while(i<a.len){
        sumOfArray+=a.arr[i++];
    }
    if(sumOfNumbers>sumOfArray){
        missingNumber=sumOfNumbers-sumOfArray;
        return missingNumber;
    }return -1;
}

int GetMissing(Array &a){
    //if array is sorted and if of n natural numbers
    //by find the difference
    int start = a.arr[0];
    int n = a.arr[a.len-1];
    int i=0;
    int diff = start-i;
    for(i;i<a.len;i++){
        if(a.arr[i]-i != diff){
            int missingElement = i+diff;
            return missingElement;
            break;
        }
    }return 1;
}


int main(){

    Array arr(10,{1,2,3,4,6,7,8});
    cout<<arr.findMissing()<<" is missing mumber"<<endl;
    cout<<Missing(arr)<<" Missing Element of Array"<<endl;
    cout<<GetMissing(arr)<<" Missing Element"<<endl;


   

    return 0;
}
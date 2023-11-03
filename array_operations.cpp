#include<iostream>
#include<stdlib.h>
using namespace std;


// structure
struct  Array
{
    int* A;
    int length;
    int size;
};

//global swap function
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = *x;
}

bool length(struct Array arr){
    if(arr.length==0){
        return false;
    }
    return true;
}

//creating array
void create(struct Array* arr){
    arr->A = (int *)malloc(10*sizeof(int));
    arr->size = 10;
    int list[5] = {10,20,30,40,50};
    for(int i=0;i<5;i++){
        arr->A[i] = list[i];
    }
    
    arr->length = 5;
}
//display array elements
void display(struct Array arr){
    if(length(arr)==false){
        return;
    }
    
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<endl;
    }
    return;
}

// append the element at end
int append(struct Array* arr, int value){
    if(arr->size==arr->length){
        return -1;
    }
    arr->A[arr->length] = value;
    arr->length ++;
    return value;
}

//pop the element at last
int pop(struct Array* arr){
    if(arr->length==0 && arr->size==0){
        return -1;
    }
    int temp = arr->A[arr->length];
    arr->A[arr->length] = 0;
    arr->length--;
    return temp;
}

//remove at index 
int remove(struct Array* arr, int index){
    if(index>=arr->length || index>0){
        return -1;
    }
    int temp = arr->A[index];
    int i = index;
    for(i;i<arr->length-1;i++){
        arr->A[i]=arr->A[i+1];
        
    }
    arr->length--;
    return temp;
}

//add at specific index

void add(struct Array* arr, int index, int value){
    if(index>=arr->size || index>arr->length){
        return;
    }
    int i= arr->length-1;
    for(i;i>=index;i--){
        arr->A[i+1]=arr->A[i]; 
    }
    arr->A[index] = value;
    arr->length++;
    return;
}
//sum of the array elements

float sum(struct Array arr){
    if(length(arr)==false){
        return 0;
    }
    float sum = 0;
    for(int i=0; i<arr.length; i++){
        sum+=arr.A[i];
    }
    return sum;
}

//min value in array

int min(struct Array arr){
    if(length(arr)==false){
        return 0;
    }
    int min = arr.A[0];
    for(int i=1; i<arr.length;i++){
        if(min>arr.A[i]){
            swap(&min,&arr.A[i]);
        }
    }
    return min;
}

//max value in array

int max(struct Array arr){
    if(length(arr)==false){
        return 0;
    }
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(max<arr.A[i]){
            swap(&max,&arr.A[i]);
        }
    }
    return max;
}

//average of array elements

float average(struct Array arr){
    if(length(arr)==false){
        return 0;
    }
    float avg = 0;
    avg = sum(arr)/arr.length;
    return avg;
}


//get value by index
int getvalue(struct Array arr, int index){
    if(length(arr)==false){
        return -1;
    }else if (index >= arr.length && index<0){
        return -1;
    }
    return arr.A[index];
}

//get index of value//linear search
int getindex(struct Array arr, int value){
    if(length(arr)==0){
        return -1;
    }for(int i=0; i<arr.length; i++){
        if(arr.A[i]==value){
            return i;
        }
    }
    return -1;
}

//binary search to find the element 

int search(struct Array arr, int value){
    if(length(arr)==0){
        return -1;
    }
    int l = 0;
    int h = arr.length-1;
    while(l<=h){
        int mid = (l+h)/2;
        if(arr.A[mid]==value){
            return mid;
        }else if(value>arr.A[mid]){
            l = mid+1;
        }else h = mid-1;
    }
    return -1;
}

// sort the array elements using selection sort
//inplace sorting

void sort(struct Array* arr){
    if(arr->length==0) return;
    //selection sort
    int i,j,min;
    i=j=0;
    for(i;i<arr->length-1;i++){
        min=i;
        for(j=i+1;j<arr->length;j++){
            if(arr->A[min]>arr->A[j]){
                min=j;
            }
        }
        if(arr->A[i]>arr->A[min]){
            int temp = arr->A[i];
            arr->A[i] = arr->A[min];
            arr->A[min] = temp;
        }
    }
}

// main function
int main(){
    struct Array arr;
    create(&arr);
    // pop(&arr);
    // append(&arr, 15);
    // remove(&arr,0);
    // add(&arr,1,5);
    // cout<<getvalue(arr,0)<<" value by index"<<endl;
    // cout<<average(arr)<<" average of values"<<endl;
    // cout<<max(arr)<< " Maximum element of array"<<endl;
    // cout<<min(arr)<<" minimum value of array"<<endl;
    // cout<<sum(arr)<<" sum of array"<<endl;
    // cout<<getindex(arr,500)<<" index of value"<<endl;
    // cout<<search(arr,100)<<" binary search of element"<<endl;
    // sort(&arr);


    display(arr);

    return 0;
}
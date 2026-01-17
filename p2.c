#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void merge(int arr[],int left,int mid, int right,int size){
    int size1=mid-left+1;
    int size2=right-mid;

    int temp1[size1],temp2[size2];

    for(int i=0;i<size1;i++){
        temp1[i]=arr[left+i];
    }

    for(int i=0;i<size2;i++){
        temp2[i]=arr[mid+1+i];
    }

    int i=0,j=0,k=left;

    while(i<size1 && j<size2){
        if(temp1[i]<=temp2[j]){
            arr[k++]=temp1[i++];
        }
        else{
            arr[k++]=temp2[j++];
        }
    }

    while(i<size1){
            arr[k++]=temp1[i++];
    }
    
    while(j<size2){
            arr[k++]=temp2[j++];
    }

}

void mergeSort(int arr[],int left, int right,int size){
     if(right>left){
        int mid= left + (right-left)/2;
        mergeSort(arr,left,mid,size);
        mergeSort(arr,mid+1,right,size);
        merge(arr,left,mid,right,size);
     }
}

void display(int arr[],int size){
    printf("The values of the Array is :    ");
    for(int i=0;i<size;i++){
        if(i>0&&i%10==0)
            printf("\n\t\t\t\t");
        printf("%d ",arr[i]);
    }

    printf("\n");
}

void DupRem(int arr[],int size){
    printf("The values of the Array is : ");
    for(int i=0;i<size;i++){
        if(i>0&&(arr[i-1]==arr[i]))
             continue;
        printf("%d ",arr[i]);
    }

    printf("\n");
}

int main(){

    int size=0;
    srand(time(0));
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    const int SIZE=size;
    int array[SIZE];
    for(int i=0;i<SIZE;i++){
        array[i]=rand()%10;
    }

    display(array,SIZE);
    mergeSort(array,0,SIZE-1,SIZE);
    DupRem(array,SIZE);

    return 0;
}
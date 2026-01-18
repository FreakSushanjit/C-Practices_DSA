#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int numSize(int num){
    int k=0;
    while(num!=0){
        k++;
        num/=2;
    }
    return k;
}

void num2binary(int arr[],int num,int size){
    int temp,i=0;
    while(num!=0){
       temp=num%2;
       num/=2;
       arr[i++]=temp;
    }
}

void binarySummation(int arr1[],int arr2[],int arr3[],int size1,int size2,int size3){
    int i=0,j=0,k=0,carry=0;
    while(i<size1&&j<size2){
        if((arr1[i]+arr2[j]==2&&carry==0)||(arr1[i]+arr2[j]==1&&carry==1)){
            arr3[k++]=0;
            i++;j++;    
            carry=1;
        }

        else if(arr1[i]+arr2[j]==2&&carry==1){
            arr3[k++]=1;
            i++;j++;    
            carry=1;
        }
        else{
            arr3[k++]=arr1[i++]+arr2[j++]+carry;
            carry=0;
        }
    }

    while(i<size1){
        if(arr1[i]+carry==2){
            arr3[k++]=0;
            i++;
            carry=1;
        }
        else{
            arr3[k++]=arr1[i++]+carry;
            carry=0;
        }
    }

    while(j<size2){
        if(arr2[j]+carry==2){
            arr3[k++]=0;
            j++;
            carry=1;
        }
        else{
            arr3[k++]=arr2[j++]+carry;
            carry=0;
        }
    }

    while(k<size3){
        arr3[k++]=carry;
        carry=0;
    }
}

void display(int arr[],int size){
     for(int i=0;i<size;i++){
        printf("%d",arr[size-i-1]);
     }
     printf("\n");
}

int main(){
    srand(time(0));

    int num = (rand()%10);
    //int num = 7;
    printf("First number is :%d\n",num);
    const int size1 = numSize(num);
    
    int num2= (rand()%10);
    //int num2= 9;
    printf("Second number is :%d\n",num2);
    const int size2 = numSize(num2);
    
    int arr1[size1],arr2[size2],size3;
    size3=size1>size2?size1+1:size2+1;
    int arr3[size3];

    printf("\n");
    num2binary(arr1,num,size1);
    num2binary(arr2,num2,size2);

    
    printf("The binary of the first number is :");
    display(arr1,size1);
    
    printf("The binary of the second number is :");
    display(arr2,size2);

    binarySummation(arr1,arr2,arr3,size1,size2,size3);
    printf("The sum of the two number is :");
    display(arr3,size3);
    //printf("%d",size1);
    //printf("%d",size2);
    return 0;
}
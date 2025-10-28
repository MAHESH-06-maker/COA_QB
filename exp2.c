#include<stdio.h>
int main (){
    int arr[8]={0};
    int once[8]={0};
    int twos[8]= {0};
    int num; 
    int temp;
    int carry = 1;
    printf("Enter number");
    scanf("%d",&num);
    if(num==0){
        printf("00000000\n");
    }
    else if(num>0){
        temp = num ;
        for(int i =7; temp!=0  && i>=0 ; i--){
            arr[i] = temp%2;
            temp = temp/2;
        }
        printf("\n");
        for(int j=0 ; j<8; j++){
            printf("%d", arr[j]);
        }
    }
    else if(num <0){
        temp = -num;
        for(int k =7; temp!=0 && k>=0; k--){
            arr[k]= temp%2;
            temp= temp/2;
        }
        for(int l = 0; l<8; l++ ){
            if(arr[l]==1){
                once[l]=0;
            }
            else if( arr[l]==0){
                once[l]=1;
            }
        }
        for(int h = 7; h>=0; h--){
            if(once[h]==1 && carry==1){
                twos[h]=0;
            }
            else if( once[h]==0 && carry==1){
                twos[h]=1;
                carry=0;
            }
            else {
                twos[h]= once[h];
            }

        }
        for(int y =0 ;y<8; y++){
            printf("%d",twos[y]);
        }
    }
}
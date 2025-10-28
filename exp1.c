#include<stdio.h>
#include<string.h>

// int main(){
//     int arr[32];
//     int num; 
//     int i =0;
//     printf("Enter number:");
//     scanf("%d", &num);
//     if(num ==0){
//         printf("0");
//     }
//     else if(num >0){
//         for(i=0 ; num!=0; i++){
//         arr[i]=num%2;
//         num = num/2;
//     }
//     }
//     else{
//         printf("invalid ");
//     }
//     for(int j = i-1; j>=0;j--){
//         printf("%d", arr[j]);
//     }
// }

int main(){
    char arr[32];
    printf("enter number:");
    scanf("%s",&arr);
    for(int i =0 ; i<strlen(arr);i++){
        switch (arr[i])
        {
            case '0': printf("0000");break;
            case '1': printf("0001");break;
            case '2': printf("0010");break;
            case '3': printf("0011");break;
            case '4': printf("0100");break;
            case '5': printf("0101");break;
            case '6': printf("0110");break;
            case '7': printf("0111");break;
            case '8': printf("1000");break;
            case '9': printf("1001");break;
            case 'a': printf("1010");break;
            case 'b': printf("1011");break;
            case 'c': printf("1100");break;
            case 'd': printf("1101");break;
            case 'e': printf("1110");break;
            case 'f': printf("1111");break;
            default:printf("invalid");break;
        }
        
    }

}
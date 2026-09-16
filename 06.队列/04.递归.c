#include<stdio.h>
//计算斐波那契数列
int fibonacci(int n){
    if(n==1 || n==2){
        return 1;
    }else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

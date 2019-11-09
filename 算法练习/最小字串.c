#include<stdio.h> 
int indexof(int j,char *arr,int i){
    int t;
    int len = strlen(arr);
    int m;
    for(t = j; t < len; t++){
        if(i == arr[t]){
            m = 0;
            break;
        }else{
            m =  len - j;
        }
    }  
    return m;
}
int lengthOfLongestSubstring(char * s){
   int len = strlen(s);
   if(len == 1) return 1;
   int i = 0,j = 0,flag = 0;
   char *arr = (char *)malloc(len + 1);
   int max = 0;
   arr[flag] = s[0];
   for(i = 1; i < len; i++){
       if(indexof(j,arr,i) != 0){
           flag++;
           arr[flag] = s[i];
       }else{
           max = max < (i - j) ? (i - j) : max;
           j++;
           flag++;
           arr[flag] = s[i];
       }
   }
    return max;
}
int main(){
	char * string = "abcabcbb";
	int n = lengthOfLongestSubstring(string);
	printf("%d",n);
	return 0;
}

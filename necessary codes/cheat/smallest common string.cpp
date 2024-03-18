#include<stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  int count[126];

  for (int i = 0; i < 126; i++) count[i] =__INT_MAX__;

  while(n--){

    char c[100001];
    scanf("%s",c);
    int freq[126]={0};
    for(int i=0;c[i]!='\0';i++){
      freq[c[i]-'A']++;
    }
    for(int i=0;i<126;i++){
      if(count[i]>freq[i]) count[i]=freq[i];
    }
  }
  int flag=0;
  for(int i=0;i<126;i++){
    for(int j=count[i];j>0;j--){
      flag++;
      printf("%c",i+'A');
    }
  }
  if(flag==0) printf("###\n");
  else printf("\n");
  return 0;
}
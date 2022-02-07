#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
pthread_t tid[6];
int count1;
int sum2;
void *thread1(void *arg){

}
void *thread2(void *arg){

}
int main(int argc, char argv[]){
    pthread_attr_t attr, attr1;
    if(argc<2){
        printf("req more args");
        exit(0);
    }
    char s1[8], s2[8], s3[8], s4[8], s5[8], s6[8];
    strcpy(s1,argv[0]);
    strcpy(s2,argv[1]);
    strcpy(s3,argv[2]);
    strcpy(s4,argv[3]);
    strcpy(s5,argv[4]);
    strcpy(s6,argv[5]);
    pthread_attr_init(&attr);
    pthread_attr_init(&attr1);
    pthread_create(&tid[0], NULL, thread1, s1);
    pthread_create(&tid[1], NULL, thread1, s1);
    pthread_create(&tid[0], NULL, thread1, s1);
    pthread_create(&tid[1], NULL, thread1, s1);
    pthread_create(&tid[0], NULL, thread1, s1);
    pthread_create(&tid[1], NULL, thread1, s1);

    
}
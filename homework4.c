#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdbool.h>

#pragma pack(1)
struct{
    int i1;
    int i2;
    double d1;
    unsigned short s1;
    unsigned short s2;
    unsigned short s3;
    int i3;
}information;

double getDouble(double d){
    char firstArray[8];
    char secondArray[8];
    int len = 8;
    double finalResult;

    memcpy(firstArray, &d, len);

    for(int i = 0; i < len; i++){
        secondArray[7 - i] = firstArray[i];
    }

    memcpy(&finalResult, secondArray, len);
    return finalResult;
}

int main(){
    FILE * fileInput = fopen("binout.dat", "rb");

    while(true){
        int recordsread = fread(&information, 26, 1, fileInput);
        if(recordsread == 0){
            break;
        }
        int i1 = ntohl(information.i1);
        printf("i1: %d 0x%x\n", i1, i1);

        int i2 = ntohl(information.i2);
        printf("i2: %d 0x%x\n", i2, i2);

        double getDoubleResult = getDouble(information.d1);
        printf("d1: %f\n", getDoubleResult);

        short s1 = ntohs(information.s1);
        printf("s1: %d 0x%hx\n", s1, s1);

        short s2 = ntohs(information.s2);
        printf("s2: %d 0x%hx\n", s2, s2);

        short s3 = ntohs(information.s3);
        printf("s3: %d 0x%hx\n", s3, s3);

        int i3 = ntohl(information.i3);
        printf("i3: %d 0x%x\n", i3, i3);
    }
}

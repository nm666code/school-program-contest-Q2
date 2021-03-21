#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

//�u���[���B�u�D�|��ƩҥH�d��H�W����
int sting_to_four_digits_int(char* chars){
    int len = strlen(chars);
    int num = 0;

    if(len > 4){
        for(int i = 4; i > 0; i--){
            num *= 10;
            num += chars[len-i]-48;
        }
    }

    else{
        for(int i = len; i > 0; i--){
            num *= 10;
            num += chars[len-i]-48;
        }
    }

    return num;
}

int main()
{
    do{
        char input[1500] = {0},buf[1500] = {0};
        char notations[max];
        char *record = NULL;
        int i = 0, counter1 = 0, counter2 = 0;
        int nums[max];


        printf("�п�J�B�⦡: (��J @ ����)\n");
        scanf("%s",input);

        if(input[0]=='@')
            break;

        printf("�A��J���ƾǹB�⦡��: \n");
        printf("%s\n",input);

        //�Τ��|�Ψ쪺�ȶ񺡰}�C��sentinel
        strcpy(buf,input);
        memset(notations,'_',max);
        memset(nums,-1,max);

        //�ΰ}�C�x�s�B��l
        for(int j = 0, k = 0; j < strlen(buf); j++){
            if(buf[j]=='+'||buf[j]=='*'){
                notations[k] = buf[j];
                k++;
            }
        }

        //�Φr����Φs�Ʀr�b�}�C
        record = strtok(buf, "*+");
        do {
            nums[i] = sting_to_four_digits_int(record);
            record = strtok(NULL, "*+");
            i++;
        } while (record);

        //��while�j��@������[
        while(notations[counter1]!='_'){
            while(notations[counter2]!='_'){
                if(notations[counter2]=='*'){
                    nums[counter2]=(nums[counter2]*nums[counter2+1])%10000;
                    notations[counter2]='+';//���o��S�Ψ�i�H�R���A�]���ڭ�����ѥ[�k�A�ѤU���N���������[�k�A�ҥH�i�H���Χ��ܹB��l
                    nums[counter2+1]=0;
                }
                counter2++;
            }
            nums[0]=(nums[0]+nums[counter1+1])%10000;
            counter1++;
        }

        //��X���G
        printf("�B�⵲�G = %d \n",nums[0]);

    }while(1);

    return 0;
}

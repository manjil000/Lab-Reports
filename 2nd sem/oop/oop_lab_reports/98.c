#include <stdio.h>

struct Customer {
    int acc_no;
    char name[50];
    float balance;
};

int main() {
    FILE *file = fopen("CUST.DAT", "wb");
   
    int n;
    printf("Enter no of customers");
    scanf("%d",&n);
    struct Customer customers[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Account No, Name, Balance: ");
        scanf("%d %s %f", &customers[i].acc_no, customers[i].name, &customers[i].balance);
        fwrite(&customers[i], sizeof(struct Customer), 1, file);
    }
    fclose(file);
    file = fopen("CUST.DAT", "rb");
    struct Customer temp;
    while (fread(&temp, sizeof(struct Customer), 1, file)) {
        if(temp.balance < 1000)
        {
            //printf("Name:%s and Acc_no is:%d",customers[i].name,customers[i].acc_no);
            printf("Acct No: %d, Name: %s\n",temp.acc_no,temp.name);
        }
    }
    fclose(file);
    
    return 0;
}

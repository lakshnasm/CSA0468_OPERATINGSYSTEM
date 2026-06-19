#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int empId;
    char empName[50];
    float empSalary;
};

int main()
{
    FILE *filePtr;
    struct Employee emp;

    filePtr=fopen("employee.dat","rb+");

    if(filePtr==NULL)
        filePtr=fopen("employee.dat","wb+");

    int choice;

    do
    {
        printf("\n1.Add Employee\n");
        printf("2.Display Employee\n");
        printf("3.Update Employee\n");
        printf("4.Exit\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                scanf("%d",&emp.empId);
                scanf("%s",emp.empName);
                scanf("%f",&emp.empSalary);

                fseek(filePtr,
                      (emp.empId-1)*sizeof(struct Employee),
                      SEEK_SET);

                fwrite(&emp,sizeof(struct Employee),1,filePtr);
                break;

            case 2:
                scanf("%d",&emp.empId);

                fseek(filePtr,
                      (emp.empId-1)*sizeof(struct Employee),
                      SEEK_SET);

                fread(&emp,sizeof(struct Employee),1,filePtr);

                printf("%d %s %.2f\n",
                       emp.empId,
                       emp.empName,
                       emp.empSalary);
                break;
        }

    }while(choice!=4);

    fclose(filePtr);
    return 0;
}

#include<stdio.h>
int main()
{
    int matrix1[10][10];
    int matrix2[10][10];
    int result[10][10];
    int i,j;//used in loops for reading and printing matrices
    int k;//used inside loop for multiplication of matrices
    int sum;//used for multiplication
    int row1, col1, row2, col2;
    printf("Enter Order Of First Matrix: ");
    scanf("%d %d",&row1,&col1);
    printf("Enter Order of Second Matrix: ");
    scanf("%d %d",&row2,&col2);

    //checking if the two matrices can be multiplied or not
    if(col1!=row2)
    {
        printf("Cannot Be Multiplied!\n");
        return 0;
    }
    //read the first matrix
    printf("Enter The First Matrix\n");
    for(i=0;i<row1;i++)
    {
        for(j=0;j<col1;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }

    //read the second matrix
    printf("Enter The Second Matrix\n");
    for(i=0;i<row2;i++)
    {
        for(j=0;j<col2;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }
    //printing the first matrix
    printf("The First Matrix Is....\n");
    for(i=0;i<row1;i++)
    {
        for(j=0;j<col1;j++)
        {
            printf("%d\t",matrix1[i][j]);
        }
        printf("\n");
    }

    //printing the second matrix
    printf("The Second Matrix Is....\n");
    for(i=0;i<row2;i++)
    {
        for(j=0;j<col2;j++)
        {
            printf("%d\t",matrix2[i][j]);
        }
        printf("\n");
    }

    //multiplication Logic
    for(i=0;i<row1;i++)
    {
        for(j=0;j<col2;j++)
        {
            sum=0;
            for(k=0;k<col1;k++)
            {
                sum+=matrix1[i][k]*matrix2[k][j];
            }
            result[i][j]=sum;
        }
    }
    //printing the product of the matrices
    printf("The Product Is...\n");
    for(i=0;i<row1;i++)
    {
        for(j=0;j<col2;j++)
        {
            printf("%d\t",result[i][j]);
        }
        printf("\n");
    }

}

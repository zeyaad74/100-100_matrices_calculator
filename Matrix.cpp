
#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
void adding(float mat1 [100][100],float mat2 [100][100],int row1,int row2,int col1,int col2){ // function of adding 2 matrics
if(col1 == col2  && row1 == row2)
{
cout<<"[";
for(int i=0;i <row1;i++)
{
    for(int j=0;j < col1  ;j++)
    {
     cout<<mat1 [j][i] + mat2 [j][i];
        if(j+1==col1)
            break;
        cout<<" ";
        }

if (i+1 == row1)
break;
cout<<";";
}
cout<<"]";
}
else
    cout<<"ERROR";
}
void substracting (float mat1 [100][100],float mat2 [100][100],int row1,int row2,int col1,int col2){ // function of substracting 2 matrics
if(col1 == col2  && row1 == row2)
{
cout<<"[";
for(int i=0;i <row1;i++)
{
    for(int j=0;j < col1  ;j++)
    {
     cout<<mat1 [j][i] - mat2 [j][i];
        if(j+1==col1)
            break;
        cout<<" ";
        }

if (i+1 == row1)
break;
cout<<";";
}
cout<<"]";
}
else
    cout<<"ERROR";
}
void multiplying (float mat1 [100][100],float mat2 [100][100],int row1,int row2,int col1,int col2)// function to multiplying 2 matrics
{
 float multiply [100][100];
    if(col1 == row2)
      {
for(int i=0;i<=row2+2;i++)
{
    for(int j=0;j<=col2+2;j++)
    {
     multiply[i][j] =0;
        for(int k=0;k<=col1+2;k++)
        {
            multiply[i][j] += mat2[i][k]*mat1[k][j];
        }
    }
}
for( int i =0;i<col1;i++)
{
    for( int j=0;j<col1;j++)
    {
        if(multiply[i][j]<.00001 && multiply[i][j]>-.00001 )
            multiply[i][j]=0;
    }
}
cout<<"[";
for(int i=0;i <row1;i++)
{
    for(int j=0;j < col2;j++)
    {
     cout<< multiply[j][i];
        if(j+1==col2)
            break;
        cout<<" ";
        }
if (i+1 == row1)
break;
cout<<";";
}
cout<<"]";
}
else
    cout<<"ERROR";
}

void power(float mat1 [100][100],int row1,int col1,int n)// function to multiply the same matrics
{ float multiply [100][100];float power [100][100];
 if(n==1)
{
  for(int i=0;i<row1;i++)
  {
    for(int j=0;j<col1;j++)
    {
        power[j][i]=mat1[j][i];
    }
  }
}
if(n>1)
 {
for(int i=0;i<=row1+2;i++)
{
    for(int j=0;j<=col1+2;j++)
    {
        multiply[i][j] =0;
        for(int k=0;k<=col1+2;k++)
        {
            multiply[i][j] += mat1[i][k]*mat1[k][j];
        }
    }
}

for(int i=0;i<=row1+2;i++)
{
    for(int j=0;j<=col1+2;j++)
    {
        power[j][i]=multiply[j][i];
    }
}
 }
if(n>2)
{
int i = 2;
while(i<n)
{
    i++;
      for(int i=0;i<=row1+2;i++)
{
    for(int j=0;j<=col1+2;j++)
    {
         multiply[i][j]  =  power[i][j] ;
    }
}
    for(int i=0;i<=row1+2;i++)
{
    for(int j=0;j<=col1+2;j++)
    {
     power[i][j] =0;
        for(int k=0;k<=col1+2;k++)
        {
            power[i][j] += mat1[i][k]*multiply[k][j];
        }
    }
}
}
}
cout<<"[";
for(int i=0;i <row1;i++)
{
    for(int j=0;j < col1  ;j++)
    {
     cout<<power[j][i];
        if(j+1==col1)
            break;
        cout<<" ";
        }
if (i+1 == row1)
break;
cout<<";";
}
cout<<"]";
}
void transpose(float mat[100][100],int row1,int col1)
{
    float transpose[100][100];
    for(int i=0;i <row1;i++)
{
    for(int j=0;j < col1  ;j++)
    {
        transpose[i][j]=mat[j][i];
    }
}
cout<<"[";
for(int i=0;i <col1;i++)
{
    for(int j=0;j < row1  ;j++)
    {
     cout<<transpose[j][i];
        if(j+1==row1)
            break;
        cout<<" ";
        }
if (i+1 == col1)
break;
cout<<";";
}
cout<<"]";
}
float determinant(float matrix[100][100],int row1,int col1)
{
    int k=1,p=0,q=0,i,j,z ; float n=0;
   while(k<col1)
    {
        i = k;z = i-1;
   while(i<col1)
    {
        j=z;
     n = (-1*(matrix[i][p]/matrix[q][p]));
     for(j;j<col1;j++)
        {
        matrix[i][j]= n * matrix[q][j] + matrix[i][j];
        }
        i++;
    }
    p++;
        q++;
        k++;
    }
    float detr=1;
for(i=0;i<col1;i++)
{
    for(j=0;j<col1;j++)
    {
        if(i==j)
        {
          if(matrix[i][j]== 0 )
          {
          detr=0;
          return detr;
          exit(1);
          }
        detr*=matrix[i][j];
        }
    }
}
return detr;
}
float* inverse(float matrix[100][100],int col1,int row1)
{
    if(col1!=row1)
    {
        cout<<"ERROR";
    exit(1);
    }
     float arr[100][100];
     for(int i=0;i<col1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            if(i==j) arr[i][j]=1;
            else
arr[i][j]=0;
        }
    }
int k=1,p=0,q=0,i,j;
float n=0;
   while(k<=col1)
    {
    i = k;
    int z = i-1;
    float c=(1/matrix[k-1][k-1]);
    for(int m=0;m<col1;m++)
    {
    matrix[k-1][m]=c*matrix[k-1][m];
    arr[k-1][m]=c*arr[k-1][m];
    }
    if(k==col1)
        break;
     while(i<col1)
       {
       j=0;
       n = (-1*(matrix[i][p]/matrix[q][p]));
           for(j;j<col1;j++)
           {
           matrix[i][j]= n * matrix[q][j] + matrix[i][j];
           arr[i][j]= n * arr[q][j] + arr[i][j];
           }
       i++;
       }
      p++; q++; k++;
    }
    k = col1-1;
while(k>0)
{
     i=k;
    while(i>0)
    {
         n = (-1*(matrix[i-1][k]/matrix[k][k]));
         for(int j=col1-1;j>=0;j--)
         {
         matrix[i-1][j]= n * matrix[k][j] + matrix[i-1][j];
         arr[i-1][j]= n * arr[k][j] + arr[i-1][j];
         }
        i--;
    }
    k--;
}
for(i =0;i<col1;i++)
{
    for(j=0;j<col1;j++)
    {
        if(arr[i][j]<.001 && arr[i][j]>-.001 )
            arr[i][j]=0;
    }
}
     static  float mat[1000];
    int x = 0;
    for(int i=0;i<col1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            mat[x] = arr[i][j];
x++;
        }
    }
return mat;
}
int main()
{
string  matrix1 [100][100];
float  mat1 [100][100];
string s1;
getline(cin,s1);
int row1 =1;
int col1 =1;
int columns1;
int x1 =0;
int y1 =0;
float v1 =0;
int count1 = 0;
   for(int i=0;i < s1.length();i++)
  {
    if (s1[i]==';')
{
       x1 = 0;
       y1 += 1;
       row1 += 1;
}
    if(s1[i]==' ' || s1[i]=='[' || s1[i]==';')
{
       matrix1 [x1][y1] = s1.substr(i+1);
       for(int i=0 ;i<row1;i++)
       {
           for(int j =0;j<col1;j++)
            mat1[x1][y1] = atof(matrix1[x1][y1].c_str());
       }
       x1 += 1 ;
       count1++;
}
}
for(int i=0;i < s1.length();i++)
{
    if(s1[i]==';')
        break;
   else if(s1[i]==' ')
        col1 += 1;
}
if(count1%row1!=0)
{
    cout<<"ERROR";
    exit(1);
}
string oper;
getline(cin,oper);
float  mat2 [100][100];
string  matrix2 [100][100];
string s2;
int row2 =1;
int col2 =1;
int columns2;
int x2 =0;
int y2 =0;
float v2 =0;
int count2=0;
if(oper[0] == '+' || oper[0] == '-' || oper[0] == '*' || oper[0] == '/')
{
    getline(cin,s2);
for(int i=0;i < s2.length();i++)
  {
    if (s2[i]==';')
{
       x2 = 0;
       y2 += 1;
       row2 += 1;
}
    if(s2[i]==' ' || s2[i]=='[' || s2[i]==';')
{
       count2++;
       matrix2 [x2][y2] = s2.substr(i+1);
       for(int i=0 ;i<row2;i++)
       {
           for(int j =0;j<col2;j++)
            mat2[x2][y2] = atof(matrix2 [x2][y2].c_str());
       }
       x2 += 1 ;
}
}
for(int i=0;i < s2.length();i++)
{
    if(s2[i]==';')
        break;
   else if(s2[i]==' ')
        col2 += 1;
}
if(count2%row2!=0)
{
    cout<<"ERROR";
    exit(1);
}
}
if (oper[0] == '+')
{
    adding(mat1,mat2,row1,row2,col1,col2);
}
if (oper[0] == '-')
{
    substracting (mat1,mat2,row1,row2,col1,col2);
}
if (oper[0] == '*')
{
    multiplying (mat1,mat2,row1,row2,col1,col2);
}
if (oper[0] == '^')
{
    int p;
    cin>>p;
    if(col1==row1)
    power(mat1,row1,col1,p);
    else cout<<"ERROR";
}
if (oper[0] == 'T')
{
    transpose(mat1,row1,col1);
}
if (oper[0] == 'D')
    if(col1!=row1)
    cout<<"ERROR";
else
{
   float detr =  determinant(mat1,row1,col1);
   cout<<detr;
}
if(oper[0]=='I')
{
    float transpose1[100][100];
    for(int i=0;i <row1;i++)
{
    for(int j=0;j < col1  ;j++)
    {
        transpose1[i][j]=mat1[j][i];
    }
}
    float* mat;
    float matrix[100][100];
  mat = inverse(transpose1,col1,row1);
  int x=0;
  for(int i=0;i<col1;i++)
  {
      for(int j=0;j<col1;j++)
      {
          matrix[i][j] = mat[x];
          x++;
      }
  }
  transpose(matrix,row1,col1);
}
if(oper[0]=='/')
{
    if(row2 != col2  || col1 != row2)
    {
        cout<<"ERROR";
        exit(1);
    }
     float transpose1[100][100];
    for(int i=0;i <row2;i++)
{
    for(int j=0;j < col2  ;j++)
    {
        transpose1[i][j]=mat2[j][i];
    }
}
 float* mat;
    float matrix[100][100];
  mat = inverse(transpose1,col2,row2);
  int x=0;
  for(int i=0;i<col1;i++)
  {
      for(int j=0;j<col1;j++)
      {
          matrix[i][j] = mat[x];
          x++;
      }
  }
   for(int i=0;i <row2;i++)
{
    for(int j=0;j < col2;j++)
    {
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
}

   float transpose2[100][100];
    for(int i=0;i <row2;i++)
{
    for(int j=0;j < col2;j++)
    {
        transpose2[i][j]=matrix[j][i];
    }
}
 multiplying(mat1,transpose2,row1,col1,row2,col2);
}
    return 0;
}


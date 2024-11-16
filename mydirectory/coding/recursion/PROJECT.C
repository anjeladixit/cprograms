#include<stdio.h>

int strlength(char str[])
{
    int len=0;
    while(str[len]!='\0')
    len++;
    return len;
}

void printstr(char str[])
{
    int len=strlength(str);
    for(int i=0;i<len;i++)
    printf("%c",str[i]);
}

void concatstring(char str1[],char str2[])
{
    int len1=strlength(str1);
    int len2=strlength(str2);
    
    for(int i=0;i<len2;i++)
    {
        str1[len1+i]=str2[i];
    }
    str1[len1+len2]='\0';
}

int equalstring(char str1[],char str2[])  
{
    //returns -1 if strings are of unequal lengths
    //returns the absolute difference of the first different character of both the strings
    //returns 0 if both the strings are equal
    int len1=strlength(str1);
    int len2=strlength(str2);

    if(len1!=len2)
    return -1;             
    else
    {
        for(int i=0;i<len1;i++)
        {
            if(str1[i]!=str2[i])
            return str1[i]>str2[i]?str1[i]-str2[i]:str2[i]-str1[i];
        }
    }
    return 0;
}

int equalsIgnorecasestr(char str1[],char str2[]) //returns 0 if not equal and 1 if equal (ignores the case)
{
    int len1=strlength(str1);
    int len2=strlength(str2);

    if(len1!=len2)
    return 0;
    else{
        for(int i=0;i<len1;i++)
        {
            if(str1[i]!=str2[i] && str1[i]-str2[i]!=32 && str2[i]-str1[i]!=32)
            return 0;
        }
    }
    return 1;
}

int occurence(char str[])
{
    int len=strlength(str);
    int count = 0;
    for(int i=0;i<len;i++)
    {
        int flag=0;
       
        for(int j=i+1;j<len;j++)
        {
            if(str[j]==str[i] && str[j]!='0' && str[j]!=' ')
            {
                str[j]='0';
                if(flag==0)
                count++;
                flag++;
            }
        }
        
    }
    return count;
}

int strfirstch(char str[],char ch)
{
    for(int i=0;i<strlength(str);i++)
    {
        if(str[i]==ch)
        return i;
    }
    return -1;
}

int strlastch(char str[],char ch)
{
    int len=strlength(str);
    for(int i=len-1;i>=0;i--)
    {
        if(str[i]==ch)
        return i;
    }
    return -1;
}

int issubstring(char str[],char sub[])
{
    int len1=strlength(str);
    int len2=strlength(sub);
    int i=0;
    while(i<len1)
    {
        if(str[i]==sub[0])
        {
            int found=1;
            for(int j=1,k=i+1;j<len2;j++,k++)
            {
                if(str[k]!=sub[j])
                found=0;
            }
            if(found==1)
            return 1;
        }
        i++;
    }
    return 0;
}

int countwords(char str[])
{
    int len=strlength(str);
    if(len==0)
    return 0;
    int space=0;
    str[len]=  str[0]==' '?' ':'\0';
    for(int i=0;i<=len;i++)
    {
        if(str[i]==' ')
        {
            while(str[i]==' ')
            {
                i++;
            }
            space++;
        }
    }
    
    if(str[0]==' ')
    return space-1;
    else if(str[len-1]==' ')
    return space;
    else
    return space+1;
}

void strtolower(char str[])
{
    int len=strlength(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]>=64 && str[i]<=90)
        str[i]=str[i]+32;
    }
}

void strtoupper(char str[])
{
    int len=strlength(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]>=97 && str[i]<=122)
        str[i]=str[i]-32;
    }
}

void extractstr1(char str1[],int start,char str2[])
{
    int len=strlength(str1);
    if(start<0 || start >=len){
    printf("Start index is invalid");
    return;}
    int k=0;
    for(int i=start;i<len;i++,k++){
    str2[k]=str1[i];
    }
    str2[k]='\0';
}

void extractstr2(char str1[],int start,int end,char str2[])
{
    if(end>=strlength(str1)){
    printf("End index is not valid");
    return;}
    if(start<0){
    printf("Start index is invalid");
    return;}
    int k=0;
    for(int i=start;i<=end;i++,k++)
    str2[k]=str1[i];
    str2[k]='\0';
}

void trim(char str[])
{
        int len=strlength(str);
        while(str[0]==' ')
        {
             for(int i=0;i<len-1;i++){
             str[i]=str[i+1];
             str[i+1]=' ';
            }
        }
        int k=len-1;
        while(str[k]==' ')
         {
            str[k]='\0';
            k--;
        }
    
} 

char isPalindrome(char str[])
{
    trim(str);
    int len=strlength(str);

    for(int i=0;i<=len/2-1;i++)
    {
        if(str[i]!=str[len-i-1])
        return 'N';
    }
    return 'Y';
}

void replaceAll(char str[],char t, char l)
{
    //char t --> character to be replaced
    //char l --> character to be replaced with
    int len=strlength(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]==t)
        str[i]=l;
    }
}


int main()
{
    printf("\n\n\n\n\n\nWELCOME TO OUR STRING LIBRARY\n(NOTE : While typing initial spaces not allowed)\n\n");
    printf("Choices : \n");
    printf("Key \t\t Action\n\n\n\n");
    printf("A\tCalculate length of string\nB\tConcat(join) two strings\nC\tto find number of characters which have appeared more than once\nD\tfind the first index of a character in given string\n");
    printf("E\tfind the last index of a character in given string\nF\tCompare two strings\nG\tCompare two strings ignoring their case\nH\tCheck whether a substring is present in a given string\n");
    printf("I\tCount no. of words in a given string\nJ\tConvert string to lower case\nK\tConvert string to uppercase\nL\tExtract string with only start index\n");
    printf("M\tExtract string with start and end index given\nN\tTrim start and end spaces in given string\nO\tCheck if a string is palindrome or not\nP\tReplace all the occurences of a character in given string with a character of your choice\n");
    printf("Z\tExit");
    char ch;

    do{

    printf("\n\nEnter your choice");
    printf("\n");
    scanf("\n%c",&ch);
   


    char str1[1000];
    char str2[1000];
    char c,r;
    int v,s,e;
    switch(ch)
    {
        case 'A':
            printf("Enter string\n");
            scanf("\n%[^\n]s",str1);
            printf("Length of string = %d",strlength(str1));
        break;
        case 'B':
            printf("Enter first string  : ");
            scanf("\n%[^\n]s",str1);
            printf("Enter second string : ");
            scanf("\n%[^\n]s",str2);
            concatstring(str1,str2);
            printf("\nOutput is %s",str1);
        break;
        case 'C':
            printf("Enter string : ");
            scanf("\n%[^\n]s",str1);
            printf("%d characters have appeared more than once",occurence(str1));
        break;
        case 'D':
            printf("Enter string : ");
            scanf("\n%[^\n]s",str1);
            printf("Enter character whose first index is to be found : ");
            scanf("\n%c",&c);
            strfirstch(str1,c)==-1?printf("Not found"):printf("%d",strfirstch(str1,c));
        break;
        case 'E':
            printf("Enter string : ");
            scanf("\n%[^\n]s",str1);
            printf("Enter character whose last index is to be found : ");
            scanf("\n%c",&c);
            strlastch(str1,c)==-1?printf("Not found"):printf("%d",strlastch(str1,c));
        break;
        case 'F':
            printf("Enter first string  : ");
            scanf("\n%[^\n]s",str1);
            printf("Enter second string : ");
            scanf("\n%[^\n]s",str2);
            v=equalstring(str1,str2);
            if(v==-1)
            printf("Strings of unequal length");
            else if(v==0)
            printf("Strings are equal");
            else
            printf("Difference between first different character = %d",v);
        break;
        case 'G':
            printf("Enter first string  : ");
            scanf("\n%[^\n]s",str1);
            printf("Enter second string : ");
            scanf("\n%[^\n]s",str2);
            v=equalsIgnorecasestr(str1,str2);
            v==0?printf("Strings are not equal"):printf("Strings are equal");
        break;
        case 'H':
            printf("Enter string  : ");
            scanf("\n%[^\n]s",str1);
            printf("Enter substring : ");
            scanf("\n%[^\n]s",str2);
            issubstring(str1,str2)==1?printf("Substring found"):printf("Substring not found");
        break;
        case 'I':
            printf("Enter string  : ");
            scanf("\n%[^\n]s",str1);
            printf("Number of words = %d",countwords(str1));
        break;
        case 'J':
            printf("Enter string  : ");
            scanf("\n%[^\n]s",str1);
            strtolower(str1);
            printstr(str1);
        break;
        case 'K':
            printf("Enter string  : ");
            scanf("\n%[^\n]s",str1);
            strtoupper(str1);
            printstr(str1);
        break;
        case 'L':
            printf("Enter string  : ");
            scanf("\n%[^\n]s",str1);
            printf("Enter start index : ");
            scanf("%d",&s);
            extractstr1(str1,s,str2);
            printstr(str2);
        break;
        case 'M':
            printf("Enter string  : ");
            scanf("\n%[^\n]s",str1);
            printf("Enter start index : ");
            scanf("%d",&s);
            printf("Enter end index : ");
            scanf("%d",&e);
            extractstr2(str1,s,e,str2);
            printstr(str2);
        break;
        case 'N':
            printf("Enter string  : ");
            scanf("\n%[^\n]s",str1);
            
            trim(str1);
            printf("Output after trimming :\n");
            printstr(str1);
        break;

        case 'O':
            printf("Enter string  : ");
            scanf("\n%[^\n]s",str1);
            isPalindrome(str1)=='Y'?printf("YES"):printf("NO");
        break;
        case 'P':
             printf("Enter string  : ");
            scanf("\n%[^\n]s",str1);
            printf("Enter character to be replaced : ");
            scanf("\n%c",&c);
            printf("Enter character to be replaced with :");
            scanf("\n%c",&r);
            replaceAll(str1,c,r);
            printstr(str1);
        break;
        case 'Z':
            printf("THANKYOU!");
        break;
        default: 
        printf("INVALID INPUT");
    }

    
    }
    while(ch!='Z');

}


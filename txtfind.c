#include <stdio.h>
#include <string.h>


#define LINE 256
#define WORD 30 


 

// the function return number of char not includ '\n'!!!
int getLine(char s[]){

    int i = 0;
    

    for (i ; i < LINE; i++)
    {
        
        if (scanf("%c" , &(*(s+i)))!=1)
        {
            return i;
        }
        
    
        if (*(s+i) == '\n' || *(s+i) == '\0' )
        {
            break;
        }
    }
    
    return i-1;

}

int getword(char w[])
{
    char c = ' ';
    int i = 0;

    if (scanf("%c", &c)!=1)
    {
        return i;
    }
    

    do
    {
        w[i] = c;
        i++;
    } while (scanf("%c", &c) && c != '\n' && c != '\t' && c != ' ' && c != '\0' && c != ' ');
    
 
    w[i] = '\0';
    
   

	return i;
}


int substring( char * str1, char * str2){
    int i = strlen(str1);
    int j = strlen(str2);
    
    if (i > j)
    {
        char *res;
        res = strstr(str1, str2);
        if(res != NULL)
        {
            return 1;
        }

    }
    else
    {
        return 0;
    }
    return 0;

}

int similar (char *s, char *t, int n){
    int one = strlen(s);
    int tow = strlen(t);
    int sizOfRm = n;


//  comper lengthe.
    if (one == tow)
   {    
        //comper if the s = t.
        if (strcmp(s,t) == 0){
            return 1;
        }
        else 
        {
            return 0;
        }
   }

//  if length(s) - lengthe(t) != n return fals
    if(one-tow != sizOfRm){
        return 0;
    }


    char new[strlen(t)];
    for (int i = 0; i < (int)strlen(t); i++)
    {
        new[i] = '0';
    }
    
    int index = 0;
    for (int i = 0; i < one; i++)
    {

        if (t[index] == s[i])
        {
            new[index] = s[i];
            index ++;
            
        }
        
    }

    if (strcmp(new,t)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    

}

void print_lines(char* str)
{
	char line[LINE] = {0};
    
    int i = 0;

	while (i < getLine(line))
	{
        int num = substring(line, str);

        if (num != 0)
        {
          printf("%s", line);
        }		
	}
}

// Prints all the words that are similar to the word
void print_similar_words(char* str)
{
	char word[WORD] = {0};
    int i = 0;
    int j = strlen(str);
    int num = 0;
	while (i = getword(word))
	{
         num = i-j;
        if ((num)>=0)
		{
            if (similar(word, str, num))
		    {
			printf("%s\n", word);
		    }
        }
	}

}




int main()
{
	char word[WORD];

    
	char choose = ' ';

	getword(word);


	scanf("%c\n", &choose);


	if (choose == 'a')
	{
		print_lines(word);
	}

	else if (choose == 'b')
	{
		print_similar_words(word);
	}

	return 0;
}



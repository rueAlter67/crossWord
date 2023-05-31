#include <stdio.h>
#include <string.h>
#define ROW 20
#define COL 20

typedef char str20[21];

int
main()
{
	str20 base = "ONPTVNUMBERTHEORYGOC";
	str20 word = "NUMBERTHEORY";
	int row, col, counter,i,j;
	counter = strlen(word);
	int found = 0;
	
//	for(row = 0; row<1; row++)
	j=0;
	i=0;
		
			while(counter>0 && base[j] != '\0')
			{
				if(base[j] == word[i])
				{
					counter--;
					i++;
					
				}
				else
					j++;
			}
			
			if(counter ==0)
				printf("word is there");
			else
				printf("word not found");
		
	return 0;
	
}
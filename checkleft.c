#include <stdio.h>
#include <string.h>
#define ROW 20
#define COL 20

typedef char str20[21];

int
checkHorizontally(char TABLE[][COL], str20 word)
{
	int col,i,j,row = 0;
	int counter= strlen(word);
	int found = 0;
	
	
	do{
		i=0;// restart the count to 0 of word
		col =0;
		counter = strlen(word);

		while(counter>0 && col<COL)
		{
			if(TABLE[row][col] == word[i])
			{
				counter--;
				i++;
				col++;	
			}
			else
				col++;
		}
		
		row++;
		
	}while(row<ROW && counter > 0);
			
	if(counter ==0)
		found = 1;
	
		
	return found;
}

int
checkVertically(char TABLE[][COL], str20 word)
{
	int row,i,j,col = 0;
	int counter= strlen(word);
	int found = 0;
	
	do{
		i=0;// restart the count to 0 of word
		row =0;
		counter = strlen(word);

		while(counter>0 && row<ROW)
		{
			if(TABLE[row][col] == word[i])
			{
				counter--;
				i++;
				row++;	
			}
			else
				row++;
		}
		
		col++;
		
	}while(col<COL && counter > 0);
			
	if(counter ==0)
		found = 1;
	
	return found;
}

int
checkLeftDiagonal(char TABLE[][COL], str20 word)
{
	int row,col=0;
	int rowD,colD; // for diagonal searches
	int counter= strlen(word);
	int found = 0; // by default
	int i=0;
	row =0;
	
	do{
		colD = col; rowD= row; 
		while(row <ROW && (colD< COL&& rowD<ROW) && counter >0) 
		{
			if(TABLE[rowD][colD] == word[i]) // searches diagonally
			{
				counter--;
				i++;
				rowD++; 
				colD++;	
			}
			else // quits the diagonal ++ move to the next row
			{
				counter = strlen(word);
				i=0;
				row++;
				rowD= row; 
				colD=col;
			}		
		}
		row=0;
		col++;
	
	}while(col<COL && counter>0);
			
	if(counter ==0)
		found = 1;
	
	return found;
}

int
main()
{
	char TABLE[20][20] =
	{
		"DIFFERENTIALGEOMETRY",
		"LPHBGRYQGEOMETRYRXCO",
		"PNRGSEJNFFQBSASRHJDM",
		"CGEOKGRXSYGHTNEMASPA",
		"OXRTBUVOUDIRAATSACST",
		"MFBAOAQZNRMSTLTBPATH",
		"BWUTPPBMLSIIIYHUPLUE",
		"IVBIRHOIEBENSTEILCVM",
		"NIQFWITLLBLRTIOAIUBA",
		"ACHDGQGHOITSICRRELMT",
		"TUFNAJEOEGTSCGYIDURI",
		"OFYZVKVUNOYYSECTMSAC",
		"RRGAMETHEORYPOIHAALA",
		"IANALYSISKMYAMQMTLGL",
		"CFZLUIJJKDQEQEYEHPEL",
		"SPNTAOWMLWXFTTHTZPBO",
		"UCATEGORYTHEORYIRSRG",
		"JFCJHVCEGGENUYYCMLAI",
		"ONPTVNUMBERTHEORYGOC",
		"DIFFERENTIALEQUATION"
	};
	

	str20 wordSearch[20] = 
	{
		"CALCULUS", "TRIGONOMETRY",	"PROBABILITY","GRAPHTHEORY",
		"GEOMETRY","TOPOLOGY","APPLIEDMATH","ANALYTICGEOMETRY",
		"COMBINATRONICS","STATISTICS","ARITHMETIC","CATEGORYTHEORY",
		"SETTHEORY","DIFFERENTIALGEOMETRY","ANALYSIS","ALLGEBRA",
		"GAMETHEORY","NUMBERTHEORY","DIFFERENTIALEQUATION","MATHEMATICALLOGIC",
	};
	
	int i;
	
	for(i=0; i<20; i++)
	{
		if(checkHorizontally(TABLE, wordSearch[i]))
			printf("\n%s can be found horizontally.");
		else if(checkVertically(TABLE, wordSearch[i]))
			printf("\n%s can be found vertically");
		else if(checkLeftDiagonal(TABLE,wordSearch[i]))
			printf("\n%s can be found left diagonally.");
		else 
			printf("\n%s can't be found.");
	}
	
	return 0;
}
#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("Hello \n");

	fork();

	printf("World \n");
	
	fork();
	
	printf("INDIA \n");
	
	return 0;
}


/* ******************************************************************

			       p1
			     Hello		
			/	      \
		      /			\		
		     /		 	 \
		  p1			 p2
		World			World
	       /   \			/    \	
	     /	    \		       /      \
	p1             p3	p2		p3
	INDIA		INDIA	INDIA		INDIA










***********************************************************************/

#include <stdlib.h>
#include <stdio.h>

int	main()
{
	int array[400];

	for (int i = 0; i < 400; i++) {     // fill array
		    array[i] = i;
		        printf("%d,", array[i]);
	}
	printf("\n done with population \n");
	printf("here is the final array\n");

	for (int i = 0; i < 400; i++) {    // shuffle array
		    int temp = array[i];
		        int randomIndex = rand() % 400;

			    array[i]           = array[randomIndex];
			        array[randomIndex] = temp;
	}


	for (int i = 0; i < 400; i++) {    // print array
		    printf("%d ",array[i]);
	}
	return (0);

}

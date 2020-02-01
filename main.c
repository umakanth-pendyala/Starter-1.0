#include <stdio.h>

int processNo, recources, alloc[20][20], maxNeed[20][20], availible[100];
int executionOrder[100], executionSet[100], deadLock = 0;


void printInitial() {
    printf ("\nallocation :\n");
    for (int i = 0; i < processNo; i++) {
        for (int j = 0; j < recources; j++) {
            printf ("%d\t", alloc[i][j]);
        }
        printf ("\n");
    }
    printf ("\nmaximum need :\n");
    for (int i = 0; i < processNo; i++) {
        for (int j = 0; j < recources; j++) {
            printf ("%d\t", maxNeed[i][j]);
        }
        printf ("\n");
    }
    printf ("\navailible processes :\n");
    for (int i = 0; i < recources; i++) printf ("%d\t", availible[i]);
}

int setExecutionOrder() {
    int count = 0, t = 0;;
    for (int k = 0; count != processNo; k++) {
        if (deadLock == processNo) return 0;
        for (int i = 0; i < processNo; i++) {
            for (int j = 0; j < recources; j++) {
                if (alloc[i][j] + availible[j] >= maxNeed[i][j] && executionSet[i] != -1) {
                    printf ("hoho");
                    executionOrder[t] = i;
                    t++;
                    executionSet[i] = -1;
                    count ++;
                }
            }
            if (executionSet[i] != -1) deadLock++;
            else for (int i = 0; i < recources; i++) availible[j] = availible[j] + alloc[i][j];///execute from here///
        }
    }
    return 1;
}


void main () {
    printf ("enter the number of processes :\t");
	scanf ("%d",&processNo);
	
	printf ("enter number of recources :\t");
	scanf ("%d",&recources);
	printf ("allocation entry :\n");
	for (int i = 0; i < processNo; i++) {
	printf ("\n");
		for (int j = 0; j < recources; j++) {
			printf ("enter allocated instances for process %d : recource %d :\t",i,j);
			scanf ("%d", &alloc[i][j]);
		}
	}
	printf ("\nmaximum need entry :\n");
	for (int i = 0; i < processNo; i++) {
	printf ("\n");
		for (int j = 0; j < recources; j++) {
			printf ("enter max need of instances for process %d : recource %d :\t",i,j);
			scanf ("%d", &maxNeed[i][j]);
		}	
	}
	printf ("\navailible recources entry :\n");
	for (int i = 0; i < recources; i++) {
		printf ("enter availible instances for recource %d :\t", i);
		scanf ("%d",&availible[i]);
	}
    printInitial();
    if (setExecutionOrder()) {
        printf ("\nthe system is in safe mode\nexecution order :\t");
        for (int i = 0; i < processNo; i++) {
            printf ("%d\t",executionOrder[i]);
        }
        printf ("\n");
    }
    else printf ("\nthe system is not in safe state\n");

}
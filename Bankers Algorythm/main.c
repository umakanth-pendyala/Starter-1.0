#include <stdio.h>

int processNo, recources, alloc[20][20], maxNeed[20][20], availible[100];
int executionOrder[100], executionDone[100], deadLock = 0, index = 0;


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

int doExecution() {
    int count = 0, tempVar = 0;
    for (int i = 0; i < processNo*processNo; i++) {
        for (int t = 0; t < processNo; t++) {
            tempVar = 0;
            for (int j = 0; j < recources; j++) {
                if (alloc[t][j] + availible[j] >= maxNeed[t][j] && executionDone[t] != 1) {
                    tempVar++;
                }
                if (tempVar == recources) {
                for (int i = 0; i < recources; i++) availible[i] += alloc[t][i]; 
                executionOrder[index] = t;
                index ++;
                executionDone[t] = 1;
                count ++;
                }
            }
        }
        tempVar = i;
    }
    if (tempVar+1 == processNo*processNo) return 0;
    else {
        printf ("\nexecution order of processes :\t");
        for (int i = 0; i <= index - 1; i++) printf (":%d\t", executionOrder[i]); 
        return 1;
    }
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
    if (doExecution()) {
        printf ("\nthe system is in safe mode\n");
        printf ("\n");
    }
    else {
        printf ("\nthe system is not in safe state\n");
        printf ("the processes are in dead lock\n");
    }

}
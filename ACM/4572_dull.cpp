/*
 Author: Isaac Secundino
 Problem:
    ID: 4572
    Name: DuLL
    Regional: North America - Mid Central
    Year: 2009
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _dull{
    int memory;
    int is_being_used;
};

struct _program{
    int memory;
    int n_dulls;
    int * dull_ids; 
};

typedef struct _program program;
typedef struct _dull dull;

void printDulls(dull * d, int N) {
    for(int i=0; i<N; i++) {
        printf("%c ",i+65);
        printf("%4d %1d\n",d[i].memory,d[i].is_being_used);
    }
}

void printProgram(program * p, int P) {
    for(int i=0; i<P; i++) {
        printf("%d ",i+1);
        printf("%4d %2d ",p[i].memory, p[i].n_dulls);
        for (int j = 0; j<p[i].n_dulls; j++) {
            printf("%c",p[i].dull_ids[j]+65);
        }
        printf("\n");
    }
}

void populateDulls (dull * dulls, int N) {
    for (int i = 0; i<N; i++) {
        int id = i;
        int memory = 0;
        
        scanf("%d",&memory);
        dulls[i].memory = memory;
        dulls[i].is_being_used = 0; 
    }
}

void populatePrograms (program * programs, int P) {
    for (int i = 0; i<P; i++) {
        int id = i+1;                   // The program id starts at 1
        char dulls_in_program[21];      // 21 = Maximun number of dulls + 1 ('\0')
        int memory = 0;
        
        scanf("%d %s",&memory, dulls_in_program);
        int length = strlen(dulls_in_program);
        int * dull_ids = (int *) malloc(sizeof(int*) * length);
        
        programs[i].memory = memory;
        programs[i].n_dulls = length;
        programs[i].dull_ids = dull_ids;

        for (int j = 0; j<length; j++) {
            int d_id = dulls_in_program[j] - 65;         // char 'A' = 65
            programs[i].dull_ids[j] = d_id; 
        }
    }
}

void populateTransition (int * transitions, int S) {
    for (int i = 0; i<S; i++) {
        scanf("%d",&transitions[i]);
    }
}

int useDull (dull * d) {
    d->is_being_used++;
    if (d->is_being_used == 1) {
        return d->memory;
    } else {
        return 0;
    }
}

int unUseDull (dull * d) {
    d->is_being_used--;
    if (d->is_being_used == 0) {
        return d->memory;
    } else {
        return 0;
    }
}

int addProgram (program p, dull * dulls) {
    int memory_used = p.memory;

    for (int i=0; i<p.n_dulls; i++) {
        int d_id = p.dull_ids[i];
        memory_used += useDull(&dulls[d_id]);
    }

    return memory_used;
}

int removeProgram (program p, dull * dulls) {
    int memory_used = -p.memory;
    
    for (int i=0; i<p.n_dulls; i++) {
        int d_id = p.dull_ids[i];
        memory_used -= unUseDull(&dulls[d_id]);
    }

    return memory_used;
}

int getPeakMemory (dull * d, int N, program * p, int P, int * t, int S) {
    int memory = 0;
    int peak = 0;
    
    for (int i=0; i<S; i++) {
        int p_id = t[i];            // Remember: ids were captured from 1
        if (p_id < 0) {
            p_id = (p_id * -1) - 1;
            memory += removeProgram(p[p_id], d);
        } else {
            p_id = p_id - 1;
            memory += addProgram(p[p_id], d);
        }
        
        if (memory > peak) {
            peak = memory;
        }
    }
    return peak;
}

int main() {
    int N, P, S;

    while ( scanf("%d %d %d", &N, &P, &S) == 3 ) {
        dull dulls[N];
        program programs[P];
        int transitions[S];

        populateDulls(&dulls[0], N);
        populatePrograms(&programs[0], P);
        populateTransition(&transitions[0], S);
        
        int peak_memory = getPeakMemory(&dulls[0], N, &programs[0], P, &transitions[0], S); 
        printf("%d\n", peak_memory);
        //printDulls(&dulls[0], N);
        //printProgram(&programs[0], P);
    }


    return 0;
}

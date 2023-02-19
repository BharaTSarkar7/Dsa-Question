#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 50
#define TIME_SLOT 10

/* Data structure for representing a process */
typedef struct Process
{
    int id;
    int burstTime;
    int remainingTime;
    struct Process *next;
} Process;

/* Function prototypes */
Process *createProcess(int id, int burstTime);
void addProcess(Process **head, Process *process);
void runProcesses(Process *head, int numProcesses);

int main()
{
    Process *head = NULL;
    int n;
    printf("Enter 1 to continue or 0 to exit\n");
    scanf("%d", &n);
    int Process_id = 1;
    while (n)
    {
        int choice;
        printf("\nEnter 1 to add processes\nEnter 2 to run processes\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int new_data;
            printf("\nEnter the No. of process\n");
            scanf("%d", &new_data);
            addProcess(&head, createProcess(Process_id, new_data));
            Process_id++;
            break;

        case 2:
            runProcesses(head, Process_id);
            break;
        }
        printf("\nEnter 1 to continue or 0 to exit\n");
        scanf("%d", &n);
    }

    return 0;
}

/* Function to create a new process */
Process *createProcess(int id, int burstTime)
{
    Process *process = (Process *)malloc(sizeof(Process));
    process->id = id;
    process->burstTime = burstTime;
    process->remainingTime = burstTime;
    process->next = NULL;
    return process;
}

/* Function to add a process to the circular linked list */
void addProcess(Process **head, Process *process)
{
    if (*head == NULL)
    {
        *head = process;
        process->next = process;
    }
    else
    {
        Process *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = process;
        process->next = *head;
    }
}

/* Function to run the processes in the circular linked list */
void runProcesses(Process *head, int numProcesses)
{
    Process *temp = head;
    while (numProcesses > 0)
    {
        temp->remainingTime -= TIME_SLOT;
        if (temp->remainingTime <= 0)
        {
            printf("Process %d completed in %dms\n", temp->id, temp->burstTime);
            temp->next = temp->next->next;
            numProcesses--;
        }
        temp = temp->next;
    }
}

/*This program defines a data structure Process that represents a process and contains fields for the process ID, burst time, remaining time, and a pointer to the next process in the circular linked list.

The main function creates a few processes and adds them to the circular linked list using the addProcess function. It then calls the runProcesses function to run the processes in the circular linked list.

The runProcesses function iterates over the circular linked list and decrements the remaining time of each process by the time slot (10ns in this case). If the remaining time of a process becomes less than or equal to zero, it prints the completion time of the process and removes it from the circular linked list.*/
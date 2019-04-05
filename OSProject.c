// Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student queries. Since there can be multiple
// requests at any time he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time.
// He will log into the system from 10am to 12am only.  He wants to have separate requests queues for students and faculty.
// Implement a strategy for the same. The summary at the end of the session should include the total time he spent on handling queries
// and average query time.

#include<stdio.h>
#include<string.h>

struct process_Struct {
    char process_name[20];
    int arrival_time, burst_time, completion_time, remaining;
}temp_Struct;


void faculty_Queue(int no_of_process) {

    int count, arrival_Time, burst_Time, quantum_time;
    struct process_Struct faculty_Process[no_of_process];

    for(count = 0; count < no_of_process; count++) {
        printf("Enter the details of Process[%d]", count+1);
        puts("");
        printf("Process Name : ");
        scanf("%s", faculty_Process[count].process_name);

        printf("Arrival Time : ");
        scanf("%d", &faculty_Process[count].arrival_time);

        printf("Burst Time : ");
        scanf("%d", &faculty_Process[count].burst_time);
        puts("");
    }
    printf("Now, enter the quantum time for FACULTY queue : ");
    scanf("%d", &quantum_time);


    // sorting the processes by their ARRIVAL time.
    // if the ARRIVAL time is same then scheduling is based on FCFS.
    for(count = 0; count < no_of_process; count++) 
	{
        for(int x = count +1; x < count; x++){
            if(faculty_Process[count].arrival_time > faculty_Process[x].arrival_time) {
                temp_Struct = faculty_Process[count];
                faculty_Process[count] = faculty_Process[x];
                faculty_Process[x] = temp_Struct;
            }
        }
    }

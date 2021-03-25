//MinMin Scheduling

#include <stdio.h>

int main()
{
  int machine, task;
  printf("Enter no. of machines and no. of tasks: ");
  scanf("%d %d", &machine, &task);

  register int i;
  register int j;
  int CT[machine][task];

  printf("\nEnter tasks machine wise:\n");
  for (i = 0; i < machine; ++i)
  {
    for (j = 0; j < task; ++j)
    {
      scanf("%d", &CT[i][j]);
    }
  }

  printf("\n\t");
  for (i = 0; i < task; ++i)
  {
    printf("T%d\t", i);
  }
  printf("\n");
  for (i = 0; i < machine; ++i)
  {
    printf("M%d\t", i);
    for (j = 0; j < task; ++j)
    {
      printf("%d\t", CT[i][j]);
    }
    printf("\n");
  }

  int ready_time[machine],
      task_count = 0,
      assignment[task][2]; 

  for (int i = 0; i < machine; i++)
    ready_time[i] = 0;


  for (int m_ = 0; m_ < machine; m_++)
    for (int t_ = 0; t_ < task; t_++)
      CT[m_][t_] += ready_time[m_];

  while (task_count < task)
{
    int task_id,
        machine_id,
        min_val = __INT_MAX__;

    for (int i = 0; i < machine; i++)
    {
      for (int j = 0; j < task; j++)
      {

        if (CT[i][j] < min_val)
        {
          min_val = CT[i][j];
          task_id = j;
          machine_id = i;
        }
      }
    }
    assignment[task_count][0] = task_id;
    assignment[task_count++][1] = machine_id;

    ready_time[machine_id] += CT[machine_id][task_id]; 

    for (int t_ = 0; t_ < task; t_++)
      CT[machine_id][t_] += CT[machine_id][task_id];

    for (int m_ = 0; m_ < machine; m_++)
      CT[m_][task_id] = __INT_MAX__ / 2; 
  }

  printf("\n\nTask Assignments:\n");
  for (int i = 0; i < task; i++) {
    printf("Task %d -> Machine %d\n", assignment[i][0], assignment[i][1]);
  }
}

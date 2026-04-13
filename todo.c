#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char description[100];
  int done;
} TASK;

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("Usage: ./todo <add> <task>\n");
    printf("Usage: ./todo <list>\n");
    printf("Usage: ./todo <done> <task_id>\n");
    return 1;
  }

  if (strcmp(argv[1], "add") == 0) {
    if (argc < 3) {
      printf("Usage: ./todo <add> <task>\n");
      return 1;
    }

    FILE *tasks = fopen("tasks.txt", "r");

    if (tasks == NULL) {
      tasks = fopen("tasks.txt", "a");
      TASK task = {1, "", 0};
      strcpy(task.description, argv[2]);
      fprintf(tasks, "%d|%s|%d\n", task.id, task.description, task.done);
      fclose(tasks);
      return 0;
    }

    TASK task;

    while (fscanf(tasks, "%d|%[^|]|%d", &task.id, task.description,
                  &task.done) != -1) {
    }

    TASK next_task = {task.id + 1, "", 0};
    strcpy(next_task.description, argv[2]);

    fclose(tasks);

    FILE *new_tasks = fopen("tasks.txt", "a");

    fprintf(new_tasks, "%d|%s|%d\n", next_task.id, next_task.description,
            next_task.done);

    fclose(new_tasks);

  } else if (strcmp(argv[1], "list") == 0) {
    FILE *tasks = fopen("tasks.txt", "r");

    if (tasks == NULL) {
      printf("No todo-list found");
      return 1;
    }

    TASK sample;

    while (fscanf(tasks, "%d|%[^|]|%d", &sample.id, sample.description,
                  &sample.done) != -1) {
      printf("%d. %s [%s]\n", sample.id, sample.description,
             sample.done == 0 ? "" : "x");
    }

    fclose(tasks);

  } else if (strcmp(argv[1], "done") == 0) {
    if (argc < 3) {
      printf("Usage: ./todo <done> <task_id>\n");
      return 1;
    }

    FILE *tasks = fopen("tasks.txt", "r+");

    if (tasks == NULL) {
      printf("No todo-list found");
    }

    TASK allTasks[100];
    int counter = 0;

    TASK sample;

    while (fscanf(tasks, "%d|%[^|]|%d", &sample.id, sample.description,
                  &sample.done) != -1) {
      allTasks[sample.id - 1] = sample;
      counter++;
    }

    for (int i = 0; i < counter; i++) {
      if (allTasks[i].id == atoi(argv[2])) {
        allTasks[i].done = 1;
      }
    }

    fclose(tasks);
    tasks = fopen("tasks.txt", "w");
    for (int i = 0; i < counter; i++) {
      fprintf(tasks, "%d|%s|%d\n", allTasks[i].id, allTasks[i].description,
              allTasks[i].done);
    }
    fclose(tasks);

  } else {
    printf("Usage: ./todo <add> <task>\n");
    printf("Usage: ./todo <list>\n");
    printf("Usage: ./todo <done> <task_id>\n");
    return 1;
  }

  return 0;
}

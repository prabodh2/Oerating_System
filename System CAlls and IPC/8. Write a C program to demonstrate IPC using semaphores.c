#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key = ftok("semfile", 65);
    int semid = semget(key, 1, 0666 | IPC_CREAT);

    struct sembuf sb = {0, -1, 0};
    printf("Waiting for semaphore...\n");
    semop(semid, &sb, 1);
    printf("Entered critical section\n");

    sb.sem_op = 1;
    semop(semid, &sb, 1);
    printf("Left critical section\n");

    semctl(semid, 0, IPC_RMID);

    return 0;
}
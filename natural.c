#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
   char name[60];
 char dob[20];
int age;
 struct Person *next;
} Person;

Person *front = NULL;
Person *rear = NULL;

void enqueue(char name[], char dob[], int age) {
 Person *newPerson = (Person *)malloc(sizeof(Person));
strcpy(newPerson->name, name);
strcpy(newPerson->dob, dob);
 newPerson->age = age;
 newPerson->next = NULL;

 if (front == NULL) {
 front = rear = newPerson;
rear->next = front;
 } else {
rear->next = newPerson;
 rear = newPerson;
 rear->next = front;
 }
 printf("Person enqueued successfully.\n");
}

void dequeue() {
 if (front == NULL) {
 printf("Queue is empty. Cannot dequeue.\n");
 return;
 }

 Person *temp = front;
 if (front == rear) {
 front = rear = NULL;
 } else {
front = front->next;
 rear->next = front;
 }
free(temp);
printf("Person dequeued successfully.\n");
}

int countSeniorCitizens() {
 if (front == NULL)
 return 0;
 int count = 0;
Person *current = front;
 do {
 if (current->age >= 60)
 count++;
 current = current->next;
 } while (current != front);

 return count;
}

void display() {
 if (front == NULL) {
 printf("Queue is empty.\n");
 return;
 }

 printf("Queue of Persons:\n");
 Person *current = front;
 do {
printf("Name: %s, DOB: %s, Age: %d\n", current->name, current->dob, current->age);
current = current->next;
 } while (current != front);
}

int main() {
int choice, age;
char name[50], dob[20];
 while (1) {
 printf("\nCircular Queue Menu:\n");
 printf("1. Enqueue Person\n");
 printf("2. Dequeue Person\n");
 printf("3. Count Senior Citizens\n");
 printf("4. Display Queue\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
switch (choice) {
case 1:
 printf("Enter name: ");
 scanf("%s", name);
 printf("Enter date of birth (dd/mm/yyyy): ");
 scanf("%s", dob);
 printf("Enter age: ");
 scanf("%d", &age);
 enqueue(name, dob, age);
break;
 case 2:
dequeue();
 break;
 case 3:
printf("Number of senior citizens in the queue: %d\n", countSeniorCitizens());
 break;
 case 4:
 display();
 break;
 case 5:
 printf("Exiting program.\n");
exit(0);
 default:
 printf("Invalid choice. Please enter a valid choice.\n");
 }
 }
 return 0;
}
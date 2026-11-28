
# Hospital Patient Consultation Management System using Circular Queue

## Aim
To implement a hospital patient consultation management system using a circular queue in C.

## Operations
1. Add patients to the queue.
2. Call the next patient for consultation.
3. Display all patients waiting for consultation.
4. Exit the application.

## Algorithm

1. Define a patient structure containing patient ID and patient name.
2. Initialize FRONT and REAR to -1.
3. Read the maximum queue size.
4. Display the menu repeatedly.
5. For adding a patient:
   - Check whether the queue is full.
   - If empty, initialize FRONT and REAR to 0.
   - Otherwise, update REAR using (REAR + 1) % N.
   - Read and store patient details.
6. For calling a patient:
   - Check whether the queue is empty.
   - Display the patient at FRONT.
   - If only one patient exists, reset FRONT and REAR to -1.
   - Otherwise, update FRONT using (FRONT + 1) % N.
7. For displaying patients:
   - Traverse from FRONT to REAR using circular indexing.
8. Repeat until the user chooses Exit.

## Sample Input

    Enter the size of the queue: 3

    1. Add patients
    2. Call patient
    3. Display
    4. Exit

    Enter your choice: 1
    Enter the patient ID: 101
    Enter the patient name: Arun

    Enter your choice: 1
    Enter the patient ID: 102
    Enter the patient name: Rahul

    Enter your choice: 3

## Sample Output

    Patients waiting:
    Patient ID: 101
    Patient name: Arun
    Patient ID: 102
    Patient name: Rahul

## Complexity Analysis

- Enqueue: O(1)
- Dequeue: O(1)
- Display: O(n)
- Space Complexity: O(n)

## Language
C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define space for (int i = 1; i <= 70; i++) printf(" ");
#define space2 for (int j = 1; j <= 40; j++) printf(" ");

#define MAX_BEDS 100

// Stack structure for bed allotment
struct BedStack {
    int top;
    int beds[MAX_BEDS];
};

// Function to initialize the stack
void initStack(struct BedStack *stack) {
    stack->top = -1;
}

// Function to push a bed number onto the stack
int push(struct BedStack *stack, int bedNumber) {
    if (stack->top >= MAX_BEDS - 1) {
        printf("Stack overflow: No more beds available.\n");
        return -1;
    }
    stack->beds[++stack->top] = bedNumber;
    return 0;
}

// Function to pop a bed number from the stack
int pop(struct BedStack *stack) {
    if (stack->top < 0) {
        printf("Stack underflow: No beds available.\n");
        return -1;
    }
    return stack->beds[stack->top--];
}

// ------------------- LOGIN FUNCTION -------------------
int login() {
    char usernm[80], password[80];
    int trials = 1;
    while (trials <= 3) {
        printf("\n\n\n");
        space printf("=============== Login Required ===============\n\n\n\n\n");
        space printf("Enter Username : ");
        scanf("%s", usernm);
        space printf("Enter Password : ");
        scanf("%s", password);

        if (strcmp(usernm, "AdminJi") == 0 && strcmp(password, "1234@") == 0) {
            space printf("Login successful!\n");
            return 1;
        } else {
            space printf("Invalid Username or Password. Try again.\n");
            trials++;
        }
    }
    space printf("Too many failed attempts. Access denied.\n");
    return 0;
}

// ------------------- STRUCTURES -------------------
typedef struct patient {
    char name[100], dis[100];
    int id, age, doc, tkn1, shift, bedNumber;
    char time1[30];
    float bill, discount, final_bill;
    struct patient *next;
} pat;

struct doctor {
    char nm[100], sft[100], deg[100], disease[150];
    int rcd, rcd1;
};

// ------------------- GLOBAL DATA -------------------
struct BedStack bedStack;

struct tm_t {
    int tkn;
    char time[30];
};

struct tm_t ar[] = {
    {1, "8:00 AM"}, {2, "8:15 AM"}, {3, "8:30 AM"}, {4, "8:45 AM"},
    {5, "9:00 AM"}, {6, "9:15 AM"}, {7, "9:30 AM"}, {8, "9:45 AM"},
    {9, "10:00 AM"}, {10, "10:15 AM"}, {11, "10:30 AM"}, {12, "10:45 AM"},
    {13, "11:00 AM"}, {14, "11:15 AM"}
};

struct tm_t ar1[] = {
    {1, "2:00 PM"}, {2, "2:15 PM"}, {3, "2:30 PM"}, {4, "2:45 PM"},
    {5, "3:00 PM"}, {6, "3:15 PM"}, {7, "3:30 PM"}, {8, "3:45 PM"},
    {9, "4:00 PM"}, {10, "4:15 PM"}, {11, "4:30 PM"}, {12, "4:45 PM"},
    {13, "5:00 PM"}, {14, "5:15 PM"}
};

struct doctor b[] = {
    {"DR.SHANKAR",      "8 AM to 12PM  2 PM to 6 PM (Sunday off)",   "MBBS - MD",                    "Fever, Cold, Flu, Typhoid, Diabetes, Hypertension",          0, 0},
    {"DR.RIYA SINGH",   "8 AM to 12PM  2 PM to 6 PM (Saturday off)", "MBBS - MS (Orthopedic Surgeon)","Bone Fracture, Joint Pain, Arthritis, Spine Disorders",      0, 0},
    {"DR.M PUNDIR",     "8 AM to 12PM  2 PM to 6 PM (Sunday off)",   "BDS - MDS",                    "Tooth Decay, Gum Disease, Oral Infection, Tooth Extraction",  0, 0},
    {"DR.R YADAV",      "8 AM to 12PM  2 PM to 6 PM (Friday off)",   "BAMS - BUMS",                  "Digestive Disorders, Chronic Pain, Asthma, Kidney Stones",   0, 0},
    {"DR.ISHA MITTAL",  "8 AM to 12PM  2 PM to 6 PM (Monday off)",   "MBBS - Gynecologist",          "PCOS, Pregnancy, Menstrual Disorders, Infertility",          0, 0},
    {"DR.P RATURI",     "8 AM to 12PM  2 PM to 6 PM (Sunday off)",   "MBBS - MD - Dermatologist",    "Acne, Eczema, Psoriasis, Skin Allergy, Hair Loss",           0, 0},
    {"DR.A SHARMA",     "9 AM to 1PM   3 PM to 7 PM (Tuesday off)",  "MBBS - MD (Cardiologist)",     "Heart Attack, Chest Pain, Arrhythmia, Heart Failure",        0, 0},
    {"DR.S KAPOOR",     "8 AM to 12PM  2 PM to 6 PM (Wednesday off)","MBBS - MS (Neurologist)",      "Migraine, Epilepsy, Stroke, Parkinson's, Alzheimer's",       0, 0},
    {"DR.V MEHTA",      "10 AM to 2PM  4 PM to 8 PM (Thursday off)", "MBBS - MD (Pulmonologist)",    "Asthma, Bronchitis, Pneumonia, Tuberculosis, COPD",          0, 0},
    {"DR.N GUPTA",      "8 AM to 12PM  2 PM to 6 PM (Saturday off)", "MBBS - MS (Gastroenterologist)","Ulcer, IBS, Liver Disease, Jaundice, Acid Reflux",          0, 0},
    {"DR.K VERMA",      "9 AM to 1PM   3 PM to 7 PM (Sunday off)",   "MBBS - MD (Pediatrician)",     "Child Fever, Malnutrition, Chickenpox, Measles, Mumps",      0, 0},
    {"DR.P JOSHI",      "8 AM to 12PM  2 PM to 6 PM (Monday off)",   "MBBS - MS (Ophthalmologist)",  "Cataract, Glaucoma, Conjunctivitis, Myopia, Retinal Issues", 0, 0}
};

float doc_fees[] = {500.0, 600.0, 700.0, 650.0, 550.0, 700.0,
                    800.0, 750.0, 700.0, 750.0, 500.0, 650.0};

pat *f = NULL;
pat *r = NULL;

// ------------------- FUNCTIONS -------------------
void det() {
    srand(time(NULL));
    pat *newPatient = (pat *)malloc(sizeof(pat));

    newPatient->id = rand() % 10000 + 1;
    space printf("Enter your name: ");
    scanf("%s", newPatient->name);
    space printf("Enter your age: ");
    scanf("%d", &newPatient->age);
    space printf("Which disease are you suffering from: ");
    scanf("%s", newPatient->dis);

    space printf("Which doctor's appointment do you want\n\n");
    space2 printf("%-5s %-20s %-35s %-45s %-35s\n", "ID", "Name", "Degree", "Treats", "Shifts");
    for (int i = 0; i < 12; i++) {
        space2 printf("%-5d %-20s %-35s %-45s %-35s\n", i + 1, b[i].nm, b[i].deg, b[i].disease, b[i].sft);
    }

    space printf("Enter your choice: ");
    scanf("%d", &newPatient->doc);
    while (newPatient->doc < 1 || newPatient->doc > 12) {
        space printf("Invalid choice. Please enter a number between 1 and 12: ");
        scanf("%d", &newPatient->doc);
    }

    int sft;
    while (1) {
        space printf("Enter shift (1 for morning, 2 for evening): ");
        scanf("%d", &sft);
        if (sft < 1 || sft > 2) {
            space printf("Invalid shift...Please re-enter\n\n");
        } else {
            break;
        }
    }

    newPatient->shift = sft;

    // Allocate bed
    int bedNum = pop(&bedStack);
    if (bedNum != -1)
        newPatient->bedNumber = bedNum;
    else
        newPatient->bedNumber = -1;

    int choice = newPatient->doc;
    if (sft == 1) {
        b[choice - 1].rcd += 1;
        int record = b[choice - 1].rcd;
        newPatient->tkn1 = ar[record - 1].tkn;
        strcpy(newPatient->time1, ar[record - 1].time);
    } else {
        b[choice - 1].rcd1 += 1;
        int record = b[choice - 1].rcd1;
        newPatient->tkn1 = ar1[record - 1].tkn;
        strcpy(newPatient->time1, ar1[record - 1].time);
    }

    newPatient->bill = doc_fees[choice - 1];
    newPatient->discount = (newPatient->age >= 60) ? (newPatient->bill * 0.10) : 0.0;
    newPatient->final_bill = newPatient->bill - newPatient->discount;

    // Link circularly
    newPatient->next = NULL;
    if (r == NULL) {
        f = r = newPatient;
        r->next = f;
    } else {
        r->next = newPatient;
        r = newPatient;
        r->next = f;
    }
}

void display(int sf) {
    if (f == NULL) {
        space printf("No appointments booked yet.\n");
        return;
    }
    pat *t = f;
    int found = 0;
    do {
        if (t->shift == sf) {
            found = 1;
            space printf("Patient Name: %s\n", t->name);
            space printf("Age: %d\n", t->age);
            space printf("ID: %d\n", t->id);
            space printf("Disease: %s\n", t->dis);
            space printf("Doctor: %s\n", b[t->doc - 1].nm);
            space printf("Token: %d\n", t->tkn1);
            space printf("Time: %s\n", t->time1);
            space printf("Bed Number: %d\n", t->bedNumber);
            space printf("Bill: Rs %.2f | Discount: Rs %.2f | Final: Rs %.2f\n",
                         t->bill, t->discount, t->final_bill);
            space printf("-----------------------------------------------\n\n");
        }
        t = t->next;
    } while (t != f);
    if (!found)
        space printf("No appointments in this shift.\n");
}

void display1() {
    if (r == NULL) {
        space printf("No recent appointment.\n");
        return;
    }
    pat *t = r;
    space printf("Patient Name: %s\n", t->name);
    space printf("Age: %d\n", t->age);
    space printf("ID: %d\n", t->id);
    space printf("Disease: %s\n", t->dis);
    space printf("Doctor: %s\n", b[t->doc - 1].nm);
    space printf("Token: %d\n", t->tkn1);
    space printf("Time: %s\n", t->time1);
    space printf("Bed Number: %d\n", t->bedNumber);
    space printf("Final Bill: Rs %.2f\n", t->final_bill);
    space printf("-----------------------------------------------\n\n");
}

void deleteAppointment() {
    if (f == NULL) {
        space printf("No appointments to delete.\n");
        return;
    }

    int pid;
    space printf("Enter Patient ID to delete appointment: ");
    scanf("%d", &pid);

    pat *curr = f, *prev = r;
    do {
        if (curr->id == pid) {
            if (curr == f && curr == r) {
                f = r = NULL;
            } else if (curr == f) {
                f = f->next;
                r->next = f;
            } else if (curr == r) {
                r = prev;
                r->next = f;
            } else {
                prev->next = curr->next;
            }

            push(&bedStack, curr->bedNumber);
            space printf("Appointment with ID %d deleted successfully.\n", pid);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != f);

    space printf("No appointment found with ID %d.\n", pid);
}

void addToFile() {
    if (r == NULL) {
        space printf("No appointments booked yet.\n");
        return;
    }
    pat *t = r;
    FILE *fp = fopen("HOSPITAL.txt", "a");
    if (!fp) {
        space printf("Cannot open file.\n");
        return;
    }
    fprintf(fp, "%-10s %-10d %-10d %-10s %-20s %-10d %-10s %-10s\n",
            t->name, t->age, t->id, t->dis, b[t->doc - 1].nm,
            t->tkn1, t->time1, (t->shift == 1 ? "MORNING" : "EVENING"));
    fclose(fp);
}

void searchById() {
    if (f == NULL) {
        space printf("No appointments.\n");
        return;
    }

    int pid, found = 0;
    space printf("Enter patient ID to search: ");
    scanf("%d", &pid);

    pat *t = f;
    do {
        if (t->id == pid) {
            found = 1;
            space printf("Patient: %s | Age: %d | Disease: %s | Doctor: %s\n",
                         t->name, t->age, t->dis, b[t->doc - 1].nm);
            space printf("Time: %s | Token: %d | Bill: Rs %.2f | Final: Rs %.2f\n",
                         t->time1, t->tkn1, t->bill, t->final_bill);
            break;
        }
        t = t->next;
    } while (t != f);

    if (!found)
        space printf("No appointment found with ID %d.\n", pid);
}

// ------------------- MAIN -------------------
int main() {
    initStack(&bedStack);
    for (int i = MAX_BEDS; i >= 1; i--) {
        push(&bedStack, i);
    }

    printf("\n\n\n");
    for (int j = 1; j <= 6; j++) {
        space
        for (int k = 1; k <= 40; k++) {
            if (k == 40 || k == 1 || j == 1 || j == 6)
                printf(".");
            else if (j == 3 && k >= 5 && k <= 35) {
                char text[] = "MAX HOSPITAL---------NEW DELHI";
                printf("%c", text[k - 5]);
            } else
                printf(" ");
        }
        printf("\n");
    }

    if (!login())
        exit(0);

    while (1) {
        printf("\n\n");
        space printf("1. Book an appointment\n");
        space printf("2. View today's appointments\n");
        space printf("3. Delete an appointment\n");
        space printf("4. Search appointment by ID\n");
        space printf("5. Exit\n");
        space printf("Enter choice: ");

        int ch;
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                det();
                addToFile();
                space printf("Appointment booked successfully!\n\n");
                display1();
                break;
            case 2:
                space printf("MORNING SHIFT\n");
                display(1);
                space printf("EVENING SHIFT\n");
                display(2);
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                searchById();
                break;
            case 5:
                exit(0);
            default:
                space printf("Invalid choice.\n");
        }
    }
}
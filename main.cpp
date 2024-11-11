#include <iostream>
#include <vector>
#include <string>

using namespace std;

int pid = 1;
int did = 1;

class Patient {
public:
    string name;
    int age;
    string gender;
    int ID;

    Patient(string n, int a, string g) {
        ID = pid++;
        name = n;
        age = a;
        gender = g;
    }

    void display() const {
        cout << "Patient ID: " << ID << "\nName: " << name << "\nAge: " << age << "\nGender: " << gender << endl;
    }
};

class Doctor {
public:
    string name;
    int age;
    string gender;
    int ID;

    Doctor(string n, int a, string g) {
        ID = did++;
        name = n;
        age = a;
        gender = g;
    }

    void display() const {
        cout << "Doctor ID: " << ID << "\nName: " << name << "\nAge: " << age << "\nGender: " << gender << endl;
    }
};

class Appointment {
public:
    int patientID;
    int doctorID;
    string date;

    Appointment(int pID, int dID, string d) {
        patientID = pID;
        doctorID = dID;
        date = d;
    }

    void display() const {
        cout << "Appointment Date: " << date << "\nPatient ID: " << patientID << "\nDoctor ID: " << doctorID << endl;
    }
};

vector<Patient> allPatients;
vector<Doctor> allDoctors;
vector<Appointment> allAppointments;

void addPatient() {
    string name, gender;
    int age;
    cout << "Enter Patient's Name: ";
    cin >> ws; // Clears leading whitespace
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Gender: ";
    cin >> gender;

    allPatients.push_back(Patient(name, age, gender));
    cout << "Patient added successfully!\n";
}

void addDoctor() {
    string name, gender;
    int age;
    cout << "Enter Doctor's Name: ";
    cin >> ws; // Clears leading whitespace
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Gender: ";
    cin >> gender;

    allDoctors.push_back(Doctor(name, age, gender));
    cout << "Doctor added successfully!\n";
}

void scheduleAppointment() {
    int pID, dID;
    string date;
    cout << "Enter Patient ID: ";
    cin >> pID;
    cout << "Enter Doctor ID: ";
    cin >> dID;
    cout << "Enter Appointment Date (DD-MM-YYYY): ";
    cin >> date;

    allAppointments.push_back(Appointment(pID, dID, date));
    cout << "Appointment scheduled successfully!\n";
}

void viewPatients() {
    if (allPatients.empty()) {
        cout << "No patients found.\n";
        return;
    }
    cout << "Patient List:\n";
    for (const auto& patient : allPatients) {
        patient.display();
        cout << "-------------------\n";
    }
}

void viewDoctors() {
    if (allDoctors.empty()) {
        cout << "No doctors found.\n";
        return;
    }
    cout << "Doctor List:\n";
    for (const auto& doctor : allDoctors) {
        doctor.display();
        cout << "-------------------\n";
    }
}

void viewAppointments() {
    if (allAppointments.empty()) {
        cout << "No appointments found.\n";
        return;
    }
    cout << "Appointment List:\n";
    for (const auto& appointment : allAppointments) {
        appointment.display();
        cout << "-------------------\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== Hospital Management System =====\n";
        cout << "1. Add Patient\n2. Add Doctor\n3. Schedule Appointment\n4. View Patients\n";
        cout << "5. View Doctors\n6. View Appointments\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                addDoctor();
                break;
            case 3:
                scheduleAppointment();
                break;
            case 4:
                viewPatients();
                break;
            case 5:
                viewDoctors();
                break;
            case 6:
                viewAppointments();
                break;
            case 7:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

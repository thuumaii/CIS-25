#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Patient
{
    int id;
    string name;
    int age;
    string gender;
    string diagnosis;
};

int binarySearch(Patient patients[], int count, int searchID)
{
    int left = 0;
    int right = count - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (patients[middle].id == searchID)
        {
            return middle;
        }
        else if (patients[middle].id < searchID)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    return -1;
}

int main()
{
    Patient* patients = new Patient[100];

    int count = 0;
    int choice;

    do
    {
        cout << "\n===== Hospital Patient System =====" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Display Patients" << endl;
        cout << "3. Search Patient" << endl;
        cout << "4. Update Patient" << endl;
        cout << "5. Save Patients" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                if (count >= 100)
                {
                    cout << "The patient list is full." << endl;
                    break;
                }

                Patient newPatient;

                cout << "Enter Patient ID: ";
                cin >> newPatient.id;

                int duplicate = binarySearch(patients, count, newPatient.id);

                if (duplicate != -1)
                {
                    cout << "Patient ID already exists." << endl;
                    break;
                }

                cin.ignore();

                cout << "Enter Name: ";
                getline(cin, newPatient.name);

                cout << "Enter Age: ";
                cin >> newPatient.age;

                cin.ignore();

                cout << "Enter Gender: ";
                getline(cin, newPatient.gender);

                cout << "Enter Diagnosis: ";
                getline(cin, newPatient.diagnosis);

                // Insert the patient in ID order.
                // This keeps the array sorted for binary search.
                int position = count;

                while (position > 0 &&
                       patients[position - 1].id > newPatient.id)
                {
                    patients[position] = patients[position - 1];
                    position--;
                }

                patients[position] = newPatient;
                count++;

                cout << "Patient added successfully!" << endl;

                break;
            }

            case 2:
            {
                if (count == 0)
                {
                    cout << "No patient records found." << endl;
                }
                else
                {
                    cout << "\n===== Patient Records =====" << endl;

                    for (int i = 0; i < count; i++)
                    {
                        cout << "\nID: " << patients[i].id << endl;
                        cout << "Name: " << patients[i].name << endl;
                        cout << "Age: " << patients[i].age << endl;
                        cout << "Gender: " << patients[i].gender << endl;
                        cout << "Diagnosis: "
                             << patients[i].diagnosis << endl;
                        cout << "--------------------------" << endl;
                    }
                }

                break;
            }

            case 3:
            {
                if (count == 0)
                {
                    cout << "No patient records found." << endl;
                    break;
                }

                int searchID;

                cout << "Enter Patient ID to search: ";
                cin >> searchID;

                int result = binarySearch(patients, count, searchID);

                if (result == -1)
                {
                    cout << "Patient not found." << endl;
                }
                else
                {
                    cout << "\nPatient Found" << endl;
                    cout << "ID: " << patients[result].id << endl;
                    cout << "Name: " << patients[result].name << endl;
                    cout << "Age: " << patients[result].age << endl;
                    cout << "Gender: " << patients[result].gender << endl;
                    cout << "Diagnosis: "
                         << patients[result].diagnosis << endl;
                }

                break;
            }

            case 4:
            {
                if (count == 0)
                {
                    cout << "No patient records found." << endl;
                    break;
                }

                int updateID;

                cout << "Enter Patient ID to update: ";
                cin >> updateID;

                int result = binarySearch(patients, count, updateID);

                if (result == -1)
                {
                    cout << "Patient not found." << endl;
                }
                else
                {
                    cin.ignore();

                    cout << "Enter New Name: ";
                    getline(cin, patients[result].name);

                    cout << "Enter New Age: ";
                    cin >> patients[result].age;

                    cin.ignore();

                    cout << "Enter New Gender: ";
                    getline(cin, patients[result].gender);

                    cout << "Enter New Diagnosis: ";
                    getline(cin, patients[result].diagnosis);

                    cout << "Patient updated successfully!" << endl;
                }

                break;
            }

            case 5:
            {
                ofstream file("patients.txt");

                if (!file)
                {
                    cout << "Unable to open patients.txt." << endl;
                }
                else
                {
                    for (int i = 0; i < count; i++)
                    {
                        file << patients[i].id << ","
                             << patients[i].name << ","
                             << patients[i].age << ","
                             << patients[i].gender << ","
                             << patients[i].diagnosis << endl;
                    }

                    file.close();

                    cout << "Patients saved to patients.txt."
                         << endl;
                }

                break;
            }

            case 6:
            {
                cout << "Good Bye!" << endl;
                break;
            }

            default:
            {
                cout << "Invalid choice!" << endl;
            }
        }

    } while (choice != 6);

    delete[] patients;

    return 0;
}
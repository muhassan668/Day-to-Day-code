#include <iostream>
#include <fstream>
using namespace std;

const int TOTAL_SEATS = 20;

void displayMenu() {
    cout << "\n--- Bus Ticket Reservation System ---\n";
    cout << "1. Book a Ticket\n";
    cout << "2. Display Available Seats\n";
    cout << "3. Cancel a Booking\n";
    cout << "4. Display Booked Tickets\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void displayAvailableSeats(int seats[]) {
    cout << "Available Seats: ";
    bool found = false;

    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i] == 0) {
            cout << (i + 1) << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << endl;
}

void displayBookedSeats(int seats[]) {
    cout << "Booked Seats: ";
    bool found = false;

    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i] == 1) {
            cout << (i + 1) << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << endl;
}

int main() {
    int seats[TOTAL_SEATS] = {0}; // 0 = available, 1 = booked
    int choice, seatNumber;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {

        case 1: // Book a Ticket
            cout << "Enter seat number (1-20): ";
            cin >> seatNumber;

            if (seatNumber < 1 || seatNumber > 20) {
                cout << "Invalid seat number!\n";
            } else if (seats[seatNumber - 1] == 1) {
                cout << "Seat already booked!\n";
            } else {
                seats[seatNumber - 1] = 1;
                cout << "Seat booked successfully!\n";
            }
            break;

        case 2: // Display Available Seats
            displayAvailableSeats(seats);
            break;

        case 3: // Cancel Booking
            cout << "Enter seat number to cancel (1-20): ";
            cin >> seatNumber;

            if (seatNumber < 1 || seatNumber > 20) {
                cout << "Invalid seat number!\n";
            } else if (seats[seatNumber - 1] == 0) {
                cout << "Seat is not booked!\n";
            } else {
                seats[seatNumber - 1] = 0;
                cout << "Booking canceled successfully!\n";
            }
            break;

        case 4: // Display Booked Tickets
            displayBookedSeats(seats);
            break;

        case 5: { // Exit and save to file
            ofstream file("booked_seats.txt");

            if (file) {
                file << "Booked Seats:\n";
                for (int i = 0; i < TOTAL_SEATS; i++) {
                    if (seats[i] == 1)
                        file << (i + 1) << " ";
                }
                file.close();
                cout << "Booked seats saved to file.\n";
            } else {
                cout << "Error saving file.\n";
            }

            cout << "Exiting program...\n";
            break;
        }

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
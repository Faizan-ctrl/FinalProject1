#include<iostream>
using namespace std;
int main() {
	const int n = 15;
	int roomNumber[n];
	for (int i = 0; i < n; i++) {
		roomNumber[i] = i + 101;
	}
	string roomTypes[n];
	for (int i = 0; i < n; i += 3) {
		roomTypes[i] = "single";
	}
	for (int i = 1; i < n; i += 3) {
		roomTypes[i] = "double";
	}
	for (int i = 2; i < n; i += 3) {
		roomTypes[i] = "suite";
	}
	bool availability[n];
	for (int i = 0; i < n; i++) {
		availability[i] = true;
	}
	double roomPrices[n];
	for (int i = 0; i < n; i += 3) {
		roomPrices[i] = 50.00;
	}
	for (int i = 1; i < n; i += 3) {
		roomPrices[i] = 100.00;
	}
	for (int i = 2; i < n; i += 3) {
		roomPrices[i] = 200.00;
	}
	string guestName[n];
	int stayDuration[n];
	for (int i = 0; i < n; i++) {
		guestName[i] = "";
		stayDuration[i] = 0;
	}
	int choice;
	do {
		cout << "Hotel Reservation System" << endl;
		cout << "1. Display available rooms" << endl;
		cout << "2. Book a room" << endl;
		cout << "3. Cancel a reservation" << endl;
		cout << "4. Update a reservation" << endl;
		cout << "5. Display current reservation for a room" << endl;
		cout << "6. Exit" << endl;
		do {
			cout << "Enter your choice (1-6): ";
			cin >> choice;
			if (choice < 1 || choice > 6) {
				cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
			}
		} while (choice < 1 || choice > 6);
		if (choice == 1) {
			cout << "Available Hotel Rooms:" << endl;
			for (int i = 0; i < n; i++) {
				if (availability[i]) {
					cout << "Room Number: " << roomNumber[i] << ", Type: " << roomTypes[i] << ", Price per night: $" << roomPrices[i] << endl;
				}
			}
		}
		else if (choice == 2) {
			int roomnumber;
			cout << "Enter room number which you want to book: ";
			cin >> roomnumber;
			string name;
			int duration;
			bool roomFound = false;
			for (int i = 0; i < n; i++) {
				if (roomNumber[i] == roomnumber) {
					roomFound = true;
					if (availability[i]) {
						cout << "Enter your name: ";
						cin >> name;
						guestName[i] = name;
						cout << "Enter stay duration (in days): ";
						cin >> duration;
						stayDuration[i] = duration;
						cout << name << " has booked room " << roomnumber << " for " << duration << " days." << endl;
						availability[roomnumber - 101] = false;
						if (!availability[i]) {
							double totalBill = roomPrices[i] * stayDuration[i];
							cout << "Total Bill: $" << totalBill << endl;
						}
					}
					else {
						cout << "Room " << roomnumber << " is already booked." << endl;
					}
					break;
				}
			}
			if (!roomFound) {
				cout << "Room number " << roomnumber << " does not exist. You may enter " << roomNumber[0] << " - " << roomNumber[0] + n - 1 << "." << endl;
			}
		}
		else if (choice == 3) {
			int roomnumber;
			cout << "Enter room number to cancel reservation: ";
			cin >> roomnumber;
			bool roomFound = false;
			for (int i = 0; i < n; i++) {
				if (roomNumber[i] == roomnumber) {
					roomFound = true;
					if (!availability[i]) {
						availability[i] = true;
						cout << "Reservation for room " << roomnumber << " has been canceled." << endl;
						stayDuration[i] = 0;
					}
					else {
						cout << "Room " << roomnumber << " is not currently booked." << endl;
					}
					break;
				}
			}
			if (!roomFound) {
				cout << "Room number " << roomnumber << " does not exist." << " You may enter " << roomNumber[0] << " - " << roomNumber[0] + n - 1 << "." << endl;
			}
		}
		else if (choice == 4) {
			int roomnumber;
			cout << "Enter room number to update reservation: ";
			cin >> roomnumber;
			string newName;
			int newDuration;
			bool roomFound = false;
			for (int i = 0; i < n; i++) {
				if (roomNumber[i] == roomnumber) {
					roomFound = true;
					if (!availability[i]) {
						cout << "Enter the new guest name: ";
						cin >> newName;
						guestName[i] = newName;
						cout << "Enter new stay duration (in days): ";
						cin >> newDuration;
						stayDuration[i] = newDuration;
						cout << "Reservation for room " << roomnumber << " has been updated to " << newName << " for " << newDuration << " days." << endl;
						double totalBill = roomPrices[i] * stayDuration[i];
						cout << "Total Bill: $" << totalBill << endl;
					}
					else {
						cout << "Room " << roomnumber << " is not currently booked." << endl;
					}
					break;
				}
			}
			if (!roomFound) {
				cout << "Room number " << roomnumber << " does not exist." << " You may enter " << roomNumber[0] << " - " << roomNumber[0] + n - 1 << "." << endl;
			}
		}
		else if (choice == 5) {
			int roomnumber;
			cout << "Enter room number to display current reservation: ";
			cin >> roomnumber;
			bool roomFound = false;
			for (int i = 0; i < n; i++) {
				if (roomNumber[i] == roomnumber) {
					roomFound = true;
					if (!availability[i]) {
						cout << "Room " << roomnumber << " is currently booked by " << guestName[i] << " for " << stayDuration[i] << " days." << endl;
					}
					else {
						cout << "Room " << roomnumber << " is currently available for reservation." << endl;
					}
					break;
				}
			}
			if (!roomFound) {
				cout << "Room number " << roomnumber << " does not exist." << " You may enter " << roomNumber[0] << " - " << roomNumber[0] + n - 1 << "." << endl;
			}
		}
	} while (choice != 6);
	return 0;
}
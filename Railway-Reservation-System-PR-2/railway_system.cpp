#include<iostream>
using namespace std;

class Train {
	
	private:
		
		int trainNumber;
		string trainName;
		string trainSource;
		string trainDestination;
		string trainTime;
		
	public:
		
		static int trainCount;
		
		/* Default Constructor */
		Train() {
			
		}
		
		/* Parameterized Constructor */
		Train(int number, string name, string source, string destination, string time) {
			this->trainNumber = number;
			this->trainName = name;
			this->trainSource = source;
			this->trainDestination = destination;
			this->trainTime = time;
			trainCount++;
		}
		
		/* Destructor */
		~Train(){
			trainCount--;
		}
		
		/* Common Setter Function */
		void setTrainInfo() {
			
			cout << endl << "Enter Train Number :- ";
			cin >> trainNumber;
			
			cin.ignore();
			
			cout << "Enter Train Name :- ";
			getline(cin, trainName);
			
			cout << "Enter Train Source :- ";
			getline(cin, trainSource);
			
			cout << "Enter Train Destination :- ";
			getline(cin, trainDestination);
			
			cout << "Enter Train Time :- ";
			getline(cin, trainTime);
			
			trainCount++;
			
			cout << endl;
			
		}

		/* Setter Function For Each Member */
		void setTrainNumber() {
			cout << endl << "Enter Train Number :- ";
			cin >> trainNumber;
			
			cin.ignore();
		}

		void setTrainName() {
			cout << "Enter Train Name :- ";
			getline(cin, trainName);
		}

		void setTrainSource() {
			cout << "Enter Train Source :- ";
			getline(cin, trainSource);
		}

		void setTrainDestination() {
			cout << "Enter Train Destination :- ";
			getline(cin, trainDestination);
		}

		void setTrainTime() {
			cout << "Enter Train Time :- ";
			getline(cin, trainTime);
		}
		
		/* Common Getter Function */
		void getTrainInfo() {
			
			cout << "Train Number :- " << trainNumber << endl;
			cout << "Train Name :- " << trainName << endl;
			cout << "Train Source :- " << trainSource << endl;
			cout << "Train Destination :- " << trainDestination << endl;
			cout << "Train Time :- " << trainTime << endl << endl;
			
		}
		
		/* Getter Function For Each Memen=ber */
		int getTrainNumber() {
			return trainNumber;	
		}

		string getTrainName() {
			return trainName;
		}

		string getTrainSource() {
			return trainSource;
		}

		string getTrainDestination() {
			return trainDestination;
		}

		string getTrainTime() {
			return trainTime;
		}

		~Train(){
    		trainCount--;
		}
	
};

class RailwaySystem{
	
	private:
		
		Train *trains;
		int totalTrains;
	
	public:
		int indexTrain = 0;
		
		RailwaySystem() {
			
		}
		
		RailwaySystem(int num) {
			
			totalTrains = num;
			trains = new Train[num];
			
		}
		
		~RailwaySystem() {
			delete[] trains;
		}
		
		void addTrainInfo() {

			if(indexTrain >= totalTrains) {
				cout << endl << "Limit Reached........" << endl;
				return;
			}

			trains[indexTrain].setTrainInfo();
			indexTrain++;
			
		}
		
		void displayTrainInfo() {

			if(indexTrain == 0) {
				cout << endl << "No Information Found..........." << endl;
				return;
			}
			
			for(int i = 0; i < indexTrain; i++) {
				cout << endl;
				trains[i].getTrainInfo();
			}
			
		}
		
		void searchTrain(int trainNum) {

			int tracker = 0;
			
			if(indexTrain == 0) {
				cout << endl;
				cout << endl << "No Information Found........" << endl;
				return;
			}
			
			for(int i = 0; i < indexTrain; i++) {
				
				if(trains[i].getTrainNumber() == trainNum) {
					trains[i].getTrainInfo();
					tracker++;
				}

			}	

			if(tracker == 0) {
				cout << endl << "Invalid Train ID......" << endl;
			}
		
		}
	
};

int Train::trainCount = 0;


int main() {

	cout << endl << "<============= Railway Reservation System =============>" << endl << endl;
	
	int n;
	
	cout << "Enter Number of Trains :- ";
	cin >> n;

	RailwaySystem manage(n);
	
	int choice;
		
	do {
		
		cout << endl << "<============= Railway Reservation System Menu =============>" << endl << endl;
		cout << "Press 1 to Add Trains." << endl;
		cout << "Press 2 to Display Trains." << endl;
		cout << "Press 3 to Search Trains." << endl;
		cout << "Press 4 to Exit." << endl;
	
		tryAgain:	
		cout << "Enter Your Choice :- ";
		cin >> choice;
		
		if(choice < 1 || choice > 4) {
			cout << endl << "Invalid Choice....." << endl << "Please Try Agan...." << endl;
			goto tryAgain;
		}
		
		switch(choice) {
			
			case 1:
				
				manage.addTrainInfo();
				
				break;
				
			case 2:
				
				manage.displayTrainInfo();
				cout << endl << "Total Train :- " << Train::trainCount ;
				
				break;
				
			case 3:
				
				int trainId;
	
				cout << endl << "Enter  Train Number :- ";
				cin >> trainId;
	
				manage.searchTrain(trainId);
				
				break;
			case 4:
				
				cout << endl << "Exiting the system. Goodbye!";
				
				break;
			
		}
			
	} while (choice!=4);
	
	return 0;
}
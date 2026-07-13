#include<iostream>
using namespace std;

class Vehicle {
	
	private:
		
		int vehicleID;
		string manuFacturer;
		string model;
		int year;
		string type;
        int set;
		
	
	public:
	
		static int totalVehicle;
		
		Vehicle() {
		}
		
		Vehicle(int id, string manufacturer, string model, int year, int set) {
			
			this->vehicleID = id;
			this->manuFacturer = manufacturer;
			this->model = model;
			this->year = year;
            this->set = set;
			
			totalVehicle++;
			
		}
		
		void setVehicleInfo() {
			
			cout << "Enter Vehicle ID :-";
			cin >> vehicleID;
			
			cin.ignore();
			
			cout << "Enter Vehicle Manufacturer :- ";
			getline(cin, manuFacturer);
			
			cout << "Enter Vehicle Model :- ";
			getline(cin, model);
			
			cout << "Enter Vehicle Year :- ";
			cin >> year;

            cout << "Enter Number Of Sets In a Vehicle :- ";
            cin >> set;
			
			totalVehicle++;
		}

		void setType(string type) {
			this->type = type;
		}

		string getType() {
			return type;
		}

		~Vehicle() {
			totalVehicle--;
		}
		
		void getVehicleInfo() {
			
			cout << endl << "Vehicle ID :- " << vehicleID << endl;
			cout << "Vehicle Manufacturer :- " << manuFacturer << endl;
			cout << "Vehicle Model :- " << model << endl;
			cout << "Vehicle Year :- " << year << endl;
			
		}
		
		int getIDInfo() {
			return vehicleID;
		}
		
		string getManuFacturerInfo() {
			return manuFacturer;
		}
		
		string getModelInfo() {
			return model;
		}
		
		int getYearInfo() {
			return year;
		}
	
};

class Car: public Vehicle {
	
	private:
		string fuelType;
		
	public:
		
		void setCarInfo() {
			
			setVehicleInfo();
			
			cin.ignore();
			
			cout << "Enter Vehicle Fuel Type :- ";
			getline(cin, fuelType);
			
		}
		
		void getCarInfo() {
			
			getVehicleInfo();
			
			cout << "Vehicle Fuel Type :- " << fuelType << endl;
			
		}
	
};

class ElectricCar: public Car {

	private:
		int batteryCapacity;
		
	public:
		
		void setElectricCarInfo() {
			
			setCarInfo();
			
			cout << "Enter Vehicle Battery Capacity(kwh) :- ";
			cin >> batteryCapacity;
			
		}
		
		void getElectricCarInfo() {
			
			getCarInfo();
			
			cout << "Vehicle Battery Capacity :- " << batteryCapacity << "kwh" << endl;
			
		}

};

class Aircraft {
	
	private:
		int flightRange;
		
	public:
		
		void setAircraftInfo() {
			
			cout << "Enter Vehicle Flight Range(mile) :- ";
			cin >> flightRange;
			
		}
		
		void getAircraftInfo() {
			
			cout << "Vehicle Flight Range :- " << flightRange << " mile" << endl;
			
		}
	
};

class FlyingCar: public Car, public Aircraft {

	private:
		int parasut;
	
	public:
		
		void setFlyingCarInfo() {
			
			setCarInfo();
			setAircraftInfo();

			cout << "Enter Number Of Parasuts In Vehicle :- ";
			cin >> parasut;
			
		}
		
		void getFlyingCarInfo() {
			
			getCarInfo();
			getAircraftInfo();

			cout << "Number OF Parasuts In Vehicle :- " << parasut << endl;
			
		}
	
};

class SportsCar: public ElectricCar {
	
	private:
		int topSpeed;
		
	public:
		
		void setSportCarInfo() {
			
			setElectricCarInfo();
			
			cout << "Enter Vehicle Top Speed(km/hr) :- ";
			cin >> topSpeed;
			
		}
		
		void getSportCarInfo() {
			
			getElectricCarInfo();
			
			cout << "Vehicle Top Speed :- " << topSpeed << "km/hr" << endl;
			
		}
	
};

class Sedan: public Car {
	
	public:
	
		void setSedanInfo() {

			cout << "Enter Seadan Details" << endl;
			
			setCarInfo();

		}

		void getSedanInfo() {

			getCarInfo();

		}

};

class SUV: public Car {

	public:

		void setSUVInfo() {

			setCarInfo();

		}

		void getSUVInfo() {

			getCarInfo();

		}

};

class VehicleRegistry {

	private:
		Vehicle *vehicleManage[100];
		int total_Vehicle = 100;

	public:

		int index = 0;

		~VehicleRegistry() {

			for(int i = 0; i < index; i++) {
				delete vehicleManage[i];
			}
	
		}

		void addElecticCar() {

			if(index >= total_Vehicle) {
				cout << endl << "Limite Reached......." << endl << endl;
				return;
			}
 
			ElectricCar *electic = new ElectricCar();
			electic->setElectricCarInfo();
			electic->setType("ElectricCar");
			vehicleManage[index] = electic;
			index++;

		}

		void addFlyingcar() {

			if(index >= total_Vehicle) {
				cout << endl << "Limite Reached......." << endl << endl;
				return;
			}

			FlyingCar *flying = new FlyingCar();
			flying->setFlyingCarInfo();
			flying->setType("FlyingCar");
			vehicleManage[index] = flying;
			index++;

		}

		void addSportCar() {

			if(index >= total_Vehicle) {
				cout << endl << "Limite Reached......." << endl << endl;
				return;
			}

			SportsCar *sport = new SportsCar();
			sport->setSportCarInfo();
			sport->setType("SportsCar");
			vehicleManage[index] = sport;
			index++;

		}
			
		void addSedanCarInfo() {

			if(index >= total_Vehicle) {
				cout << endl << "Limite Reached......." << endl << endl;
				return;
			}
	
			Sedan *sedan = new Sedan();
			sedan->setSedanInfo();
			sedan->setType("Sedan");
			vehicleManage[index] = sedan;
			index++;
		
		}

		void addSUVInfo() {

			if(index >= total_Vehicle) {
				cout << endl << "Limite Reached......." << endl << endl;
				return;
			}

			SUV *suv = new SUV();
			suv->setSUVInfo();
			suv->setType("SUV");
			vehicleManage[index] = suv;
			index++;

		}

		void displayALLVehicle() {
			
			if(index == 0) {
					cout << endl << "No Informaation Found......." << endl << endl;
					return;
				}

			cout << endl << "<============ DISPLAY ALL VEHICLE ============>" << endl;
				
			for(int i = 0; i < index; i++) {
					

                string type = vehicleManage[i]->getType();

				if(type == "Sedan") {
                    ((Sedan*)vehicleManage[i])->getSedanInfo();
                }

				if(type == "ElectricCar") {
                    ((ElectricCar*)vehicleManage[i])->getElectricCarInfo();
                }

				if(type == "FlyingCar") {
                    ((FlyingCar*)vehicleManage[i])->getFlyingCarInfo();
                }

				if(type == "SportsCar") {
                    ((SportsCar*)vehicleManage[i])->getSportCarInfo();
                }

				if(type == "SUV") {
                    ((SUV*)vehicleManage[i])->getSUVInfo();
                }

				cout << "--------------------------------------------------------" << endl ;

			}

		}

		void searchByID(int id) {

			int tracker = 0;

			if(index == 0) {
				cout << endl << "No Informaation Found......." << endl << endl;
			}

			for(int i = 0; i < index; i++) {

				if(vehicleManage[i]->getIDInfo() == id) {

					string type = vehicleManage[i]->getType();

					if(type == "ElectricCar") {

						((ElectricCar*)vehicleManage[i])->getElectricCarInfo();

					} else if(type == "FlyingCar") {

						((FlyingCar*)vehicleManage[i])->getFlyingCarInfo();

					} else if(type == "SportsCar") {

						((SportsCar*)vehicleManage[i])->getSportCarInfo();

					} else if(type == "Sedan") {

						((Sedan*)vehicleManage[i])->getSedanInfo();

					} else if(type == "SUV") {

						((SUV*)vehicleManage[i])->getSUVInfo();

					}

					tracker++;

				}

			}

			if(tracker == 0) {
				cout << endl << "No Informaation Found " << endl << "Invalid ID ......." << endl << endl;
			}

		}

};

int Vehicle::totalVehicle = 0;


int main() {

	VehicleRegistry manage;

	int choice;

	do {

        cout << endl << "<============ VEHICLE REGISTRY ============>" << endl << endl;

		cout << "Press 1 to Choose Vehicles." << endl;
		cout << "Press 2 to View all Vehicles." << endl;
		cout << "Press 3 to Search by ID." << endl;
		cout << "Press 4 to Exit." << endl;

		cout <<"Enter Your Choice :- ";
		cin >> choice;

		if(choice < 1 || choice > 4) {
			cout << endl << "Invalid Number Enter.........." << endl;
			return 0;
		}

		switch(choice) {

			case 1:

				int options;

				do{

                    cout << endl << "<============ VEHICLE OPTION ============>" << endl << endl;

					cout <<"Press 1 to Add Electric Car Details." << endl;
					cout << "Press 2 to Add Flying Car Details." << endl;
					cout << "Press 3 to Add Sport Car Details." << endl;
					cout << "Press 4 to Add Sedan Details." << endl;
					cout << "Press 5 to Add SUV Details." << endl;
					cout << "Press 6 to Exit." << endl;

					cout << endl << "Enter Your Choice :- ";
					cin >> options;

					if(options < 1 || options > 6) {
						cout << endl << "Invalid Number Enter.........." << endl;
						return 0;
					}

					switch(options) {

						case 1:
							manage.addElecticCar();

							break;

						case 2:
							manage.addFlyingcar();

							break;

						case 3:
							manage.addSportCar();

							break;

						case 4:
							manage.addSedanCarInfo();

							break;

						case 5:
							manage.addSUVInfo();

							break;

						case 6:
							cout << endl;
							break;

					}

				} while(options != 6);

				break;

			case 2:
				manage.displayALLVehicle();

				break;

			case 3:
				
				int id;

				cout << endl << "Enter Vehicle ID :- ";
				cin >> id;

				manage.searchByID(id);

				break;

			case 4:
				cout << endl << endl << "<============ THANK YOU ============>";

				break;

		}


	} while (choice != 4);
	

	return 0;
}
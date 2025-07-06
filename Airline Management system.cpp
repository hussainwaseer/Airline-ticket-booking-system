#include<iostream>
#include<unistd.h>
#include<cstring>
#include<iomanip>
#include<fstream>
using namespace std ;
	ofstream rec("Record.xls",ios::app);
	int way , no_of_tickets_adults , no_of_tickets_infants , no_of_tickets_children , total_tickets , select_class ;
	int depart_time , re_time , plane_type_int , re_plane_type_int, total_seats;
	string departure_date , return_date , departure_time , return_time , plane_type , return_plane_type , ticket_class;
	string passenger_names_adults[1000] , passenger_names_children[1000] , passenger_names_infants[1000] ; 
	string contact_number , email_id, tickets; 
	
	int passenger_ages_adults[1000] , passenger_ages_children[1000] , passenger_ages_infants[1000] ;
	char depart_country[50] , arrival_country[50] ;
	
	const long double payofadultsE1 = 15000; 
	const long double payofchildrenE1 = 12000;
	const long double payofinfantsE1 = 7000;
	
	const long double payofadultsE2 = 15000*1.8; 
	const long double payofchildrenE2 = 12000*1.8;
	const long double payofinfantsE2 = 7000*1.8;

	const long double payofadultsB1 = 150000; 
	const long double payofchildrenB1 = 120000;
	const long double payofinfantsB1 = 70000;
	
	const long double payofadultsB2 = 150000*1.8; 
	const long double payofchildrenB2 = 120000*1.8;
	const long double payofinfantsB2 = 70000*1.8;

    int total_pay_economy, total_pay_business;	
	
	void welcome() 
    {
        int width = 80 ;  
        int height = 20 ; 
        for (int i = 0; i < width; ++i) 
	    {
            cout << "*";
        }
        cout << endl;
        for (int i = 0; i < width; ++i) 
	    {
            cout << "*";
        }
	    cout <<endl;
        for (int i = 0; i < height/2; ++i) 
	    {
	        cout <<"****"<<setw(width-4)<< "****"<<endl;
        }
        cout <<"****"<<setw(56)<<"Welcome To The AHS Airplane Ticket Booking"<<setw(20)<< "****"<<endl;
	    for (int i = 0; i < height/2; ++i) 
	    {
	        cout <<"****"<<setw(width-4)<< "****"<<endl;
        }
 	    for (int i = 0; i < width; ++i) 
	    {
            cout << "*";
        }
        cout << endl;
	    for (int i = 0; i < width; ++i) 
	    {
            cout << "*";
        }
        cout<<endl ;
    }
    
void registration(string &departure, string &name, string &number, string &email, int &age, int &child, int &infant, int &Way, string &time, string &Seat_class, string &Arrival, string &dep_date, string &arr_date,string &aircraft_name)
{
	cout<<"=-=-=-=-=-=-=-=-=-=-=-Registration-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
    cout<<"ENTER THE COUNTRY THAT YOU WANT TO DEPART FROM: " ; cin>>depart_country;
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
    strupr(depart_country) ;
	departure=depart_country;
    sleep(2);
    system("cls") ;
	ifstream destination ;
    destination.open("ARRIVAL_COUNTRIES.txt") ;
	string dest ;
    while(destination.eof()==0)
    {
        getline(destination,dest) ;
        cout<<dest <<endl ;
    }
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
    cout<<"ENTER WHICH COUNTRY DO YOU WANT TO GO: "; cin>>arrival_country ; 
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
    strupr(arrival_country) ;
    Arrival=arrival_country;
    
     sleep(2) ;
    system("cls") ;
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	cout<<"ENTER 1 FOR ONE-WAY OR 2 FOR TWO-WAY: "; cin>>way; Way=way;
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	 sleep(2) ;
    system("cls") ;
	if(way==1)
    {
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
    	cout<<"ENTER THE DATE THAT YOU WANT TO DEPART ON(MM/DD/YYYY): " ; cin>>departure_date ;
    	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
    	 sleep(2);
    	 dep_date=departure_date;
	}
	else
	{
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout<<"ENTER THE DATE THAT YOU WANT TO DEPART ON(MM/DD/YYYY): " ; cin>>departure_date ;
		dep_date=departure_date;
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout<<"ENTER THE DATE ON WHICH YOU WANT TO RETURN(MM/DD/YYYY): " ; cin>>return_date ;
        arr_date=return_date;
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
         sleep(2);
	}
	system("cls") ;
	if(way==1)
    {
    	ifstream time ;
	    time.open("DEPARTURE_TIME.txt") ;
	    string choose_time ;
	    while(time.eof()==0)
	    {
		getline(time,choose_time) ;
		cout<<choose_time <<endl ;
	    }
	    cout<<endl <<endl ;
	     sleep(2);  
	    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	    cout<<"ENTER THE TIME AT WHICH YOU WANT TO DEPART(1-8): " ; cin>>depart_time ;
	    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	}
	else
	{
		ifstream time ;
	    time.open("DEPARTURE_TIME.txt") ;
	    string choose_time ;
	    while(time.eof()==0)
	    {
		getline(time,choose_time) ;
		cout<<choose_time <<endl ;
	    }
	    cout<<endl <<endl ;
	   
	}
	do{
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	cout<<"ENTER THE TIME AT WHICH YOU WANT TO DEPART(1-8): " ; cin>>depart_time ;
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	if(depart_time == 1){
		departure_time="02:00";
		time=departure_time;
	}
	else if(depart_time == 2){
		departure_time="05:00";
		time=departure_time;
	}
	else if(depart_time == 3){
		departure_time="08:00";
		time=departure_time;
	}
	else if(depart_time == 4){
		departure_time="11:00";
		time=departure_time;
	}
	else if(depart_time == 5){
		departure_time="14:00";
		time=departure_time;
	}
	else if(depart_time == 6){
		departure_time="17:00";
		time=departure_time;
	}
	else if(depart_time == 7){
		departure_time="20:00";
		time=departure_time;
	}
	else if(depart_time == 8){
		departure_time="23:00";
		time=departure_time;
	}
	else{
		cout<<"Invalid input!!!\n";
	}
}
	while(depart_time<1 && depart_time>8);
	do{
	cout<<"ENTER THE TIME AT WHICH YOU WANT TO RETURN(1-8): " ; cin>>re_time ;
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	if(re_time == 1){
		return_time="02:00";
	}
	else if(re_time == 2){
		return_time="05:00";
	}
	else if(re_time == 3){
		return_time="08:00";
		
	}
	else if(re_time == 4){
		return_time="11:00";
	}
	else if(re_time == 5){
		return_time="14:00";
	}
	else if(re_time == 6){
		return_time="17:00";
	}
	else if(re_time == 7){
		return_time="20:00";
	}
	else if(re_time == 8){
		return_time="23:00";
	}
	else{
		cout<<"Invalid input!!!\n";
	}
	}
	while(depart_time>=1 && depart_time>=8);
	sleep(2);
	system("cls") ;
	if(way==1)
    {
    	ifstream plane ;
        plane.open("AIRCRAFT_TYPES.txt") ;
        string plane_types ;
        while(plane.eof()==0)
        {
        getline(plane,plane_types) ;
        cout<<plane_types <<endl ;
        }
        cout<<endl <<endl ;
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout<<"ENTER THE PLANE IN WHICH YOU WANT TO DEPART: "; cin>>plane_type_int ;
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        system("cls") ;
	}
	else
	{
		ifstream plane ;
        plane.open("AIRCRAFT_TYPES.txt") ;
        string plane_types ;
        while(plane.eof()==0)
        {
        getline(plane,plane_types) ;
        cout<<plane_types <<endl ;
        }
        cout<<endl <<endl ;
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout<<"ENTER THE PLANE IN WHICH YOU WANT TO DEPART: "; cin>>plane_type_int ;
    	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout<<"ENTER THE PLANE IN WHICH YOU WANT TO RETURN: "; cin>>re_plane_type_int ;
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		system("cls") ;	
	}
	if(plane_type_int == 1){
		plane_type = "B707";
		aircraft_name=plane_type;
	}
	if(plane_type_int == 2){
		plane_type = "B717";
		aircraft_name=plane_type;
	}
	if(plane_type_int == 3){
		plane_type = "B727";
		aircraft_name=plane_type;
	}
	if(plane_type_int == 4){
		plane_type = "B777";
		aircraft_name=plane_type;
	}
	if(plane_type_int == 5){
		plane_type = "D345";
		aircraft_name=plane_type;
	}
	if(plane_type_int == 6){
		plane_type = "F765";
		aircraft_name=plane_type;
	}
	if(plane_type_int == 7){
		plane_type = "O130";
		aircraft_name=plane_type;
	}
	if(plane_type_int == 8){
		plane_type = "S435";
		aircraft_name=plane_type;
	}
	if(re_plane_type_int == 1){
		return_plane_type = "B707";
	}
	if(re_plane_type_int == 2){
		return_plane_type = "B717";
	}
	if(re_plane_type_int == 3){
		return_plane_type = "B727";
	}
	if(re_plane_type_int == 4){
		return_plane_type = "B777";
	}
	if(re_plane_type_int == 5){
		return_plane_type = "D345";
	}
	if(re_plane_type_int == 6){
		return_plane_type = "F765";
	}
	if(re_plane_type_int == 7){
		return_plane_type = "O130";
	}
	if(re_plane_type_int == 8){
		return_plane_type = "S435";
	}
	do{
		
	
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	cout<<"HOW MANY TICKETS DO YOU WANT TO PURCHASE FOR ADULTS(12+): " ; cin>>no_of_tickets_adults ;
		}
		while(no_of_tickets_adults<0);
	do{
	
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	cout<<"HOW MANY TICKETS DO YOU WANT TO PURCHASE FOR CHILDREN(2-11): " ; cin>>no_of_tickets_children ; child=no_of_tickets_children;
	}
	while(no_of_tickets_children<0);
	do{
		
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	cout<<"HOW MANY TICKETS DO YOU WANT TO PURCHASE FOR INFANTS(UNDER 2): " ; cin>>no_of_tickets_infants ; infant=no_of_tickets_infants;
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	}
		while(no_of_tickets_infants<0);
	system("cls") ;
	
	ifstream class_type ;
	class_type.open("CLASS.txt") ;
	string clas ;
	cout<<"(150000 per ticket in business class)\n(15000 per ticket in Economy class)"<<endl;
	while(class_type.eof()==0)
	{
		getline(class_type,clas) ;
		cout<<clas<<endl ;
	}
	cout<<endl <<endl ;
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	cout<<"ENTER THE CLASS IN WHICH YOU WANT TO TRAVEL(1 OR 2): " ; cin>>select_class ; 
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
	if(select_class==1){
		Seat_class="Business";
	}
	else if(select_class==2){
		Seat_class="Economy";
	}
	system("cls") ; 
	cout<<"=-=-=-=-=-=-=-=-=-=-PASSENGER DETAILS-=-=-=-=-=-=-=-=-=-="<<endl;
	cout<<setw(32)<<"ENTER PASSENGER DETAILS: " <<endl ;
	cin.ignore() ;
	
	for(int i =0 ; i<no_of_tickets_adults ; i++)
	{
		if(i==0)
		{
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout<<"ENTER NAME OF " <<i+1 <<" ADULT: " ; getline(cin,passenger_names_adults[i]) ; name=passenger_names_adults[i];//cin.ignore();
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout<<"ENTER THE NUMBER OF " <<i+1 <<" ADULT: " ; cin>>contact_number ; number=contact_number;
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout<<"ENTER THE EMAIL OF " <<i+1 <<" ADULT: " ; cin>>email_id ; email=email_id;
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout<<"ENTER THE AGE OF " <<i+1 <<" ADULT:" ; cin>>passenger_ages_adults[i] ; age=passenger_ages_adults[i];
		while(passenger_ages_adults[i]<12)
		{
			cout<<"CONDITION NOT MET! ENTER AGAIN: " ; cin>>passenger_ages_adults[i] ; 
		}
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cin.ignore() ;	
		}
		else
		{
		cout<<"ENTER NAME OF " <<i+1 <<" ADULT: " ; getline(cin,passenger_names_adults[i]) ;
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout<<"ENTER THE AGE OF " <<i+1 <<" ADULT:" ; cin>>passenger_ages_adults[i] ;
		while(passenger_ages_adults[i]<12)
		{
			cout<<"CONDITION NOT MET! ENTER AGAIN: " ; cin>>passenger_ages_adults[i] ; 
		}
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;	
		cin.ignore() ;
		}
	}
	for(int i =0 ; i<no_of_tickets_children ; i++)
	{
		cout<<"ENTER THE NAME OF " <<i+1 <<" CHILDREN: " ; getline(cin,passenger_names_children[i]) ;
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout<<"ENTER THE AGE OF " <<i+1 <<" CHILDREN:" ; cin>>passenger_ages_children[i] ;
		while(passenger_ages_children[i]>=12||passenger_ages_children[i]<=0||passenger_ages_children[i]<=2)
		{
			cout<<"CONDITION NOT MET! ENTER AGAIN: " ; cin>>passenger_ages_children[i] ; 
		}
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cin.ignore() ;
	}
	for(int i =0 ; i<no_of_tickets_infants ; i++)
	{
		cout<<"ENTER THE NAME OF " <<i+1 <<" INFANT: " ; getline(cin,passenger_names_infants[i]) ;
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cout<<"ENTER THE AGE OF " <<i+1 <<" INFANT: " ; cin>>passenger_ages_infants[i] ;
		while(passenger_ages_infants[i]>2||passenger_ages_infants[i]<=0)
		{
			cout<<"CONDITION NOT MET! ENTER AGAIN: " ; cin>>passenger_ages_infants[i] ; 
		}
		cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
		cin.ignore() ;
    }    
}

void details(int &cost)
{
    if (select_class==1)
	{
    	ticket_class="BUSINESS CLASS    ";
    	if(way==1)
		{
    	total_pay_business = ((no_of_tickets_adults*payofadultsB1) + (no_of_tickets_children*payofchildrenB1) + (no_of_tickets_infants*payofinfantsB1));
		}
		if(way==2)
		{
		total_pay_business = ((no_of_tickets_adults*payofadultsB2) + (no_of_tickets_children*payofchildrenB2) + (no_of_tickets_infants*payofinfantsB2));
		}
	}
	
    if (select_class==2)
	{
    	ticket_class="ECONOMY CLASS      (15000 per ticket)";
    	if(way==1)
		{
    	total_pay_economy = ((no_of_tickets_adults*payofadultsE1) + (no_of_tickets_children*payofchildrenE1) + (no_of_tickets_infants*payofinfantsE1));
		}
		if(way==2)
		{
		total_pay_economy = ((no_of_tickets_adults*payofadultsE2) + (no_of_tickets_children*payofchildrenE2) + (no_of_tickets_infants*payofinfantsE2));
		}
	}
	sleep(2);
	total_seats = no_of_tickets_adults + no_of_tickets_children + no_of_tickets_infants ; 
	cout<<"****------------------YOUR SEAT DETAILS-------------------****"<<endl;
    cout<<"****------------------------------------------------------****"<<endl;
    cout<<"****"<<setw(58)<<"****"<<endl;
	cout<<setw(12)<<left<<"****"<<setw(11)<<"YOU CHOOSE "<<setw(14)<<left<<ticket_class<<" TICKETS"<<setw(17)<<right<<"****"<<endl;
	if(no_of_tickets_adults > 0)
	{
		if(no_of_tickets_adults==1)
		{
            cout<<setw(12)<<left<<"****"<<setw(23)<<left<<"YOU BOOKED ADULT SEAT."<<setw(4)<<left<<no_of_tickets_adults<<setw(23)<<right<<"****"<<endl;
    	}
		else
		{
			cout<<setw(12)<<left<<"****"<<setw(24)<<left<<"YOU BOOKED ADULT SEATS."<<setw(4)<<left<<no_of_tickets_adults<<setw(22)<<right<<"****"<<endl;
		}
	}
    if(no_of_tickets_children > 0)
	{
    	if(no_of_tickets_children==1)
		{
			cout<<setw(12)<<left<<"****"<<setw(23)<<left<<"YOU BOOKED CHILD SEAT."<<setw(4)<<left<<no_of_tickets_children<<setw(23)<<right<<"****"<<endl; 
		}
		else
		{
			cout<<setw(12)<<left<<"****"<<setw(24)<<left<<"YOU BOOKED CHILD SEATS."<<setw(4)<<left<<no_of_tickets_children<<setw(22)<<right<<"****"<<endl;
		}
	}
    if(no_of_tickets_infants > 0)
	{
    	if(no_of_tickets_infants==1)
		{
			cout<<setw(12)<<left<<"****"<<setw(25)<<left<<"YOU BOOKED INFANTS SEAT."<<setw(4)<<left<<no_of_tickets_infants<<setw(21)<<right<<"****"<<endl;
		}
		else
		{
			cout<<setw(12)<<left<<"****"<<setw(26)<<left<<"YOU BOOKED INFANTS SEATS."<<setw(4)<<left<<no_of_tickets_infants<<setw(20)<<right<<"****"<<endl;			
		}
	}
	cout<<setw(12)<<left<<"****"<<setw(18)<<left<<"YOUR TOTAL SEATS: "<<setw(4)<<left<<total_seats<<setw(28)<<right<<"****"<<endl;
    cout<<"****"<<setw(58)<<"****"<<endl;
	cout<<"****------------------------------------------------------****"<<endl;
	
	cout<<"\nPayment Details loading....."<<endl;
	system("PAUSE");
	system("cls");
	
	long double adultB1 = no_of_tickets_adults*payofadultsB1;
	long double adultB2 = no_of_tickets_adults*payofadultsB2;
	long double adultE1 = no_of_tickets_adults*payofadultsE1;
	long double adultE2 = no_of_tickets_adults*payofadultsE2;
	
	long double childB1 = no_of_tickets_children*payofchildrenB1;
	long double childB2 = no_of_tickets_children*payofchildrenB2;
	long double childE1 = no_of_tickets_children*payofchildrenE1;
	long double childE2 = no_of_tickets_children*payofchildrenE2;
	
	long double infantB1 = no_of_tickets_infants*payofinfantsB1;
	long double infantB2 = no_of_tickets_infants*payofinfantsB2;
	long double infantE1 = no_of_tickets_infants*payofinfantsE1;
	long double infantE2 = no_of_tickets_infants*payofinfantsE2;
	
	if(way==1){
		tickets="ONE WAY TICKETS";
	}
	if(way==2){
		tickets="RETURN TICKETS / TWO WAY TICKETS";
	}
	
	
	cout<<"**_________________YOUR PAYMENT DETAILS_________________**"<<endl;
    cout<<"**______________________________________________________**"<<endl;
    cout<<"**"<<setw(56)<<"**"<<endl;
    cout<<setw(12)<<left<<"**"<<setw(32)<<left<<tickets<<setw(14)<<right<<"**"<<endl;
	cout<<setw(12)<<left<<"**"<<setw(14)<<left<<ticket_class<<setw(14)<<left<<" TICKET PRICES"<<setw(18)<<right<<"**"<<endl;
	if(no_of_tickets_adults > 0)
	{
		if(select_class==1)
		{
			if(way==1)
            cout<<setw(12)<<left<<"**"<<setw(2)<<left<<no_of_tickets_adults<<setw(20)<<left<<" ADULT SEAT COST Rs"<<setw(14)<<left<<adultB1<<setw(10)<<right<<"**"<<endl; 
			if(way==2)
			cout<<setw(12)<<left<<"**"<<setw(2)<<left<<no_of_tickets_adults<<setw(20)<<left<<" ADULT SEAT COST Rs"<<setw(14)<<left<<adultB2<<setw(10)<<right<<"**"<<endl;
		}
		if(select_class==2)
		{
			if(way==1)	
			cout<<setw(12)<<left<<"**"<<setw(2)<<left<<no_of_tickets_adults<<setw(20)<<left<<" ADULT SEAT COST Rs"<<setw(14)<<left<<adultE1<<setw(10)<<right<<"**"<<endl;	
			if(way==2)
			cout<<setw(12)<<left<<"**"<<setw(2)<<left<<no_of_tickets_adults<<setw(20)<<left<<" ADULT SEAT COST Rs"<<setw(14)<<left<<adultE2<<setw(10)<<right<<"**"<<endl;
		}
	}
    if(no_of_tickets_children > 0)
	{
    	if(select_class==1)
		{
			if(way==1)
			cout<<setw(12)<<left<<"**"<<setw(2)<<left<<no_of_tickets_children<<setw(20)<<left<<" CHILD SEAT COST Rs"<<setw(14)<<left<<childB1<<setw(10)<<right<<"**"<<endl; 
			if(way==2)
			cout<<setw(12)<<left<<"**"<<setw(2)<<left<<no_of_tickets_children<<setw(20)<<left<<" CHILD SEAT COST Rs"<<setw(14)<<left<<childB2<<setw(10)<<right<<"**"<<endl;
		}
		if(select_class==2)
		{
			if(way==1)
			cout<<setw(12)<<left<<"**"<<setw(2)<<left<<no_of_tickets_children<<setw(20)<<left<<" CHILD SEAT COST Rs"<<setw(14)<<left<<childE1<<setw(10)<<right<<"**"<<endl;
			if(way==2)
			cout<<setw(12)<<left<<"**"<<setw(2)<<left<<no_of_tickets_children<<setw(20)<<left<<" CHILD SEAT COST Rs"<<setw(14)<<left<<childE2<<setw(10)<<right<<"**"<<endl;
		}
	}
	if(no_of_tickets_infants > 0)
	{
		if(select_class==1)
		{
			if(way==1)
			cout<<setw(12)<<left<<"**"<<setw(2)<<left<<no_of_tickets_infants<<setw(21)<<left<<" INFANTS SEAT COST Rs"<<setw(14)<<left<<infantB1<<setw(9)<<right<<"**"<<endl;
    		if(way==2)
    		cout<<setw(12)<<left<<"**"<<setw(2)<<left<<no_of_tickets_infants<<setw(21)<<left<<" INFANTS SEAT COST Rs"<<setw(14)<<left<<infantB2<<setw(9)<<right<<"**"<<endl;
		}
		if(select_class==2)
		{
			if(way==1)
			{
			cout<<setw(12)<<left<<"**"<<setw(2)<<left<<no_of_tickets_infants<<setw(21)<<left<<" INFANTS SEAT COST Rs"<<setw(14)<<left<<infantE1<<setw(9)<<right<<"**"<<endl;
			}
    		if(way==2)
			{
			cout<<setw(12)<<left<<"**"<<setw(2)<<left<<no_of_tickets_infants<<setw(21)<<left<<" INFANTS SEAT COST Rs"<<setw(14)<<infantE2<<setw(9)<<right<<"**"<<endl;
			}
		}		
	}
	if(select_class==1)
	{
    cout<<setw(12)<<left<<"**"<<setw(13)<<left<<"TOTAL COST Rs"<<setw(20)<<left<<total_pay_business<<setw(13)<<right<<"**"<<endl;
	cost=total_pay_business;
	}
	if(select_class==2)
	{
    cout<<setw(12)<<left<<"**"<<setw(13)<<left<<"TOTAL COST Rs"<<setw(20)<<left<<total_pay_economy<<setw(13)<<right<<"**"<<endl;
	cost=total_pay_economy;
	}
	cout<<"**______________________________________________________**"<<endl<<endl<<endl;

}

void onewaytickets()
{
	if(no_of_tickets_adults > 0)
	{
	    for(int i=0; i<no_of_tickets_adults; i++)
	    {
	        cout<<"**********************************************************"<<endl;
	        cout<<setw(6)<<left<<"*"<<setw(16)<<"NAME:"<<setw(16)<<"FLIGHT:"<<setw(19)<<"DATE:"<<"*"<<endl;
	        cout<<setw(6)<<left<<"*"<<setw(16)<<passenger_names_adults[i]<<setw(16)<<plane_type<<setw(19)<<departure_date<<"*"<<endl;
	        cout<<"*"<<setw(57)<<right<<"*"<<endl;
	        cout<<setw(6)<<left<<"*"<<setw(11)<<depart_country<<setw(23)<<"------------------>>"<<setw(17)<<arrival_country<<"*"<<endl;
	        cout<<"*"<<setw(57)<<right<<"*"<<endl;
	        cout<<setw(6)<<left<<"*"<<setw(15)<<"TIME"<<setw(26)<<"CLASS"<<setw(11)<<right<<"*"<<endl;
	        cout<<setw(6)<<left<<"*"<<setw(15)<<departure_time<<setw(26)<<ticket_class<<setw(11)<<right<<"*"<<endl;
	        cout<<"*"<<setw(57)<<right<<"*"<<endl;
	        cout<<"**********************************************************"<<endl<<endl;	
	    } 	
	}
	if(no_of_tickets_children > 0)
	{
	    for(int i=0; i<no_of_tickets_children; i++)
	    {
	        cout<<"**********************************************************"<<endl;
			cout<<setw(6)<<left<<"*"<<setw(16)<<"NAME:"<<setw(16)<<"FLIGHT:"<<setw(19)<<"DATE:"<<"*"<<endl;
			cout<<setw(6)<<left<<"*"<<setw(16)<<passenger_names_children[i]<<setw(16)<<plane_type<<setw(19)<<departure_date<<"*"<<endl;
			cout<<"*"<<setw(57)<<right<<"*"<<endl;
			cout<<setw(6)<<left<<"*"<<setw(11)<<depart_country<<setw(23)<<"------------------>>"<<setw(17)<<arrival_country<<"*"<<endl;
			cout<<"*"<<setw(57)<<right<<"*"<<endl;
			cout<<setw(6)<<left<<"*"<<setw(15)<<"TIME"<<setw(26)<<"CLASS"<<setw(11)<<right<<"*"<<endl;
			cout<<setw(6)<<left<<"*"<<setw(15)<<departure_time<<setw(26)<<ticket_class<<setw(11)<<right<<"*"<<endl;
			cout<<"*"<<setw(57)<<right<<"*"<<endl;
			cout<<"**********************************************************"<<endl<<endl;	
		}	
	}
	if(no_of_tickets_infants > 0)
	{
		for(int i=0; i<no_of_tickets_infants; i++)
		{
			cout<<"**********************************************************"<<endl;
			cout<<setw(6)<<left<<"*"<<setw(16)<<"NAME:"<<setw(14)<<"FLIGHT:"<<setw(19)<<"DATE:"<<"*"<<endl;
			cout<<setw(6)<<left<<"*"<<setw(16)<<passenger_names_infants[i]<<setw(14)<<plane_type<<setw(19)<<departure_date<<"*"<<endl;
			cout<<"*"<<setw(57)<<right<<"*"<<endl;
			cout<<setw(6)<<left<<"*"<<setw(11)<<depart_country<<setw(23)<<"------------------>>"<<setw(17)<<arrival_country<<"*"<<endl;
			cout<<"*"<<setw(57)<<right<<"*"<<endl;
			cout<<setw(6)<<left<<"*"<<setw(15)<<"TIME"<<setw(26)<<"CLASS"<<setw(11)<<right<<"*"<<endl;
			cout<<setw(6)<<left<<"*"<<setw(15)<<departure_time<<setw(26)<<ticket_class<<setw(11)<<right<<"*"<<endl;
			cout<<"*"<<setw(57)<<right<<"*"<<endl;
			cout<<"**********************************************************"<<endl<<endl;	
		}	
	}
}

void returntickets()
	{
	    if(no_of_tickets_adults > 0)
	    {
		    for(int i=0; i<no_of_tickets_adults; i++)
		    {
		        cout<<"**********************************************************"<<endl;
	            cout<<setw(6)<<left<<"*"<<setw(16)<<"NAME:"<<setw(16)<<"FLIGHT:"<<setw(19)<<"DATE:"<<"*"<<endl;
	            cout<<setw(6)<<left<<"*"<<setw(16)<<passenger_names_adults[i]<<setw(16)<<return_plane_type<<setw(19)<<return_date<<"*"<<endl;
	            cout<<"*"<<setw(57)<<right<<"*"<<endl;
	            cout<<setw(6)<<left<<"*"<<setw(11)<<arrival_country<<setw(23)<<"------------------>>"<<setw(17)<<depart_country<<"*"<<endl;
	            cout<<"*"<<setw(57)<<right<<"*"<<endl;
	            cout<<setw(6)<<left<<"*"<<setw(15)<<"TIME"<<setw(26)<<"CLASS"<<setw(11)<<right<<"*"<<endl;
	            cout<<setw(6)<<left<<"*"<<setw(15)<<return_time<<setw(26)<<ticket_class<<setw(11)<<right<<"*"<<endl;
	            cout<<"*"<<setw(57)<<right<<"*"<<endl;
	            cout<<"**********************************************************"<<endl<<endl;	
	        } 	
	    }
	    if(no_of_tickets_children > 0)
	    {
	        for(int i=0; i<no_of_tickets_children; i++)
			{
	            cout<<"**********************************************************"<<endl;
	            cout<<setw(6)<<left<<"*"<<setw(16)<<"NAME:"<<setw(16)<<"FLIGHT:"<<setw(19)<<"DATE:"<<"*"<<endl;
	            cout<<setw(6)<<left<<"*"<<setw(16)<<passenger_names_children[i]<<setw(16)<<return_plane_type<<setw(19)<<return_date<<"*"<<endl;
	            cout<<"*"<<setw(57)<<right<<"*"<<endl;
	            cout<<setw(6)<<left<<"*"<<setw(11)<<arrival_country<<setw(23)<<"------------------>>"<<setw(17)<<depart_country<<"*"<<endl;
	            cout<<"*"<<setw(57)<<right<<"*"<<endl;
	            cout<<setw(6)<<left<<"*"<<setw(15)<<"TIME"<<setw(26)<<"CLASS"<<setw(11)<<right<<"*"<<endl;
	            cout<<setw(6)<<left<<"*"<<setw(15)<<return_time<<setw(26)<<ticket_class<<setw(11)<<right<<"*"<<endl;
	            cout<<"*"<<setw(57)<<right<<"*"<<endl;
	            cout<<"**********************************************************"<<endl<<endl;	
	        }	
	    }
	    if(no_of_tickets_infants > 0)
		{
	        for(int i=0; i<no_of_tickets_infants; i++)
			{
	            cout<<"**********************************************************"<<endl;
	            cout<<setw(6)<<left<<"*"<<setw(16)<<"NAME:"<<setw(16)<<"FLIGHT:"<<setw(19)<<"DATE:"<<"*"<<endl;
	            cout<<setw(6)<<left<<"*"<<setw(16)<<passenger_names_infants[i]<<setw(16)<<return_plane_type<<setw(19)<<return_date<<"*"<<endl;
	            cout<<"*"<<setw(57)<<right<<"*"<<endl;
	            cout<<setw(6)<<left<<"*"<<setw(11)<<arrival_country<<setw(23)<<"------------------>>"<<setw(17)<<depart_country<<"*"<<endl;
	            cout<<"*"<<setw(57)<<right<<"*"<<endl;
	            cout<<setw(6)<<left<<"*"<<setw(15)<<"TIME"<<setw(26)<<"CLASS"<<setw(11)<<right<<"*"<<endl;
	            cout<<setw(6)<<left<<"*"<<setw(15)<<return_time<<setw(26)<<ticket_class<<setw(11)<<right<<"*"<<endl;
	            cout<<"*"<<setw(57)<<right<<"*"<<endl;
	            cout<<"**********************************************************"<<endl<<endl;	
	        }	
	    }
    }

	void ticketprint()
	{
	    cout<<"#######################---TICKETS---#######################"<<endl<<endl;
	    if(way==1)
		{
	        cout<<"----------------------ONE WAY TICKETS----------------------"<<endl;
	        onewaytickets();	
	    }
	    if(way==2)
	    {
	        cout<<"----------------------TWO WAY TICKETS----------------------"<<endl<<endl;
	        cout<<"----------------------GOING  TICKETS-----------------------"<<endl;
	        onewaytickets();
	        cout<<"----------------------RETURN TICKETS----------------------"<<endl;
	        returntickets();
	    }	
	}


void thankyou() 
{
    int width = 80; 
    int height = 20; 

    for (int i = 0; i < width; ++i) 
	{
        cout << "*";
    }
    cout << endl;
    for (int i = 0; i < width; ++i) 
	{
        cout << "*";
    }
	cout <<endl;
    for (int i = 0; i < height/2; ++i) 
	{
	cout <<"****"<<setw(width-4)<< "****"<<endl;
    }
    cout <<"****"<<setw(54)<<"Thank You! PLease keep visiting us."<<setw(22)<< "****"<<endl;
    cout <<"****"<<setw(54)<<"Records are saved in 'Record.xlsx'."<<setw(22)<< "****"<<endl;
    for (int i = 0; i < height/2; ++i) 
	{
	cout <<"****"<<setw(width-4)<< "****"<<endl;
    }
    for (int i = 0; i < width; ++i) 
	{
        cout << "*";
    }
    cout << endl;
    for (int i = 0; i < width; ++i) 
	{
        cout << "*";
    }
	
}

int main()
{
	string name,number,email,time,departure,Seat_class,Arrival,dep_date,arr_date="Nill",aircraft_name;
	int age,cost,child,infant,Way;
	welcome() ;
	system("pause") ;
	system("cls") ;
    registration(departure,name,number,email,age,child,infant,Way,time,Seat_class,Arrival,dep_date,arr_date,aircraft_name) ;
    system("cls") ;
    details(cost) ;
    system("pause") ;
    system("cls") ;
    ticketprint() ;
    system("pause") ;
    system("cls") ;
    thankyou() ;
    rec<<name<<"\t"<<age<<"\t"<<number<<"\t"<<email<<"\t"<<departure<<"\t"<<Arrival<<"\t"<<Way<<"\t"<<aircraft_name<<"\t"<<dep_date<<"\t"<<arr_date<<"\t"<<time<<"\t"<<Seat_class<<"\t"<<child<<"\t"<<infant<<"\t"<<cost<<endl;
    cout<<endl;
	system("PAUSE");
	return 0 ;
}

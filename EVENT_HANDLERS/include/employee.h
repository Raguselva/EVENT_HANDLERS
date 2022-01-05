// For employee to update his/her status
void update_status(char *,int,char *);

// For employee to say to receptionist to where to keep the parcel
void update_parcelInfo(char *,char *);

// Replies with what to do for the guest
void reply(char *);
//Actions to be taken by the employee for the guest
void visitor1();
void delivery1();
void caller1();
void visitor2();
void delivery2();
void caller2();
void visitor3();
void delivery3();
void caller3();
void register_with_receptionist(Teams *);
void set_service_status(char *);


//void (*my_actions[]) () = {caller,delivery,visitor};
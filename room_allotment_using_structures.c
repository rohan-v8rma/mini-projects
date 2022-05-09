#include <stdio.h>

struct STUDENT {
    //student details to be read
    int reg_no;
    int date_of_arrival;

    //variables for automated room allotment
    char block;
    int room_no;
};

int read_student_details(int index, struct STUDENT master_list[5000]) {
    /*
    Since array names themselves are pointers, they are passed by reference automatically 
    and any changes we make to them within the program are on the main copy of the array.
    */

    int reg_no;
    printf("Registration number: ");
    scanf("%d", &reg_no); 
    
    //! here, we are assuming that every candidate will enter unique number and 
    //! we haven't added any safeguard against duplicates

    int date_of_arrival;
    printf("Date of arrival: ");
    scanf("%d", &date_of_arrival);

    master_list[index].reg_no = reg_no;
    master_list[index].date_of_arrival = date_of_arrival;
}

int allot_room(int index, struct STUDENT master_list[5000], char *block, int *room_no) {
    
    if (*room_no > 1000) {
        if (*block >= 'e') {
            printf("Sorry, all rooms are full.");
        }
        else {
            *block += 1;
            *room_no == 1;
        };
    };

    master_list[index].block = *block;
    master_list[index].room_no = *room_no;
    
    *room_no += 1;
};

int detail_extractor(struct STUDENT master_list[5000]) {
    int reg_no;
    
    printf("Registration number of student: ");
    scanf("%d", &reg_no);

    for(int index = 0; index < 5000; index++) {
        if (master_list[index].reg_no == reg_no) {
            printf(
            "Student details are: \n\
            Date of arrival: %d \n\
            Block: %c \n\
            Room number: %d \n\
            ", master_list[index].date_of_arrival, master_list[index].block, master_list[index].room_no);
        };
    }
}

int main() {
    struct STUDENT master_list[5000];

    int option = -1;
    char block = 'a';
    int room_no = 1;
    int index = 0;

    while(option != 0) {
        char *option_text = 
        
        "Enter an integer value as an option: \n\
        0. Exit \n\
        1. Read student details \n\
        2. Detail inquiry \n >>> ";
        
        printf("%s", option_text);
        scanf("%d", &option);
        
        if (option == 1) {
            read_student_details(index, master_list);
            
            //running the function for room allotment.
            allot_room(index, master_list, &block, &room_no);

            index += 1;
        }
        else if (option == 2) {
            detail_extractor(master_list);
        }
        else if (option == 0) {
            break;
        };   
    }
}
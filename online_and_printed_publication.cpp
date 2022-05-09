#include <iostream>
using namespace::std;

class article {
    public:
        char articleTitle[50];
        char author[50];
        int y_of_publication;
};

class bookArticle : public article {
    public: 
        int ISBN_no;
        int chap_no;
        int starting_page_no;
        int ending_page_no;

        bookArticle(int A, int B, int C, int D) {
            ISBN_no = A;
            chap_no = B;
            starting_page_no = C;
            ending_page_no = D;
        };

        void calculate_charge() {
            int publication_charge = (1000 * (ending_page_no - starting_page_no + 1));
            printf("The publication charge is %d\n", publication_charge);
        };

};

class onlineArticle : public article {
    public: 
        int eISBN_no;
        int volume_no;
        int no_of_pages;

        void calculate_charge() {
            int publication_charge = (5000 * (no_of_pages / 3));
            printf("The publication charge is %d\n", publication_charge);
        };

        onlineArticle(int A, int B, int C) {
            eISBN_no = A;
            volume_no = B;
            no_of_pages = C;
        };
};

int main() {
    bookArticle food_science(1122, 2, 245, 268);
    food_science.calculate_charge();


    onlineArticle dangers_of_social_media(1123, 17, 30);
    dangers_of_social_media.calculate_charge();

    return 0;
}
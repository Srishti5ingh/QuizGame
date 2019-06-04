#include <bits/stdc++.h> // To include any header file needed
//#include<iostream>
//#include<fstream>
//#include<cstring>
//#include<sstream>
//#include<string>
//#include<iomanip>
//#include<cmath>

using namespace std;

#define MAX_CHAR 100
#define MAX_QUESTIONS 30
void category_wise_marks();

// Global variables to be used in different scopes
string cat;
string ques;
string options [4];
int ans;
string CATEGORY_NAMES[4] = {"Music", "Sports", "GK", "Misc"};
int category_score[4] = {0, 0, 0, 0};

struct question_bank
{
    string category;
    string qstatement;
    string options[4];
    int answer_pos;
};

   struct players_qbank
{
    string category;
    string qstatement;
    string user_ans;
    string correct_ans;
    int m;
};

struct players_qbank pq [10]; // Questions that appears for the player

int main()
{

    struct question_bank q[MAX_QUESTIONS];
    //struct players_qbank pq [10];
    int correct_ans_count =0; int wrong_ans_count = 0;
    ifstream fin;
    string line;

    // Opening the text file, reading the data line by line and storing it in structure question_bank variables
    // The delimiter used here is space but can be changed to any other character, like "|"

    fin.open("qdata.txt");

    for (int i =0; i <MAX_QUESTIONS && !fin.eof(); i++)
    {
        getline(fin, line);
        istringstream ss(line);
        ss >> cat >> ques >> options[0] >> options[1]>> options[2] >> options[3] >> ans;

        q[i].category = cat;
        q[i].qstatement = ques;
        q[i].options[0] = options[0];
        q[i].options[1] = options[1];
        q[i].options[2] = options[2];
        q[i].options[3] = options[3];
        q[i].answer_pos = ans;
    }

    fin.close();

cout<<endl << endl << "***************************************** Your Quiz Has Started *************************************************"<<endl<<endl << endl;

    for (int i=0; i<10; i++)
    {
        // Initializing random number generator
        time_t t;
        srand((unsigned) time(&t));
        int n= t%10;

        pq[i].category = q[n].category; pq[i].qstatement = q[n].qstatement; pq[i].correct_ans = q[n].options[q[n].answer_pos];

        cout<<"Category:    "<< q[n].category<< endl;
        cout<<"Q" << i+1 << "   "<< q[n].qstatement<<endl;
        cout<<q[n].options[0] <<endl << q[n].options[1] << endl <<q[n].options[2] << endl <<q[n].options[3] << endl << endl;

        cout<< "Enter your answer:    ";
        cin>>pq[i].user_ans;

        if ( pq[i].user_ans == q[n].options[q[n].answer_pos])
            {
                pq[i].m = 1;
                correct_ans_count = correct_ans_count + 1;
                cout<<"Correct answer!!"<<endl << endl;
            }
        else
        {
            pq[i].m = 0;
            wrong_ans_count = wrong_ans_count + 1 ;
            cout<< "Wrong answer!"<< endl <<endl;
        }
    }

    int q_attempted = correct_ans_count + wrong_ans_count;


////Printing the final Outcome
    cout<< endl<< endl << "******************************************* Your Results *****************************************************"<< endl << endl<<endl;
    for (int i=0; i<10; i++)
    {
        cout<<"Question Category:   " << pq[i].category<< endl << "Question:    " << pq[i].qstatement << endl;
        cout<< "Correct Answer:   " << pq[i].correct_ans << endl;
        cout<< "Your Answer:    " << pq[i].user_ans << endl << "Marks Awarded:    " << pq[i].m << endl << endl << endl;
    }


////Printing Category-wise marks
cout<< endl << "************************************* Category-wise Marks *************************************************"<<endl<<endl;
category_wise_marks();



cout<< "************************************* YOUR FINAL SCORE: " << correct_ans_count << " out of " << q_attempted<< " ***********************************" << endl << endl << endl << endl;

return 0;

} // main() closed


void category_wise_marks()
 {

    for( int j=0; j<10; j++)
    {
        if (pq[j].category == CATEGORY_NAMES[0])
        {
             category_score[0] = category_score[0] + pq[j].m;
        }
        else if (pq[j].category == CATEGORY_NAMES[1])
        {
            category_score[1] = category_score[1] + pq[j].m;
        }

        else if (pq[j].category == CATEGORY_NAMES[2])
        {
            category_score[2] = category_score[2] + pq[j].m;
        }
        else
        {
            category_score[3] = category_score[3] + pq[j].m;
        }

    } // first for loop closed

        for (int j =0; j<4; j++)
        {
                cout << "Category:    " << CATEGORY_NAMES[j] << endl;
                cout << "Your Score:    " << category_score[j] <<endl <<endl << endl;
        }

 } //Function category_wise_marks closed


 //// *** This program does not include dummy functions or functions that gives user the options to start or exit the game, these modifications can be added if need be.


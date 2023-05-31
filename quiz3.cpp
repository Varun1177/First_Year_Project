#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>
#include <stdlib.h>
#include <windows.h>
#include <cwchar>
#include <mmsystem.h>



class Question {
public:
    int askQuestion(int num = -1);
    friend std::istream& operator >> (std::istream& is, Question& ques);

private:
    std::string question_text;
    std::string answer_1;
    std::string answer_2;
    std::string answer_3;
    std::string answer_4;
    char correct_answer;
};

void PrintArt(std::ifstream myfile);
void InititializeQuizGame(std::ifstream data);
void load(std::istream& is, std::vector<Question>& questions);
void Shuffle(std::vector<Question>& questions);
void PrintResults(std::vector<Question>& questions);
void close();
void displayFileContent(const std::string& filename);
using namespace std;


int main()
{   

    int a,b,c,d;
    system("CLS");

    cout<<"\t\t\t\t\t\t";
    string S = "\033[31;1;4mWELCOME TO QUIZ GAME";

    for (int i = 0; i < S[i]; i++) {
  
        cout << S[i];
  
        Sleep(100);
    }
    cout<<"\n\n";
    cout<<"LOADING: ";

    for(int i = 5; i > 0 ; i--){
        cout<<"..."<< i ;
        Sleep(1000);
    }
    
    
    cout<<"\033[0m";

    start:

    system("CLS");
    cout<<"\033[31;1;5m";
    cout<<"\t\t\t\t\t\t\t  START\n";
    cout<<"\033[0m";
    cout<<"\t\t\t\t\t\t(Enter 1 To Start The Quiz)\n";

    cout<<"\033[31;1;5m";
    cout<<"\t\t\t\t\t\t\t  ABOUT\n";
    cout<<"\033[0m";
    cout<<"\t\t\t\t\t   (Enter 2 For Additional Information)\n";

    cout<<"\033[31;1;5m";
    cout<<"\t\t\t\t\t\t\t  EXIT \n";
    cout<<"\033[0m";
    cout<<"\t\t\t\t\t   (Enter 3 For To Close The Application)\n";

    cout<<"\033[31;1;5m";
    cout<<"\n\n\n\t\t\t\t\t\t\t  INPUT \n";
    cout<<"\033[0m";
    cout<<"\t\t\t\t\t\t\t    ";
    cin>>a;

    if(a==1){

        W:

        system("CLS");

        cout<<"\033[31;1;5m";
        cout<<"\t\t\t\t\t\t\t CATEGORY \n";
        cout<<"\033[0m";

        cout<<"\033[31;1;5m";
        cout<<"\t\t\t\t\t\t     PREVIOUS SCORES \n";
        cout<<"\033[0m";

        cout<<"\033[31;1;5m";
        cout<<"\t\t\t\t\t\t\t   EXIT \n";
        cout<<"\033[0m";


        cout<<"\033[31;1;5m";
        cout<<"\n\n\n\t\t\t\t\t\t\t  INPUT \n";
        cout<<"\033[0m";
        cout<<"\t\t\t\t\t\t\t    ";
        cin>>b;

        if(b==1){

            system("CLS");

                int x;
            cout<<"\033[31m";
            std::cout<<"\n\nENTER THE QUIZ CATEGORY: "<<std::endl;
            cout<<"\033[0m";
            cout<<"\033[96m";
            std::cout<<"PRESS 1 FOR SPORTS: "<<std::endl;
            std::cout<<"PRESS 2 FOR ENVIRONMENTAL: "<<std::endl;
            std::cout<<"PRESS 3 FOR ENTERTAINMENT: "<<std::endl;
            std::cout<<"PRESS 4 FOR C PROGRAMMING: "<<std::endl;
            std::cout<<"PRESS 5 TO EXIT THE PROGRAM: "<<std::endl;
            std::cin>>x;
            cout<<"\033[0m";

        switch (x)
            {
        case 1:
            InititializeQuizGame(std::ifstream("sports.txt"));
        break;

        case 2:
            InititializeQuizGame(std::ifstream("environmental.txt"));
        break;

        case 3:
            InititializeQuizGame(std::ifstream("entertainment.txt"));
        break;

        case 4:
            InititializeQuizGame(std::ifstream("programming.txt"));
        break;

        case 5: 
             close();      

        default:
            break;
            }

        }

        else if(b==2){
            displayFileContent("quiz_score.txt"); 
        }

        else if(b==3){
            close();
        }


    }

    else if(a==2){
        system("CLS");
        cout<<"PRESS 1 TO RETURN BACK\n";
        Q:
        cin>>c;
        if(c==1){
        goto start;
        }
        else{
            cout<<"INVALID INPUT PLEASE TRY AGAIN\n";
            goto Q;
        }
    }

    else if(a==3){
        close();
    }

    return 0;
}

void InititializeQuizGame(std::ifstream data)
{
    if (data.is_open())
    {
        std::vector<Question> questions;
        load(data, questions);
        Shuffle(questions);
        PrintResults(questions);
        
    }
    else
    {
        std::cout << "Error: File not found!\n";
    }
    std::cin.get();
}

std::istream& operator >> (std::istream& is, Question& ques)
{
    std::string line;
    while (std::getline(is, line))
    {
        if (line.size() == 0)
            continue;
        break;
    }

    ques.question_text = line;
    getline(is, ques.answer_1);
    getline(is, ques.answer_2);
    getline(is, ques.answer_3);
    getline(is, ques.answer_4);
    is >> ques.correct_answer;
    return is;
}

void load(std::istream& is, std::vector<Question>& questions)
{
    Question q;
    while (is >> q)
        questions.push_back(q);
}

int Question::askQuestion(int num) //Ask the question. 
{
    system("CLS");

    int score = 0;
    if (num > 0)
    std::cout << num << ".) ";
    std::cout << question_text << "\n";
    std::cout << "a. " << answer_1 << "\n";
    std::cout << "b. " << answer_2 << "\n";
    std::cout << "c. " << answer_3 << "\n";
    std::cout << "d. " << answer_4 << "\n";

    //Ask user for their answer.
    char guess = ' ';
    //PositionCursor();
    std::cout << "What is your answer?\n";;
    std::cin >> guess;

    if (guess == correct_answer) {
        std::cout << "Correct!\n";;
        score = 10;
        std::cin.get();
        std::cin.get();
    }
    else
    {
        std::cout << "Incorrect, the correct answer was " << correct_answer << ".\n";
        std::cin.get();
        std::cin.get();
    }
    return score;
}

void Shuffle(std::vector<Question>& questions) //Shuffle the questions. 
{
    std::random_device rd;
    std::mt19937 randomGenerator(rd());
    std::shuffle(questions.begin(), questions.end(), randomGenerator);
}

void PrintResults(std::vector<Question>& questions)
{
    int total = 0; //Total score.
    char name[20];

    //Keep track of score.
    for (size_t i = 0; i < 10; ++i)
    {
        total += questions[i].askQuestion(i + 1);
    }
    //Print Total score.
    //clearScreen();
    if (total >= 60) {
        std::cout << "\n\n";
        std::cout << "You scored " << total << " out of 100!\n";
        //PrintArt(std::ifstream("quiz_passed.txt"));
    }
    else
    {
        std::cout << "You scored " << total << " out of 100....\n";
        std::cout << "Sorry, you failed... Better luck next time.\n";
        //PositionCursor();
    }
    std::cout<<"Enter the name of the person who gave the quiz: "<<std::endl;
    std::cin>>name;

    std::ofstream myfile("quiz_score.txt",std::ios::app);
        if(myfile.is_open())
    {
     myfile << " NAME: " << name << "| SCORE: " << total <<"\n";
     myfile.close();
    }
    
    std::cout<<"5";
    Sleep(1000);
    std::cout<<"...4";
     Sleep(1000);
    std::cout<<"...3";
     Sleep(1000);
    std::cout<<"...2";
     Sleep(1000);
    std::cout<<"...1";
     Sleep(1000);
    main();

}

void close(){
    exit(0);
}

void displayFileContent(const std::string& filename) {

    system("CLS");

    std::ifstream file(filename); // Open the file for reading

    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    Sleep(5000);

    file.close(); // Close the file

    main();
}

void PositionCursor()
{
    std::cout << std::string(10, '\n');
}
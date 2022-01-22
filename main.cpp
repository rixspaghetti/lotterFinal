// worked with Zachary Vollmer

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
    using namespace std;

    vector<int> getNumbers();
    void setPowerBall(vector<int>&);
    void showNumbers(const vector<int>& v);


    int main()
    {
        cout << "You feeling lucky?" << endl; // tst
        char generate;
        // seed random gen within file
        srand(time(NULL));
        do
        {
            // asks for number of lotto numbers
            cout << "How many lotto numbers do you wanna generate?";
            int lottoNum;
            cin >> lottoNum;
            bool again = true;
            vector<int> numbers;

            //loop to get set of numbers
            // up to user how many times
            for(int i = 0; i < lottoNum && again; i++)
            {
                // populates
                numbers = getNumbers();
                // gets power ball
                setPowerBall(numbers);
                //prints
                showNumbers(numbers);


            }
            cout << "Do you wanna generate another set of numbers? --> y --> n :";

            cin >> generate;
        }while(generate == 'y');




    }
// function to get numbers
    vector<int> getNumbers()
    {
        //make a vector
        vector<int> numbers;
        // loops through vector
        for(int i = 0; i <= 4; i++)
        {
            numbers.push_back(rand() % 69 + 1);
            if(i != 0)
            {
                // no duplicates so while 1 num == another num generate another rand
                while (numbers.at(i) == numbers.at(i -1 ))
                {
                    cout << "you have a match" << endl;
                    numbers.at(i) = rand() % 69 + 1;
                }
            }
        }

        // sort numbers least to greatest
        sort(numbers.begin(), numbers.end());

        return numbers;
    }


// function to get power ball number
    void setPowerBall(vector<int> & numbers)
    {
        // creates rand num for power ball
        // from 1 to 26 inclusive
        numbers.push_back(rand() % 26 + 1);


    }
// function that prints out numbers
    void showNumbers(const vector<int>& numbers)
    {
        // print numbers
        //loops through vector
        for(int i = 0; i < numbers.size(); i++)
        {
            // 6th number is  power ball
            if (i == 5)
            {
                cout << " Powerball: ";
            }
            cout << numbers.at(i) << " ";

        }
        cout << endl;
    }




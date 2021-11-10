# include <bits/stdc++.h>
using namespace std;


int CheckFormat(){
    int a;
    cout << "1. T20\n"
         << "2. ODI\n"
         << "Choose format: ";
    cin >> a;

    switch(a){
        case 1:
        return 20;
        break;

        case 2:
        return 50;
        break;

        default:
        return 0;
        break;
    }
}

class RunStuffs{
    public:
    void RunRate(){
        int a, b;

        a = CheckFormat();
        if(a==0){
            cout << "\nEnter a valid option Idiot!" << "\n\n";
            return;
        }

        cout << "\nEnter the total runs scored by the team: ";
        cin >> b;

        cout << "Run Rate is: " << fixed << setprecision(2) << (float)b/a << "\n\n";
    }

    void CurrentRunRate(){
        int a;
        float b;
        cout << "Enter total runs scored till now: ";
        cin >> a;
        cout << "Enter total over played till now: ";
        cin >> b;
        cout << "Current Run Rate is: " << fixed << setprecision(2) << (float)a/b << "\n\n";
    }

    void NetRunRate(){
        int a, b;
        float k, l;
        cout << "Enter total run scored by your team in the league: ";
        cin >> a;
        cout << "Enter total over played by your team in the league: ";
        cin >> k;
        cout << "Total number of runs scored by oppenents team against your team: ";
        cin >> b;
        cout << "Total number of overs played by opponents team against your team: ";
        cin >> l;

        float nrr = ((a/k)-(b/l));
        if(nrr<=0){
            cout << "Net Run Rate is: " << fixed << setprecision(2) << nrr << "\n\n";
            return;
        }
        cout << "Net Run Rate is: " << fixed << setprecision(2) << '+' << nrr << "\n\n";
    }

    void RequiredRunRate(){
        int a, b, c;
        float d;

        a = CheckFormat();
        if(a==0){
            cout << "\nEnter a valid option Idiot!" << "\n\n";
            return;
        }

        cout << "Enter the target: ";
        cin >> b;
        cout << "Enter total runs scored till now: ";
        cin >> c;
        cout << "Enter total overs played till now: ";
        cin >> d;

        cout << "Required Run Rate is: " << fixed << setprecision(2) << (float)(b-c)/(a-d) << "\n\n";
    }

    void ProjectedScore(){
        int f = CheckFormat();
        if(f==0){
            cout << "\nEnter a valid option Idiot!" << "\n\n";
            return;
        }

        int a, b;
        float k, l;
        cout << "Enter total runs scored till now: ";
        cin >> a;
        cout << "Enter total overs played till now: ";
        cin >> k;

        cout << "Projected Score:"
             << "\n1.  8/over: " << (a+((f-k)*8))
             << "\n2. 10/over: " << (a+((f-k)*10))
             << "\n3. 12/over: " << (a+((f-k)*12)) << "\n\n";
    }
};

class BatsmanStuffs{
    public:
    void StrikeRate(){
        int a, b;
        cout << "Enter the number of runs scored: ";
        cin >> a;
        cout << "Enter the numbers of balls faced: ";
        cin >> b;

        cout << "Strike Rate: " << fixed << setprecision(2) << (float)(a/b)*100 << "\n\n";
    }
};

class BowlerStuffs{
    public:
    void BowlerAvg(){
        int a, b;
        cout << "Enter the numbers of runs conceded: ";
        cin >> a;
        cout << "Enter the numbers of wickets taken: ";
        cin >> b;
        
        cout << "Bowler Average: " << fixed << setprecision(2) << (float)(a/b) << "\n\n";
    }
};

class CricketCalculator : public RunStuffs, public BatsmanStuffs, public BowlerStuffs{
    public:
    void ShowStuff(){
        int a;
        cout << "\n1. Run Rate             2. Current Run Rate      "
             << "3. Net Run Rate\n"
             << "4. Required Run Rate    "
             << "5. Projected Score       " 
             << "6. Strike Rate\n"
             << "7. Bowler Average        "
             << "8. Exit\n"
             << "Choose one option from the following: ";
        cin >> a;

        switch(a){
            case 1:
            cout << "\nCalculating Run Rate:\n";
            RunRate();
            break;

            case 2:
            cout << "\nCalculating Current Run Rate:\n";
            CurrentRunRate();
            break;

            case 3:
            cout << "\nCalculating Net Run Rate:\n";
            NetRunRate();
            break;

            case 4:
            cout << "\nCalculating Required Run Rate:\n";
            RequiredRunRate();
            break;

            case 5:
            cout << "\nCalculating Projected Score:\n";
            ProjectedScore();
            break;

            case 6:
            cout << "\nCalculating Strike Rate:\n";
            StrikeRate();
            break;

            case 7:
            cout << "\nCalculating Bowler Average:\n";
            BowlerAvg();
            break;

            case 8:
            return;

            default:
            cout << "\nEnter a valid option!\n\n";
            break;
        }
        char b;
        cout << "Type y to go main menu or type anything to exit: ";
        cin >> b;
        if(b!='y'){
            return;
        ShowStuff();
        }
    }
};
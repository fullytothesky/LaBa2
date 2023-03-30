#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>
#include "bibl.h"
using namespace std;
struct TVshow {
    string name;
    int time_start;
    int time_end;
    int minute_start;
    int minute_end;
    int time_show;
};


int main() {

    TVshow show;
    int choice;
    vector<TVshow> shows;


    cout << "Do you want to add your tv show? 1 - YES  2 - NO\n choose:";
    cin >> choice;
while (choice==1) {


        cout << "enter show name:" << endl;
        cin.ignore();
        getline(cin, show.name);

        cout << "enter hour of start:" << endl;
        cin >> show.time_start;

        cout << "enter minutes of start:" << endl;
        cin >> show.minute_start;

        cout << "enter hour of end:" << endl;
        cin >> show.time_end;

        cout << "enter minutes of end:" << endl;
        cin >> show.minute_end;


        int start_hour, start_min, end_hour, end_min;

        start_hour = show.time_start;

        start_min = show.minute_start;

        end_hour = show.time_end;

        end_min = show.minute_end;
    show.time_show=calculateShowDuration( start_hour,  start_min,  end_hour,  end_min);

        cout << "Duration of show: " << show.time_show << " minutes\n";


        cout << show.time_show<<endl;

    shows.push_back(show);

    cout<<"you want to add more information?1-yes 2 - no:"<<endl;
    cin>>choice;
}


     string help;
    ofstream fileb("binary.bin",  ios::binary);

    if(fileb.is_open()){
        size_t vector_size = shows.size();
        fileb.write(reinterpret_cast<const char*>(&vector_size), sizeof(vector_size));

        // Записуємо кожен об'єкт TVshow
        for (const TVshow& show : shows) {
            fileb.write(reinterpret_cast<const char*>(&show), sizeof(show));
        }
        fileb.close();


    }



    else{
    cerr<<"error opening file"<<endl;
}

    vector<TVshow>newshows;
    ofstream file2("binary2.bin", ios::binary);
    ifstream file("binary.bin");
    if (file.is_open()&&file2.is_open()){
            size_t vector_size;
            file.read(reinterpret_cast<char*>(&vector_size), sizeof(vector_size));


            for (int i = 0; i < vector_size; i++) {
                file.read(reinterpret_cast<char*>(&shows[i]), sizeof(TVshow));
            }

            for (int i = 0; i < shows.size(); i++) {
                cout << "Show #" << i+1 << ":" << endl;
                cout << "Name: " << shows[i].name << endl;
                cout << "Start time: " << shows[i].time_start << ":" << shows[i].minute_start << endl;
                cout << "End time: " << shows[i].time_end << ":" << shows[i].minute_end << endl;
                cout << "Duration: " << shows[i].time_show << " minutes" << endl;
                cout << endl;
                if(shows[i].time_start>=9&&shows[i].time_end<=18){
                    newshows.push_back(shows[i]);
                }
            }

        }

    for(int i=0;i<newshows.size();i++){
        cout << "Show Filtered" << i+1 << ":" << endl;
        cout << "Name: " << newshows[i].name << endl;
        cout << "Start time: " << newshows[i].time_start << ":" << newshows[i].minute_start << endl;
        cout << "End time: " << newshows[i].time_end << ":" << newshows[i].minute_end << endl;
        cout << "Duration: " << newshows[i].time_show << " minutes" << endl;
        cout << endl;
    }
    size_t vector2_size = newshows.size();
    for(int i=0;i<newshows.size();i++){
        file2.write(reinterpret_cast<const char*>(&newshows), sizeof(newshows));
    }
    file2.close();
}
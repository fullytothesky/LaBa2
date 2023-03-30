#include "bibl.h"
using namespace std;
int calculateShowDuration(int start_hour, int start_min, int end_hour, int end_min) {

    auto start = chrono::system_clock::now();// cтворюємо об'єкти часу початку і кінця шоу
    start += chrono::hours(start_hour) + chrono::minutes(start_min);

    auto end = chrono::system_clock::now();
    end += chrono::hours(end_hour) + chrono::minutes(end_min);


    auto duration = chrono::duration_cast<chrono::minutes>(end - start);  // розрахунок часу шоу

    return duration.count();}//
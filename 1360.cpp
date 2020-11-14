class Solution {
public:

    //The condition for a year to be a leap year is: (year2%100 && year2%4==0) || year2%400==0
    int daysBetweenDates(string date1, string date2) {
        
        int year1 = stoi(date1.substr(0,4)), year2 = stoi(date2.substr(0,4));
        int month1 = stoi(date1.substr(5,2)), month2 = stoi(date2.substr(5,2));
        int day1 = stoi(date1.substr(8,2)), day2 = stoi(date2.substr(8,2));

        unordered_map<int,int> monthDays;
        for(int m = 1; m<13;m++){
            
            if(m<=7 && m!=2){
                if(m%2)
                    monthDays[m] = 31;
                else
                    monthDays[m] = 30;
            }
            else if(m!=2){
                if(m%2)
                    monthDays[m] = 30;
                else
                    monthDays[m] = 31;
            }
        }
        monthDays[2] = 28;

        
        int totalDays1 = (year1-1)*365 + (year1-1)/4 - (year1-1)/100 + (year1-1)/400;
        for(int i=1;i<month1;i++)
            totalDays1 += monthDays[i];
        totalDays1 += day1;
        if(month1>2 && ( (year1%100 && year1%4==0) || year1%400==0) )
            totalDays1 += 1;
        cout<<totalDays1<<endl;
        
        int totalDays2 = (year2-1)*365 + (year2-1)/4 - (year2-1)/100 + (year2-1)/400;
        for(int i=1;i<month2;i++)
            totalDays2 += monthDays[i];
        totalDays2 += day2;
        if(month2>2 && ( (year2%100 && year2%4==0) || year2%400==0) )
            totalDays2 += 1;
        cout<<totalDays2<<endl;
        
        return abs(totalDays1-totalDays2);
    }
};
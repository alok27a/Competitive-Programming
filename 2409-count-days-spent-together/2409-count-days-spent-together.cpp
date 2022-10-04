class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
          int monthAA = stoi(arriveAlice.substr(0,2)), dayAA = stoi(arriveAlice.substr(3)), monthAD = stoi(leaveAlice.substr(0,2)), dayAD = stoi(leaveAlice.substr(3));
        int monthBA = stoi(arriveBob.substr(0,2)), dayBA = stoi(arriveBob.substr(3)), monthBD = stoi(leaveBob.substr(0,2)), dayBD = stoi(leaveBob.substr(3));
        int monthStart, dayStart, monthEnd, dayEnd, totalDays;
        if (monthAA == monthBA) {
            monthStart = monthAA;
            dayStart = max(dayAA, dayBA);
        } else if (monthAA < monthBA) {
            monthStart = monthBA;
            dayStart = dayBA;
        } else {
            monthStart = monthAA;
            dayStart = dayAA;
        }
        if (monthAD == monthBD) {
            monthEnd = monthAD;
            dayEnd = min(dayAD, dayBD);
        } else if (monthAD < monthBD) {
            monthEnd = monthAD;
            dayEnd = dayAD;
        } else {
            monthEnd = monthBD;
            dayEnd = dayBD;
        }
        vector<int> v = { 0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (monthStart > monthEnd) return false;
        if (monthStart == monthEnd && dayStart > dayEnd) return false;
        if (monthStart == monthEnd) return dayEnd-dayStart+1;
        totalDays = v[monthStart]-dayStart + dayEnd;
        monthStart++;
        while (monthStart < monthEnd)
            totalDays += v[monthStart++];
        
        return totalDays+1;
    }
};
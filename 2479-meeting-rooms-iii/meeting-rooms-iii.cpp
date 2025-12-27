class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());

        set<int> free;
        set<pair<long long int,int>> booked;

        for(int i=0;i<n;i++){
            free.insert(i);
        }

        vector<int> bookings(n,0);

        for(auto i: meetings){
            int start = i[0];
            int end = i[1];

            //Free up the previous rooms

            while(booked.size()>0 && (booked.begin())->first<=start)
            {
                int room = (booked.begin())->second;
                booked.erase(booked.begin());

                free.insert(room);

            }

            if(free.size()>0){
                int room = *(free.begin());
                bookings[room]++;

                free.erase(free.begin());

                booked.insert({end,room});
            }else{

                auto earliest = *booked.begin();
               long long int earliestTime = earliest.first;
                int room = earliest.second;

                booked.erase(booked.begin());
               long long int dur = end-start;
                bookings[room]++;
                booked.insert({earliestTime+dur,room});
            }

        
        }

        int maxBookings =0;
        int room =0;
        for(int i=0;i<n;i++){
            if(maxBookings<bookings[i]){
                maxBookings = bookings[i];
                room =i;
            }
        }

        return room;
    }
};
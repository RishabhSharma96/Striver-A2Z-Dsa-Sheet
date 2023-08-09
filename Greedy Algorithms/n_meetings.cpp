class meeting {
public:
   int start;
   int end;
   int pos;
};

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    bool static comparator(struct meeting m1, meeting m2) {
         if (m1.end < m2.end) return true;
         else if (m1.end > m2.end) return false;
         else if (m1.pos < m2.pos) return true;
         return false;
     }
    
    int maxMeetings(int startt[], int endt[], int n)
    {
        meeting meet[n];
        for (int i = 0; i < n; i++) {
         meet[i].start = startt[i], meet[i].end = endt[i], meet[i].pos = i + 1;
        }
        
        sort(meet, meet + n, comparator);
        
        int endTime = -1;
        int meetings = 0 ;
        
        for(auto it : meet){
            if(it.start > endTime){
                meetings++;
                endTime = it.end;
            }
        }
        
        return meetings ;

    }
};

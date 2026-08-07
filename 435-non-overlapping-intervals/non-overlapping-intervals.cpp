class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> mpp;
        int n = intervals.size();
        
        if (n == 0) return 0;

        // Copying to pair vector
        for(int i = 0; i < n; i++){
            mpp.push_back({intervals[i][0] , intervals[i][1]});
        }

        // FIX 1: Lambda parameters must be pair<int,int>, not vector<pair...>
        sort(mpp.begin(), mpp.end(), [](const pair<int,int> &a, const pair<int,int> &b){
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

        int cnt = 0;
        int end = mpp[0].second;
        
        for(int i = 1; i < n; i++){
            // FIX 2: Check mpp[i].first, not intervals[i][0]
            if(mpp[i].first < end){
                // Overlap found! We remove this interval.
                cnt++; 
                // FIX 3: Do NOT update 'end' here. We keep the smaller 'end' to prevent future overlaps.
            } else {
                // No overlap. Update 'end' to the end time of the current interval.
                end = mpp[i].second;
            }
        }
        return cnt;
    }
};
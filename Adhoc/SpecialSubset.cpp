#include<bits/stdc++.h>
using namespace std;

class SpecialSubsets {
public:
    static int countSubsets(vector<int> nums,int target) {
        int ws = 0, we = nums.size()-1;
        int ans =0;

        while(ws<=we) {
            int mine = nums[ws], maxe = nums[we];
            cout << nums[ws] << " " << nums[we] << endl;

            if(mine + maxe < target) {
                cout << "Entered" << endl;
                ans += pow(2,we-ws);
                ws++;
            } else {
                we--;
            }
        }


        return ans;
    }
};

// 3 3 6 8
// 10
// 3,3,6,33,36,36
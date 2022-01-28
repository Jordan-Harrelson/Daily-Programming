class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> vec = {0,0,0};
        for(int num : bills)
        {
            switch(num)
            {
                case 5:
                    vec[0] += 1;
                    break;
                case 10: 
                    vec[1] += 1;
                    if(vec[0] == 0)
                        return false;
                    vec[0] -= 1;
                        break;
                default:
                    vec[2] +=1;
                    if(vec[0] == 0 || vec[1] == 0)
                    {
                        if(vec[0] < 3)
                            return false;
                        vec[0] -= 3;
                        break;
                    }
                    vec[0] -= 1;
                    vec[1] -= 1;
                    break;
            }
            
        }
        return true;
    }
};

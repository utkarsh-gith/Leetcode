// can also use stack the same way

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans;

        for (int asteroid : asteroids)
        {
            bool destroyed = false;

            while (!ans.empty() && ans.back() > 0 && asteroid < 0)
            {
                if (abs(ans.back()) < abs(asteroid))
                {
                    ans.pop_back();
                }
                else if (abs(ans.back()) == abs(asteroid))
                {
                    ans.pop_back();
                    destroyed = true;
                    break;
                }
                else
                {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed)
            {
                ans.push_back(asteroid);
            }
        }

        return ans;
    }
};
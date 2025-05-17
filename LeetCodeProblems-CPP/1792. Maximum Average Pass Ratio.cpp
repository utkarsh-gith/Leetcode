class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {

        priority_queue<pair<double, int>> ratio;
        for (int i = 0; i < classes.size(); i++)
        {
            double d1 = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            double d2 = (double)classes[i][0] / classes[i][1];
            ratio.push({d1 - d2, i});
        }

        while (extraStudents > 0)
        {

            int idx = ratio.top().second;
            ratio.pop();
            classes[idx][0]++;
            classes[idx][1]++;
            double d1 = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1);
            double d2 = (double)classes[idx][0] / classes[idx][1];
            ratio.push({d1 - d2, idx});
            extraStudents--;
        }

        double max = 0;
        for (int i = 0; i < classes.size(); i++)
        {
            max += (double)classes[i][0] / classes[i][1];
        }

        return max / classes.size();
    }
};
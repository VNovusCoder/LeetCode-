
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(int index, vector<int>& candidates, int target) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates at the same level
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Since sorted, no need to continue
            if (candidates[i] > target) {
                break;
            }

            path.push_back(candidates[i]);

            // i + 1 because each element can be used once
            solve(i + 1, candidates, target - candidates[i]);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target);

        return ans;
    }
};

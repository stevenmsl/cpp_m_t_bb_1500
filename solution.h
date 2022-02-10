

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;
namespace sol1500
{
    class FileSharing
    {
    private:
        /*
          - user ids returned and can be reused
            by new users
          - use min-heap as we need to return
            the smallest id if the pool is
            not empty
        */
        priority_queue<int, vector<int>, greater<int>> idPool;

        int maxIdIssued = 0;
        /*
          - record the chunks and the users own it
          - the value if the map is a set as when
            a chunk is requested, we need to return
            a list of user id in ascending order
        */
        unordered_map<int, set<int>> chunks;

        /*
          - record the users and the chunks each user owns
        */
        unordered_map<int, unordered_set<int>> users;

    public:
        FileSharing(int m);
        int join(vector<int> ownedChunks);
        void leave(int userId);
        vector<int> request(int userId, int chunkId);
    };

    class Solution
    {
    public:
    };

}
#endif
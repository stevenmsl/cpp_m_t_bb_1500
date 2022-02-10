#include "solution.h"
#include <iterator>
using namespace sol1500;
using namespace std;

/*takeaways
  - this is a good exercise in picking up
    proper data structures to implement
    the requirements
  - check solution.h for more details
*/
/* C++ note
   - use set if you need the elements in it sorted
   - know how to insert a vector into a set which
     already contains some elements
   - know the behavior of map (unordered_map) container
     that using the subscript operator will automatically
     create an entry for you
     - check the comments in the join method
*/

FileSharing::FileSharing(int m)
{
  /*
    - maybe throw if the chucnk id is greater than m
    - all the private members have been instantiated
      you don't need to do anything here for that
      - check the solution.h file
  */
}
int FileSharing::join(vector<int> ownedChunks)
{
  int userId = -1;
  /*
     - min-heap; smallest id will be returned
  */
  if (!idPool.empty())
  {
    userId = idPool.top();
    idPool.pop();
  }
  else
    userId = ++maxIdIssued;

  for (auto c : ownedChunks)
  {
    /*
       - an entry will be created
         if the key doesn't exist
       - the value of the entry
         will be instantiated
     */
    users[userId].insert(c);
    chunks[c].insert(userId);
  }

  return userId;
}
void FileSharing::leave(int userId)
{
  if (users.count(userId) == 0)
    return;
  /* no longer owns these chunks */
  for (auto c : users[userId])
    chunks[c].erase(userId);

  /*
    - we do need to remove it from the users
      as we rely on users to check if a user
      has already joined
  */
  users.erase(userId);

  /* return the id to the pool */
  idPool.push(userId);
}
vector<int> FileSharing::request(int userId, int chunkId)
{
  if (users.count(userId == 0) || chunks.count(chunkId) == 0)
    return vector<int>();
  /*
    - chunks[chunkId] is a set which has its
      elements in ascending order by default
  */
  auto result = vector<int>(chunks[chunkId].begin(),
                            chunks[chunkId].end());

  /* userId needs to own the chunk as well */

  if (chunks[chunkId].count(userId) == 0)
    chunks[chunkId].insert(userId);
  if (users[userId].count(chunkId) == 0)
    users[userId].insert(chunkId);

  return result;
}
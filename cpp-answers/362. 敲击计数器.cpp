/* naive solution(It's amazing that it pass all the test cases..... The time complexity is awful high!)
class HitCounter
{
public:
    vector<int> times;
    HitCounter()
    {
    }

    void hit(int timestamp)
    {
        times.push_back(timestamp);
    }

    int getHits(int timestamp)
    {
        int cnt = 0;
        int startTime = timestamp - 300 + 1; // [startTime, timestamp]
        for (int i = 0; i < times.size(); i++)
        {
            if (times[i] >= startTime)
            {
                cnt++;
            }
        }
        return cnt;
    }
}; */

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */

/* Solution 2: use queue */
class HitCounter
{
public:
    queue<int> time;
    HitCounter()
    {
    }

    void hit(int timestamp)
    {
        time.push(timestamp);
    }

    int getHits(int timestamp)
    {
        int startTime = timestamp - 5 * 60;
        while (!time.empty() && time.front() <= startTime)
        {
            time.pop();
        }
        return time.size();
    }
};
// 2034. Stock Price Fluctuation
// https://leetcode.com/problems/stock-price-fluctuation/submissions/879379905/
class StockPrice
{
    priority_queue<int> pq_max;
    priority_queue<int, vector<int>, greater<int>> pq_min;
    unordered_map<int, int> freq;
    unordered_map<int, int> um;

    int max_ts, curr;

public:
    StockPrice()
    {
        max_ts = curr = 0;
    }

    void update(int ts, int price)
    {

        if (um.find(ts) != um.end())
        { // If this timestamp is already present
            freq[um[ts]]--;

            while (!pq_max.empty() && freq[pq_max.top()] == 0)
            {
                pq_max.pop();
            }
            while (!pq_min.empty() && freq[pq_min.top()] == 0)
            {
                pq_min.pop();
            }
        }

        um[ts] = price; // Update timestamp with new price

        if (freq[price]++ == 0)
        { // If not present in heaps
            pq_max.push(price);
            pq_min.push(price);
        }

        if (ts >= max_ts)
        { // Maintain latest price (current)
            max_ts = ts;
            curr = price;
        }
    }

    int current()
    {
        return curr;
    }

    int maximum()
    {
        return pq_max.top();
    }

    int minimum()
    {
        return pq_min.top();
    }
};
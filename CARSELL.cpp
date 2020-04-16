#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

using namespace std;

ll mod = 1e9 + 7;


int main() {
	ll T;
	int N;
	
	cin >> T;
	
	for (ll i = 1; i <= T; i++)
	{
		vector<ll> prices;
		ll max_profit = 0;
		ll temp;
		cin >> N;
		for (ll c = 1; c <= N; c++)
		{
			cin >> temp;
			prices.push_back(temp);
		}


		sort(prices.begin(), prices.end());
		ll k = 0;
		ll depreciation = 0;
		for (ll j = prices.size() - 1; j >= 0; j--)
		{

			if (k == 0)
			{
				depreciation = prices[j];
			}
			else
			{
				depreciation = prices[prices.size() - 1] - k;
				if (depreciation < 0)
				{
					depreciation = 0;
				}
			}
			//max_profit += depreciation;
			//max_profit += max_profit % mod;
			max_profit = ((max_profit + depreciation) % mod); 
			prices.pop_back();
			k++;
		}
		cout << max_profit  << endl;
	}

	return 0;
}

class Solution {
private:
	template <class I, class F, int K = 256>
	static void countingSort(I first, I last, I output, F slot) {
		array<int, K> count = {};
		for (auto it = first; it != last; ++it)
			++count[slot(it)];
		partial_sum(count.begin(), count.end(), count.begin());
		for (auto it = last; it != first; --it)
			*(output + --count[slot(it - 1)]) = *(it - 1);
	}
	template <class I, int K = 256, int D = 4>
	static void radixSort(I first, I last, I output) {
		auto end = output + distance(first, last);
		for (int d = 0; d < D; ++d) {
			auto slot = [&](const auto& it) {
				unsigned char byte = *it >> (8 * d);
				if (d == D - 1)
					byte ^= 0x80; /* negative numbers should come before positive numbers */
				return byte;
			};
			countingSort(first, last, output, slot), swap(first, output), swap(last, end);
		}
		copy(first, last, output);
	}
public:
	/* time: O(n), space: O(n) */
	static vector<int> sortArray(vector<int>& nums) {
		const int n = nums.size();
		vector<int> ans(n);
		radixSort(nums.begin(), nums.end(), ans.begin());
		return ans;
	}
};

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
    int freq[10] = {0};

    // Count frequency
    for (int d : digits) {
        freq[d]++;
    }

    int count = 0;

    // Try all 3-digit even numbers
    for (int num = 100; num <= 999; num++) {
        if (num % 2 != 0) continue; // must be even

        int a = num / 100;
        int b = (num / 10) % 10;
        int c = num % 10;

        int need[10] = {0};
        need[a]++;
        need[b]++;
        need[c]++;

        bool valid = true;

        for (int d = 0; d < 10; d++) {
            if (need[d] > freq[d]) {
                valid = false;
                break;
            }
        }

        if (valid) count++;
    }

    return count;
}

};
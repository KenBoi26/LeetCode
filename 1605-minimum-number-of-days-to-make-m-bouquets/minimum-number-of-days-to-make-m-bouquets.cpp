const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;


void* operator new(size_t size) {
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char* aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}


void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}
class Solution {
public:

    int calc(vector<int> &bloomDay, int mid, int k){
        int count = 0;
        int prev = -1;
        int temp = 0;
        
        for(int i=0; i<bloomDay.size(); i++){
            
            if(bloomDay[i]-mid <= 0){
                temp++;
            }else{
                temp = 0;
            }

            prev = bloomDay[i]-mid;

            if(temp >= k){
                count++;
                temp = 0;
            }
        }

        
        return count;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;
        while(left <= right){
            int mid = left+(right-left)/2;

            if(calc(bloomDay, mid, k) >= m){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return ans;
    }
};
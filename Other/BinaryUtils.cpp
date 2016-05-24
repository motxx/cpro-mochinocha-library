/*namespace utility { namespace binary {*/
template<class T, class ResultType = long long> vector<ResultType> binary_representation(T x, int const LeastDigit = 0) {if(x == 0) return {0};vector<ResultType> ret;while(x > 0) {ret.push_back(x % 2);x /= 2;}while((int)ret.size() < LeastDigit) {ret.push_back(0);}reverse(all(ret));return ret;}/*
// http://qiita.com/logicmachine/items/3531ddb0b8acc04cb613
inline void binary_convert(uint32_t *ptr, const string &s){int const n = s.size();for(int i=0; i<n; ++i){ptr[i >> 5] |= static_cast<uint32_t>(s[i] - '0') << (i & 31);}}
static inline int32_t __attribute__((always_inline)) _mm_popcnt_u32(uint32_t x){int32_t result;__asm__("popcnt %1, %0" : "=r" (result) : "r" (x));return result;}
static inline int nlz(unsigned int x){int n;union {unsigned long long as_uint64;double as_double;} data;data.as_double = (double)x + 0.5;n = 1054 - (data.as_uint64 >> 52);return n;}
//static inline int msb(uint32_t v) { assert(0); } // unimplemented
static inline int lsb(int x) {return x&(-x);}
template<class T> ostream& operator << (ostream& ost, vector<T> && v) { for(auto && e: v) ost << e; return ost; }
#define USE_BINARY_REP      using utility::binary::binary_representation;
#define USE_BINARY_OUT      using utility::binary::operator<<;
#define USE_BINARY_CONVERT  using utility::binary::binary_convert;
#define USE_BIT_COUNT       using utility::binary::_mm_popcnt_u32;  \
                            using utility::binary::nlz; \
                            using utility::binary::lsb;
#define USE_BINARY_UTILS    USE_BINARY_REP ; USE_BINARY_OUT ; USE_BINARY_CONVERT ; USE_BIT_COUNT
}}*/
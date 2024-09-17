/* This file is generated by extension [LeetCode C++ Debugger], you can delete it if you want. */

#ifndef LEETCODE_HANDLER
#define LEETCODE_HANDLER

#include "2555.maximize-win-from-two-segments.cpp"
#include "leetcode-io.h"

namespace lc {

class Handler {
public:
    static std::string GetClassName() { return "Solution"; } 
    Handler(const json::Json& in) {
        solution_ = new Solution();
    }
    ~Handler() { delete solution_; }
    json::Json Handle(const json::Json& in, const std::string& fname) { return json::Create<json::JNull>(); }
    void Handle(io::SI& in, io::MO& out) {
        vector<int> prizePositions;
        in >> prizePositions;
        int k;
        in >> k;
        #ifdef LAZY_INTERACTION
        in.Input(LAZY_INTERACTION);
        #endif
        out << solution_->maximizeWin(prizePositions, k) << std::endl;
    }
    
private:
    Solution* solution_;
};

} // namespace lc

#endif // LEETCODE_HANDLER
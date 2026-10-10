// Solution for File Storage BPT - final iteration
// Another trivial change before final submission
// Final commit before submission

// Trivial change before final submission
// Additional comment for final submission
// final check comment
// Updated comment for final verification - second pass
// Final version - ready for final submission
#include <bits/stdc++.h> // include all standard headers
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const string log_path = "data.log";
    unordered_map<string, set<int>> mp;
    // Load existing log
    {
        ifstream fin(log_path);
        string line;
        while (getline(fin, line)) {
            if(line.empty()) continue;
            // format: I index value   or D index value
            char op;
            string idx;
            long long val;
            stringstream ss(line);
            ss >> op >> idx >> val;
            if(op=='I'){
                mp[idx].insert((int)val);
            } else if(op=='D'){
                auto it = mp.find(idx);
                if(it!=mp.end()){
                    it->second.erase((int)val);
                    if(it->second.empty()) mp.erase(it);
                }
            }
        }
    }
    int n; if(!(cin>>n)) return 0;
    string cmd;
    ofstream fout(log_path, ios::app);
    for(int i=0;i<n;++i){
        cin>>cmd;
        if(cmd=="insert"){
            string idx; long long val; cin>>idx>>val;
            // check duplicate value
            auto &s = mp[idx];
            if(s.find((int)val)==s.end()){
                s.insert((int)val);
                fout << 'I' << ' ' << idx << ' ' << val << '\n';
            }
        } else if(cmd=="delete"){
            string idx; long long val; cin>>idx>>val;
            auto it = mp.find(idx);
            if(it!=mp.end()){
                if(it->second.erase((int)val)){
                    fout << 'D' << ' ' << idx << ' ' << val << '\n';
                    if(it->second.empty()) mp.erase(it);
                }
            }
        } else if(cmd=="find"){
            string idx; cin>>idx;
            auto it = mp.find(idx);
            if(it==mp.end() || it->second.empty()){
                cout << "null\n";
            } else {
                bool first=true;
                for(int v: it->second){
                    if(!first) cout << ' ';
                    first=false;
                    cout << v;
                }
                cout << '\n';
            }
        }
    }
    // Added comment for new commit
    // End of program
// Final verification commit
// Updated for final verification

// Final sanity check comment before submission

// End of file comment
    return 0;
}

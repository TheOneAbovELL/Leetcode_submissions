class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> obs;
        for(auto& o:obstacles){
            obs.insert((long long)o[0]<<32|(unsigned int)o[1]);
        }
        int dir=0;
        int x=0,y=0;
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int res=0;
        for(int c:commands){
            if(c==-2){
                dir=(dir+3)%4;
            }else if(c==-1){
                dir=(dir+1)%4;
            }else{
                for(int i=0;i<c;i++){
                    int nx=x+dx[dir];
                    int ny=y+dy[dir];
                    if(obs.count((long long)nx<<32|(unsigned int)ny)){
                        break;
                    }
                    x=nx;
                    y=ny;
                    res=max(res,x*x+y*y);
                }
            }
        }
        return res;
    }
};
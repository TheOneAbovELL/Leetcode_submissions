class Robot {
private:
    int w,h;
    int x=0,y=0;
    int dir=0;
    vector<string> dirs={"East","North","West","South"};
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int perimeter;
public:
    Robot(int width, int height) {
        w=width;
        h=height;
        perimeter=2*(w+h-2);
        if(perimeter==0) perimeter=1;
    }
    void step(int num) {
        if(perimeter>0){
            num%=perimeter;
            if(num==0&&(x==0&&y==0&&dir==0)) num=perimeter;
        }
        while(num>0){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx<0||nx>=w||ny<0||ny>=h){
                dir=(dir+1)%4;
                continue;
            }
            x=nx;
            y=ny;
            num--;
        }
    }
    vector<int> getPos() {
        return {x,y};
    }
    string getDir() {
        return dirs[dir];
    }
};
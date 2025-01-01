class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        int r[3]={0,1,-1};
        int c[3]={0,1,-1};
        vector<vector<int>>v(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=0;
                int num=0;
                for(int d=0;d<3;d++){
                    for(int e=0;e<3;e++){
                        int row=i+r[d];
                        int col=j+c[e];
                        if(row>=0&&row<n&&col>=0&&col<m){
                            sum+=img[row][col];
                            num++;
                        }
                    }
                }
                v[i][j]=sum/num;
            }
        }
        return v;
    }
};
int birthday(vector<int> s, int d, int m) {
    int sum=0;
    int col=0;
    for(int i=0;i<s.size();i++){
        for(int it=i;it<(m+i);it++){
            sum=sum+s[it];
        }
        if(sum==d){
            col++;
        }
        sum=0;
    }
    return col;
}

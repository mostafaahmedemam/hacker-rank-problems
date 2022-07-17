int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    /*
     * Write your code here.
     */
    int max_sum=0;
    sort(keyboards.begin(),keyboards.end());
    sort(drives.begin(),drives.end());
    for(int i=0;i<keyboards.size();i++){
        for(int j=0;j<drives.size();j++){
            if(max_sum< keyboards[i]+drives[j]&&keyboards[i]+drives[j] <= b ){
                max_sum=keyboards[i]+drives[j];
            }
        }
    }
    if(max_sum!=0)
    return max_sum;
    else return -1;
}

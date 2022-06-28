
string balancedSums(vector<int> arr) {
    // int sum_upper=0;
    // int sum_lower=0;
    
    // for(int i=1;i<arr.size()-1;i++){
    //     sum_upper=accumulate(arr.begin(), arr.begin()+i, 0);
    //     sum_lower=accumulate(arr.begin()+i+1, arr.end(), 0);
    //     cout<<"it-"<<i<<"--- sum_upper="<<sum_upper<<"--- sum_lower="<<sum_lower<<endl;
    //     if(sum_lower==sum_upper){
    //         return "YES";
    //     }
    // }
    // return "NO";
    int sum_right=0;
    int sum_left=0;
    sum_right=accumulate(arr.begin(), arr.end(), 0);
    for(int i=0;i<arr.size()-1;i++){
        if(sum_left==sum_right)
            return "YES";
        sum_left=sum_left+arr[i];
        sum_right=sum_right-sum_left-arr[i+1];
    }
    return "NO";
}

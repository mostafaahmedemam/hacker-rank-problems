void miniMaxSum(vector<int> arr) {
    int sum=0;

    int min=0,max=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-1;i++){
        min+=arr[i];
    }
    for(int it=1;it<arr.size();it++){
        max+=arr[it];
    }
    //cout<<sum-arr[arr.size()-1]<<" "<<sum-arr[0];
    cout<<min<<" "<<max;
    
}

int migratoryBirds(vector<int> arr) {
    vector<int>frequency(arr.size(),0);
    int max=0;
    int sum=0;
    // for(int i=0;i<arr.size();i++){
    //     for(int it=0;it<arr.size();it++){
    //         if(){}
    //     }
    // }
    for(int i=0;i<arr.size();i++){
        frequency[arr[i]]++;
    }
    int out=0;
    for(int i=0;i<arr.size();i++){
        if(frequency[i]>max){
            max=frequency[i];
            out=i;
            }
    }
    return out;
}

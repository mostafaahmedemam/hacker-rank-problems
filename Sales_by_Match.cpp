int sockMerchant(int n, vector<int> ar) {
    sort(ar.begin(),ar.end());
    int internal_sum=0;
    int num_pairs=0;
    for(int i=0;i<ar.size();i++){
        if(ar[i]==ar[i+1]){
            internal_sum++;
        }
        else{
            num_pairs=num_pairs + ((internal_sum+1)/2);
            internal_sum=0;
        }
    }
    return num_pairs;
}

map<int, int> get_occerence(vector<int> numbers){
    typedef map<int, int> CounterMap;
    CounterMap counts;
    for (int i = 0; i < numbers.size(); ++i)
    {
        CounterMap::iterator it(counts.find(numbers[i]));
        if (it != counts.end()){
            it->second++;
        } else {
            counts[numbers[i]] = 1;
        }
    }
    return counts;   
}
int sockMerchant(int n, vector<int> ar) {
    typedef map<int, int> CounterMap;
    CounterMap counts;
    counts=get_occerence(ar);
    map<int, int>::iterator it;
    int number_pairs=0;
    for (it = counts.begin(); it != counts.end(); it++)
    {
        if(it->second % 2 == 0){
            number_pairs++;
        }
       
    }
    // for(int i=0;i<counts.size();i++){
        
    // }
    return number_pairs;
}

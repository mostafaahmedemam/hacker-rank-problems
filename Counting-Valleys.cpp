int countingValleys(int steps, string path) {
    int reference=0,down=0;
    int num_valleys=0;
    for(int i=0;i<path.size();i++){
        if(path[i]=='U')reference++;
        if(path[i]=='D')reference--;
        
        if(reference==0 && path[i]=='U' ){
            num_valleys++;
        }
    }
    return num_valleys;
}
 

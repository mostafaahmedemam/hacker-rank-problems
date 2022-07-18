void kaprekarNumbers(int p, int q) {
    int sqr = 0;
    string sqrString = "";
    int r = 0, l = 0;
    int flag = 0;
    for (int i = p; i <= q; i++) {
        sqr = i * i;
        sqrString = to_string(sqr);
        //calculate split digit
       // if (sqrString.length() % 2 == 0) {
           
            r = stoi(sqrString.substr(0, to_string(i).length()));
            l = stoi(sqrString.substr(to_string(i).length()));

            if (r + l == i) { cout << i << " "; flag = 1; }
        //}
        else if (i == 1) { cout << i << " "; flag = 1; }
        /*else {
            if (sqrString.length() > 1){
                flag = 1;
            r = stoi(sqrString.substr(0,to_string(i).length()));
            l = stoi(sqrString.substr(to_string(i).length()));
            if (r + l == i) {
                cout << i << " ";
            }
           
            }
        }*/
    }
    if (!flag)
        cout << "INVALID RANGE" << endl;
}

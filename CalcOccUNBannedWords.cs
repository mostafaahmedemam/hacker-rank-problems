public class Solution {
    public string MostCommonWord(string paragraph, string[] banned) {
        char[] delimiterChars = { ' ', ',', '.', '!', ';' ,'?'};
        string[] words = paragraph.Split(delimiterChars,System.StringSplitOptions.RemoveEmptyEntries);
        var g = words.GroupBy( i => i );
        int max=0;
        string maxWord="";
        for(int i=0;i<words.Count();i++){
            words[i]=words[i].ToLower();
        }
        foreach( var grp in g )
        {
            
            if(max<grp.Count() && !banned.Contains(grp.Key))
            {
                max=grp.Count();
                maxWord=grp.Key;
            }
          //Console.WriteLine( "{0} {1}", grp.Key, grp.Count() );
        }
        return maxWord;
    }
}

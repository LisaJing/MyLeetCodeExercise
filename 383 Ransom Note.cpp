class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransomNoteChar[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int magazineChar[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(string::iterator sit = ransomNote.begin();sit != ransomNote.end();sit++)
        {
        	ransomNoteChar[*sit - 'a']++;
        }
        for(string::iterator sit = magazine.begin();sit != magazine.end();sit++)
        {
        	magazineChar[*sit - 'a']++;
        }
        for(int i = 0;i < 26;i++)
        {
        	if(ransomNoteChar[i] > magazineChar[i])
        		return false;
        }
        return true;
    }
};

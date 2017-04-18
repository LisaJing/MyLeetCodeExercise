class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        if(size <= 0)
            return false;
        map<char, char > Parentheses;
        Parentheses['('] = ')';
        Parentheses['['] = ']';
        Parentheses['{'] = '}';
        
        
        stack<char> char_stack;
        string::iterator sit = s.begin();
        while(sit != s.end())
        {
            cout << "*sit: " << *sit << endl;
            switch(*sit)
            {
                case '(':
                case '[':
                case '{':
                    char_stack.push(*sit);
                    break;
                case ')':
                case ']':
                case '}':
                    if(char_stack.size() <= 0)
                        return false;
                    if(*sit == Parentheses[char_stack.top()])
                    {
                        char_stack.pop();
                        break;
                    }
                    else
                        return false;
                default:
                    return false;
            }
            sit++;
        }
        if(char_stack.empty())
            return true;
        else
            return false;
    }
};

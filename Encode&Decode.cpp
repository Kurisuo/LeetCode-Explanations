class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";

        if(strs.empty()){ 
            return "";
        }

        //we can add the length of the string at the beginning followed by a #
        //what if the string already contains a hash? 
        // ----> we could use a boolean as a lock, while the first has has been read
        //    -----> skip reading all other hashes as a condition and read as ASCII

        //set delimiters and get lengths
        for(const string& x : strs){ //forces x to be a read-only variable 
            int len = x.length();
            encoded.append(to_string(len) + '#' + x);
          //  x.insert(0, '#'); // _#abcd slow, forces shifts everytime
          // x.insert(0, len); // 4#abcd
        }
        return encoded;
    }


    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;

        //while loop for manual control
        while (i < s.length()){
            int j = s.find('#', i);
            int len = stoi(s.substr(i, j - i));

            decoded.push_back(s.substr(j + 1, len));
            i = j + len + 1;
        }

        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
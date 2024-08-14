class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long volume = (long long)length * (long long)width * (long long)height;
        // if( volume <= 10e9) cout<<"true";
        bool isBulky = isBulk(volume, length, width, height);
        bool isHeavy = mass >= 100 ? true : false;
        if(isBulky && isHeavy) return "Both";
        else if (!isBulky && !isHeavy) return "Neither";
        else if (isBulky && !isHeavy) return "Bulky";
        else if(!isBulky && isHeavy) return "Heavy";
        return "";
    }

    bool isBulk(long long volume, long long length, long long width, long long height){
        if(volume >= 1e9 || length >= 1e4 || width >= 1e4 || height >= 1e4) return true;
        return false;
    }
};
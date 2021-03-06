class Solution {
public:
    bool validUtf8(vector<int>& arr) {
         int rb = 0;

        //Traversing the array
        for(int i = 0; i < arr.size(); i++){
            //We are checking for the new fresh char
            if(rb == 0){
                //char of 1 byte
                if(arr[i] >> 7 == 0){
                    rb = 0;
                }
                //char of two bytes
                else if(arr[i] >> 5 == 6){
                    rb = 1;
                }
                //char of three bytes
                else if(arr[i] >> 4 == 14){
                    rb = 2;
                }
                //char of four bytes
                else if(arr[i] >> 3 == 30){
                    rb = 3;
                }
                else{
                    return false;
                }
            }
            //We are checking for the continuation of char of size more than 1 byte
            else{
                if(arr[i] >> 6 == 2){
                    rb--;
                }
                else{
                    return false;
                }
            }
        }
        if(rb == 0)
        return true;
        return false;
    }
};
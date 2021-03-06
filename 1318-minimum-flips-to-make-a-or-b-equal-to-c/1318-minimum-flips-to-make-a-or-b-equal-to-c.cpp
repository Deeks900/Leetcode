class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        for(int i = 0; i < 32; i++){
            int mask = (1 << i);
            bool ai = false;
            bool bi = false;
            bool ci = false;
            if((a&mask) != 0){
                ai = true;
            }
            if((b&mask) != 0){
                bi = true;
            }
            if((c&mask) != 0){
                ci = true;
            }
            
            //Now dealing with the cases
            if(ci){
                if(!ai && !bi){
                    count++;
                }
            }
            else{
               if(ai&&!bi){
                    count++;
                }
                else if(!ai&&bi){
                    count++;
                }
                else if(ai&&bi){
                    count += 2;
                }
            }
        }
        
        return count;
    }
};
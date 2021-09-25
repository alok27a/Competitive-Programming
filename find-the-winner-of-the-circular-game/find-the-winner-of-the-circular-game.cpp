class Solution {
public:
    int findTheWinner(int n, int k) {
        list<int>l; //creates a doubly linked list using stl container//
    for(int i=0;i<n;i++)
        l.push_back(i); //pushes i to the end of the doubly linked list//
      
     auto it = l.begin(); 
    while(l.size()>1){
         
        for(int i=1;i<k;i++){
            it++;
             
            if(it==l.end()){
              //if iterator reaches the end,then we change it to begin of the list//
                it = l.begin();
            }
        }
         
         it = l.erase(it);
          
         if(it==l.end()){
           //if iterator reaches the end,then we change it to begin of the list//
                it = l.begin();
            }
    }
     
    return l.front()+1; //returns front element of the list//
    }
};